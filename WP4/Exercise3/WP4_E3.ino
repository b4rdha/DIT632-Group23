// (C) Bassam -> Group: 23 (2022)
// Work package 4 
// Exercise 3 "ADDRESSABLE LEDS"
// Submission code: Abc!7

/*------------------------------------------------------------
EXERCISE 3 ADDRESSABLE LEDS
A program to measure the temperature and and light up the Neopixels ring.

- The program measures the temperature periodically, these readings of the tempreature sensor get converted to temperature in C degrees.
- Depends on the converted temperature the Neopixel ring shall light up as many leds as it's correspondent to the temperature.
- Neopixel ring 24 LEDS is used and the tempreature is between 0 and 125. Example 25 degrees is correspondent to 5 LEDS to light up. 
- Temperature less than 0 means no LEDS to light up.   

--------------------------------------------------------------*/


// include libriaries

// Neopixel library 
#include <Adafruit_NeoPixel.h>
#include <math.h>

#define NEOPIXELS_PIN   3   // Neopixel ring is attached to pin 3
#define NUMPIXELS       24  // number of neopixels in strip
#define TEMP_PIN        A0  // temperature pin is attached to pin A0
#define RED_LED         4   // the red LED is attached to pin 4
#define SOUND_PIN       5   // Piezo is attached to pin 5


// setting up the Neopixel object giving it the number of pixels and the pin attched to it. 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIXELS_PIN, NEO_GRB + NEO_KHZ800);

// functions

//function to take a sensor reading and convert it to temperature in c degrees. 
float getTemp (int temp_reads);

// function to calculate how many leds will light up in the neopixels ring. the fuction is given the temperature.  
int get_num_leds_to_light(float temp);

// function takes a number of lEDs to light up in the neopixels. 
void light_up (int num);

// fucntion to indicate that we have reached the limit of the addressable leds. 
void warn_sound_light();



int wait =                    50; // timing delay in milliseconds
int temp_sensor_reading =     0;  // tempreature sensor readings 
float voltage;                    // the voltage converted from the reading will be stored here.
float temperature;                // the temperature value will be stored here.
int num_leds_to_light;            // to store the number of leds to light up in teh neopixels ring



/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup() {
  // start the serial monitor
  Serial.begin(9600);
  
  // Initialize the NeoPixel library.
  pixels.begin();

  // set up the pins for red LED and the sound pins to be output, tenperature pin to be input.
  pinMode(RED_LED, OUTPUT);
  pinMode(SOUND_PIN, OUTPUT);
  pinMode(TEMP_PIN, INPUT);
  
}


/*
* loop() - this function runs infinitely where we need to run the code constantly
*/
void loop() {

  // get the sensor reading and store it in temp_sensor_readig variable.
  temp_sensor_reading = analogRead(TEMP_PIN);

  // by getTemp function we calculae the temperature by passing it the sensor reading. 
  getTemp(temp_sensor_reading);

  // pritn out the temperature to the serial monitor. 
  Serial.print ("Temp is: ");
  Serial.println(temperature);


  // calculate how many leds to light up by get_num_leds_to_light function, passing it the temperature 
  // and store it in num_leds_to_light variable. 
  num_leds_to_light = get_num_leds_to_light(temperature); 
    
  // print out how many leds to light up
  Serial.print("Number to light: ");
  Serial.println(num_leds_to_light);

  // light_up function takes a number of how many leds to light up and execute the operation.
  light_up (num_leds_to_light);
    
}


/* Function that converts the readings from the sensor to temperature 
 *  The temp reading are passed as param and then converted to millivolts then to tenperature 
 *  @param int temp_reads -- voltage of temperature sensor reading 
 */
float getTemp (int temp_reads)
{
  voltage = (5./1023.) * temp_reads;      //calculate voltage on 10bits resolution. 
  voltage = voltage * 1000;               // convert the volatge to millivolts. 
  temperature = (voltage - 500) / 10;     // convet the millivolts to temperature -> each 10 millivolts = 1 C degree

  
  return temperature;                     // return the temperature 

}



/* Function that caluculates how many Addressable LEDs to light up in the neopixels ring 
 *  Linear regression is used here to find an equation to calculate how many LEDs to light up.
 * first -> get the slope m = y2-y1 / x2-x1
 * m = 24-0 / 125 - 0 = 24/125
 * m = 24/125 
 * and then the equation to calculate how many neopixels to turn on is -> 
 * y - y0 = m (x-x0) y0 and x0 are both equal to 0 so -> 
 * y = (24./125.) * x  ---- y is the neopixels to light up and
 * x is the temperature given
 * final formula to use -> Addressable leds to light = (24./125.) * temperature
 *  @param int temp -- the current temperature given. 
 */
int get_num_leds_to_light(float temp)
{
  // return a rounded number of the result of the used formula. (round() is a Math library fucntion)
  return round((24./125.) * temperature);
}



/* Function that takes as an input how many leds to light up and do the executes the light up operation. 
 *  It lights up the neopixels leds ascending in case of temperature increase 
 *  and decending in case of temperature decrease.
 *  @param int num -- number pixels to light up. 
 */
void light_up (int num)
{
  // loop over the neopixels leds (24). 
  for (int i = 0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255

    // as long as the number of pixels to light up is higher than i
    // we light up the led 
      if (i < num)
      {
        // put red color in this pixel at i 
        pixels.setPixelColor(i, pixels.Color(255, 0, 0));

      }
      // else we have light up all the leds required, then start to clean out
      // the leds that are not supposed to be on.  
      //start from 24th pixel and clear all pixels until we reach last led to be on. 
      else 
      {
          for (int j = NUMPIXELS; j >= num; j--)
          {
            // set the pixel RGB values to 0 at j
            pixels.setPixelColor(j, pixels.Color(0, 0, 0));
          }
      }

        // This sends the updated pixel color to the hardware.
        pixels.show();

       // check if the last pixel is on. if true -> this method will turn the red LED 
       // and the sound alarm.
        warn_sound_light();

      // delay for 50 milliseconds.
      delay(wait);
    }
}


/* Function that turn the red LED and the sound alarm on when the last pixel in the  
 *  ring is turned on. 
 */
void warn_sound_light()
{
  // if pixel number 23 (zero based indexing -> 24) is not off
  if (pixels.getPixelColor(23) != 0x000000)
  {     
    // turn the red LED on 
     digitalWrite(RED_LED, HIGH);

    // turn the red sound alarm on
     digitalWrite(SOUND_PIN, HIGH);
   }
   // otherwise turn them off. 
  else
   {
    // turn the red LED off
     digitalWrite(RED_LED, LOW);
    // turn the red sound alarm off
     digitalWrite(SOUND_PIN, LOW);
    }
}
