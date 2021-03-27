#include <cmath>
#include <vector>

#include "menus.h"
#include "plotter.h"

int main() {
  // MainMenu();
  int numPoints = 69;
  float inc = 7.5 / (numPoints - 1);
  std::vector<double> time(numPoints, 0.0);
  std::vector<double> response(numPoints, 0.0);
  for (int i = 0; i < numPoints; ++i) {
    time[i] = i * inc;
    response[i] = std::cos(i * inc);
  }

  makeplots(time, response);
  
  return 0;
}
