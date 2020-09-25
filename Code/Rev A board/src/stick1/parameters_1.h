#ifndef PARAMETERS_1_H
#define PARAMETERS_1_H

#ifdef BUILD_STICK_1




#include "parameters_common.h"


#define IMAGE1_WIDTH 17
#define IMAGE2_WIDTH 17


// filled with second color border
const uint8_t PROGMEM image1[][10] =
{
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,2,2,2,0,0},
	{0,0,0,0,2,1,1,1,2,0},
	{0,0,0,2,1,1,1,1,1,2},
	{0,0,2,1,1,1,1,1,1,2},
	{0,2,1,1,1,1,1,1,2,0},
	{2,1,1,1,1,1,1,2,0,0},
	{0,2,1,1,1,1,1,1,2,0},
	{0,0,2,1,1,1,1,1,1,2},
	{0,0,0,2,1,1,1,1,1,2},
	{0,0,0,0,2,1,1,1,2,0},
	{0,0,0,0,0,2,2,2,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
};


// X
const uint8_t PROGMEM image2[][10] =
{
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,3,3,0,0,0,0,0,0,0},
  {3,3,3,3,0,0,0,0,0,0},
  {3,3,3,3,0,0,0,3,3,0},
  {3,3,3,3,3,3,3,3,3,3},
  {0,3,3,3,3,3,3,3,3,3},
  {3,3,3,3,3,3,3,3,3,3},
  {3,3,3,3,0,0,0,3,3,0},
  {3,3,3,3,0,0,0,0,0,0},
  {0,3,3,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0},
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


#endif // #ifdef BUILD_STICK_1
#endif // #ifndef PARAMETERS_1_H
