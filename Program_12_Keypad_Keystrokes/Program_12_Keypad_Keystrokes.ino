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
