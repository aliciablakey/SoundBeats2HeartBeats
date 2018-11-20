// Analog Sensor

int inPin = A0; // Sensor connected to analog pin 0
int val = 0; // variable to store the read value

int Pin2 = A1;
int val2 = 0;

void setup() {
Serial.begin(9600);
pinMode(inPin, INPUT);
pinMode(Pin2, INPUT);
}

void loop() {
Serial.println(val2);

val = analogRead(inPin); // read the input pin
delay(33); // 30 frames per second

val2 = analogRead(Pin2);
delay(33);
}