#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 13


Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);
//int A2Pin = A2; // Sensor connected to analog pin 0
int A3Pin = A3;
//int A4Pin = A4; 
int A12Pin = A12; //13
int A9Pin = A9; //33
int A7Pin = A7; //32

int val1 = 0;
int val2 = 0;
int val3 = 0;




void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

//Serial.begin(9600);
////pinMode(A2Pin, INPUT);
//pinMode(A3Pin, INPUT);
////pinMode(A4Pin, INPUT);
//pinMode(A12Pin, INPUT);
//pinMode(A9Pin, INPUT);
//pinMode(A7Pin, INPUT);
////pinMode(Pin2, INPUT);
////pinMode(LED1Pin, OUTPUT);
////pinMode(LED2Pin, OUTPUT);
////pinMode(LED3Pin, OUTPUT);


}

void loop() {
//  
ledLoop();
//printData();


//
////val1 = analogRead(A2Pin); // read the input pin (odd behaviour)
//val2 = analogRead(A3Pin); // read the input pin
////val3 = analogRead(A4Pin); // read the input pin
//val4 = analogRead(A12Pin); // read the input pin
//val5 = analogRead(A9Pin); // read the input pin
//val6 = analogRead(A7Pin); // read the input pin
//
////LED1 = analogRead(LED1Pin); // read the input pin
////LED2 = analogRead(LED2Pin); // read the input pin
////LED3 = analogRead(LED3Pin); // read the input pin
//
//delay(500); // 30 frames per second



}


//void printData() {
//Serial.print("Pr::");
//Serial.print("1:");
//Serial.print(val1);
//Serial.print(", ");
//Serial.print("2:");
//Serial.print(val2);
//Serial.print(", ");
//Serial.print("3:");
//Serial.print(val3);
//Serial.print(", ");
//Serial.print("4:");
//Serial.print(val4);
//Serial.print(", ");
//Serial.print("5:");
//Serial.print(val5);
//Serial.print(", ");
//Serial.print("6:");
//Serial.print(val6);
//Serial.print("\n");

//Serial.print("LED Output::");
//Serial.print("1:");
//Serial.print(LED1);
//Serial.print(", ");
//Serial.print("2:");
//Serial.print(LED2);
//Serial.print(", ");
//Serial.print("3:");
//Serial.print(LED3);
//Serial.print("\n");
//}



void ledLoop() {

  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  theaterChase(strip.Color(127, 127, 127), 50); // White
  theaterChase(strip.Color(127, 0, 0), 50); // Red
  theaterChase(strip.Color(0, 0, 127), 50); // Blue

  rainbow(20);
  rainbowCycle(20);
  theaterChaseRainbow(50);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
