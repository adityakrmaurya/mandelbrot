#include "fractal_creator.h"

namespace fractal {

void FractalCreator::AddRange(double range_end, RGB const& rgb) {
  ranges_.push_back(range_end * Mandelbrot::kMaxIterations);
  colors_.push_back(rgb);
  if (first_range_) {
    range_total_.push_back(0);
  }
  first_range_ = true;
}
void FractalCreator::AddZoom(const Zoom& zoom) { zoom_list_->Add(zoom); }
void FractalCreator::Run(std::string name) {
  // AddZoom(fractal::Zoom(302, height_ - 190, 0.1));
  // AddZoom(fractal::Zoom(256, height_ - 116, 0.2));
  CalculateIteration();
  CalculateTotalIterations();
  CalculateRangeTotal();
  DrawFractal();
  WriteBitmap(name);
}
FractalCreator::FractalCreator(int width, int height) {
  width_ = width;
  height_ = height;
  histogram_ = unique_ptr<int[]>(new int[width_ * height_]{0});
  iteration_ = unique_ptr<int[]>(new int[width_ * height_]{0});
  bitmap_ = new Bitmap(width_, height_);
  zoom_list_ = new ZoomList(width_, height_);
  zoom_list_->Add(Zoom(width_ / 2, height_ / 2, 4.0 / width_));
}
FractalCreator::~FractalCreator() {}
void FractalCreator::CalculateIteration() {
  // configuration phase
  for (int y = 0; y < height_; y++) {
    for (int x = 0; x < width_; x++) {
      double x_fractal = zoom_list_->DoZoom(x, y).first;
      double y_fractal = zoom_list_->DoZoom(x, y).second;
      int iterations = Mandelbrot::GetIterations(x_fractal, y_fractal);
      // increment the value of that iteration in the array
      iteration_[x + y * width_] = iterations;
      if (iterations != Mandelbrot::kMaxIterations) {
        histogram_[iterations]++;
      }
    }
  }
}
void FractalCreator::CalculateRangeTotal() {
  int range_index = 0;
  for (int i = 0; i < Mandelbrot::kMaxIterations; i++) {
    int pixels = histogram_[i];
    if (i >= ranges_[range_index + 1]) {
      range_index++;
    }
    range_total_[range_index] += pixels;
  }
}
void FractalCreator::CalculateTotalIterations() {
  // calculating total no of iterations not including those at MAX_ITERATION
  for (int i = 0; i < Mandelbrot::kMaxIterations; i++) {
    total_ += histogram_[i];
  }
}
void FractalCreator::DrawFractal() {
  // implementation phase
  RGB start_color(0, 0, 40);
  RGB end_color(43, 255, 240);

  for (int y = 0; y < height_; y++) {
    for (int x = 0; x < width_; x++) {
      int iterations = iteration_[x + y * width_];
      int range = GetRange(iterations);
      int range_total = range_total_[range];
      int range_start = ranges_[range];
      RGB& start_color = colors_[range];
      RGB& end_color = colors_[range + 1];
      RGB color_diff = end_color - start_color;
      int total_pixels = 0;
      for (int i = range_start; i < iterations; i++) {
        total_pixels += histogram_[i];
      }
      uint8_t red =
          (iterations == Mandelbrot::kMaxIterations
               ? 0
               : (start_color.red_ +
                  color_diff.red_ * (double)total_pixels / range_total));
      uint8_t green =
          (iterations == Mandelbrot::kMaxIterations
               ? 0
               : (start_color.green_ +
                  color_diff.green_ * (double)total_pixels / range_total));
      uint8_t blue =
          (iterations == Mandelbrot::kMaxIterations
               ? 0
               : (start_color.blue_ +
                  color_diff.blue_ * (double)total_pixels / range_total));

      bitmap_->SetPixel(x, y, red, green, blue);
    }
  }
}
void FractalCreator::WriteBitmap(std::string name) { bitmap_->Write(name); }
int FractalCreator::GetRange(int iterations) const {
  int range = 0;
  for (size_t i = 1; i < ranges_.size(); ++i) {
    range = i;
    if (ranges_[i] > iterations) {
      break;
    }
  }
  range--;
  return range;
}
}  // namespace fractal