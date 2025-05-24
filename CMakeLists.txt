# 5 below latest version on Debian (23/05/2025)
cmake_minimum_required(VERSION 3.26)

project(
  shellac-engine
  VERSION 0.0.1
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
