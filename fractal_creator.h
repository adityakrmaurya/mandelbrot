#ifndef FRACTAL_CREATOR_H_
#define FRACTAL_CREATOR_H_
#include <cmath>
#include <memory>
#include <string>

#include "bitmap.h"
#include "mandelbrot.h"
#include "zoom_list.h"
namespace fractal {
class FractalCreator {
 private:
  int width_, height_, total_{0};
  unique_ptr<int[]> histogram_;
  unique_ptr<int[]> iteration_;
  Bitmap* bitmap_;
  ZoomList* zoom_list_;

 public:
  FractalCreator(int width, int height);
  ~FractalCreator();
  void AddZoom(const Zoom& zoom);
  void CalculateIteration();
  void CalculateTotalIterations();
  void DrawFractal();
  void WriteBitmap(std::string name);
};
}  // namespace fractal
#endif