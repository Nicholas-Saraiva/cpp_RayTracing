#pragma once
#include <vector>
#include "Color.hpp"

namespace rt {
	class Canvas {
	public:
		int	width, height;
		std::vector<Color> pixels;

		Canvas(int w, int h);

		void	write_pixel(const int x, const int y, const Color& color);
		Color	pixel_at(const int x, const int y) const;

	};
}
