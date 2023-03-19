/*This code is designed to function as an ohmmeter whereas it measures the resistance of an unknown resistor (Rb)
in a voltage divider circuit where it consists of two resistors, one known (Ra) and the other unknown (Rb).
The circuit is powered by a 5V source through Arduino, and the output voltage (Vb) between the resistors is measured using the Arduino's analog input pin (A0).
The calculated output voltage (Vb) is displayed on the LCD screen followed by a custom Omega character string, as well as the current value.*/

// Include the LiquidCrystal library for controlling the LCD screen
#include <LiquidCrystal.h>

// Define the LCD screen pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

// Initialize the LCD screen object
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Define the custom character array for the Omega symbol
byte customChar [] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B01010,
  B11011,
  B00000,
};

// Setup function runs once when the Arduino starts
void setup() {
  lcd.begin(16, 2); // Set up the LCD's number of columns and rows
  lcd.createChar(0, customChar); // Create the custom Omega character
  analogRead(A0); // Perform an analog read on pin A0
  Serial.begin(9600); // Begin serial communication at 9600 baud rate
}

// Loop function runs continuously after the setup() function
void loop() {
  float sensorValue = analogRead(A0); // Read the analog value from pin A0
  float voltage = (sensorValue/1023.0)*5.0; // Calculate the voltage based on the sensor value
  float Ia = (5.0 - voltage/0.989); // Calculate the current flowing through the resistance (Ia)
  float Ib = Ia; // Set the value of Ib equal to Ia
  float Vb = voltage; // Set the value of Vb equal to the calculated voltage
  float Rb = (Vb/Ib); // Calculate the resistance (Rb) using Ohm's Law

  delay(1000); // Wait for 1000 milliseconds (1 second)
  lcd.setCursor(0,0); // Set the cursor to the first position (column 0, row 0)
  lcd.print("Rb="); // Print "Rb=" on the LCD
  lcd.print(Rb); // Print the calculated resistance (Rb) on the LCD
  lcd.print("k"); // Print "k" (for kilo-ohms) on the LCD
  lcd.write((byte)0); // Print the custom Omega symbol on the LCD

  // Print values to the Serial Monitor
  Serial.print("Bit# = ");
  Serial.print(sensorValue);
  Serial.print("\t");
  Serial.print("voltage = ");
  Serial.print(voltage);
  Serial.print("\t");
  Serial.print("Ia = ");
  Serial.print(Ia);
  Serial.print("\t");
  Serial.print("Rb = ");
  Serial.println(Rb);
}