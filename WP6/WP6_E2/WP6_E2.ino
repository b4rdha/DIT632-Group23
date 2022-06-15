
// File: WP6_E2.c

/*----------------------------------------------------------------------------

// (C) Ediz -> Group: 23 (2022)
// Work package 6 (Tinkercad)
// Exercise 2 (optional)
// Submission code: L3097

-------------------------------------------------------------------------------

The program is an ultrasonic parking assistance system by illuminates the (4) 
different colored LEDs and produce danger/warning sounds through a piezo speaker 
according to the distance measurement received from the ultrasonic sensor.

When a truck/vehicle is parked backwords, the driver can comprehend the danger 
level by observing the LEDs and listening to the sound from the speaker. The closer 
a vehicle gets to the obstacle by reversing, the more LEDs illuminate and 
the intensity of sound rises to indicate the collision level. 

References
 - Arduino documentation

-------------------------------------------------------------------------------*/

// Global variables for pins used.
const int green = 5; 				      // Variable decleration for green LED on pin 5.
const int yellow = 4; 				    // Variable decleration for yellow LED on pin 4.
const int orange = 3;   			    // Variable decleration for orange LED on pin 3.
const int red = 2;   				      // Variable decleration for red LED on pin 2.
const int buzzer = 9;				      // Variable decleration for buzzer(piezo speaker) on pin 9.
const int ultraSonicSensor = 7;		// Variable decleration for ultrasonic sensor on pin 7.

// Global variables for danger zones in miliseconds.
const int dangerZoneGreen = 800;	// Variable decleration for green danger zone LED in miliseconds.
const int dangerZoneYellow = 600;	// Variable decleration for yellow danger zone LED in miliseconds.
const int dangerZoneOrange = 400;	// Variable decleration for orange danger zone LED in miliseconds.
const int dangerZoneRed_1 = 300;	// Variable decleration for red danger zone_1 LED in miliseconds.
const int dangerZoneRed_2 = 100;	// Variable decleration for red danger zone_2 LED in miliseconds.

float cm = 0;	// Variable for ultrasonic sensor distance.

// Setup section for the program
void setup()
{
  
  // LED pins for sending the signals out
  pinMode(green, OUTPUT); 		// led #5
  pinMode(yellow, OUTPUT); 		// led #4
  pinMode(orange, OUTPUT); 		// led #3
  pinMode(red, OUTPUT); 		  // led #2
  
  // Buzzer pin for sending the signals out
  pinMode(buzzer, OUTPUT);		// buzzer #9
  
  // To exchange messages with the Serial Monitor at a data rate of 9600 bits per second (960 characters per second)
  Serial.begin(9600);
}

// Looping the functions until termination.
void loop(){

  // Function call for measuring the ping time.
  measurePing();

  /* Function call to illuminate the leds & produce sounds through Piezo speaker 
  to indicate the collision level. */
  distanceToObstacle();

}

// Function for measuring the ping time
void measurePing(){

  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  
  Serial.print(cm); 		    // Printing the cm measurement to the serial monitor
  Serial.println(" cm"); 	  // Printing the measurement unit extention to the serial monitor.
  
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
    
  // Ultrasonice sensor pin for sending the signals out
  pinMode(triggerPin, OUTPUT);  	// Clear the trigger
  
  // Sets the trigger pin to OFF state for 2 microseconds
  digitalWrite(triggerPin, LOW);	// Ultrasonice sensor OFF
  delayMicroseconds(2);				    // Wait for 2 microseconds
  
  // Sets the trigger pin to ON state for 10 microseconds
  digitalWrite(triggerPin, HIGH);	// Ultrasonice sensor ON
  delayMicroseconds(10);			    // Wait for 10 microseconds
  digitalWrite(triggerPin, LOW);	// Ultrasonice sensor OFF
  
  // Sets the pin to input to listen if some echo returns
  pinMode(echoPin, INPUT);
  
  // Reads the echo pin, and returns the sound wave travel time in microseconds.
  return pulseIn(echoPin, HIGH);
}

