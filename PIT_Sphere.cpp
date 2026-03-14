#include <iostream>
#include "Tuple.hpp"
#include "Terminal.hpp"
#include "Math.hpp"
#include "Color.hpp"
#include "Canvas.hpp"
#include "Matrix.hpp"
#include "Ray.hpp"
#include "Object.hpp"
#include "Intersection.hpp"
#include <cmath>


int main(){
	std::cout << "\n--- Rendering Chapter 5 Silhouette ---" << std::endl;

    const int canvas_pixels = 1000;
    rt::Canvas canvas(canvas_pixels, canvas_pixels);
    auto ray_origin = rt::Tuple::point(0, 0, -5);

    float wall_z = 10.0f;
    float wall_size = 7.0f;
    float pixel_size = wall_size / canvas_pixels;
    float half = wall_size / 2.0f;

    rt::Sphere shape;
    //shape.inv_transform = (rt::Matrix::Scaling(1, 0.5, 1)).Inverse();
    //shape.inv_transform = (rt::Matrix::multiply_matrix(rt::Matrix::Rotation_z(45), rt::Matrix::Scaling(0.5, 1, 1))).Inverse();

    auto color = rt::Color(1, 0, 0);
    for (int y = 0; y < canvas_pixels; ++y) {
        float world_y = half - (pixel_size * y);

        for (int x = 0; x < canvas_pixels; ++x) {
            float world_x = -half + (pixel_size * x);

            auto target = rt::Tuple::point(world_x, world_y, wall_z);
            auto r = rt::Ray(ray_origin, (target - ray_origin).normalize());

            auto xs = rt::Ray::intersect(shape, r);

            if (xs.hit().obj != nullptr)
			{
                canvas.write_pixel(x, y, color);
            }
        }
    }

    canvas.canvas_to_ppm();
    std::cout << "Status: " << rt::term::GREEN << "Success! " <<
        rt::term::RESET << "Image saved to build/img_<number>.ppm" << std::endl;
}
