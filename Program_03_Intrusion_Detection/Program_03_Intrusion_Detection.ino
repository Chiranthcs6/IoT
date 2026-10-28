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
