#include <FastLED.h>
//int A2Pin = A2; // Sensor connected to analog pin 0
int A3Pin = A3;
//int A4Pin = A4; 
int A12Pin = A12; //13
int A9Pin = A9; //33
int A7Pin = A7; //32

int val = 0; // variable to store the read value

int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;
int val6 = 0;



int inputSensor = A3; // will be used for analog 0.
int startupValue; // start Value
int sensorValue = 0; // value of output
int PrInputA = 0; // value of when light is on
int PrInputB = 0; // when light is Red

#define NUM_LEDS 60
#define DATA_PIN 13
#define CLOCK_PIN 36

int sampleRate = 2000;// how much time has passed for green
int sampleRateB = 3500; // how much time since Orange
long lastReading; // used for timer

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {

Serial.begin(9600);
//pinMode(A2Pin, INPUT);
pinMode(A3Pin, INPUT);
//pinMode(A4Pin, INPUT);
pinMode(A12Pin, INPUT);
pinMode(A9Pin, INPUT);
pinMode(A7Pin, INPUT);
//pinMode(Pin2, INPUT);
//pinMode(LED1Pin, OUTPUT);
//pinMode(LED2Pin, OUTPUT);
//pinMode(LED3Pin, OUTPUT);

//ledInit();
FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
//  
printData();
//ledLoop();


//val1 = analogRead(A2Pin); // read the input pin (odd behaviour)
val2 = analogRead(A3Pin); // read the input pin
//val3 = analogRead(A4Pin); // read the input pin
val4 = analogRead(A12Pin); // read the input pin
val5 = analogRead(A9Pin); // read the input pin
val6 = analogRead(A7Pin); // read the input pin

//LED1 = analogRead(LED1Pin); // read the input pin
//LED2 = analogRead(LED2Pin); // read the input pin
//LED3 = analogRead(LED3Pin); // read the input pin

delay(500); // 30 frames per second



}


void printData() {
Serial.print("Pr::");
Serial.print("1:");
Serial.print(val1);
Serial.print(", ");
Serial.print("2:");
Serial.print(val2);
Serial.print(", ");
Serial.print("3:");
Serial.print(val3);
Serial.print(", ");
Serial.print("4:");
Serial.print(val4);
Serial.print(", ");
Serial.print("5:");
Serial.print(val5);
Serial.print(", ");
Serial.print("6:");
Serial.print(val6);
Serial.print("\n");

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
}
