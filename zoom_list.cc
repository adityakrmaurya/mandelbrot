#include "zoom_list.h"

namespace fractal {
ZoomList::ZoomList(int width, int height) : width_(width), height_(height) {}
void ZoomList::Add(const Zoom& zoom) { zooms.push_back(zoom); }
std::pair<double, double> ZoomList::DoZoom(int x, int y) {
  return std::pair<double, double>(0, 0);
}
}  // namespace fractal
