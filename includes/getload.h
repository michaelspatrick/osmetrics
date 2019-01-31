#include <cstdlib>
#include <iostream>

double * getLoadAvg( )
{
  static double load[3]; 
  getloadavg(load, 3);
  return load;
}
