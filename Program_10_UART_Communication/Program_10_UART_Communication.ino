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
