# BCS701 Internet of Things – Lab Programs

## 1. Develop a program to blink 5 LEDs back and forth.

```cpp
int leds[] = {2, 3, 4, 5, 6};
int numLeds = 5;
int delayTime = 200;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], HIGH);
    delay(delayTime);
    digitalWrite(leds[i], LOW);
  }

  for (int i = numLeds - 2; i > 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(delayTime);
    digitalWrite(leds[i], LOW);
  }
}
```

## 2. Develop a program to interface a relay with Arduino board.

```cpp
int relayPin = 7;

void setup() {
  pinMode(relayPin, OUTPUT);
}

void loop() {
  digitalWrite(relayPin, HIGH);
  delay(2000);

  digitalWrite(relayPin, LOW);
  delay(2000);
}
```

## 3. Develop a program to deploy an intrusion detection system using Ultrasonic and sound sensors.

```cpp
#define TRIG_PIN 9
#define ECHO_PIN 8
#define SOUND_SENSOR A0
#define BUZZER 7
#define LED 6

long duration;
int distance;
int soundValue;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(SOUND_SENSOR, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  soundValue = analogRead(SOUND_SENSOR);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Sound Value: ");
  Serial.println(soundValue);

  if (distance < 30 || soundValue > 500) {
    digitalWrite(BUZZER, HIGH);
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(BUZZER, LOW);
    digitalWrite(LED, LOW);
  }

  delay(200);
}
```

## 4. Develop a program to control a DC motor with Arduino board.

```cpp
int motorPin1 = 9;
int motorPin2 = 10;
int enablePin = 11;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, HIGH);
}

void loop() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(2000);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  delay(1000);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(2000);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  delay(1000);
}
```

## 5. Develop a program to deploy smart street light system using LDR sensor.

```cpp
int LDRPin = A0;
int LEDPin = 9;
int LDRValue = 0;
int threshold = 500;

void setup() {
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  LDRValue = analogRead(LDRPin);
  Serial.println(LDRValue);
  if (LDRValue > threshold) {
    digitalWrite(LEDPin, HIGH);
  } else {
    digitalWrite(LEDPin, LOW);
  }
  delay(200);
}
```

## 6. Develop a program to classify dry and wet waste with the Moisture sensor (DHT22).

```cpp
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
```

## 7. Develop a program to read the pH value of a various substances like milk, lime and water.

```cpp
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
```

## 8. Develop a program to detect the gas leakage in the surrounding environment.

```cpp
const int mq2Pin = A0;
const int buzzerPin = 9;
const int ledPin = 13;
int gasThreshold = 400;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
}

void loop() {
  int gasValue = analogRead(mq2Pin);
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);
  if (gasValue > gasThreshold) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    Serial.println("Gas leakage detected!");
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }
  delay(500);
}
```

## 9. Develop a program to demonstrate weather station readings using Arduino.

```cpp
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
```

## 10. Develop a program to setup a UART protocol and pass a string through the protocol.

```cpp
void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("UART Communication Setup Complete!");
  Serial.println("Sending String: Hello, UART Protocol!");
}

void loop() {
  Serial.println("Hello, UART Protocol!");
  delay(2000);
}
```

## 11. Develop a water level depth detection system using Ultrasonic sensor.

```cpp
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
```

## 12. Develop a program to simulate interfacing with the keypad module to record the keystrokes.

```cpp
#include <Keypad.h>

const byte ROW_NUM = 4;
const byte COLUMN_NUM = 4;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pin_rows[ROW_NUM] = {2, 3, 4, 5};
byte pin_column[COLUMN_NUM] = {6, 7, 8, 9};

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

void setup() {
  Serial.begin(9600);
  Serial.println("Keypad Interface - Recording Keystrokes");
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.print("Key Pressed: ");
    Serial.println(key);
  }
}
```
