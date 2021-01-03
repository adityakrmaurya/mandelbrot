#include "mandelbrot.h"

#include <complex>
using namespace std;
namespace fractal {
Mandelbrot::Mandelbrot() {}
Mandelbrot::~Mandelbrot() {}
int Mandelbrot::GetIterations(double x, double y) {
  complex<double> z = 0;
  complex<double> c(x, y);
  int iterations = 0;
  while (iterations < kMaxIterations) {
    z = z * z + c;
    if (abs(z) > 2) break;
    iterations++;
  }
  return iterations;
}
}  // namespace fractal
