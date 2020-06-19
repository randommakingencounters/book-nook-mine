// Base NeoPixel flame code thanks to Simon Cleveland (mysecretstache)
// For the ultimate NeoPixel guide, check out:
// https://learn.adafruit.com/adafruit-neopixel-uberguide/overview

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// What pin is the NeoPixel attached to
#define PIN 5

//  The overall brightness 0-255

int brightness =50;

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoPixel light01 = Adafruit_NeoPixel(1, 1, NEO_GRB + NEO_KHZ800);
// The current board design allows for up to three distinct pins
// Adafruit_NeoPixel light02 = Adafruit_NeoPixel(1, 2, NEO_GRB + NEO_KHZ800);
// Adafruit_NeoPixel light03 = Adafruit_NeoPixel(1, 3, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(brightness);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  
  //  Regular (orange) flame:
    int r = 230, g = 90, b = 0;

  // Flicker, based on our initial RGB values
  // To limit color variation, remove flicker variable as needed
  for(int i=0; i<strip.numPixels(); i++) {
    int flicker = random(0,25);
    int r1 = r-flicker;
    int g1 = g-flicker;
    int b1 = b;
    if(g1<0) g1=0;
    if(r1<0) r1=0;
    if(b1<0) b1=0;
    strip.setPixelColor(i,r1,g1, b1);
  }
  strip.show();

  delay(random(10,100));
}
