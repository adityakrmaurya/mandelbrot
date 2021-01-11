// contains information about the type, size and layout of a device independent
// bitmap file
#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_
#include <cstdint>
#pragma pack(push, 1)
namespace fractal {
struct BitmapFileHeader {
  // signature
  char header[2]{'B', 'M'};
  // size of the file in bytes
  int32_t file_size;
  // unused (=0)
  int32_t reserved{0};
  // offset from beginning of the file to the beginning of the bitmap data
  int32_t data_offset;
};
}  // namespace fractal
#pragma pack(pop)
#endif
 