/* This code uses potentiometer to control the color of an RGB LED.
The LED will transition through different colors from black to white as the potentiometer is turned.*/

// Define the pins for the RGB LED
const int redPin = 9;    // Red LED pin
const int greenPin = 10; // Green LED pin
const int bluePin = 11;  // Blue LED pin
const int potPin = A0;   // Potentiometer pin

// Setup function
void setup() {
  pinMode(redPin, OUTPUT);   // Set red LED pin as output
  pinMode(greenPin, OUTPUT); // Set green LED pin as output
  pinMode(bluePin, OUTPUT);  // Set blue LED pin as output
}

// Main loop function
void loop() {
  int potValue = analogRead(potPin); // Read potentiometer value (0-1023)

  // Black
  if (potValue >= 0 && potValue <= 171) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
  // Red
  else if (potValue < 342) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
  // Yellow
  else if (potValue < 513) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  }
  // Green
  else if (potValue < 684) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  }
  // Cyan
  else if (potValue < 855) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 100);
    analogWrite(bluePin, 100);
  }
}