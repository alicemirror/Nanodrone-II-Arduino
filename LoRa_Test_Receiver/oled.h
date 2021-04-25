/**
 * @file oledsettings.h
 * @brief Definition of the OLED library control parameters and constants.
 * 
 * @warning Include only the font family that are needed in the application as
 * every font set is defined as a PROGMEM element consuming memory.
 * 
 * @author Modyfied and adepted by Enrico Miglino <enrico.miglino@gmail.com>
 * @date December 2020
 * @version 0.1
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Colors
#define COL_WHITE 1

// Font family to enable the desired font and size
#define MONO 10
#define MONO_BOLD 11
#define MONO_OBLIQUE 12 
#define MONO_BOLD_OBLIQUE 13
#define SERIF 20
#define SERIF_BOLD 21
#define SERIF_ITALIC 22
#define SERIF_BOLD_ITALIC 23
#define SANS 30
#define SANS_OBLIQUE 31
#define SANS_BOLD 32
#define SANS_BOLD_OBLIQUE 33

// Define the font families used by the application, undef the ones not needed
#define FREE_MONO
#define FREE_MONO_BOLD 
#define FREE_MONO_OBLIQUE 
#define FREE_MONO_BOLD_OBLIQUE 
#undef FREE_SERIF 
#undef FREE_SERIF_BOLD 
#undef FREE_SERIF_ITALIC 
#undef FREE_SERIF_BOLD_ITALIC 
#undef FREE_SANS 
#undef FREE_SANS_OBLIQUE 
#undef FREE_SANS_BOLD 
#undef FREE_SANS_BOLD_OBLIQUE 

// --- Font family: Sans bold oblique
#ifdef FREE_SANS_BOLD_OBLIQUE
#include <Fonts/FreeSansBoldOblique12pt7b.h>
#include <Fonts/FreeSansBoldOblique18pt7b.h>
#include <Fonts/FreeSansBoldOblique24pt7b.h>
#include <Fonts/FreeSansBoldOblique9pt7b.h>
#endif

// --- Font family: Sans oblique
#ifdef FREE_SANS_OBLIQUE
#include <Fonts/FreeSansOblique12pt7b.h>
#include <Fonts/FreeSansOblique18pt7b.h>
#include <Fonts/FreeSansOblique24pt7b.h>
#include <Fonts/FreeSansOblique9pt7b.h>
#endif

// --- Font family: Monospaced
#ifdef FREE_MONO
#include <Fonts/FreeMono12pt7b.h>
#include <Fonts/FreeMono18pt7b.h>   
#include <Fonts/FreeMono24pt7b.h>   
#include <Fonts/FreeMono9pt7b.h>     
#endif

// --- Font family: Monospaced bold
#ifdef FREE_MONO_BOLD
#include <Fonts/FreeMonoBold12pt7b.h>    
#include <Fonts/FreeMonoBold18pt7b.h>    
#include <Fonts/FreeMonoBold24pt7b.h>    
#include <Fonts/FreeMonoBold9pt7b.h>   
#endif

// --- Font family: Monospaced bold oblique
#ifdef FREE_MONO_BOLD_OBLIQUE
#include <Fonts/FreeMonoBoldOblique12pt7b.h> 
#include <Fonts/FreeMonoBoldOblique18pt7b.h> 
#include <Fonts/FreeMonoBoldOblique24pt7b.h> 
#include <Fonts/FreeMonoBoldOblique9pt7b.h>  
#endif

// --- Font family: Monospaced oblique
#ifdef FREE_MONO_OBLIQUE
#include <Fonts/FreeMonoOblique12pt7b.h>   
#include <Fonts/FreeMonoOblique18pt7b.h>   
#include <Fonts/FreeMonoOblique24pt7b.h>   
#include <Fonts/FreeMonoOblique9pt7b.h>    
#endif

// --- Font family: Serif
#ifdef FREE_SERIF
#include <Fonts/FreeSerif12pt7b.h>
#include <Fonts/FreeSerif18pt7b.h>
#include <Fonts/FreeSerif24pt7b.h>
#include <Fonts/FreeSerif9pt7b.h>
#endif

// --- Font family: Serif bold
#ifdef FREE_SERIF_BOLD
#include <Fonts/FreeSerifBold12pt7b.h>
#include <Fonts/FreeSerifBold18pt7b.h>
#include <Fonts/FreeSerifBold24pt7b.h>
#include <Fonts/FreeSerifBold9pt7b.h>
#endif

// --- Font family: Serif bold italic
#ifdef FREE_SERIF_BOLD_ITALIC
#include <Fonts/FreeSerifBoldItalic12pt7b.h>
#include <Fonts/FreeSerifBoldItalic18pt7b.h>
#include <Fonts/FreeSerifBoldItalic24pt7b.h>
#include <Fonts/FreeSerifBoldItalic9pt7b.h>
#endif

// --- Font family: Serif italic
#ifdef FREE_SERIF_ITALIC
#include <Fonts/FreeSerifItalic12pt7b.h>
#include <Fonts/FreeSerifItalic18pt7b.h>
#include <Fonts/FreeSerifItalic24pt7b.h>
#include <Fonts/FreeSerifItalic9pt7b.h>
#endif

// --- Font family: Sans
#ifdef FREE_SANS
#include <Fonts/FreeSans12pt7b.h>    
#include <Fonts/FreeSans18pt7b.h>
#include <Fonts/FreeSans24pt7b.h>
#include <Fonts/FreeSans9pt7b.h>
#endif

// --- Font family: Sand bold
#ifdef FREE_SANS_BOLD
#include <Fonts/FreeSansBold12pt7b.h>   
#include <Fonts/FreeSansBold18pt7b.h>   
#include <Fonts/FreeSansBold24pt7b.h>    
#include <Fonts/FreeSansBold9pt7b.h>
#endif

#ifndef _OLEDSETTINGS
#define _OLEDSETTINGS

//! Screen size
#define OLED_WIDTH 128
//! Screen size
#define OLED_HEIGHT 64

//! The I2C OLED display address
#define OLED_I2C 0x3C

//! Scroll left to right
#define OLED_SCROLL_LEFT_RIGHT 1
//! Scroll right to left
#define OLED_SCROLL_RIGHT_LEFT 2
//! Scroll diagonal right
#define OLED_SCROLL_DIAG_RIGHT 3
//! Scroll diagonal left
#define OLED_SCROLL_DIAG_LEFT 4
//! Stop scrolling text
#define OLED_SCROLL_STOP 5

#endif
