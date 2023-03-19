/*This code uses a potentiometer that serves as a sensor to show bit#,
then that bit# is converted into voltage value
that firstly shows both of those values into the Serial Monitor.
After that, it prints those values into the LCD whereas an additional PB input is used to switch between
displaying bit# or voltage value indicated on the LCD.*/

#include <LiquidCrystal.h> // Include the LiquidCrystal library

// LCD pin connections
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Create an LCD object

// Pin declarations
 int potentiometerPin = A0; // Assign the potentiometer input to analog pin A0
 int PB = 7; // Assign the pushbutton input to digital pin 7

void setup() {
  lcd.begin(16, 2); // Set up a 16x2 character LCD (number of columns and rows)
  Serial.begin(9600); // Start the Serial Monitor at 9600 baud rate
  pinMode(PB, INPUT_PULLUP); // Configure the PB as an input using the built-in pullup internal resistor.
}

void loop() {

  // Read the value from the potentiometer
  int sensorValue = analogRead(potentiometerPin); // Read the analog input from the potentiometer and store it in 'sensorValue'

  // Mathematically convert the sensor value to a voltage value
  float voltage = (sensorValue)*(5.0 / 1023.0); // Calculate the voltage value by multiplying the sensor value by (5V / 1023)

  // Check the pushbutton state
  int buttonState = digitalRead(PB); // Read the digital input from the pushbutton and store it in 'buttonState'

  // Print the bit# and voltage value to the Serial Monitor
  Serial.print("Bit# =   "); // Print "Bit# =  " to the Serial Monitor to identify which value belongs to
  Serial.print(sensorValue); // Print the sensor value (bit value) next to the Serial Monitor "Bit# = "
  Serial.print("\t"); // Print a tab character to the Serial Monitor, separating the bit-value and voltage value
  Serial.print("Voltage =  "); // Print "Voltage =  " next to the Serial Monitor to identify which value belongs to
  Serial.println(voltage); // Print the voltage value to next the Serial Monitor "Voltage = "

  // BUTTON STATE STATEMENTS
  if (buttonState == LOW) { // if the button is pressed (PB reads LOW)
    // Display voltage value on the LCD
    lcd.setCursor(0, 0); // Set the cursor to the first column of the first row
    lcd.print("Voltage =  "); // Print "Voltage = " to the LCD
    lcd.print(voltage); // Print the voltage value to the LCD


  } else { // otherwise, if the button is not pressed (PB reads HIGH)
    // Display bit# on the LCD
    lcd.setCursor(0, 0); // Set the cursor to the first column of the first row
    lcd.print("Bit # =   "); // Print the string "Bit# =   " to the LCD
    lcd.print(sensorValue); // Print the sensor value (bit#) to the LCD


  }

  delay(250); // Wait for 250 milliseconds before taking the next reading
}