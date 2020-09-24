// This is where we chose what version of the code gets compiled.
#define BUILD_STICK_1
//#define BUILD_STICK_2
//#define BUILD_STICK_3



/*
   ICSP header is, looking down on pins (not looking into female cable):

   1  MISO    2 VCC
   3 SCK      4 MOSI
   5 RST      6 GND

   ATTiny85:

   1 RST   5 VCC
   2 NC    6 SCK
   3 NC    7 MISO
   4 GND   8 MOSI

 */




#include <Arduino.h>
#include <FastLED.h>
#include <avr/power.h>
#include "stick1/parameters_1.h"
#include "stick2/parameters_2.h"
#include "parameters_common.h"

// STICK 2 PROGRAM: SLOW RAINBOW THEN HEARTS







//filled
const uint8_t PROGMEM image1[][10] =
{
  	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,0,0},
	{0,0,0,0,1,1,1,1,1,0},
	{0,0,0,1,1,1,1,1,1,1},
	{0,0,1,1,1,1,1,1,1,1},
	{0,1,1,1,1,1,1,1,1,0},
	{1,1,1,1,1,1,1,1,0,0},
	{0,1,1,1,1,1,1,1,1,0},
	{0,0,1,1,1,1,1,1,1,1},
	{0,0,0,1,1,1,1,1,1,1},
	{0,0,0,0,1,1,1,1,1,0},
	{0,0,0,0,0,1,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
  	{0,0,0,0,0,0,0,0,0,0}
};

// that's a penis.gif
/*const uint8_t PROGMEM image2[][10] =
   {
        {0,1,1,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,1,0},
        {1,0,0,0,0,1,0,0,1,0},
        {1,0,0,0,0,1,0,0,1,0},
        {1,0,0,0,1,0,0,0,1,0},
        {0,1,1,1,0,1,0,0,0,1},
        {1,0,0,0,0,1,0,0,0,1},
        {1,0,0,0,0,1,0,0,0,1},
        {1,0,0,0,0,1,0,0,0,1},
        {0,1,0,0,1,1,0,0,0,1},
        {0,0,1,1,0,1,0,0,0,1},
        {0,0,0,0,0,1,0,0,0,1},
        {0,0,0,0,0,1,0,0,0,1},
        {0,0,0,0,0,1,0,0,1,1},
        {0,0,0,0,0,1,1,1,0,1},
        {0,0,0,0,1,0,0,0,0,1},
        {0,0,0,0,1,0,0,0,0,1},
        {0,0,0,0,1,0,0,0,0,1},
        {0,0,0,0,1,1,1,0,0,1},
        {0,0,0,0,1,0,0,0,0,1},
        {0,0,0,0,1,0,0,0,1,0},
        {0,0,0,0,0,1,1,1,0,0}
   };*/


CRGB leds[NUMPIXELS];

// with BGR
// Red coef is green
// Green coef is blue
//therefore blue is red


uint32_t timeNow = 0;
uint32_t heartbeatOffInterval = 950;
uint32_t heartbeatOnInterval = 10;
uint32_t lastTimeHeartbeatOn = 0;
uint32_t lastTimeHeartbeatOff = 0;

uint32_t prog1_sweepInterval = 0;
uint32_t prog1_lastTimeSweep = 0;

uint32_t prog2_sweepInterval = 3;
uint32_t prog2_lastTimeSweep = 0;


uint8_t heartbeatLed = 0;
uint8_t buttonState = 0;


void setup()
{
	if(F_CPU == 16000000)
	{
		clock_prescale_set(clock_div_1);
	}

	pinMode(HEARTBEAT_LED, OUTPUT);
	pinMode(BUTTON1, INPUT);

	digitalWrite(HEARTBEAT_LED, HIGH);

	FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUMPIXELS)
	.setCorrection(CORRECTION);

	for(int i = 0; i < NUMPIXELS; i++)
	{
		leds[i] = CRGB(16, 0, 16);
	}
	FastLED.setBrightness(10);
	FastLED.show();

}


int8_t sweepIndex = 0;
int8_t sweepDir = 1;
uint8_t rainbowIncrement = 7;
uint8_t rainbowStart = 0;
uint8_t column_index = 0;
uint8_t row_index = 0;
void program_1(void)
{
	rainbowStart = rainbowStart -1;
	FastLED.setBrightness(180);
	fill_rainbow(leds, NUMPIXELS, rainbowStart, rainbowIncrement);
	for(int row_index = 0; row_index < 10; row_index++)
	{
		//image[column_index*IMAGE_WIDTH + row_index]; argument will go from 0 to (IMAGE_WIDTH*IMAGE_HEIGHT -1)
		// with row_index from 0 to (IMAGE_HEIGHT - 1);
		// column_index from 0 to (IMAGE_WIDTH - 1)
		uint8_t image_value = pgm_read_byte(&(image1[column_index][row_index]));
		if(image_value==0 )
		{
			leds[row_index] = CRGB(0, 0, 0);
		}
		//  else
		//  {
//      leds[row_index] = CRGB(32, 0, 32);
		//  }
	}
	column_index++;
	if(column_index == IMAGE1_WIDTH)
	{
		column_index = 0;;
	}
};


void program_2(void)
{
	FastLED.setBrightness(10);
	rainbowStart = rainbowStart - 1;
	fill_rainbow(leds, NUMPIXELS, rainbowStart, rainbowIncrement);
}

void loop()
{
	timeNow = millis();
	buttonState = digitalRead(BUTTON1);
	if(heartbeatLed == 1)
	{
		if(timeNow - lastTimeHeartbeatOn > heartbeatOnInterval)
		{
			lastTimeHeartbeatOff = timeNow;
			heartbeatLed = 0;
			digitalWrite(HEARTBEAT_LED, LOW);

		}
	}
	if(heartbeatLed == 0)
	{
		if(timeNow - lastTimeHeartbeatOff > heartbeatOffInterval)
		{
			lastTimeHeartbeatOn = timeNow;
			heartbeatLed = 1;
			digitalWrite(HEARTBEAT_LED, HIGH);
		}
	}



	if(!buttonState)
	{
		if(timeNow - prog1_lastTimeSweep > prog1_sweepInterval)
		{
			prog1_lastTimeSweep = timeNow;
			program_1();
			FastLED.show();
		}
	}
	else
	{
		if(timeNow - prog2_lastTimeSweep > prog2_sweepInterval)
		{
			prog2_lastTimeSweep = timeNow;
			program_2();
			FastLED.show();
		}
	}


}
