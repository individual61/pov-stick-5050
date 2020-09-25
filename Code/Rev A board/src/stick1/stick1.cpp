#ifdef BUILD_STICK_1

#include "parameters_common.h"
#include "stick1/parameters_1.h"


// failed penis, constant flashing 




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

CRGB leds[NUMPIXELS];

// with BGR
// Red coef is green
// Green coef is blue
//therefore blue is red


uint32_t timeNow = 0;


uint32_t prog1_sweepInterval = 0;
uint32_t prog1_lastTimeSweep = 0;

uint32_t prog2_sweepInterval = 3;
uint32_t prog2_lastTimeSweep = 0;







uint8_t buttonPrevState = 0;
uint8_t buttonState = 0;
uint32_t timeNowbutton = 0;
uint32_t lastTimePressedButton = 0;
uint8_t displayAlternateImage = 0;
void checkButton(void)
{
	bool buttonState = digitalRead(BUTTON1);
	if (buttonState == 0) // pressed
	{
		timeNowbutton = millis();
		if (timeNowbutton - lastTimePressedButton > DEBOUNCEDELAY)
		{
			displayAlternateImage = 1;
			lastTimePressedButton = timeNowbutton;
		}
	}
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
		uint8_t image_value = 0;
		if(displayAlternateImage == 0)
		{
      	FastLED.setBrightness(120);
			image_value = pgm_read_byte(&(image1[column_index][row_index]));
		}
		else
		{
      	FastLED.setBrightness(180);
			image_value = pgm_read_byte(&(image2[column_index][row_index]));
		}
		if(image_value==0 )
		{
			leds[row_index] = CRGB(0, 0, 0);
		}
	/*	if(image_value==2 )
		{
			leds[row_index] = CRGB(60, 60,60);
		}
		if(image_value==1 )
		{
			leds[row_index] = CRGB(130, 0, 130);
		}*/
  if(image_value==3 )
    {
      leds[row_index] = CRGB(255, 255,255);
    }

	}
	column_index++;
	// image done
	if(column_index == IMAGE1_WIDTH)
	{
    if(displayAlternateImage == 1)
    {
      displayAlternateImage = 0;
    }
		column_index = 0;;
	}
};



void loop_1()
{
	timeNow = millis();
	checkButton();
	
	if(timeNow - prog1_lastTimeSweep > prog1_sweepInterval)
	{
		prog1_lastTimeSweep = timeNow;
		program_1();
		FastLED.show();
	}
}




#endif