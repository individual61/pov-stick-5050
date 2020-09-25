// This is where we chose what version of the code gets compiled.
#define BUILD_STICK_1
// #define BUILD_STICK_2
//#define BUILD_STICK_3

//  ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ 
//                                                                                                                 
//
//
//      ██████   ██████  ██    ██     ███████ ████████ ██  ██████ ██   ██     ███████  ██████  ███████  ██████ 
//      ██   ██ ██    ██ ██    ██     ██         ██    ██ ██      ██  ██      ██      ██  ████ ██      ██  ████ 
//      ██████  ██    ██ ██    ██     ███████    ██    ██ ██      █████       ███████ ██ ██ ██ ███████ ██ ██ ██ 
//      ██      ██    ██  ██  ██           ██    ██    ██ ██      ██  ██           ██ ████  ██      ██ ████  ██ 
//      ██       ██████    ████       ███████    ██    ██  ██████ ██   ██     ███████  ██████  ███████  ██████  
//                                                                                                             
//
//
//  ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ 

/* 
Description:	POV Stick 5050: A persistence of vision stick with an AtTiny85, 10 APA102C RGB LEDs, one button, and a surprise.

Author: 		Paul Blackburn, @individual61 on GitHub

License: 		CC BY 4.0 (Attribution)

Github: 		https://github.com/individual61/pov-stick-5050

Excuses: 		Everything is in one file because I could not resolve a linker issue, 
         		most likely due to Arduino/PlatformIO particularities. 
		 		I'd rather not spend more time on it.


 Misc: 			Typeface for visual blocks is ANSI Regular
 				http://patorjk.com/software/taag/#p=display&h=0&c=c%2B%2B&f=ANSI%20Regular&t=...................%0A%20%20%20%20%20%20%201%0A...................


Hardware:		The GitHub repo has KiCAD board files and a mostly-correct BOM. Three were made in 2018 using OSHPark boards.
				Assembled by hand and reflowed with a hacked $30 Target reflow skillet (see my reflow-skillet repo).
				Programmed using an Adafruit USBTinyISP. 

   				ICSP header is, looking down on pins/pads on board (not looking into female cable):

  				 1 MISO    2 VCC
  				 3 SCK      4 MOSI
  				 5 RST      6 GND

  				 ATTiny85:

  				 1 RST   5 VCC
  				 2 NC    6 SCK
  				 3 NC    7 MISO
  				 4 GND   8 MOSI


 */

//  ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ 

#include <Arduino.h>
#include <FastLED.h>
#include <avr/power.h>
#include <parameters.h>

uint32_t timeNow = 0;

uint32_t heartbeatOffInterval = HEARTBEAT_OFF_INTERVAL;
uint32_t heartbeatOnInterval = HEARTBEAT_ON_INTERVAL;

uint32_t lastTimeHeartbeatOn = 0;
uint32_t lastTimeHeartbeatOff = 0;

uint8_t heartbeatLed = 0;

CRGB leds[NUMPIXELS];
// with BGR
// Red coef is green
// Green coef is blue
// therefore blue is red

//  ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██
//                                                           
//
//
//                               ██ 
//                              ███ 
//                               ██ 
//                               ██ 
//                               ██ 
//                                  
//
//
//  ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██
//                                                           
//                   failed penis, constant flashing
//
#ifdef BUILD_STICK_1

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

int8_t sweepDir = 1;
uint8_t rainbowIncrement = 7;
uint8_t rainbowStart = 0;
uint8_t column_index = 0;
uint8_t row_index = 0;
void program_1(void)
{
	// note that the rainbow advances on every sweep, not on every individual image, and even if we are in image2
	rainbowStart = rainbowStart - 1;

	fill_rainbow(leds, NUMPIXELS, rainbowStart, rainbowIncrement);
	for (int row_index = 0; row_index < NUMPIXELS; row_index++)
	{
		//image[column_index*IMAGE_WIDTH + row_index]; argument will go from 0 to (IMAGE_WIDTH*IMAGE_HEIGHT -1)
		// with row_index from 0 to (IMAGE_HEIGHT - 1);
		// column_index from 0 to (IMAGE_WIDTH - 1)

		uint8_t image_value = 0;
		// Image 1
		if (displayAlternateImage == 0)
		{
			FastLED.setBrightness(120);
			image_value = pgm_read_byte(&(image1[column_index][row_index]));
		}

		// Image 2
		if (displayAlternateImage == 1)
		{
			FastLED.setBrightness(180);
			image_value = pgm_read_byte(&(image2[column_index][row_index]));
		}
		if (image_value == 0)
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
		if (image_value == 3)
		{
			leds[row_index] = CRGB(255, 255, 255);
		}
	}
	column_index++;
	// image done

	// If we are displaying image 2 and are at the end, turn off displayAlternateImage.
	// This should be the only place where this is changed back to 0 (image 1).
	// checkButton() is the only place where it can be set to 1 (image 2).
	if (displayAlternateImage == 1)
	{
		if (column_index == IMAGE2_WIDTH)
		{
			displayAlternateImage = 0;
			column_index = 0;
		}
	}
	if (displayAlternateImage == 0)
	{
		if (column_index == IMAGE1_WIDTH)
		{
			column_index = 0;
		}
	}
};

