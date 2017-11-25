# CS207_project - Soil Property Sensor

## Project Goal:

The aim of this project is to use an arduino uno for determining the moisture content, temperature, and pH level of soil samples.

## Electronics Materials:

- Arduino Uno
- DS18B20 Waterproof temperature sensor
- 4.7 kOhm resistor
- XCSOURCE Soil Moisture Sensor, with inegrated circuit and 5 female to female cables that come with it
- Gravity Analog pH Meter Kit
- assortment of cables

## Circuit Diagram:

![Alt text](https://github.com/henschec/CS207_project/blob/master/soilsensorcircuit.png "Arduino Circuit Setup")

## Temperature Sensor:
Setup for the waterproof temperature sensor follows codebender_cc's article on instructables "How to Use DS18B20 Temperature Sensor - Arduino Tutorial", link: http://www.instructables.com/id/How-to-use-DS18B20-Temperature-Sensor-Arduino-Tuto/

The waterproof temperature sensor used is shown below. 

![Alt text](https://github.com/henschec/CS207_project/blob/master/tempsensor.png "Waterproof Temperature Sensor")

The end of the cable has 3 wires, red, yellow, and black. The yellow wire is used to aquire data and must be connected in series to a 4.7 kOhm resistor and digital pin 2 of the arduino. The black and red wires both go to ground. The other end of the 4.7 kOhm resistor is connected to 5 V.

The code for reading the temperature sensor uses the libraries OneWire.h, and DallasTemperature.h, which can be downloaded by navigating through the Sketch dropdown menu on arduino to IncludeLibrary to ManageLibraries shown below.

![Alt text](https://github.com/henschec/CS207_project/blob/master/downloading_libraries.png)

## Moisture Sensor:
Setup for the soil moisture sensor follows a basic tutorial on ElectronicWings called "Soil Moisture Sensor Interfacing with Arduino UNO ", link: http://www.electronicwings.com/arduino/soil-moisture-sensor-interfacing-with-arduino-uno

The purchased moisture sensor has everything built in. Five female to female cables are needed to connect the moisture sensor to the Arduino. Two connect the conducting probes to the integrated circuit, and the other three are used to connect the integrated circuit to 5 V, ground, and analog pin 1. Note that the moisture sensor used in the creation of this project is shown below, and differs slightly from the one shown in the circuit diagram. The sensor board has four connectors, VCC, GND, D0, and A0, from bottom to top in the picture below. The VCC connects to 5 V on the breadboard, GND connects to ground, and A0 connects to analog pin 1 on the Arduino.

![Alt text](https://github.com/henschec/CS207_project/blob/master/moisturesensor.png "XCSOURCE Soil Moisture Sensor")

The code for the soil moisture sensor is pretty straight forward. It simply reads in the analog value (ranging from 0 to 1023, 0 for when the sensor is completely submersed in water, 1023 when dry) and converts this value based on the analysis plot shown below.

Do analysis of moisture sensor readings for different water contents of soil.

## pH Sensor:
The pH sensor is similar to the soil moisture sensor, everything comes built in. The board for the pH sensor is connected to the BNC cable that is attached to the pH sensor. THe other end of the board has 3 wires, black = GND, red = VCC, and blue = A0. The black wire is connected to ground on breadboard, red connected to 5 V, and the blue wire gets connected to analog pin 0 on the arduino.
