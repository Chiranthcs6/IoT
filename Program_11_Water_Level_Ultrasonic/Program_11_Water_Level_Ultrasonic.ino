#include <LiquidCrystal_I2C.h>

const int trigPin = 9;
const int echoPin = 10;
LiquidCrystal_I2C lcd(0x27, 16, 2);
long duration;
int distance;
int maxHeight = 200;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.print("Water Level Depth");
  delay(2000);
  lcd.clear();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration / 58.2;

  int waterLevel = maxHeight - distance;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm ");
  Serial.print("Water Level Depth: ");
  Serial.print(waterLevel);
  Serial.println(" cm");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Level: ");
  lcd.print(waterLevel);
  lcd.print(" cm");
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  delay(1000);
}
