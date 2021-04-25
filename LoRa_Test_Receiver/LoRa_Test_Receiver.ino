/**
@file LoRa_Test_Receiver
@brief Arduino MKR 1300 WAN LoRa WAN receiving test

The receiver includes a 0.9 inches Oled monochromatic display
to show updates on the connection status and data.

@date April, 2021
@author Enrico Miglino <enrico.miglino@gmail.com>
@version 1.0.1
*/
#include <LoRa.h>
#include <Streaming.h>
#include <Streaming.h>
#include "oled.h"

#define SYS_LED 6

//! Dispaly instance
Adafruit_SSD1306 oled = Adafruit_SSD1306(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

/**
Initialization function
*/
void setup() {
  // Initialize the monitoring serial
  Serial.begin(38400);
  // Initialize the communication serial
  Serial1.begin(115200);

  // Notify the LoRa activity
  pinMode(SYS_LED, OUTPUT);
  digitalWrite(SYS_LED, LOW);

  Serial << "LoRa Receiver" << endl;

  if (!LoRa.begin(915E6)) {
    Serial <<"Starting LoRa failed! System halted." << endl;
    while (1);
  }

  // Initialize the display
  oled.begin(SSD1306_SWITCHCAPVCC, OLED_I2C);
  oled.setRotation(2); // Rotate the display 180 Deg

  // Clear the buffer.
  oled.clearDisplay();
  oled.display();

  // Show title
  initDisplay(&oled); 
  textFont(MONO_BOLD, 9, &oled);
  showText("LoRa", 40, 9, COL_WHITE, &oled); 
  showText("Receiver", 13, 25, COL_WHITE, &oled);
  showText("Ver.1.0", 16, 40, COL_WHITE, &oled);
  showText("NanodroneII", 0, 55, COL_WHITE, &oled);

  delay(5000);

  // Clear the buffer.
  oled.clearDisplay();
  textFont(MONO, 9, &oled);
  showText("Ready", 35, 40, COL_WHITE, &oled);
  delay(3000);

  oled.clearDisplay();
  oled.display();

}

void loop() {
  int packetSize = LoRa.parsePacket();

  if(Serial1.available()) {
    Serial << "From PSoC6 " << Serial1.readString() << endl;
  }
  
  if (packetSize) {
    digitalWrite(SYS_LED, HIGH);
    Serial << "Receiving LoRa packet of " << packetSize << " bytes" << endl;
    // read packet
    while (LoRa.available()) {
      String inPacket = LoRa.readString();
      Serial << "Sending >>" << inPacket << endl;
      Serial1.println(inPacket); 
    }
    digitalWrite(SYS_LED, LOW);
  }
}

// =========================================================
//                      Oled functions
// =========================================================

/**
 * Show the text string at the desired coordinates.
 * 
 * The text is shown according to the current settings (color, font, etc.)
 * 
 * \param text The string of text to display
 * \param x The x cursor coordinates
 * \param y The y cursor coordinates
 * \param color The color of the text
 * \param disp Pointer to the Oled display class
 */
void showText(char* text, int x, int y, int color, Adafruit_SSD1306* disp) {
  // Set the desired color
  switch(color) {
    case COL_WHITE:
    oled.setTextColor(SSD1306_WHITE);
    break;
  }
  disp->setCursor(x, y);
  disp->print(text);
  disp->display();
}

/**
 * Initialize the display before showing a new screen.
 * 
 * \note This method should be called for first before setting a new
 * string or when the screen setting changes.
 * 
 * \param disp Pointer to the Oled display class
 */
void initDisplay(Adafruit_SSD1306* disp) {
  disp->clearDisplay();
  disp->display();
}

/**
 * Set the desired font and size to the text.
 * 
 * \param fontName One of the following font families:\n
 * \param fontSize The size in point of the font chosen between one of the
 * following values: 9, 12, 18, 24
 * \param disp Pointer to the Oled display class
 * 
 * \return 0 if the font is set else return -1
 */
int textFont(int fontName, int fontSize, Adafruit_SSD1306* disp) {
  int j;

  // Check for the font size
  if( (fontSize != 9) && (fontSize != 12) &&
      (fontSize != 18) &&(fontSize != 24) ) {
        return -1;
      }

  // Switch the font family
  switch(fontName) {
    case MONO:
    #ifndef FREE_MONO
    disp->setFont();
    return -1;
    #else
    switch(fontSize) {
      case 9:
        disp->setFont(&FreeMono9pt7b);
      break;
      case 12:
        disp->setFont(&FreeMono12pt7b);
      break;
      case 18:
        disp->setFont(&FreeMono18pt7b);
      break;
      case 24:
        disp->setFont(&FreeMono24pt7b);
      break;
    }
    #endif
    break;

    case MONO_BOLD:
    #ifndef FREE_MONO_BOLD
    disp->setFont();
    return -1;
    #else
    switch(fontSize) {
      case 9:
        disp->setFont(&FreeMonoBold9pt7b);
      break;
      case 12:
        disp->setFont(&FreeMonoBold12pt7b);
      break;
      case 18:
        disp->setFont(&FreeMonoBold18pt7b);
      break;
      case 24:
        disp->setFont(&FreeMonoBold24pt7b);
      break;
    }
    #endif
    break;

    case MONO_OBLIQUE:
    #ifndef FREE_MONO_OBLIQUE
    disp->setFont();
    return -1;
    #else
    switch(fontSize) {
      case 9:
        disp->setFont(&FreeMonoOblique9pt7b);
      break;
      case 12:
        disp->setFont(&FreeMonoOblique12pt7b);
      break;
      case 18:
        disp->setFont(&FreeMonoOblique18pt7b);
      break;
      case 24:
        disp->setFont(&FreeMonoOblique24pt7b);
      break;
    }
    #endif
    break;

    case MONO_BOLD_OBLIQUE:
    #ifndef FREE_MONO_BOLD_OBLIQUE
    disp->setFont();
    return -1;
    #else
    switch(fontSize) {
      case 9:
        disp->setFont(&FreeMonoBoldOblique9pt7b);
      break;
      case 12:
        disp->setFont(&FreeMonoBoldOblique12pt7b);
      break;
      case 18:
        disp->setFont(&FreeMonoBoldOblique18pt7b);
      break;
      case 24:
        disp->setFont(&FreeMonoBoldOblique24pt7b);
      break;
    }
    #endif
    break;
  } 
}

