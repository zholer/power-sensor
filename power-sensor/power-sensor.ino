#include <PimaticProbe.h>

#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance
PimaticProbe probe = PimaticProbe(2, 1000);
double old_power = 0;

void setup()
{  
  Serial.begin(9600);
  emon1.current(A0, 80);             // Current: input pin, calibration.
}

void loop()
{
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  double new_power = 120 * Irms;
  Serial.print(new_power);         // Apparent power
  Serial.print(" ");
  Serial.println(Irms);          // Irms
  if (abs(old_power - new_power) > 10) {
    //probe.transmit(true, new_power, 1, 7);
    old_power = new_power;
  }
  //delay(1000);
}

