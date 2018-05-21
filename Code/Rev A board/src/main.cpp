#include <Arduino.h>

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
void setup() { pinMode(0, OUTPUT); }

void loop()
{
  digitalWrite(0, HIGH);
  delay(500);
  digitalWrite(0, LOW);
  delay(500);
  // put your main code here, to run repeatedly:
}
