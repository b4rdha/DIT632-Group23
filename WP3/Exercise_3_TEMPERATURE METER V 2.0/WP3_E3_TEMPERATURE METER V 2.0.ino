// (C) Bassam -> Group: 23 (2022)
// Work package 3
// Exercise 3 TEMPERATURE METER V 2.0
// Submission code: AbC-12!

/*------------------------------------------------------------
EXERCISE 3 TEMPERATURE METER V 2.0
A program to measure the temperature by TMP36 sensor, The program recieves the voltage
from the sensor and convert it with 10 bits resolution to the corresponding temperature
using this formula -> Temperature (°C) = (VOUT – 500) / 10.
The results shall be printed to the serial every 500 ms. 
--------------------------------------------------------------*/

                 
//define the temp sensor TMP36 Pin
#define temp_sensor_pin A0  //the sensor is connected to A0



/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup()
{
  Serial.begin(9600);  //Start the serial connection with the computer
                       //to view the result open the serial monitor 
  pinMode(temp_sensor_pin, INPUT); // set the pin mode for the temp sensor to input
}


/*
 * loop() - this function runs infinitely where we need to run the code constantly
 */
void loop()              
{
 
 int temp_analog_reading = analogRead(temp_sensor_pin); //get the voltage reading from the temperature sensor
 
  
 float voltage = temp_analog_reading * 5.0; // converting the reading to voltage by multiplying it with 5 "which is the supply voltage given"

 
 voltage /= 1023.0;                     // divide the voltage on 1023 for 10 bits resolution

  
 float mVolt = voltage * 1000;          // to be able to use the give formula which uses the millivolt unit, we need to convert the voltage to millivolts.
 
 // print out the millivolts
 Serial.print("Millivoltage is: ");
 Serial.println(mVolt); 
 Serial.println("---------------------------");
  
  
 float temperature = (mVolt - 500)/10 ; // to convert the millivolts to c degrees we need to convert the millivolts to C degrees. 
                                        // The first 500 millivolts are left as an offset to calculate the negative degrees. So each 10 mv = 1 C degree
                                        // 500 + 10 =  1 C degree. 
                                        // 500 - 10 = -1 C degree. 
                                        // so 500 mv are subtracted from the millivolts and then divided by 10 to get how many C degrees.


// print out the temperature
 Serial.print("Temperature is: ");
 Serial.println(temperature);
 
 delay(500);                            //wait for 500 milliseconds
}
