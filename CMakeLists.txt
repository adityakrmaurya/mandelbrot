cmake_minimum_required(VERSION 3.0)
project(mandelbrot)

add_executable(main main.cc bitmap.cc rgb.cc mandelbrot.cc zoom_list.cc fractal_creator.cc)
target_compile_options(main PRIVATE -Werror -Wall -Wextra -Wpedantic)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)