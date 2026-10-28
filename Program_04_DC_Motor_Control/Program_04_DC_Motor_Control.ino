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
