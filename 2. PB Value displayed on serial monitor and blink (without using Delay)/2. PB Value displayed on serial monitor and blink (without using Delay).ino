/*
This code blinks an LED at a specified interval using the millis() function 
and toggles another LED based on the state of a pushbutton. 
The button is read using digitalRead() and the LED is controlled with digitalWrite(). 
The serial communication is also used to output the state of the pushbutton.

This code implements a system that blinks two LEDs. One LED blinks periodically with a 1-second interval using the millis() function,
while the other LED is controlled by the buttonState of PB.


*/
const int ledPin = 11;       // Define the pin for the first LED (blinking).
const int ledPin2 = 10;      // Define the pin for the second LED (controlled by button).
const int buttonPin = 12;     // the pin that the button is attached to
int buttonState = 0;         // variable to store the button state
int ledState = LOW;          // variable used to store the current LED state

unsigned long previousMillis = 0;  // store the last recorded timestamp for blinking LED.
const long interval = 1000;        // set the blinking interval in milliseconds (1 second).

void setup() {
  Serial.begin(9600);                 // initialize the serial communication at 9600 baud rate.
  pinMode(ledPin, OUTPUT);             // set the first LED pin as an output.
  pinMode(ledPin2, OUTPUT);           // set the second LED pin as an output.
  pinMode(buttonPin, INPUT_PULLUP);   // configure the button pin as an input with the built-in internal pull-up resistor.

}

void loop() {
  unsigned long currentMillis = millis();     //get the current elapsed time since the Arduino started and store it in the currentMillis variable

  // check if it's time to blink the first LED by comparing the elapsed time currentMillis with the previous recorded time previousMillis and the defined interval of 1s
  if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis; // save the last time LED was blinked by updating the previousMillis variable with the current time

    // toggle the LED state
    if (ledState == LOW) {
      ledState = HIGH;
    } else {                  //if the ledState is not LOW 
      ledState = LOW;         //change the ledState to LOW
    }

    digitalWrite(ledPin, ledState);  // set the LED with the ledState of the variable
  }

  // read the current state of the button and store it in the variable buttonState
  buttonState = digitalRead(buttonPin);

  // turn on/off the other LED based on the button state
  if (buttonState == HIGH) {        // if button is HIGH (not pressed)
    digitalWrite(ledPin2, HIGH);    // turn the second LED on
  } else {                          // otherwise, if the button is LOW (pressed)
    digitalWrite(ledPin2, LOW);     // turn the second LED off
  }

  // print the button state to the serial monitor
  Serial.print("ButtonState =    ");
  Serial.println(buttonState);
}

