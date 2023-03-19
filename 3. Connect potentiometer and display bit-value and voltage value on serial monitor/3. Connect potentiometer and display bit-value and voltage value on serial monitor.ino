/*This code initializes the potentiometer input, 
then reads the analog value from the potentiometer
then converts it to a voltage value
and finally displays both the bit value and the voltage value in a seperate column on the Serial Monitor on a loop every 250 milliseconds*/

// Pin declaration
const int potentiometerPin = A0; // Assign the potentiometer input to analog pin A0

void setup() {
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

  delay(250); // Wait for 250 milliseconds before the next reading

}