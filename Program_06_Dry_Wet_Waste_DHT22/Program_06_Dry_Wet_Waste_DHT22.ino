#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
#define LED_DRY 3
#define LED_WET 4

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED_DRY, OUTPUT);
  pinMode(LED_WET, OUTPUT);
}

void loop() {
  float humidity = dht.readHumidity();
  if (isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  if (humidity > 60) {
    digitalWrite(LED_WET, HIGH);
    digitalWrite(LED_DRY, LOW);
    Serial.println("Classification: Wet Waste");
  } else {
    digitalWrite(LED_DRY, HIGH);
    digitalWrite(LED_WET, LOW);
    Serial.println("Classification: Dry Waste");
  }
  delay(2000);
}
