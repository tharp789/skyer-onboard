cmake_minimum_required(VERSION 3.14)
project(tests)

# Ensure Release build for performance
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# High-performance compile options
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-O3 -march=native -ffast-math)
endif()

# Required packages
find_package(ament_cmake REQUIRED)
find_package(mavsdk REQUIRED)

# Include and link C++ libraries
target_include_directories(send_mission PRIVATE
    ${mavsdk_INCLUDE_DIRS}
)

ament_package()