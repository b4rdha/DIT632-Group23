// (C) Bassam -> Group: 23 (2022)
// Work package 3
// Exercise 1 blinking LED and LED with button
// Submission code: AbC-12!

/*------------------------------------------------------------
EXERCISE 3 blinking LED and LED with button
A program to light an LED when pressing a button and the other LED shall be blinking every one second 

- This program  the button shall be cutting the current
by recieving the power supply from one terminal and the other terminal shall be connected to the LED Anode.
So that if the button is pressed the current is flowing otherwise the current is broken.

- This program could be implemented in another way so that the button give the arduino-board it's input 
(pressed or not which means 1 or 0) so the LED shall react on the state of the button. The button and the LED
are not connected directly but connected to the board. 

- This other version is also attached with the zip
--------------------------------------------------------------*/


//define blinking LED pin and the button pin LED
#define blink_led 13      // blink LED is connected to pin 13  
#define button_led 12     // button LED is connected to pin 12


/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
  
void setup ()
{

  // declare that both LEDs are outputs
  pinMode(blink_led, OUTPUT);
  pinMode(button_led, OUTPUT);
  
  // set the button LED to button_state which means off 
  digitalWrite(button_led, HIGH);
  
 }


/*
* loop() - this function runs infinitely where we need to run the code constantly
*/
void loop()
{

  // turn the blinking LED on 
  digitalWrite(blink_led, HIGH);
  
  // wait for a second
  delay(1000);
  
  // turn the blinking LED off
  digitalWrite(blink_led, LOW);
  
  // wait for a second
  delay(1000);
 
}
