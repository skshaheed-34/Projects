#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// === WiFi Credentials ===
const char* ssid = "5677A";
const char* password = "Biryani@5677A";

// === ThingSpeak Configuration ===
const char* server = "http://api.thingspeak.com/update";
String apiKey = "K45SSWNZ0BO9ZZ2T";

// === DHT11 Sensor ===
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// === MQ2 Sensor ===
#define MQ2_PIN 34

// === Fan Pins ===
#define FAN_ENA 23
#define FAN_IN1 14
#define FAN_IN2 12

// === Buzzer ===
#define BUZZER_PIN 27

// === Timing Variables ===
unsigned long lastUpdate = 0;
const unsigned long updateInterval = 15000;

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("🚀 System Booting...");

  dht.begin();
  pinMode(FAN_ENA, OUTPUT);
  pinMode(FAN_IN1, OUTPUT);
  pinMode(FAN_IN2, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(FAN_IN1, HIGH);
  digitalWrite(FAN_IN2, LOW);
  analogWrite(FAN_ENA, 0);

  Serial.println("🔌 Connecting to WiFi...");
  WiFi.begin(ssid, password);
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 15) {
    delay(1000);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ WiFi connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\n❌ WiFi connection failed.");
  }
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastUpdate >= updateInterval || lastUpdate == 0) {
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();
    int gasValue = analogRead(MQ2_PIN);

    // Estimate AQI value
    int aqi = map(gasValue, 200, 2000, 0, 500);
    aqi = constrain(aqi, 0, 500);

    // Fan speed from TEMP
    int fanSpeed_temp = 0;
    if (temp >= 18 && temp < 20) fanSpeed_temp = 140;
    else if (temp >= 20 && temp <= 25) fanSpeed_temp = 160;
    else if (temp > 25) fanSpeed_temp = 255;

    // Fan speed from GAS
    int fanSpeed_gas = 0;
    if (gasValue >= 600 && gasValue < 800) fanSpeed_gas = 140;
    else if (gasValue >= 800 && gasValue < 1000) fanSpeed_gas = 160;
    else if (gasValue >= 1000) fanSpeed_gas = 255;

    int fanSpeed = max(fanSpeed_temp, fanSpeed_gas);

    // === Apply full-speed burst if needed
    if (fanSpeed > 0 && fanSpeed < 180) {
      Serial.println("💨 Boosting fan with full speed burst...");
      analogWrite(FAN_ENA, 255);  // Full speed burst
      delay(1000);                // 1 second
    }

    // Apply final fan speed
    analogWrite(FAN_ENA, fanSpeed);

    // Buzzer logic
    if (fanSpeed > 0 || gasValue > 600) {
      tone(BUZZER_PIN, 1000);
      Serial.println("🔔 Buzzer ON: Fan active or gas detected");
    } else {
      noTone(BUZZER_PIN);
      Serial.println("🔕 Buzzer OFF");
    }

    // Debug output
    Serial.print("✅ Temp: "); Serial.print(temp);
    Serial.print(" °C | Hum: "); Serial.print(hum);
    Serial.print(" % | Gas: "); Serial.print(gasValue);
    Serial.print(" | AQI: "); Serial.print(aqi);
    Serial.print(" | Fan PWM: "); Serial.println(fanSpeed);

    // ThingSpeak upload
    String url = String(server) + "?api_key=" + apiKey +
                 "&field1=" + String(temp) +
                 "&field2=" + String(hum) +
                 "&field3=" + String(fanSpeed) +
                 "&field4=" + String(aqi) +
                 "&field5=" + String(gasValue);

    Serial.println("🌐 Sending to ThingSpeak...");
    Serial.println(url);

    HTTPClient http;
    http.begin(url);
    int httpCode = http.GET();

    if (httpCode > 0) {
      Serial.println("📡 Data sent to ThingSpeak!");
    } else {
      Serial.println("⚠️ Error sending data:");
      Serial.println(httpCode);
    }

    http.end();
    lastUpdate = currentMillis;
  }

  delay(1000);
}
