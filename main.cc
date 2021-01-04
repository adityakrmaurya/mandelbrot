#include <iostream>
#include <memory>

#include "fractal_creator.h"
int main() {
  const int kWidth = 800;
  const int kHeight = 600;
  fractal::FractalCreator fractal_creator(kWidth, kHeight);
  fractal_creator.AddZoom(fractal::Zoom(302, kHeight - 190, 0.1));
  fractal_creator.AddZoom(fractal::Zoom(256, kHeight - 116, 0.2));
  fractal_creator.CalculateIteration();
  fractal_creator.CalculateTotalIterations();
  fractal_creator.DrawFractal();
  fractal_creator.WriteBitmap("test.bmp");
  std::cout << "Complete" << std::endl;
  return 0;
}
