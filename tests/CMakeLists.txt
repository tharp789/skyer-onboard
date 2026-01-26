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
find_package(MAVSDK REQUIRED)

add_executable(send_mission send_mission.cpp)

# Include and link C++ libraries
target_include_directories(send_mission PRIVATE
    ${mavsdk_INCLUDE_DIRS}
)

target_include_directories(send_mission PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../mavlink/generated
)

target_link_libraries(send_mission PRIVATE MAVSDK::mavsdk)