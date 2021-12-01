#ifndef _DRAWMINAL_DRAWMINAL_INCLUDED_H_
#define _DRAWMINAL_DRAWMINAL_INCLUDED_H_
#pragma once

#include <vector>
#include "../shapes/base/shape2d.h"
#include "../shapes/coords/point2d.h"
#include "../shapes/coords/point3d.h"
#include "../shapes/2d/line.h"
#include "../shapes/2d/rect.h"
#include "../vterm/vterm.h"

namespace drawminal {

using namespace shapes;
using namespace vterm;

constexpr unsigned int pixel_map[4][2] = {
    {0x01, 0x08},
    {0x02, 0x10},
    {0x04, 0x20},
    {0x40, 0x80}
};

class Drawminal : public VTerm {
public:
	Drawminal(short w_ratio, short h_ratio);
	Drawminal(void *context, short w_ratio, short h_ratio);
	~Drawminal();

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
    short _w_ratio, _h_ratio;
	short _dwable_w, _dwable_h;
	int _linear_length;
	std::string _dwable;
};

} // namespace drawminal

#endif // !_DRAWMINAL_DRAWMINAL_INCLUDED_H_
