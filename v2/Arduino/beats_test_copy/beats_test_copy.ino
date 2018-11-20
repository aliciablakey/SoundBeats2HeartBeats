#include <ArduinoJson.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 13


Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);
int A7Pin = A7;
int A9Pin = A9;
int A3Pin = A3;


//black wire sensor to pin 32 || A7
//val sesnor 6
//purple wire sensor pin 33 || A9
//val sesnor 5
//Green wire sesnor to pin A3
//val sesnor 2

int val1 = 0;
int val2 = 0;
int val3 = 0;




void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

Serial.begin(9600);

pinMode(A3Pin, INPUT);
pinMode(A9Pin, INPUT);
pinMode(A7Pin, INPUT);

//pinMode(Pin2, INPUT);
//pinMode(LED1Pin, OUTPUT);
//pinMode(LED2Pin, OUTPUT);
//pinMode(LED3Pin, OUTPUT);


}

void loop() {
 
  val1 = analogRead(A3Pin); // read the input pin (odd behaviour)
  val2 = analogRead(A7Pin); // read the input pin
  val3 = analogRead(A9Pin); // read the input pin
  printData();


//  if(val1 < 50||val2 < 50 ||val3 < 50){
//    Serial.write("ledLoop() started running!");
//    ledLoop();
//    Serial.write("ledLoop() done running!");
//  } else {
//    
//  }


  if (analogRead(A3Pin) < 50) {
    noLoop();
  } else {
    ledLoop();
  }
    
}


void printData() {
Serial.print("Sensor::");
Serial.print("1:");
Serial.print(val1);
Serial.print(", ");
Serial.print("2:");
Serial.print(val2);
Serial.print(", ");
Serial.print("3:");
Serial.print(val3);
Serial.println();
}

void noLoop(){

}

void ledLoop() {
  Serial.write("ledLoop() started running!");
  colorWipe(strip.Color(255, 0, 0), 50); // Red
//  colorWipe(strip.Color(0, 255, 0), 50); // Green
//  colorWipe(strip.Color(0, 0, 255), 50); // Blue
//  theaterChase(strip.Color(127, 127, 127), 50); // White
//  theaterChase(strip.Color(127, 0, 0), 50); // Red
//  theaterChase(strip.Color(0, 0, 127), 50); // Blue
//  rainbow(20);
//  rainbowCycle(20);
//  theaterChaseRainbow(50);
  Serial.write("ledLoop() done running!");
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    
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
