/*******************************************************
Nom ......... : RGB_tool_Attiny
Role ........ : Interface Ramps imprimante 3D vers un bandeau lumineux à LED RGB
                4 entrées RGB et Mode (blink) récupérées comme booleens
                1 sortie PWM pour la commande des 4 leds
Auteur ...... : Patave
Version ..... : V1.0
Date ........ : 07/05/2021

Board ....... : Attiny85
Environnement : VS-Code & Arduino IDE
********************************************************/

#include <Adafruit_NeoPixel.h>
#include <avr/io.h>   //allows for register commands to be understood

#define OUTPUT_PIN 1   // output pin Neopixe PB1

#define INPUT_R 2  // input RED value PB2
#define INPUT_G 3  // input GREEN value PB3
#define INPUT_B 4  // input BLUE value PB4
#define INPUT_M 0  // input MODE value PB0

#define NUMPIXELS      4 // number of neopixels in strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, OUTPUT_PIN, NEO_GRB + NEO_KHZ800);

int delayval = 200; // timing delay in milliseconds

bool redColor = false; // true Red ON
bool greenColor = false; //True Green ON
bool blueColor = false;  //True Blue ON
bool blinkMode = false;  //True Blink mode

bool blink = false;
int decal=0;


void setup() {
  // Initialize I/O
  pinMode(INPUT_R, INPUT_PULLUP);
  pinMode(INPUT_G, INPUT_PULLUP);
  pinMode(INPUT_B, INPUT_PULLUP);
  pinMode(INPUT_M, INPUT_PULLUP);
  
  // Initialize the NeoPixel library.
  strip.begin();
  strip.setBrightness(50);  
}

void loop() {
  // Read inputs
  redColor =    digitalRead(INPUT_R);
  greenColor =  digitalRead(INPUT_G);
  blueColor =   digitalRead(INPUT_B);
  blinkMode =   digitalRead(INPUT_M);

  if (!blinkMode) { 
    for (int i=0; i < NUMPIXELS; i++) {
          strip.setPixelColor(i, strip.Color(redColor*255, greenColor*255, blueColor*255));
      }
  } else {
     if (blink) {
        for (int i=0; i < NUMPIXELS; i++) {
          strip.setPixelColor(i, strip.Color(redColor*255, greenColor*255, blueColor*255));
        }
      } else strip.clear();
      blink=!blink;
  }

  strip.show();
  // Delay for a blink (in milliseconds).
  delay(delayval);
}
