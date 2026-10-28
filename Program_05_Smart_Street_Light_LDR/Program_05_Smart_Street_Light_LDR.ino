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
