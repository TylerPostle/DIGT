#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
#include <SparkFun_LPS25HB_Arduino_Library.h> //Click here to get the library: http://librarymanager/All#SparkFun_LPS25HB

LPS25HB pressureSensor; // Create an object of the LPS25HB class
OpenLog TylersLog; //Create instance

void setup()
{

  Wire.begin();
  TylersLog.begin(); //Open connection to OpenLog (no pun intended)
pressureSensor.begin()
  Serial.begin(9600); //9600bps is used for debug statements

  TylersLog.append("TylersLog.txt");
  TylersLog.println("Pressure, Temperature, Time");
 TylersLog.syncFile();

  Serial.println("Done!");
}

void loop() {
    Serial.print("Pressure in hPa: ");
  Serial.print(pressureSensor.getPressure_hPa()); // Get the pressure reading in hPa
  Serial.print(", Temperature (degC): ");
  Serial.println(pressureSensor.getTemperature_degC()); // Get the temperature in degrees C

TylersLog.print("Pressure in hPa: ");
  TylersLog.print(pressureSensor.getPressure_hPa()); // Get the pressure reading in hPa
  TylersLog.print(", ");
  TylersLog.println(pressureSensor.getTemperature_degC()); // Get the temperature in degrees C

  delay(40); // Wait - 40 ms corresponds to the maximum update rate of the sensor (25 Hz)
}
