/*
  Project: LED Brightness Control using a Potentiometer
  Author: M M Saathvik
  Reg No: 26BVD0145
  Course: VLSI Design & Technology
  Description: This program reads an analog signal from a potentiometer and maps 
               it to a PWM signal to control the brightness of an LED.
*/

// Pin Assignments
const int potPin = A0;   // Analog input pin connected to potentiometer wiper
const int ledPin = 9;    // PWM digital output pin connected to LED anode

// Variables
int potValue = 0;        // Variable to store raw analog reading (0 - 1023)
int brightness = 0;      // Variable to store mapped PWM value (0 - 255)

void setup() {
  // Configure LED pin as output
  pinMode(ledPin, OUTPUT);
  
  // Initialize serial communication at 9600 baud for debugging/monitoring
  Serial.begin(9600);
}

void loop() {
  // Read analog voltage from potentiometer (10-bit ADC: 0 to 1023)
  potValue = analogRead(potPin);
  
  // Scale reading from 10-bit ADC resolution (0-1023) to 8-bit PWM resolution (0-255)
  brightness = map(potValue, 0, 1023, 0, 255);
  
  // Write PWM signal to control LED brightness
  analogWrite(ledPin, brightness);
  
  // Display readings on Serial Monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(" | LED Brightness: ");
  Serial.println(brightness);
  
  // Small delay for signal stabilization and monitor readability
  delay(100);
}