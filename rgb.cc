#include "rgb.h"
namespace fractal {
RGB::RGB(double red, double green, double blue)
    : red_(red), green_(green), blue_(blue) {}
RGB RGB::operator-(const RGB& second) {
  return RGB(red_ - second.red_, green_ - second.green_, blue_ - second.blue_);
}
}  // namespace fractal