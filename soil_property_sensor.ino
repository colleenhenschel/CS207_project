/*
 * Soil Property Sensor
 * CS 207 Project
 * 
 * This program is to be used with the instructions found 
 * https://github.com/henschec/CS207_project
 * 
 * The values of a waterproof temperature sensor, smoisture sensor, 
 * and a pH sensor will be printed to Serial
 */

//Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>

const int moisture_pin = A1;     // moisture sensor analog output to Arduino Analog Input 1
const int pH_pin = A2;           //pH meter Analog output to Arduino Analog Input 2
// Data wire for temp sensor is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2 // defines digital pin 2 as temperature sensor pin
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Begin serial communication
  sensors.begin(); // This is for initializing the temperature sensor
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // TEMPERATURE:
  sensors.requestTemperatures();   //grabs temperature in Celsius
  Serial.print("Temperature is: "); // Print out temperature heading
  Serial.println(sensors.getTempCByIndex(0)); // "byIndex" because you can have more than one IC on the same bus. 0 refers to the first IC on the wire
  
  // MOISTURE:
  float moisture_percentage; // variable to store moisture percent
  int sensor_analog; 
  sensor_analog = analogRead(moisture_pin); // gets analog value from pin 1
  //Serial.print("\n\n");
  //Serial.print("Moisture Readout = ");
  //Serial.print(sensor_analog);
  //Serial.print("\n\n");
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) ); // Calculates percentage of moisture based on sensor capabilities
  Serial.print("Moisture Percentage = "); //OUtput moisture percent
  Serial.print(moisture_percentage); //value
  Serial.print("%\n\n");
  float volwaterovervolsoil; //Will store the fraction of volume of water / volume of soil
  Serial.print("Moisture Content (Vol water/ Vol Soil) = ");
  if(sensor_analog > 220)
  {
    volwaterovervolsoil = (sensor_analog - 1023)/(-2580.8);
    Serial.print(volwaterovervolsoil);
  }
  else
  {
    Serial.print("Greater than 0.3111")
  }
  Serial.print("%\n\n");
  // pH:
  float phvalue = 3.5*(float)analogRead(pH_pin)*5.0/1024; //the 5.0/1024 converts to volts, the 3.5 converts to pH value
  Serial.print("    pH:");
  Serial.println(phvalue); // printing out the pH value
  
  //Update values every 1 sec.
  delay(1000);
}
