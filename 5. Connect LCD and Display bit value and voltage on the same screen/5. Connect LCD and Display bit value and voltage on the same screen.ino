/*This code initializes the LCD by including the LiquidCrystal library,
then it reads the potentiometer value analog A0
then it converts that bit# to a voltage value.
It firstly prints them to Serial Monitor before printing LCD to ensure that the code is functional
and finally displays both the bit# and the voltage value on the LCD.*/

#include <LiquidCrystal.h> // Include the LiquidCrystal library

// LCD pin connections
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Create an LCD object

// Pin declarations
const int potentiometerPin = A0; // Assign the potentiometer input to analog pin A0

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2); // Set up a 16x2 character LCD

  Serial.begin(9600); // Start the Serial Monitor at 9600 baud rate
}
void loop() {
  // Read the value from the potentiometer
  int sensorValue = analogRead(potentiometerPin); // Read the analog input from the potentiometer and store it in 'sensorValue'
  // Mathematically convert the sensor value to a voltage value
  float voltage = (sensorValue)*(5.0 / 1023.0); // Calculate the voltage value by multiplying the sensor value by (5V / 1023)

  // Print the bit# and voltage value to the Serial Monitor
  Serial.print("Bit# =   "); // Print "Bit# =  " to the Serial Monitor to identify which value belongs to
  Serial.print(sensorValue); // Print the sensor value (bit value) next to the Serial Monitor "Bit# = "
  Serial.print("\t"); // Print a tab character to the Serial Monitor, separating the bit-value and voltage value
  Serial.print("Voltage =  "); // Print "Voltage =  " next to the Serial Monitor to identify which value belongs to
  Serial.println(voltage); // Print the voltage value to next the Serial Monitor "Voltage = "
  // Print the bit# and voltage value to the LCD
  lcd.setCursor(0, 0); // Set the cursor to the first column of the first row
  lcd.print("Bit# =  "); // Print the string "bit# =   " to the LCD
  lcd.print(sensorValue); // Print the sensor value to the LCD corresponding to the "bit# =  "
  lcd.setCursor(0, 1); // Set the cursor to the first column of the second row
  lcd.print("Voltage =  "); // Print the string "Voltage =   " to the LCD
  lcd.print(voltage); // Print the voltage value to the LCD

  delay(250); // add a 500ms delay before the next reading so have a more stable display, since without delay, values change really fast it wouldn't be clear on LCD screen
}