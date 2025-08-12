// Tecsun  PL-880 Backlight controller
// Using ESP8266 microcontroller.
// Author: Miguel Perez
// Parts of the code taken from other sources and examples.


#include <Arduino.h>

// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>

// Tabla usada para correccion de color en los pixeles
// Credits go to its author(s)
const uint8_t PROGMEM gamma8[] = {
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
  2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
  5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
 10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
 25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
 37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
 51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
 69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
 90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };




// Which pin on the Arduino is connected to the NeoPixels?
// In the LOLIN32 mini pro pin D6
#define PIN        12

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1// Popular NeoPixel ring size
int MaximumBrightness = 255;
int currentBrightnessPercentage = 100;

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. 
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // initialize serial communication at 115200 bits per second:
  //Serial.begin(115200);
  strip.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  float intensity = MaximumBrightness * currentBrightnessPercentage / 100;
  strip.setBrightness(intensity);

  strip.show();  // Initialize all pixels to 'off'
}

void all_to_same_color(uint32_t color)
{
  // Now set every LED to that color
  for (int ledNumber=0; ledNumber<NUMPIXELS; ledNumber++) {
    strip.setPixelColor(ledNumber, color);
  }
  strip.show();

  delay(DELAYVAL); 
}

bool is_backlight_on()
{
    // read the input on analog pin 0:
    int sensorValue = analogRead(A0);

    //Serial.println(sensorValue);

    //PL880 Catode backlight LED (when plugged/connected to the board)
    //365 -> off
    //245 -> on
    return sensorValue < 300;
}

void loop()
{
  if( is_backlight_on() )
  {
    //Set solid red color
    all_to_same_color( strip.Color(  pgm_read_byte(&gamma8[255]), 
                              pgm_read_byte(&gamma8[0]),
                              pgm_read_byte(&gamma8[0])) );

    delay(DELAYVAL * 6);
  }
  else
  {
    strip.clear();
    strip.show();
    delay(DELAYVAL);
  }
}

