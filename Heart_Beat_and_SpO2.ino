#include <WiFi.h>
#include <FirebaseESP32.h>
#include <MAX30100_PulseOximeter.h>

// Firebase settings
#define FIREBASE_HOST "Your_Firebase_Database_URL"
#define FIREBASE_AUTH "Your_Firebase_Secret"

// WiFi credentials
#define WIFI_SSID "Your_WiFi_SSID"
#define WIFI_PASSWORD "Your_WiFi_Password"

// Initialize MAX30100 sensor and Firebase
PulseOximeter pox;
FirebaseData firebaseData;
FirebaseAuth firebaseAuth;
FirebaseConfig firebaseConfig;

// Timing variables
uint32_t tsLastReport = 0;

void setup() {
  Serial.begin(115200);

  // Initialize the MAX30100 sensor
  if (!pox.begin()) {
    Serial.println("MAX30100 was not found. Check wiring/power.");
    while (1);
  }
  Serial.println("MAX30100 initialized.");

  // Connect to WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize Firebase
  firebaseConfig.host = FIREBASE_HOST;
  firebaseConfig.signer.tokens.legacy_token = FIREBASE_AUTH;
  Firebase.begin(&firebaseConfig, &firebaseAuth);
  Firebase.reconnectWiFi(true);

  // Check Firebase connection status
  if (!Firebase.ready()) {
    Serial.println("Firebase initialization failed. Check configuration and credentials.");
  } else {
    Serial.println("Connected to Firebase");
  }

  // Set up the callback for SpO2 and heart rate updates
  pox.setOnBeatDetectedCallback(onBeatDetected);
}

// Callback function to be called when a beat is detected
void onBeatDetected() {
  Serial.println("Beat detected!");
}

void loop() {
  // Update sensor readings
  pox.update();

  // Only report every 2 seconds
  if (millis() - tsLastReport > 2000) {
    float spo2 = pox.getSpO2();
    float bpm = pox.getHeartRate();

    // Check if values are valid
    if (spo2 > 0 && bpm > 0) {
      Serial.print("SpO2: ");
      Serial.print(spo2);
      Serial.print(" %");

      Serial.print("\tHeart Rate: ");
      Serial.print(bpm);
      Serial.println(" bpm");

      // Update Firebase with SpO2
      if (Firebase.ready()) {
        if (Firebase.setFloat(firebaseData, "/spo2", spo2)) {
          Serial.println("SpO2 data sent to Firebase");
        } else {
          Serial.print("Failed to send SpO2 data: ");
          Serial.println(firebaseData.errorReason());
        }

        // Update Firebase with heart rate
        if (Firebase.setFloat(firebaseData, "/bpm", bpm)) {
          Serial.println("Heart Rate data sent to Firebase");
        } else {
          Serial.print("Failed to send Heart Rate data: ");
          Serial.println(firebaseData.errorReason());
        }
      } else {
        Serial.print("Firebase is not ready: ");
        Serial.println(firebaseData.errorReason());
      }
    } else {
      //Serial.print("Firebase is not ready: ");
      Serial.println(firebaseData.errorReason());
    }

    // Update last report timestamp
    tsLastReport = millis();
  }
}
