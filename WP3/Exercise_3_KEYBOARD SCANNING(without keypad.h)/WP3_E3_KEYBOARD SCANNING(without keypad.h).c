// (C) Ediz -> Group: 23 (2022)
// Work package 3 (Tinkercad)
// Exercise 3
// Submission code: AbC-12!


/*------------------------------------------------------------------------------

The program printing the pressed keys to the serial monitor without <Keypad.h> library 
by using hardwares the keypad, ardunio board, resistors,5v power, through currents in the cables.

References 
 - https://www.arduino.cc/reference/en/libraries/
 - https://forum.arduino.cc/t/help-to-define-portd-ddrd/517089/5

-------------------------------------------------------------------------------*/

// Defined macros for rows and columns 
#define rows 4
#define cols 4


// Defining keymap
// Two dimentional char array to keep 4x4 keys
// "F" key instead of * & "E" key is instead of # 
const char keys[rows][cols] = {
        {'1','2','3','A'},
        {'4','5','6','B'},
        {'7','8','9','C'},
        {'F','0','E','D'}
};

const int colsPins[cols] = {7, 6, 5, 4}; // Connect keypad col1, col2, col3, col4 to these Arduino pins.
const int rowsPins[rows] = {11, 10, 9, 8}; // Connect keypad row1, row2, row3 and row4 to these Arduino pins

// Declared global input variable to store keys
char input;

// Function "setup" where the program initiates 
void setup()
{
  // This starts serial communication, so that the Arduino can send out commands through the USB connection.
  // 9600 bits per second (960 bytes per second or 960 characters pers second)
  Serial.begin(9600);
  
  // the register type (B/D). in this case "B" & "D" is used for binary matrix to receive input as bits.
  DDRD = 0b00000000; // Data Direction Register that is used to configure the directions (as input) of the I/O lines of Port-D Register pin 8 to pin 11.
  DDRB = 0b00001111; // Data Direction Register that is used to configure the directions (as input) of the I/O lines of Port-B Register pin 4 to pin 7.
}

// Function "loop" where the program itirates the functionality for every execution
void loop()
{
  input = pressedKey(); // constant function call whether a key is pressed and assign the value in.
    
  if(input != 0){ // check whether button is pressed
  	Serial.println(input); //print the pressed button
    delay(1000); // delay 1 second after pressing
  }
}

// Function "loop" where the program itirates the functionality for every execution
unsigned char pressedKey()
{
    char pressedButton = 0; // used to store the key to Not-pressed mening "0"
    int i,j; // Variables for the loop indexes
    
  	for(i = 0; i < rows; i++){ // First loop for the rows
        
      digitalWrite(rowsPins[i], LOW); // set the current row to LOW (deactivate) for validation
      
      for(j = 0; j < cols; j++){ // Second loop for the columns for that current row
          
        // If the column is LOW, with the help of "pull-up resistors" which is connected to 5V 
        // the key over current row and column is pressed
        if(digitalRead(colsPins[j]) == LOW){ 
          pressedButton = keys[i][j]; // the current key is store the value in the variable
       	}
      }
      
      digitalWrite(rowsPins[i], HIGH); // Right after, set back the current row to HIGH (on) because "pull-up resistors" are used
    }
  
    return pressedButton; // return pressed key
}