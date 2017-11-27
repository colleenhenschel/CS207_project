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

const int moisture_pin = A1;
const int pH_pin = A2;           //pH meter Analog output to Arduino Analog Input 0
// Data wire for temp sensor is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Begin serial communication
  sensors.begin(); // This is for the temperature sensor
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // TEMPERATURE:
  sensors.requestTemperatures();  
  Serial.print("Temperature is: ");
  Serial.println(sensors.getTempCByIndex(0)); // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  
  // MOISTURE:
  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(moisture_pin);
  //Serial.print("\n\n");
  //Serial.print("Moisture Readout = ");
  //Serial.print(sensor_analog);
  //Serial.print("\n\n");
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print("%\n\n");

  // pH:
  float phvalue = 3.5*(float)analogRead(pH_pin)*5.0/1024; //the 5.0/1024 converts to volts, the 3.5 converts to pH value
  Serial.print("    pH:");
  Serial.println(phvalue);
  
  //Update values every 1 sec.
  delay(1000);
}
