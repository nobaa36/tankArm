#include <LiquidCrystal.h>//biblioteka lcd
#include <SPI.h>///magistrala do ndadajnika
#include "nRF24L01.h"//biblioteka nadajnika , nie wiem czy potrzebna
#include "RF24.h"///biblioteka ndajanika , nie wiem czy potrzebna

int i=1;
byte msg[6];
bool ok;
const uint64_t pipe = 0xE8E8F0F0E1LL;
bool mode=true;
byte nadsrodkiem=145;
byte podsrodkiem=111;
RF24 radio(9,10);
LiquidCrystal lcd(2, 8, 3, 4, 5, 6);
int robot=0;
boolean wybor=false;

void setup() {//-------------------------setup
Serial.begin(57600);
radio.begin();
radio.openWritingPipe(pipe);
pinMode(18,INPUT_PULLUP);
pinMode(19,INPUT_PULLUP);
  
}//-------------------------------------setup

void loop() {
  switch (robot) {
    case 0:
      choose();
      Serial.println("wybrano robot");
      break;
      case 1:
      Serial.println("wybieram tank");
      tank();
      Serial.println("tank aktywowany");
      break;
      case 2:
      spider();
      Serial.println("2");
      break;
  }
  
 
 }
      


