#ifndef ZOOM_H_
#define ZOOM_H_

namespace fractal {
struct Zoom {
  int m_x;
  int m_y;
  double m_scale{0.0};
  Zoom(int x, int y, double scale) : m_x(x), m_y(y), m_scale(scale) {}
};
}  // namespace fractal
#endif
