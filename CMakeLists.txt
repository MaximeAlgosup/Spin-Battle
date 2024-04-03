# How to use with msys2: (Windows)
#   cmake -S . -B Build -G "MSYS Makefiles"
#   cd Build
#   make

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "g++")

project(
  Spin-Battle
  VERSION 1.0
  LANGUAGES CXX
)

find_package(Threads REQUIRED)

add_executable(Spin-Battle
    Src/main.cpp
    Src/arena/arena.cpp
    Src/spinner/spinner.cpp
    Src/spinner/player.cpp
    Src/spinner/bot.cpp
    Src/display/display.cpp
    Src/menu/menu.cpp
    Src/menu/selectMenu.cpp
    Src/menu/setting.cpp
    Src/menu/stadiumMenu.cpp
    Src/menu/themeMenu.cpp
    Src/menu/credit.cpp
    Src/party/party.cpp
)

target_include_directories(Spin-Battle
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Src"
    "${CMAKE_CURRENT_SOURCE_DIR}/Src/arena"
    "${CMAKE_CURRENT_SOURCE_DIR}/Src/spinner"
    "${CMAKE_CURRENT_SOURCE_DIR}/Src/display"
    "${CMAKE_CURRENT_SOURCE_DIR}/Src/menu"
    "${CMAKE_CURRENT_SOURCE_DIR}/Src/party"
)

target_link_libraries(Spin-Battle
  PRIVATE
    Threads::Threads
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)

target_compile_options(Spin-Battle
  PRIVATE
    -Wall -Wextra -pedantic -g -O2
)

set_target_properties(Spin-Battle
  PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
)

