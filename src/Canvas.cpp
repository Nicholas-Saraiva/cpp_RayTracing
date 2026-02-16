#include "Canvas.hpp"
#include <string>
#include <bits/stdc++.h>

using namespace std;

static string	get_unique_filename(const string& base_name);
static int	scale(float value);

namespace rt {
	Canvas::Canvas(int w, int h)
		: width(w), height(h), pixels(w * h, Color(0, 0, 0)) {};

	Color	Canvas::pixel_at(const int x, const int y) const {
		if (x > 0 && x < width && y > 0 && y < height)
			return (this->pixels[(y * width) + x]);
		return (Color());
	}

	void	Canvas::write_pixel(const int x, const int y, const Color& color) {
		if (x > 0 && x < width && y > 0 && y < height)
			this->pixels[(y * width) + x] = color;
	}

	void	Canvas::canvas_to_ppm() const {
		string		file_name = get_unique_filename("img.ppm");
		string		current_line, line = "";
		ofstream	out(file_name);
		int			r, g, b;
		Color		pixel;

		if (!out.is_open())
			throw (std::runtime_error("Error: out doesn't open"));
		out << "P3\n" << width << " " << height << "\n255\n";
		for (int y = 0; y < this->height; y++)
		{
			for (int x = 0; x < this->width; x++)
			{
				pixel = this->pixel_at(x, y);
				r = scale(pixel.r);
				g = scale(pixel.g);
				b = scale(pixel.b);
				int	color[3] = {r, g, b};

				for (int i = 0; i < 3; i++) {
					string	s = to_string(color[i]);

					if (current_line.size() + s.size() + 1 > 70) {
						line += current_line + '\n';
						current_line = "";
					}
					if (!current_line.empty())
						current_line += " ";
					current_line += s;
				}
			}
			line += current_line + '\n';
			current_line = "";
		}
		out << line << endl;
	}
}

static string	get_unique_filename(const string& base_name) {
	ifstream	file(base_name);
	if (!file.is_open())
		return (base_name);
	file.close();
	file.clear();

	size_t	pos = base_name.find_last_of('.');
	string	name = (pos == string::npos) ? base_name : base_name.substr(0, pos);
	string	ext = (pos == string::npos) ? "" : base_name.substr(pos, base_name.length() - pos);
	string	res;
	int	counter = 1;

	while (true) {
		res = name + "_" + to_string(counter) + ext;
		file.open(res);
		if (!file.is_open())
			break ;
		file.close();
		file.clear();
		counter++;
	}
	return (res);
}

static int	scale(float value) {
	int	result = static_cast<int>(std::round(value * 255.0f));

	if (result < 0);
		return (0);
	if (result > 255)
		return (255);
	return (result);
}
