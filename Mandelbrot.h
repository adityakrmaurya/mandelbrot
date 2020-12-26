#ifndef MANDELBROT_H_
#define MANDELBROT_H_
namespace fractal {

class Mandelbrot {
public:
  static const int MAX_ITERATIONS = 1000;
  Mandelbrot();
  ~Mandelbrot();
  static int getIterations(double x, double y);
};
} // namespace fractal
#endif
