// images.h
// contains image buffers for simple space invaders
// Jonathan Valvano, March 5, 2018
// Capture image dimensions from BMP files

#ifndef __images_h
#define __images_h
#include <stdint.h>


// *************************** Images ***************************
// enemy ship that starts at the top of the screen (arms/mouth closed)
// width=16 x height=10
#define black   0x0000
#define ST7735_BLUE    0xF800
#define ST7735_RED     0x001F
#define ST7735_GREEN   0x07E0
#define cyan   0xFFE0
#define ST7735_MAGENTA 0xF81F
#define orange    0x03FF
#define blue 0xF800
#define gray 0xC618
#define dgray 0x4208
#define brown 0x02FF
#define yellow 0x07FF
#define white   0x0

const uint16_t naruto[] = { //16 wide, 18 tall
	black, black, black, black, black, black, black, black, black, black, black, black, black, black, black, black,
	black, black, white, white, white, black, white, white, white, black, white, white, white, white, black, black, //16th row
  black, black, white, white, white, orange, white, white, white, orange, white, white, white, white, black, black, //15th row
	black, black, white, white, brown, orange, orange, orange, orange, orange, brown, white, white, white, black, black, //14th row
	black, black, white, white, black, black, black, black, black, black, black, white, white, white, black, black, //13th row
	black, black, white, white, black, orange, orange, black, orange, orange, black, white, white, white, black, black, //12th row
	black, black, white, white, white, black, black, black, black, black, white, white, white, white, black, black, //11th row
	black, black, white, white, brown, brown, brown, brown, brown, brown, brown, white, dgray, white, black, black, // 10th row
	black, black, white, yellow, brown, brown, brown, brown, brown, brown, brown, yellow, gray, dgray, black, black, //9th row
	black, black, white, brown, brown, blue, brown, brown, brown, blue, brown, brown, dgray, white, black, black, //8th row
	black, black, white, yellow, brown, blue, brown, brown, brown, blue, brown, yellow, white, white, black, black, // 7th row
	black, black, white, dgray, brown, brown, brown, brown, brown, brown, brown, dgray, white, white, black, black, //6th row
	black, black, white, yellow, dgray, dgray, gray, gray, gray, yellow, dgray, yellow, white, white, black, black, //5th row
  black, black, white, yellow, yellow, yellow, yellow, yellow, yellow, yellow, yellow, yellow, white, white, black, black, //4th row
  black, black, yellow, yellow, yellow, yellow, yellow, yellow, yellow, yellow, yellow, yellow, yellow, white, black, black, // 3rd row
	black, black, white, white, white, yellow, yellow, white, yellow, yellow, white, white, white, white, black, black, // 2nd row
	black, black, white, white, white, white, white, white, white, white, white, white, white, white, black, black, //1st row
	black, black, black, black, black, black, black, black, black, black, black, black, black, black, black, black
};

