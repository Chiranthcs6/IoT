#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int phPin = A0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("pH Sensor");
  delay(2000);
}

void loop() {
  int sensorValue = analogRead(phPin);
  float voltage = sensorValue * (5.0 / 1023.0);

  float pH = 3.5 * voltage;

  Serial.print("pH Value: ");
  Serial.println(pH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("pH: ");
  lcd.print(pH);

  delay(1000);
}
