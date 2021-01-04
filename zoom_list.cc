#include "zoom_list.h"
namespace fractal {
ZoomList::ZoomList(int width, int height) : width_(width), height_(height) {}
// adds the new zoom to the zoom vector
// transform the axis or 2D plane
void ZoomList::Add(const Zoom& zoom) {
  zooms.push_back(zoom);
  x_center_ += (zoom.x_ - width_ / 2) * scale_;
  y_center_ += (zoom.y_ - height_ / 2) * scale_;
  scale_ *= zoom.scale_;
}
std::pair<double, double> ZoomList::DoZoom(int x, int y) {
  double x_fractal = (x - width_ / 2) * scale_ + x_center_;
  double y_fractal = (y - height_ / 2) * scale_ + y_center_;
  return std::pair<double, double>(x_fractal, y_fractal);
}
}  // namespace fractal
