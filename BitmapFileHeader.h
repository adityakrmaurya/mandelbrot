// contains information about the type, size and layout of a device independent
// bitmap file
#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_
#include <cstdint>
using namespace std;
namespace fractal {
struct BitmapFileHeader {
  // signature
  char header[2]{'B', 'M'};
  // size of the file in bytes
  int32_t fileSize;
  // unused (=0)
  int32_t reserved{0};
  // offset from beginning of the file to the beginning of the bitmap data
  int32_t dataOffset;
};
} // namespace fractal
#endif