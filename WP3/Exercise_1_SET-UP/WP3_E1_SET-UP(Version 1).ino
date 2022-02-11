// (C) Bassam -> Group: 23 (2022)
// Work package 3
// Exercise 1 blinking LED and LED with button
// Submission code: AbC-12!

/*------------------------------------------------------------
EXERCISE 3 blinking LED and LED with button
A program to light an LED when pressing a button and the other LED shall be blinking every 500 ms 

- This program is implemented so that the button give the arduino-board it's input 
(pressed or not which means 1 or 0) so the LED shall react on the state of the button. The button and the LED
are not connected directly but connected to the board. 

- The program could be implemented in another way where the button shall be cutting the current
by recieving the power supply from one terminal and the other terminal shall be connected to the LED Anode.
So that if the button is pressed the current is flowing otherwise the current is broken.  
--------------------------------------------------------------*/




//define blinking LED pin and the button pin LED
#define blink_led 13      // blink LED is connected to pin 13  
#define button_led 12     // button LED is connected to pin 12
#define button 11         // button is connected to pin 11


// global variable

// initial state is 0 means that button in not pressed
int button_state = 0;


/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
  
void setup ()
{

  // declare that both LEDs are outputs
  pinMode(blink_led, OUTPUT);
  pinMode(button_led, OUTPUT);
  
  // declare the button as input so we can read it's value
  pinMode(button, INPUT);

  // set the button LED to button_state which means off 
  digitalWrite(button_led, button_state);
  
 }


/*
* loop() - this function runs infinitely where we need to run the code constantly
*/
void loop()
{

  // read the button_state if return 1 = on or 0 = off
  button_state = digitalRead(button);

  // in case if the button pressed
  if (button_state == 1)
  {

    // turn the LED on 
    digitalWrite(button_led, HIGH);
  
  }
  // otherwise the LED shall be off
  else
  {
    digitalWrite(button_led, LOW);
  }

  // turn the blinking LED on 
  digitalWrite(blink_led, HIGH);
  
  // wait for 500 ms
  delay(500);
  
  // turn the blinking LED off
  digitalWrite(blink_led, LOW);
  
  // wait for 500 ms
  delay(500);
 
}