/* Function to illuminate the leds & produce sounds through Piezo speaker according 
the distance measured by ultra sonic sensor. */
void distanceToObstacle(){
  
  /* Conditions to illuminate the leds & produce sounds through Piezo speaker.
  When the reverse distance less than 200cm to obstacle, illuminate & darken following leds
  and produce danger zone sound to indicate the collision level. */
  if(cm > 150 && cm < 200){
    
    digitalWrite(green,HIGH); 	// illuminate the green(#5) led
    digitalWrite(yellow,LOW); 	// darken the yellow(#4) led
    digitalWrite(orange,LOW);	  // darken the orange(#3) led
    digitalWrite(red,LOW);    	// darken the red(#2) led

    // Speaker tone function call with specified pin, Hz and sound time.
    piezoSpeakerTone();

    // Wait for 800 millisecond(s)
    delay(dangerZoneGreen);

  /* When the reverse distance between 100cm and 150cm to obstacle, illuminate & darken following leds
  and produce danger zone sound to indicate the collision level. */
  }else if(cm > 100 && cm <= 150){
    
    digitalWrite(green,HIGH);	  // illuminate the green(#5) led
    digitalWrite(yellow,HIGH);	// illuminate the yellow(#4) led
    digitalWrite(orange,LOW); 	// darken the orange(#3) led
    digitalWrite(red,LOW);	  	// darken the red(#2) led

    // Speaker tone function call with specified pin, Hz and sound time.
    piezoSpeakerTone();

    // Wait for 600 millisecond(s)
    delay(dangerZoneYellow);

  /* When the reverse distance between 3cm and 100cm to obstacle, illuminate & darken following leds
  and produce danger zone sound to indicate the collision level. */
  }else if(cm > 30 && cm <= 100){
    
    digitalWrite(green,HIGH);	  // illuminate the green(#5) led
    digitalWrite(yellow,HIGH);	// illuminate the yellow(#4) led
    digitalWrite(orange,HIGH);	// illuminate the orange(#5) led
    digitalWrite(red,LOW);		  // darken the red(#2) led

    // Speaker tone function call with specified pin, Hz and sound time.
    piezoSpeakerTone();

    // Wait for 400 millisecond(s)
    delay(dangerZoneOrange);

  /* When the reverse distance between 25cm and 30cm to obstacle, illuminate following leds
  and produce danger zone sound to indicate the collision level. */
  }else if(cm > 25 && cm <= 30){
    
    digitalWrite(green,HIGH);	  // illuminate the green(#5) led
    digitalWrite(yellow,HIGH);	// illuminate the yellow(#4) led
    digitalWrite(orange,HIGH);	// illuminate the orange(#3) led
    digitalWrite(red,HIGH);		  // illuminate the red(#2) led

    // Speaker tone function call with specified pin, Hz and sound time.
    piezoSpeakerTone();

    // Wait for 300 millisecond(s)
    delay(dangerZoneRed_1);

  /* When the reverse distance less then 25cm to obstacle, blink following leds 
  and produce danger zone sound to indicate the collision level. */
  }else if(cm > 0 && cm <= 25){

    // Function call to blink all LEDs
    blink();

    // Speaker tone function call with specified pin, Hz and sound time.
    piezoSpeakerTone();

    // Wait for 100 millisecond(s)
   	delay(dangerZoneRed_2);
    
  /* When the reverse distance more then 200cm to obstacle, turn off the following leds 
  and do not produce danger zone sound to indicate the collision level. */
  }else{

    // Function call to turn off the LEDs and the piezo speaker.
    led_SpeakerOff();
  }
}

// Function to turn off the LEDs and the piezo speaker
void led_SpeakerOff(){
  
	  digitalWrite(green,LOW);  // darken the green(#5) led
    digitalWrite(yellow,LOW);	// darken the yellow(#4) led
    digitalWrite(orange,LOW);	// darken the orange(#3) led
    digitalWrite(red,LOW);		// darken the red(#2) led
  
    // do not produce tone
  	noTone(9);
}

// Function to blink all LEDs
void blink()
{
    digitalWrite(green,HIGH);	  // illuminate the green(#5) led
    digitalWrite(yellow,HIGH);	// illuminate the yellow(#4) led
 	  digitalWrite(orange,HIGH);	// illuminate the orange(#3) led
    digitalWrite(red,HIGH);		  // illuminate the red(#2) led
    
  	// Wait for 100 millisecond(s)
  	delay(100);
  
    digitalWrite(green,LOW);	// darken the green(#5) led
    digitalWrite(yellow,LOW);	// darken the yellow(#4) led
 	  digitalWrite(orange,LOW);	// darken the orange(#5) led
    digitalWrite(red,LOW);		// darken the red(#5) led
}

// Speaker tone function with specified pin, Hz and sound time.
void piezoSpeakerTone(){
  
  	// play a note on pin 9 with 392 Hz for 40 ms.
	tone(9, 392, 200);
}
