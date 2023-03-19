/* This code is for controlling an RGB LED using Pulse Width Modulation (PWM).
The purpose of this code is to set specific PWM values for the R,G,and B pins which will determine the particular brightness of each (RGB) color,
thus resulting a specific mixed color produced by the RGB LED.*/

int R = 11;  // Red LED pin is connected to PWM pin 11
int G = 10;  // Green LED is connected to PWM pin 10
int B = 9;   // Blue LED is connected to PWM pin 9 
void setup() {
  
  pinMode(R, OUTPUT); //initialize the red LED pin (11) as an OUTPUT.
  pinMode(G, OUTPUT); //initialize the green LED pin (10) as an OUTPUT.
  pinMode(B, OUTPUT); //initialize the blue LED pin (9) as an OUTPUT.
}

void loop() {
  // control the RGB LED colors through analogWrite / PWM function. (0 to 255 range, where 0 is off and 255 is full brightness).
  analogWrite(R, 250);  // Set the red LED's brightness by sending a PWM signal of 250 
  analogWrite(G, 128);  // Set the green LED's brightness by sending a PWM signal of 128 
  analogWrite(B, 114);  // Set the blue LED's brightness by sending a PWM signal of 114 

  // The specific combination values are set to produce a specific "Salmon Pink" color.
  // The values were determined through an online RGB colour finder.
}