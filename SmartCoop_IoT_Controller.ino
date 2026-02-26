 * GREENSPHERE LTD - SMART COOP IoT CONTROLLER
 * Developer: GreenSphere Tech Team
 * Hardware: ESP32 Microcontroller
 * Sensors: DHT22 (Temp & Humidity), Water Flow Sensor, Fill Sensor
 * Actuators: Exhaust Fan, Red Warning Light, Buzzer Alarm, Feeder Motor
 */

#include <DHT.h>

// --- PINS DEFINITION (Guhuza insinga na ESP32) ---
#define DHTPIN 4          // DHT22 Data pin
#define DHTTYPE DHT22     // Sensor type (DHT22)
#define FAN_PIN 5         // Relay for Exhaust Fan
#define LIGHT_PIN 18      // Red Warning Light
#define BUZZER_PIN 19     // Buzzer Alarm
#define FEEDER_PIN 21     // Feed Dispenser Motor Relay
#define WATER_FLOW_PIN 2  // Water Flow Sensor

DHT dht(DHTPIN, DHTTYPE);

// Variables for water flow monitoring
volatile int waterPulses = 0;

void IRAM_ATTR countWaterPulses() {
  waterPulses++;
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Setting the pin modes (Kumenyesha ESP32 ibyinjira n'ibisohoka)
  pinMode(FAN_PIN, OUTPUT);
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(FEEDER_PIN, OUTPUT);
  pinMode(WATER_FLOW_PIN, INPUT_PULLUP);

  // Attach interrupt for water flow sensor
  attachInterrupt(digitalPinToInterrupt(WATER_FLOW_PIN), countWaterPulses, FALLING);

  // Initial state (Kuzimya byose mbere yo gutangira)
  digitalWrite(FAN_PIN, LOW);
  digitalWrite(LIGHT_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(FEEDER_PIN, LOW);

  Serial.println("GreenSphere Smart Coop IoT System Started...");
}

void loop() {
  // 1. Read Temperature and Humidity (Gupima Ubushyuhe n'Ubuhehere)
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: "); Serial.print(h); Serial.print(" %\t");
  Serial.print("Temperature: "); Serial.print(t); Serial.println(" *C ");

  // 2. Temperature Control Logic (Amabwiriza y'iyo ubushyuhe burenze 30°C)
  if (t > 30.0) {
    digitalWrite(FAN_PIN, HIGH);     // Turn on Exhaust Fan
    digitalWrite(LIGHT_PIN, HIGH);   // Turn on Red Warning Light
    digitalWrite(BUZZER_PIN, HIGH);  // Sound the Buzzer
    Serial.println("WARNING: High Temp (> 30C)! Fan & Alarm ON.");
  } else {
    digitalWrite(FAN_PIN, LOW);      // Turn off Exhaust Fan
    digitalWrite(LIGHT_PIN, LOW);    // Turn off Red Warning Light
    digitalWrite(BUZZER_PIN, LOW);   // Turn off Buzzer
  }

  // 3. Print Water Flow status (Kugenzura amazi inkoko zinywa)
  Serial.print("Water Flow Pulses: "); Serial.println(waterPulses);

  // 4. Send Data to Blockchain/Cloud (Bizamara amasegonda 5 mbere yo kongera gupima)
  // TODO: Add smart contract interaction logic here
  
  Serial.println("-----------------------------------");
  delay(5000); 
}
