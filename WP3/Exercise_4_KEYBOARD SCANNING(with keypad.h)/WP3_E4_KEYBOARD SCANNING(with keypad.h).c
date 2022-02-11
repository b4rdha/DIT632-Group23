// (C) Ediz -> Group: 23 (2022)
// Work package 3 (Tinkercad)
// Exercise 4
// Submission code: AbC-12!


/*------------------------------------------------------------------------------

The program printing the pressed keys to the serial monitor by using getKey() & 
makeKeymap() functions in library <Keypad.h> as well ashardwares the keypad, 
ardunio board, resistors,5v power, through currents in the cables.

References 
 - https://www.arduino.cc/reference/en/libraries/

-------------------------------------------------------------------------------*/

// Used library 
#include <Keypad.h>

// Variables for keeping the count of rows and columns
const byte rows = 4;
const byte cols = 4;

// Defining keymap
// Two dimentional char array to keep 4x4 keys
// "F" key instead of * & "E" key is instead of # 
char keys[rows][cols] = {
        {'1','2','3','A'},
        {'4','5','6','B'},
        {'7','8','9','C'},
        {'F','0','E','D'}
};

byte rowsPins[rows] = {2, 3, 4, 5}; // Connect keypad row1, row2, row3 and row4 to these Arduino pins
byte colsPins[cols] = {6, 7, 8, 9}; // Connect keypad col1, col2, col3, col4 to these Arduino pins.

// Declared object to store pre-compiled makekeymap() function
// which takes keys as single parameter and 
Keypad keypad = Keypad (makeKeymap(keys), rowsPins, colsPins, rows, cols);

// Declared global index variable
byte i = 0;

// Function "setup" where the program initiates 
void setup()
{
  // This starts serial communication, so that the Arduino can send out commands through the USB connection.
  // 9600 bits per second (960 bytes per second or 960 characters pers second)
  Serial.begin(9600); 
  
  // for loop to iterate the entire keymap
  for(i = 0; i < 8; i++){
  	pinMode(i, OUTPUT); // sets the "i" as output 
  }
}

// Function "loop" where the program itirates the functionality for every execution
void loop()
{
  // Variable to me is pressed.store the pressed keys through getKey() pre-compiled function in keypad.h library.
  char pressedButton = keypad.getKey();
  
  // If-statement to check whetwer the key is pressed
  if(pressedButton){
  	Serial.print("Pressed key is "); // Prints the string to the serial monitor
    Serial.println(pressedButton);  // Prints the pressed keys every its pressed
  }
}