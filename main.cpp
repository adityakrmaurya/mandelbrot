#include "Bitmap.h"
#include "Mandelbrot.h"
#include <iostream>

using namespace std;
using namespace fractal;
int main() {
  int const WIDTH = 800;
  int const HEIGHT = 600;
  Bitmap bitmap(WIDTH, HEIGHT);
  double min = 1e6;
  double max = -1e6;
  // scaling hack
  // the fractal values ranges from -1 to 1 on both axis
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      double xFractal = (x - WIDTH / 2) * 2.0 / WIDTH;
      double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;
      int iterations = Mandelbrot::getIterations(xFractal, yFractal);
      uint8_t red =
          (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);
      bitmap.setPixel(x, y, red, red, red);
      if (red < min) {
        min = red;
      }
      if (red > max) {
        max = red;
      }
    }
  }
  cout << min << ", " << max << endl;
  bitmap.write("test.bmp");
  cout << "Complete";
  return 0;
}
