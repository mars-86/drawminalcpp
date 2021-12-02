#ifndef _DRAWER_DRAWER_INCLUDED_H_
#define _DRAWER_DRAWER_INCLUDED_H_
#pragma once

#include <vector>
#include "../shapes/base/shape2d.h"
#include "../shapes/coords/point2d.h"
#include "../shapes/coords/point3d.h"
#include "../shapes/2d/line.h"
#include "../shapes/2d/rect.h"
#include "../vterm/vterm.h"

extern const unsigned int pixel_map[4][2];

namespace drawminal {

using namespace shapes;
using namespace vterm;

class Drawer : public VTerm {
public:
	Drawer();
	Drawer(void *context, const VTopt &opts);
	Drawer(void *context, const VTopt &opts, short w_ratio, short h_ratio);
	~Drawer();

	void draw(const char *s, int x, int y);
	void draw(const char *s, int x, int y, int z);
	void draw(const std::vector<Point2D>& points);
	void draw(const std::vector<Point3D>& points);
	void draw(const Shape2D& shape);
	void erase(int x, int y);
	void erase(int x, int y, int z);
	void erase(const std::vector<Point2D>& points);
	void erase(const std::vector<Point3D>& points);
	void erase(const Shape2D& shape);
	void print(void);
	void draw_rect(const Rect& rect, const Color& color);
	void fill_rect(const Rect& rect, const Color& color);
	// const void set_region(const UIComponent& uic, const gfx::Rect& rect);
	// const Region& get_region(const gfx::Rect& rect);

private:
    short _w_ratio = 2, _h_ratio = 4;
	short _dwable_w, _dwable_h;
	int _linear_length;
	std::string _dwable;

	inline void _draw(const std::vector<Point2D> points)
	{
        for (auto i : points) {
            int x = (i.get_x() - 1), y = (i.get_y() - 1), xr = x / _w_ratio, yr = y  / _h_ratio;
            // std::cout << "{" << (y % _h_ratio) << " " << (x % _w_ratio) << "} = " << pixel_map[y % _h_ratio][x % _w_ratio] << " ";
            _buffer[yr * get_width() + xr] |= pixel_map[y % _h_ratio][x % _w_ratio];
        }
	}

	inline void _erase(const std::vector<Point2D> points)
	{
        for (auto i : points) {
            int x = (i.get_x() - 1), y = (i.get_y() - 1), xr = x / _w_ratio, yr = y  / _h_ratio;
            // std::cout << "{" << (y % _h_ratio) << " " << (x % _w_ratio) << "} = " << pixel_map[y % _h_ratio][x % _w_ratio] << " ";
            _buffer[yr * get_width() + xr] &= ~pixel_map[y % _h_ratio][x % _w_ratio];
        }
	}
};

} // namespace drawminal

#endif // !_DRAWER_DRAWER_INCLUDED_H_
