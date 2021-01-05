#ifndef RGB_H_
#define RGB_H_
namespace fractal {
struct RGB {
  double red_, green_, blue_;
  RGB(double, double, double);
  RGB operator-(const RGB&);
};
}  // namespace fractal

#endif