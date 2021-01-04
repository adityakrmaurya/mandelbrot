#include <math.h>

#include <iostream>
#include <memory>

#include "bitmap.h"
#include "mandelbrot.h"
#include "zoom_list.h"
using namespace std;
using namespace fractal;

int main() {
  const int kWidth = 800;
  const int kHeight = 600;
  ZoomList zoom_list(kWidth, kHeight);
  zoom_list.Add(Zoom(kWidth / 2, kHeight / 2, 4.0 / kWidth));
  Bitmap bitmap(kWidth, kHeight);
  unique_ptr<int[]> histogram(new int[Mandelbrot::kMaxIterations]{0});
  unique_ptr<int[]> iteration(new int[kWidth * kHeight]{0});
  // configuration phase
  for (int y = 0; y < kHeight; y++) {
    for (int x = 0; x < kWidth; x++) {
      // scaling hack:
      // the fractal values ranges from -1 to 1 on both axis
      double x_fractal = zoom_list.DoZoom(x, y).first;
      double y_fractal = zoom_list.DoZoom(x, y).second;
      int iterations = Mandelbrot::GetIterations(x_fractal, y_fractal);
      // increment the value of that iteration in the array
      iteration[x + y * kWidth] = iterations;
      if (iterations != Mandelbrot::kMaxIterations) {
        histogram[iterations]++;
      }
    }
  }
  // calculating total no of iterations not including those at MAX_ITERATION
  int total = 0;
  for (int i = 0; i < Mandelbrot::kMaxIterations; i++) {
    total += histogram[i];
  }
  // implementation phase
  for (int y = 0; y < kHeight; y++) {
    for (int x = 0; x < kWidth; x++) {
      int iterations = iteration[x + y * kWidth];
      double hue = 0.0;
      for (int i = 0; i < iterations; i++) {
        hue += ((double)histogram[i]) / total;
      }
      uint8_t red = 0;
      uint8_t green =
          (iterations == Mandelbrot::kMaxIterations ? 0 : pow(255, hue));
      uint8_t blue = 0;

      bitmap.SetPixel(x, y, red, green, blue);
    }
  }
  bitmap.Write("test.bmp");
  cout << "Complete";
  return 0;
}
