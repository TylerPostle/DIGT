#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
#include <SparkFun_LPS25HB_Arduino_Library.h> 

//TEACHER COMMENT you should change pressureSensor to another name not from the example code
LPS25HB pressureSensor; // Create an object of the LPS25HB class
OpenLog TylersLog; //Create instance

void setup()
{

  Wire.begin();
  TylersLog.begin(); //Open connection to OpenLog (no pun intended)
pressureSensor.begin()
  Serial.begin(9600); //9600bps is used for debug statements

  //TEACHER COMMENT add a comment to explain what are these 3 lines setting up
  TylersLog.append("TylersLog.txt");
  TylersLog.println("Pressure, Temperature, Time"); //TEACHER COMMENT so down on line 37 how are you going to get time being added?
 TylersLog.syncFile();

  Serial.println("Done!");
}

void loop() {
  //TEACHER COMMENT what are these lines of code doing/for?
    Serial.print("Pressure in hPa: ");
  Serial.print(pressureSensor.getPressure_hPa()); // Get the pressure reading in hPa
  Serial.print(", Temperature (degC): ");
  Serial.println(pressureSensor.getTemperature_degC()); // Get the temperature in degrees C

  //TEACHER COMMENT what are these lines of code for?
TylersLog.print("Pressure in hPa: ");
  TylersLog.print(pressureSensor.getPressure_hPa()); // Get the pressure reading in hPa
  TylersLog.print(", ");
  TylersLog.println(pressureSensor.getTemperature_degC()); // Get the temperature in degrees C

  delay(40); // Wait - 40 ms corresponds to the maximum update rate of the sensor (25 Hz)
}
