#include <Keypad.h>

// Define keypad rows and columns
const byte ROW_NUM    = 4; // Four rows
const byte COLUMN_NUM = 4; // Four columns

// Define the keypad keys
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Pin configuration for keypad
byte pin_rows[ROW_NUM] = {9, 8, 7, 6};
byte pin_columns[COLUMN_NUM] = {5, 4, 3, 2};

// Create an instance of the keypad library
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_columns, ROW_NUM, COLUMN_NUM);

// Pin for LED
const int ledPin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  digitalWrite(ledPin, LOW); // LED initially OFF
  Serial.println("Press Key 8 to turn ON the LED, Key 5 to turn OFF the LED.");
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    Serial.print("Key pressed: ");
    Serial.println(key);
    
    if (key == '8') {
      // Turn ON the LED
      digitalWrite(ledPin, HIGH);  // LED ON
      Serial.println("LED ON!");
    }
    else if (key == '5') {
      // Turn OFF the LED
      digitalWrite(ledPin, LOW);   // LED OFF
      Serial.println("LED OFF!");
    }
  }
}