void setup_1(void)
{
	FastLED.setBrightness(180);
}

void loop_1()
{
	timeNow = millis();
	checkButton();

	// Update lights only if we have waited longer than prog1_sweepInterval
	if (timeNow - prog1_lastTimeSweep > prog1_sweepInterval)
	{
		prog1_lastTimeSweep = timeNow;
		program_1();
		FastLED.show();
	}
}

#endif // #ifdef BUILD_STICK_1
//  ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██
//                                                           
//
//
//                              ██████ 
//                                   ██ 
//                               █████  
//                              ██     
//                              ███████ 
//                                      
//
//
//  ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██
//                                                           
//                      SLOW RAINBOW THEN HEARTS
#ifdef BUILD_STICK_2

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
	rainbowStart = rainbowStart - 1;
	FastLED.setBrightness(180);
	fill_rainbow(leds, NUMPIXELS, rainbowStart, rainbowIncrement);
	for (int row_index = 0; row_index < 10; row_index++)
	{
		// image[column_index*IMAGE_WIDTH + row_index]; 
		// argument will go from 0 to (IMAGE_WIDTH*IMAGE_HEIGHT -1)
		// with row_index from 0 to (IMAGE_HEIGHT - 1);
		// column_index from 0 to (IMAGE_WIDTH - 1)
		uint8_t image_value = pgm_read_byte(&(image1[column_index][row_index]));
		if (image_value == 0)
		{
			leds[row_index] = CRGB(0, 0, 0);
		}
		//  else
		//  {
		//      leds[row_index] = CRGB(32, 0, 32);
		//  }
	}
	column_index++;
	if (column_index == IMAGE1_WIDTH)
	{
		column_index = 0;
		;
	}
};

void program_2(void)
{
	FastLED.setBrightness(10);
	rainbowStart = rainbowStart - 1;
	fill_rainbow(leds, NUMPIXELS, rainbowStart, rainbowIncrement);
}

void setup_2(void)
{
}

void loop_2(void)
{
	buttonState = digitalRead(BUTTON1);

	if (!buttonState)
	{
		if (timeNow - prog1_lastTimeSweep > prog1_sweepInterval)
		{
			prog1_lastTimeSweep = timeNow;
			program_1();
			FastLED.show();
		}
	}
	else
	{
		if (timeNow - prog2_lastTimeSweep > prog2_sweepInterval)
		{
			prog2_lastTimeSweep = timeNow;
			program_2();
			FastLED.show();
		}
	}
}

//
#endif // #ifdef BUILD_STICK_2 
//  ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██
//                                                           
//
//
//                              ██████ 
//                                   ██ 
//                               █████  
//                                   ██ 
//                              ██████  
//                                     
//
//
//  ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██
#ifdef BUILD_STICK_3                                                      

void setup_3(void)
{
}

void loop_3(void)
{
}

#endif // #ifdef BUILD_STICK_3
//  ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██
//                                                           
//
//
//              ███    ███  █████  ██ ███    ██ 
//              ████  ████ ██   ██ ██ ████   ██ 
//              ██ ████ ██ ███████ ██ ██ ██  ██ 
//              ██  ██  ██ ██   ██ ██ ██  ██ ██ 
//              ██      ██ ██   ██ ██ ██   ████ 
//                                              
//
//
//  ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██
//                                                           
//

void setup()
{
	if (F_CPU == 16000000)
	{
		clock_prescale_set(clock_div_1);
	}

	pinMode(HEARTBEAT_LED, OUTPUT);
	pinMode(BUTTON1, INPUT);

	digitalWrite(HEARTBEAT_LED, HIGH);

	FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUMPIXELS)
		.setCorrection(CORRECTION);

	for (int i = 0; i < NUMPIXELS; i++)
	{
		leds[i] = CRGB(16, 0, 16);
	}
	FastLED.setBrightness(10);
	FastLED.show();

// After the common setup has been run, run stick-specific setup.
#ifdef BUILD_STICK_1
	setup_1();
#endif

#ifdef BUILD_STICK_2
	setup_2();
#endif

#ifdef BUILD_STICK_3
	setup_3();
#endif
}

void loop()
{
	timeNow = millis();

	// Beat heartbeat LED
	if (heartbeatLed == 1)
	{
		if (timeNow - lastTimeHeartbeatOn > heartbeatOnInterval)
		{
			lastTimeHeartbeatOff = timeNow;
			heartbeatLed = 0;
			digitalWrite(HEARTBEAT_LED, LOW);
		}
	}
	if (heartbeatLed == 0)
	{
		if (timeNow - lastTimeHeartbeatOff > heartbeatOffInterval)
		{
			lastTimeHeartbeatOn = timeNow;
			heartbeatLed = 1;
			digitalWrite(HEARTBEAT_LED, HIGH);
		}
	}

// After common loop instructions, run stick-specific loop.
#ifdef BUILD_STICK_1
	loop_1();
#endif

#ifdef BUILD_STICK_2
	loop_2();
#endif

#ifdef BUILD_STICK_3
	loop_3();
#endif
}
