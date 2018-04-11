#include <unistd.h>
#include <iostream>
#include <signal.h>
#include "lm35.h"

using namespace std;

bool shouldRun = true;

void sig_handler(int signo)
{
  if (signo == SIGINT)
    shouldRun = false;
}

int main()
{
  signal(SIGINT, sig_handler);

//! [Interesting]

  // Instantiate a LM35 on analog pin A0, with a default analog
  // reference voltage of 5.0
  upm::LM35 *sensor = new upm::LM35(0);
  
  // Every half second, sample the sensor and output the temperature

  while (shouldRun)
    {
      cout << "Temperature: " << sensor->getTemperature() << " C" << endl;
      
      usleep(500000);
    }

//! [Interesting]

  cout << "Exiting" << endl;

  delete sensor;
  return 0;
}
