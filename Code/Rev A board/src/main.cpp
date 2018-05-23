#include <Arduino.h>
#include <FastLED.h>
#include <avr/power.h>



#define NUMPIXELS 10     // Number of LEDs in strig
#define CLOCK_PIN 2     // "Pin 2" in Arduino is chip pin #7
#define DATA_PIN 0      // "Pin 0" in Arduino is chip pin #5
#define COLOR_ORDER RBG // my strip is BGR
#define CORRECTION TypicalLEDStrip
#define BUTTON1 4
#define HEARTBEAT_LED 3


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
	FastLED.show();

}

uint32_t timeNow = 0;
uint32_t heartbeatInterval = 500;
uint32_t lastTimeHeartbeat = 0;

uint32_t sweepInterval = 0;
uint32_t lastTimeSweep = 0;
int8_t sweepIndex = 0;
int8_t sweepDir = 1;



uint8_t heartbeatLed = 0;

uint8_t buttonState = 0;

void loop()
{
	timeNow = millis();
	buttonState = digitalRead(BUTTON1);

	if(timeNow - lastTimeHeartbeat > heartbeatInterval)
	{
		lastTimeHeartbeat = timeNow;
		if(heartbeatLed == 0)
		{
			heartbeatLed = 1;
			digitalWrite(HEARTBEAT_LED, LOW);
		}
		else
		{
			heartbeatLed = 0;
			digitalWrite(HEARTBEAT_LED, HIGH);
		}
	}



	if(timeNow - lastTimeSweep > sweepInterval)
	{
		lastTimeSweep = timeNow;
		sweepIndex = sweepIndex + sweepDir;
		if(sweepIndex < 0)
		{
			sweepIndex = 1;
			sweepDir = 1;
		}
		if(sweepIndex >= NUMPIXELS)
		{
			sweepIndex = NUMPIXELS - 1;
			sweepDir = -1;
		}
		for(int i = 0; i < NUMPIXELS; i++)
		{
			if(i == sweepIndex)
			{
				if(buttonState == 0)
				{
					leds[i] = CRGB(16, 0, 16);
				}
				else
				{
					leds[i] = CRGB(0, 16, 0);
				}
			}
			else
			{
				leds[i] = CRGB(0, 0, 0);
			}

		}
		FastLED.show();
	}



	// put your main code here, to run repeatedly:
}
