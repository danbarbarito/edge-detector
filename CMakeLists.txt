cmake_minimum_required(VERSION 3.1)

project(edge-detection)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.56 REQUIRED COMPONENTS
             date_time filesystem program_options)
add_executable(edge-detection src/main.cpp)
target_link_libraries(edge-detection ${Boost_LIBRARIES})

install(TARGETS edge-detection)
