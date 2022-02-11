
// (C) Bardha -> Group: 23 (2022)
// Work package 3
// Exercise 2
// Submission code: AbC-12!

/*------------------------------------------------------------
References:
    - C programming (course literature), Class exercises
--------------------------------------------------------------*/

/*------------------------------------------------------------
EXERCISE 3
The system measures temperature and light and indicates with LEDs
the range in three different tiers: 
Normal range - green, when the light and temperature match the 
normal dependencies. 
Below range- yellow, when the temperature is below the normal
dependencise. 
Above range - red, when the temperature is above the normal 
dependencies. 
--------------------------------------------------------------*/
// Pin Variables
//sensors
int TEMP_PIN = 0; 
int LIGHT_PIN = 1;
//Led variables
int R_LED = 9; 
int Y_LED = 11; 
int G_LED = 13; 

void setup()
{
  Serial.begin(9600);  
  //define mode for circuit pins
  pinMode(R_LED, OUTPUT); 
  pinMode(Y_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);
  pinMode(LIGHT_PIN, INPUT);
   
}
 
void loop()                     // run over and over again
{
 //getting the voltage reading from the temperature sensor
 int tempReading = analogRead(TEMP_PIN); 
 //getting the light reading from the light sensor
 int lightReading = analogRead(LIGHT_PIN);

 //map the readings from the light sensor in percentage ratings  
 int lightRate = map(lightReading, 6, 679, 0, 100); 
  

 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = tempReading * 5.0195;
 voltage /= 1024.0; 
 
 // print out the voltage
 Serial.print(voltage); Serial.println(" volts");
 
 // now print out the temperature
 float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
 Serial.print(temperatureC); Serial.println(" degrees C");
 
 Serial.print(lightRate);
  
 // act on the temperature and light value 
 //check for light rate first
  if (lightRate==0) //For light range under 0%, check the temperature 
  {
    if (temperatureC < -12) //if temperature below 12
    {
      lights(LOW, LOW, HIGH); //indicate normal dependency
    }
    else
    {
      lights(HIGH, LOW, LOW); //indicate red-temperature above
    }
  }
  else if (lightRate >= 1 && lightRate <= 20) //for light rate 1-20%
  {
    if (temperatureC >= -12 && temperatureC <=0) //check if temperature within normal dependency
    {
      lights(LOW, LOW, HIGH); // indicate green
    }
    else if(temperatureC < -12) //if temperature below range
    {
      lights(LOW, HIGH, LOW); //indicate below dependency
    }
    else
    {
      lights(HIGH, LOW, LOW); // indicate above dependency- red
    }
  }
  else if (lightRate >= 21 && lightRate <= 60) //for light rate 21-60
  {
    if (temperatureC >= 0 && temperatureC <= 20) //check if temp is in range
    {
      lights(LOW, LOW, HIGH); //indicate green if in range
    }
    else if (temperatureC <0) //when temperature is below zero
    {
      lights(LOW, HIGH, LOW); //indicate blue, under normal dependency
    }
    else
    {
      lights(HIGH, LOW, LOW); //otherwise indicate above normal dependency-red
    }
  }
  else
  {
    if(temperatureC > 21) //check if temperature above 21
    {
      lights(LOW, LOW, HIGH); //when yes, indicate normal dependency
    }
    else 
    {
      lights(LOW, HIGH, LOW); //otherwise indicate below normal dependency- yellow
    }
 }
    

 delay(1000);      //waiting a second
}

void lights(int R, int Y, int G) //function to switch leds on and off, used for optimization
{
   digitalWrite(R_LED, R);
   digitalWrite(Y_LED, Y);
   digitalWrite(G_LED, G);
}