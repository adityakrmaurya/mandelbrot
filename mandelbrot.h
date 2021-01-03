#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace fractal {
class Mandelbrot {
 public:
  static const int kMaxIterations = 1000;
  Mandelbrot();
  ~Mandelbrot();
  static int GetIterations(double x, double y);
};
}  // namespace fractal
#endif
