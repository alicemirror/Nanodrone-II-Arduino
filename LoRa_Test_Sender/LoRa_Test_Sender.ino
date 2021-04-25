/**
@file LoRa_Test_Sender
@brief Arduino MKR 1300 WAN LoRa WAN sending test

It is expected that the sender module (onboard of the drone) 
will try to connect to the ground receiver when the receiver is already 

@date April, 2021
@author Enrico Miglino <enrico.miglino@gmail.com>
@version 1.0.1
*/

#include <SPI.h>
#include <LoRa.h>
#include <Streaming.h>

int counter = 0;
String val="";

/**
Initialize the Lora connection with the gound device. 
*/
void setup() {
 if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  LoRa.beginPacket();
  LoRa << "Nanodrone test " << counter << endl;
  LoRa.endPacket();
  counter++; // this help keep track if the packet is recived on the sender side

  // Wait about a minute
  delay(58000);
}
