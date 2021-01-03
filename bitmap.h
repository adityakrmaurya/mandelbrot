#ifndef BITMAP_H_
#define BITMAP_H_
#include <cstdint>
#include <memory>
#include <string>
using namespace std;

namespace fractal {
class Bitmap {
 private:
  int width_{0};
  int height_{0};
  unique_ptr<uint8_t[]> p_pixels_{nullptr};

 public:
  Bitmap(int width, int height);
  void SetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
  bool Write(std::string filename);
  ~Bitmap();
};
}  // namespace fractal

#endif
