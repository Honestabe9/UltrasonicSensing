// ELEGOO UNO R3: Ultrasoninc Sensor HC-SR04 Module

#include <HCSR04.h>

// Attaching pin D12 to the pin labeled "Trig" and pin D~11 to the pin labeled "Echo," of HC-SR04

#define pin_Trig 12
#define pin_Echo 11 

// defines variables
long duration; // Time-duration of sound wave traveling
int distance; // Measurement for distance(s)

void setup() 
{
  pinMode(pin_Trig, OUTPUT); // pin_Trig is set as an OUTPUT
  pinMode(pin_Echo, INPUT); // pin_Echo is set as an INPUT
  
  Serial.begin(9600); // // Serial Communication => starting with a standard of 9600 bps or symbols/s (baud rate)
  Serial.println("Ultrasonic Sensor HC-SR04 Test w/ ELEGOO UNO R3"); // Printing some text out for the Serial monitor
}

void loop() 
{
  digitalWrite(pin_Trig, LOW); // Clears the pin_Trig condition
  delayMicroseconds(2);
  
  digitalWrite(pin_Trig, HIGH); // pin_Trig is set to be ON for 10 μs
  delayMicroseconds(10);
  
  digitalWrite(pin_Trig, LOW);
  
  duration = pulseIn(pin_Echo, HIGH); // pin_Echo is read in, and this returns the time-duration of sound wave traveling

  distance = ((duration) / (1/0.034)) / 2; // Computing distance by accounting for sound to travel through the air and bouncing back to the module-
  //and the speed of sound waves is a factor of this formula which is assumed to be at room temperature and in the units cm/μs

  // Displaying distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
