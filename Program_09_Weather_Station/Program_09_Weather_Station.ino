#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Adafruit_BMP085.h>

DHT dht(2, DHT22);
Adafruit_BMP085 bmp;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  dht.begin();
  bmp.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  float p = bmp.readPressure() / 100.0;

  Serial.println("Temp: " + String(t) + " C  Hum: " + String(h) + " %  Pres: " + String(p) + " hPa");

  lcd.clear();
  lcd.print("T:" + String(t) + " H:" + String(h));
  lcd.setCursor(0, 1);
  lcd.print("P:" + String(p) + " hPa");

  delay(2000);
}
