# How to use with mingw: (Windows)
#   cmake -S . -B Build -G "MinGW Makefiles"
#   cd Build
#   mingw32-make

# How to use with msys2: (Windows)
#   cmake -S . -B Build -G "MSYS Makefiles"
#   cd Build
#   make
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "g++")

project(
  Spin-Battle
  VERSION 0.1
  LANGUAGES CXX
)

find_package(Threads REQUIRED)

add_executable(Spin-Battle
    Src/main.cpp
    Src/map/arena.cc
    Src/spinner/spinner.cc
    Src/spinner/player.cc
    Src/spinner/bot.cc
)

target_include_directories(Spin-Battle
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Src"
    "${CMAKE_CURRENT_SOURCE_DIR}/Src/map"
    "${CMAKE_CURRENT_SOURCE_DIR}/Src/spinner"
)

target_link_libraries(Spin-Battle
  PRIVATE
    Threads::Threads
    sfml-graphics
    sfml-window
    sfml-system
)

target_compile_options(Spin-Battle
  PRIVATE
    -Wall -Wextra -pedantic -g -O2
)

set_target_properties(Spin-Battle
  PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)
