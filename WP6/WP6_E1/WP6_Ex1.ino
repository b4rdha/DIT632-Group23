// (C) Bassam -> Group: 23 (2022)
// Work package 6
// Exercise 1 DC motor controller
// Submission code: L3097

/*------------------------------------------------------------
EXERCISE 1 DC motor controller
A program to control a DC motor with encoder and H-bridge motor driver. We give the motor instruction to rotate to a desired degree
- The Motor has 3000 tics to complete one full circle. Which means that around each 8.3 tics we get 1 degree. 
so for example if we want the motor to go to 180 degrees "half of the circle" it means the motor needs to complete 1500 tics 
from it's initial position when we start the program. Every time we stop and rerun the program, the position where the motor
has is considered to be it's initial position.
--------------------------------------------------------------*/

// define the encoder and the motor driver input pins 
#define ENCA 2   // ecnoder A pin attched to pin 2
#define ENCB 3  // ecnoder B pin attched to pin 3
#define PWM1 5  // input 2 attched to pin 5
#define PWM2 6  // input 1 attched to pin 6


int pos = 0; // Position in ticks
int deg = 0; // Position in degrees

int degtarget = 0; // Target position in degrees

int speed = 0; // Desired motor speed

int kp = 5; // Proportional constant for controller (tuning parameter)
int u_out = 0; // output of controller

int e = 0; // error
int a = 0; // a-encoder signal
int b = 0; // b-encoder signal



/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup() {
 
  // start the serial
  Serial.begin(9600);
  
  // set the pins mode
  pinMode(ENCA,INPUT_PULLUP);
  pinMode(ENCB,INPUT_PULLUP);
  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);  
  
  // interrupt attched on encoder A when RIGING 
  attachInterrupt(digitalPinToInterrupt(ENCA), ISR_readEncoder, RISING );
  
  
  // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
  analogWrite(PWM2, 10); 
  delay(1000); // TinkerCad bug
  analogWrite(PWM1, 10);
}


/*
* loop() - this function runs infinitely where we need to run the code constantly
*/
void loop() {
  // Stop the motor, but not to zero because then TinkerCad dies....
  analogWrite(PWM1, 10);
  delay(1000); // TinkerCad...bug
  analogWrite(PWM2, 10);
  
  // Check if motor rotated all the way around, and reset counter
    if (pos > 2299){
      deg = deg - 359;
      pos = pos - 2299;
    }
    if (pos < 0){
      deg = 359 + deg;
      pos = 2299 + pos;
    }
  
  // Print current position
  Serial.print("The current position in degrees is: ");
  Serial.print(deg);
  Serial.print("\n");
   
  // Get input 
  degtarget = getInput();
  
  // Calculate initial error
  e = degtarget - deg;
    
  // Loop until error is zero
  while(e){
    
    // Map current position into degrees
    deg = map(pos,0,2299,0,359);
  
    // Calculate current error
    e = degtarget - deg;
    
    // Get necessary speed signal
    speed = getAction(e);
    
    // Send speed signal to motor
    // Rotating clockwise
    if(speed >= 0){
      if (speed < 100) // motor does not react with too low inputs
        speed = 100;
      analogWrite(PWM2, 0);
      analogWrite(PWM1, speed);
    }
  
    // Rotating counter-clockwise
    else{
      if (-speed < 100) // motor does not react with too low inputs
        speed = -100; 
      analogWrite(PWM1, 0);
      analogWrite(PWM2, -speed); 
    }
  }
}

/*
* getInput() - this function gets the user input for the desired degree.
*/
 
int getInput(){
  
  int ready = 0;
  char buf[3];
  int input = -1;
  
  Serial.print("Please enter the desired position: \n");
  
  while(!ready){
    ready = Serial.readBytes(buf,3);
    input = atoi(&buf[0]);
  }
 
  return input;
}  


/*
* getAction() - this function calculates the speed for the motor.
* @params int error- is the difference between the desired degree and the current degree
*/
int getAction(int error){
  // initialise u_out to zero
  u_out = 0;
  // calculate u_out giving the current error and multiply it by 5
  u_out = kp*error;
  
  if (u_out > 254){
    return 255;
  }
  else if (u_out < -254){
    return -255;
  }  
  else
     return u_out;
}


/*
* ISR_readEncoder() - this function when interrupt.
* the function gets the signals from the encoders and increment or decrement the position. 
* When a is triggered first that means that we rotating towards the right direction 
* otherwise we are rotating to the left direction. 
* note: position here is position in tics not degrees
*/
void ISR_readEncoder(){
  // read the encoder signals 
  a = digitalRead(ENCA);
  b = digitalRead(ENCB);
  
  // if we are rotating to the right
  if (a > b)
    // increment pos 
    pos++;
  else
    // decrement pos
    pos--;
}
