#ifdef BUILD_STICK_2


#include "parameters_common.h"
#include "stick2/parameters_2.h"

// STICK 2 PROGRAM: SLOW RAINBOW THEN HEARTS

uint32_t prog1_sweepInterval = 0;
uint32_t prog1_lastTimeSweep = 0;

uint32_t prog2_sweepInterval = 3;
uint32_t prog2_lastTimeSweep = 0;

uint8_t buttonState = 0;

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

void loop_2(void)
{
    buttonState = digitalRead(BUTTON1);

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

#endif
