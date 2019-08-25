cmake_minimum_required(VERSION 3.1)

project(edge-detection)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.56 REQUIRED COMPONENTS
  date_time filesystem program_options)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(edge-detection src/main.cpp src/edge_detector.cpp)
target_link_libraries(edge-detection ${Boost_LIBRARIES} sfml-graphics)

install(TARGETS edge-detection)
