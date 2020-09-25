#ifndef PARAMETERS_COMMON_H
#define PARAMETERS_COMMON_H




#define NUMPIXELS 10     // Number of LEDs in strig
#define CLOCK_PIN 2     // "Pin 2" in Arduino is chip pin #7
#define DATA_PIN 0      // "Pin 0" in Arduino is chip pin #5
#define COLOR_ORDER RBG // my strip is BGR
#define CORRECTION TypicalLEDStrip
#define BUTTON1 4
#define HEARTBEAT_LED 3

#define HEARTBEAT_OFF_INTERVAL 950;
#define HEARTBEAT_ON_INTERVAL 10;


void loop_2(void);
void loop_3(void);


#endif