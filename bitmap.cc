#include "bitmap.h"

#include <fstream>

#include "bitmap_file_header.h"
#include "bitmap_info_header.h"

using namespace std;

namespace fractal {
Bitmap::Bitmap(int width, int height)
    : width_(width),
      height_(height),
      p_pixels_(new uint8_t[width * height * 3]{}) {}

bool Bitmap::Write(std::string filename) {
  BitmapFileHeader file_header;
  BitmapInfoHeader info_header;
  file_header.file_size = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) +
                          width_ * height_ * 3;
  file_header.data_offset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
  info_header.width = width_;
  info_header.height = height_;
  ofstream file;
  file.open(filename, ios::out | ios::binary);
  if (!file) {
    return false;
  }
  file.write((char *)&file_header, sizeof(file_header));
  file.write((char *)&info_header, sizeof(info_header));
  file.write((char *)p_pixels_.get(), width_ * height_ * 3);

  file.close();
  if (!file) {
    return false;
  }
  return true;
}
// x and y are like coordinate plane points
void Bitmap::SetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
  int c;

  uint8_t *pPixel = p_pixels_.get();
  pPixel += (3 * y) * width_ + (3 * x);
  pPixel[0] = blue;
  pPixel[1] = green;
  pPixel[2] = red;
}

Bitmap::~Bitmap() {}
}  // namespace fractal
