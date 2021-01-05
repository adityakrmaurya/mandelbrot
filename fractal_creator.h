#ifndef FRACTAL_CREATOR_H_
#define FRACTAL_CREATOR_H_
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "bitmap.h"
#include "mandelbrot.h"
#include "rgb.h"
#include "zoom_list.h"
namespace fractal {
class FractalCreator {
 private:
  int width_, height_, total_{0};
  unique_ptr<int[]> histogram_;
  unique_ptr<int[]> iteration_;
  Bitmap* bitmap_;
  ZoomList* zoom_list_;
  vector<int> ranges_;
  vector<RGB> colors_;
  vector<int> range_total_;
  bool first_range_{false};
  void CalculateIteration();
  void CalculateTotalIterations();
  void DrawFractal();
  void WriteBitmap(std::string name);
  void CalculateRangeTotal();
  int GetRange(int iterations) const;

 public:
  FractalCreator(int width, int height);
  void AddZoom(const Zoom& zoom);
  void Run(std::string);
  void AddRange(double range_end, RGB const& rgb);
  ~FractalCreator();
};
}  // namespace fractal
#endif