#ifndef ZOOM_H_
#define ZOOM_H_

namespace fractal {
struct Zoom {
  int x_;
  int y_;
  double scale_{0.0};
  Zoom(int x, int y, double scale) : x_(x), y_(y), scale_(scale) {}
};
}  // namespace fractal
#endif
