#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_
#include <vector>

#include "zoom.h"
namespace fractal {
class ZoomList {
 private:
  int height_{0};
  int width_{0};
  std::vector<Zoom> zooms;
  double x_center_{0}, y_center_{0}, scale_{1};

 public:
  ZoomList(int width, int height);
  void Add(const Zoom& zoom);
  std::pair<double, double> DoZoom(int x, int y);
};
}  // namespace fractal
#endif
