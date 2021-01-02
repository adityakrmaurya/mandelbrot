#include <math.h>

#include <iostream>
#include <memory>

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
using namespace std;
using namespace fractal;

int main() {
  int const WIDTH = 800;
  int const HEIGHT = 600;
  Bitmap bitmap(WIDTH, HEIGHT);
  unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
  unique_ptr<int[]> iteration(new int[WIDTH * HEIGHT]{0});
  // configuration phase
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      // scaling hack:
      // the fractal values ranges from -1 to 1 on both axis
      double xFractal = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT;
      double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;
      int iterations = Mandelbrot::getIterations(xFractal, yFractal);
      // increment the value of that iteration in the array
      iteration[x + y * WIDTH] = iterations;
      if (iterations != Mandelbrot::MAX_ITERATIONS) {
        histogram[iterations]++;
      }
    }
  }
  // calculating total no of iterations not including those at MAX_ITERATION
  int total = 0;
  for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
    total += histogram[i];
  }

  // implementation phase
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      int iterations = iteration[x + y * WIDTH];
      double hue = 0.0;
      for (int i = 0; i < iterations; i++) {
        hue += ((double)histogram[i]) / total;
      }
      uint8_t red = 0;
      uint8_t green =
          (iterations == Mandelbrot::MAX_ITERATIONS ? 0 : pow(255, hue));
      uint8_t blue = 0;

      bitmap.setPixel(x, y, red, green, blue);
    }
  }
  bitmap.write("test.bmp");
  cout << "Complete";
  return 0;
}