const unsigned short SmallEnemy10pointA[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
//18x8 (wxh)
const unsigned short ns[] = {
 0xE7FF, 0x0000, 0xBF7F, 0xA71F, 0x8E9F, 0x6D9D, 0x4C9C, 0x54DF, 0x337D, 0x231D, 0x22FD, 0x2B5C, 0x3BFE, 0x653F, 0x4439, 0x8E7F,
 0x9EDF, 0xB75F, 0xF7FF, 0xDFDF, 0xC79F, 0xAF3F, 0x9EDF, 0x865F, 0x75FF, 0x6D7F, 0x443D, 0x2B7B, 0x339C, 0x33BB, 0x54DE, 0x6D9F,
 0x863F, 0x8E9F, 0xA6FF, 0xBF7F, 0xF7FF, 0x0000, 0xCFBF, 0xAF3F, 0xAF3F, 0x969F, 0x8E5F, 0x7E1F, 0x653E, 0x2B98, 0x3C3A, 0x33F9,
 0x7DFF, 0x7E3F, 0x96BF, 0x9EFF, 0xAF3F, 0xBF7F, 0xFFFF, 0xF7FF, 0xD7DF, 0xCFBF, 0xBF7F, 0x9EFF, 0x9EDF, 0x969F, 0x7E1F, 0x4C99,
 0x4CBA, 0x54FB, 0x969F, 0x96BF, 0xA6FF, 0xAF3F, 0xBF7F, 0xCFBF, 0x0000, 0xF7FF, 0xEFFF, 0xD7DF, 0xC79F, 0xB75F, 0xAF3F, 0x9EDF,
 0xA71F, 0x5D19, 0x5CF8, 0x75DC, 0xA71F, 0xA71F, 0xB75F, 0xBF7F, 0xD7DF, 0xE7DF, 0x0000, 0xFFFF, 0xF7FF, 0xE7FF, 0xD7DF, 0xC79F,
 0xBF7F, 0xB75F, 0xB77F, 0x8E3B, 0x64F6, 0xAF3F, 0xBF7F, 0xBF7F, 0xC79F, 0xCFBF, 0x0000, 0xEFFF, 0x0000, 0x0000, 0x0000, 0xF7FF,
 0xEFFF, 0xDFDF, 0xCFBF, 0xC79F, 0xC79F, 0xBF7F, 0x9E5B, 0xC7BF, 0xC79F, 0xCFBF, 0xDFDF, 0xE7DF, 0x0000, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xF7FF, 0xEFFF, 0xE7FF, 0xDFDF, 0xDFFF, 0xDFFF, 0xD7BF, 0xDFDF, 0xE7FF, 0x0000, 0xFFFF, 0x0000, 0xFFFF
};


//18x8
const unsigned short sp[] = {
 0x0000, 0x0000, 0xBF7F, 0xA71F, 0x8E9F, 0x6D9D, 0x4C9C, 0x54DF, 0x337D, 0x231D, 0x22FD, 0x2B5C, 0x3BFE, 0x653F, 0x4439, 0x8E7F,
 0x9EDF, 0xB75F, 0xF7FF, 0x0000, 0xC79F, 0xAF3F, 0x9EDF, 0x865F, 0x75FF, 0x6D7F, 0x443D, 0x2B7B, 0x339C, 0x33BB, 0x54DE, 0x6D9F,
 0x863F, 0x8E9F, 0xA6FF, 0xBF7F, 0xF7FF, 0xE7DF, 0xCFBF, 0xAF3F, 0xAF3F, 0x969F, 0x8E5F, 0x7E1F, 0x653E, 0x2B98, 0x3C3A, 0x33F9,
 0x7DFF, 0x7E3F, 0x96BF, 0x9EFF, 0xAF3F, 0xBF7F, 0x0000, 0xF7FF, 0xD7DF, 0xCFBF, 0xBF7F, 0x9EFF, 0x9EDF, 0x969F, 0x7E1F, 0x4C99,
 0x4CBA, 0x54FB, 0x969F, 0x96BF, 0xA6FF, 0xAF3F, 0xBF7F, 0x0000, 0x0000, 0xF7FF, 0xEFFF, 0xD7DF, 0xC79F, 0xB75F, 0xAF3F, 0x9EDF,
 0xA71F, 0x5D19, 0x5CF8, 0x75DC, 0xA71F, 0xA71F, 0xB75F, 0xBF7F, 0xD7DF, 0xE7DF, 0x0000, 0xFFFF, 0xF7FF, 0xE7FF, 0xD7DF, 0xC79F,
 0xBF7F, 0xB75F, 0xB77F, 0x8E3B, 0x64F6, 0xAF3F, 0xBF7F, 0xBF7F, 0xC79F, 0xCFBF, 0xDFDF, 0x0000, 0x0000, 0x0000, 0x0000, 0xF7FF,
 0xEFFF, 0xDFDF, 0xCFBF, 0xC79F, 0xC79F, 0xBF7F, 0x9E5B, 0xC7BF, 0xC79F, 0xCFBF, 0xDFDF, 0xE7DF, 0xF7FF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xF7FF, 0xEFFF, 0xE7FF, 0xDFDF, 0xDFFF, 0xDFFF, 0xD7BF, 0xDFDF, 0xE7FF, 0xEFFF, 0x0000, 0xFFFF, 0x0000
};


// enemy ship that starts at the top of the screen (arms/mouth open)
// width=16 x height=10
const unsigned short SmallEnemy10pointB[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

// enemy ship that starts in the middle of the screen (arms together)
// width=16 x height=10
const unsigned short SmallEnemy20pointA[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

// enemy ship that starts in the middle of the screen (arms apart)
// width=16 x height=10
const unsigned short SmallEnemy20pointB[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};



// enemy ship that starts at the bottom of the screen (arms down)
// width=16 x height=10
const unsigned short SmallEnemy30pointA[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

// enemy ship that starts at the bottom of the screen (arms up)
// width=16 x height=10
const unsigned short SmallEnemy30pointB[] = {
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

// image of the player's ship
// includes two blacked out columns on the left and right sides of the image to prevent smearing when moved 2 pixels to the left or right
// width=18 x height=8
const unsigned short PlayerShip0[] = {
 0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0,
 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0,
 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0,
 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0,
 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0,
 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

const unsigned short pship[] = {
 0xE7FF, 0xD7DF, 0xBF7F, 0xA71F, 0x8E9F, 0x6D9D, 0x4C9C, 0x54DF, 0x337D, 0x231D, 0x22FD, 0x2B5C, 0x3BFE, 0x653F, 0x4439, 0x8E7F,
 0x9EDF, 0xB75F, 0x0000, 0xDFDF, 0xC79F, 0xAF3F, 0x9EDF, 0x865F, 0x75FF, 0x6D7F, 0x443D, 0x2B7B, 0x339C, 0x33BB, 0x54DE, 0x6D9F,
 0x863F, 0x8E9F, 0xA6FF, 0xBF7F, 0x0000, 0xE7DF, 0xCFBF, 0xAF3F, 0xAF3F, 0x969F, 0x8E5F, 0x7E1F, 0x653E, 0x2B98, 0x3C3A, 0x33F9,
 0x7DFF, 0x7E3F, 0x96BF, 0x9EFF, 0xAF3F, 0xBF7F, 0xFFFF, 0xF7FF, 0xD7DF, 0xCFBF, 0xBF7F, 0x9EFF, 0x9EDF, 0x969F, 0x7E1F, 0x4C99,
 0x4CBA, 0x54FB, 0x969F, 0x96BF, 0xA6FF, 0xAF3F, 0xBF7F, 0xCFBF, 0x0000, 0xF7FF, 0xEFFF, 0xD7DF, 0xC79F, 0xB75F, 0xAF3F, 0x9EDF,
 0xA71F, 0x5D19, 0x5CF8, 0x75DC, 0xA71F, 0xA71F, 0xB75F, 0xBF7F, 0xD7DF, 0xE7DF, 0x0000, 0xFFFF, 0xF7FF, 0xE7FF, 0xD7DF, 0xC79F,
 0xBF7F, 0xB75F, 0xB77F, 0x8E3B, 0x64F6, 0xAF3F, 0xBF7F, 0xBF7F, 0xC79F, 0xCFBF, 0xDFDF, 0xEFFF, 0x0000, 0x0000, 0x0000, 0xF7FF,
 0xEFFF, 0xDFDF, 0xCFBF, 0xC79F, 0xC79F, 0xBF7F, 0x9E5B, 0xC7BF, 0xC79F, 0xCFBF, 0x0000, 0xE7DF, 0x0000, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0xFFFF, 0xF7FF, 0xEFFF, 0xE7FF, 0xDFDF, 0xDFFF, 0xDFFF, 0xD7BF, 0xDFDF, 0xE7FF, 0xEFFF, 0xFFFF, 0x0000, 0x0000
};

// small shield floating in space to cover the player's ship from enemy fire (undamaged)
// width=18 x height=5
const unsigned short Bunker0[] = {
 0x079F, 0x079F, 0x079F, 0x079F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x079F, 0x079F,
 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x079F,
 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F,
 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x0000, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F,
 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x0000, 0x0000, 0x0000, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F,
 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x0000, 0x0000,

};

#endif /* __images_h */