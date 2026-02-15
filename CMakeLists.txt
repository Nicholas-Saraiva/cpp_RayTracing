cmake_minimum_required(VERSION 3.10)
project(RayTracer)

set(CMAKE_CXX_STANDARD 11)

set(SRC
	src/main.cpp
	src/Tuple.cpp
	src/Color.cpp
	src/Canvas.cpp
)

include_directories(include)

add_executable(raytracer ${SRC})
