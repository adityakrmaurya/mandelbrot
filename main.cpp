#include "Bitmap.h"
#include "Mandelbrot.h"
#include <iostream>
#include <memory>

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
  unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      double xFractal = (x - WIDTH / 2 - 100) * 2.0 / HEIGHT;
      double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;
      int iterations = Mandelbrot::getIterations(xFractal, yFractal);
      // increment the value of that iteration in the array
      if (iterations != Mandelbrot::MAX_ITERATIONS) {
        histogram[iterations]++;
      }
      uint8_t color =
          (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);
      color *= color * color;
      bitmap.setPixel(x, y, 9, color, 9);
      if (color < min) {
        min = color;
      }
      if (color > max) {
        max = color;
      }
    }
  }
  cout << endl;
  int count = 0;
  for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
    cout << histogram[i] << " " << flush;
    count += histogram[i];
  }
  cout << endl << count << "; " << WIDTH * HEIGHT << endl;
  cout << min << ", " << max << endl;
  bitmap.write("test.bmp");
  cout << "Complete";
  return 0;
}
