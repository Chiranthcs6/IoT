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
