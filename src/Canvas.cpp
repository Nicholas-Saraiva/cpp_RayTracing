#include "Canvas.hpp"

namespace rt {
	Canvas::Canvas(int w, int h)
		: width(w), height(h), pixels(w * h, Color(0, 0, 0)) {};

	Color	Canvas::pixel_at(const int x, const int y) const {
		if (x > 0 && x < width && y > 0 && y < height)
			return (this->pixels[(1 +  y) * x]);
		return (Color());
	}

	void	Canvas::write_pixel(const int x, const int y, const Color& color) {
		if (x > 0 && x < width && y > 0 && y < height)
			this->pixels[(1 +  y) * x] = color;
	}
}
