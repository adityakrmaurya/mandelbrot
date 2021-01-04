#include "fractal_creator.h"

namespace fractal {
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
void FractalCreator::CalculateTotalIterations() {
  // calculating total no of iterations not including those at MAX_ITERATION
  for (int i = 0; i < Mandelbrot::kMaxIterations; i++) {
    total_ += histogram_[i];
  }
}
void FractalCreator::DrawFractal() {
  // implementation phase
  for (int y = 0; y < height_; y++) {
    for (int x = 0; x < width_; x++) {
      int iterations = iteration_[x + y * width_];
      double hue = 0.0;
      for (int i = 0; i < iterations; i++) {
        hue += ((double)histogram_[i]) / total_;
      }
      uint8_t red = 0;
      uint8_t green =
          (iterations == Mandelbrot::kMaxIterations ? 0 : pow(255, hue));
      uint8_t blue = 0;

      bitmap_->SetPixel(x, y, red, green, blue);
    }
  }
}
void FractalCreator::AddZoom(const Zoom& zoom) { zoom_list_->Add(zoom); }
void FractalCreator::WriteBitmap(std::string name) { bitmap_->Write(name); }
}  // namespace fractal