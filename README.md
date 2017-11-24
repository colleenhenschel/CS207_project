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


## Temperature Sensor:
Setup for the waterproof temperature sensor follows codebender_cc's article on instructables "How to Use DS18B20 Temperature Sensor - Arduino Tutorial", link: http://www.instructables.com/id/How-to-use-DS18B20-Temperature-Sensor-Arduino-Tuto/

The waterproof temperature sensor used is shown below. 

![Alt text](https://github.com/henschec/CS207_project/blob/master/tempsensor.png "Waterproof Temperature Sensor")

The end of the cable has 3 wires, red, yellow, and black. The yellow wire is used to aquire data and must be connected in series to a 4.7 kOhm resistor and digital pin 2 of the arduino. The black and red wires both go to ground. The other end of the 4.7 kOhm resistor is connected to 5 V.

The code for reading the temperature sensor uses the libraries OneWire.h, and DallasTemperature.h, which can be downloaded by navigating through the Sketch dropdown menu on arduino to IncludeLibrary to ManageLibraries shown below.

![Alt text](https://github.com/henschec/CS207_project/blob/master/downloading_libraries.png)

## Moisture Sensor:
Setup for the soil moisture sensor follows a basic tutorial on ElectronicWings called "Soil Moisture Sensor Interfacing with Arduino UNO ", link: http://www.electronicwings.com/arduino/soil-moisture-sensor-interfacing-with-arduino-uno

The purchased moisture sensor has everything built in. Five female to female cables are needed to connect the moisture sensor to the Arduino. Two connect the conducting probes to the integrated circuit, and the other three are used to connect the integrated circuit to 5 V, ground, and analog pin 1.

picture here?

The code for the soil moisture sensor is pretty straight forward... changes will need to be made here for when I calibrate the moisture sensor.
