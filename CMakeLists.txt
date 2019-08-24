cmake_minimum_required(VERSION 3.1)

project(edge-detection)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.56 REQUIRED COMPONENTS
  date_time filesystem program_options)

find_package(SDL2 REQUIRED)
include_directories(edge-detection ${SDL2_INCLUDE_DIRS})

add_executable(edge-detection src/main.cpp)
target_link_libraries(edge-detection ${Boost_LIBRARIES} ${SDL2_LIBRARIES})

install(TARGETS edge-detection)
