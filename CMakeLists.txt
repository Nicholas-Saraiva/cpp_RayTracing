cmake_minimum_required(VERSION 3.10)
project(RayTracer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(RAYTRACER_CORE_SRC
	src/core/Tuple.cpp
	src/core/Color.cpp
	src/core/Matrix.cpp
	src/render/Canvas.cpp
	src/render/Ray.cpp
	src/render/Intersection.cpp
)

add_library(raytracer_core ${RAYTRACER_CORE_SRC})
target_include_directories(raytracer_core PUBLIC
	include
	include/core
	include/render
	include/scene
	include/util
)

add_executable(raytracer PIT_Sphere.cpp)
target_link_libraries(raytracer PRIVATE raytracer_core)

set_target_properties(raytracer_core raytracer PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO
)
