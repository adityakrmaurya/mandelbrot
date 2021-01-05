#include <iostream>
#include <memory>

#include "fractal_creator.h"
#include "rgb.h"
int main() {
  const int kWidth = 800;
  const int kHeight = 600;
  fractal::FractalCreator fractal_creator(kWidth, kHeight);
  fractal_creator.AddRange(0.0, fractal::RGB(0, 25, 100));
  fractal_creator.AddRange(0.3, fractal::RGB(25, 100, 100));
  fractal_creator.AddRange(0.5, fractal::RGB(100, 25, 0));
  fractal_creator.AddRange(1.0, fractal::RGB(200, 100, 25));

  fractal_creator.Run("bitmap_image.bmp");
  std::cout << "Complete" << std::endl;
  return 0;
}
