// specifies the dimensions, comperssion type and color format for the bitmap
#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>
#pragma pack(push, 1)

namespace fractal {
struct BitmapInfoHeader {
  // size of header
  int32_t header_size{40};
  // horizontal width of bitmap in pixels
  int32_t width;
  // vertical width of bitmap in pixels
  int32_t height;
  // numbers of planes
  int16_t planes{1};
  // store palette entry information. Number of possible colors. 24 = 24bit RGB
  int16_t bits_per_pixel{24};
  // Type of compression:
  // a) 0 = BI_RGB no compression
  // b) 1 = BI_RLE8 8bit RLE encoding
  // c) 2 = BI_RLE4 4bit RLE encoding
  int32_t compression{0};
  // size of image
  int32_t dataSize{0};
  // Pixels/meter
  int32_t horizontal_resolution{2400};
  // Pixels/meter
  int32_t vertical_resolution{2400};
  // number of actually used colors
  int32_t colors{0};
  // number of important colors. 0 = all
  int32_t important_colors{0};
};
}  // namespace fractal
#pragma pack(pop)
#endif
