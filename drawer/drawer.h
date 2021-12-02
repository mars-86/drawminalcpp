#ifndef _DRAWER_DRAWER_INCLUDED_H_
#define _DRAWER_DRAWER_INCLUDED_H_
#pragma once

#include <vector>
#include "draw_strategy.h"
#include "../shapes/coords/point3d.h"
#include "../shapes/2d/line.h"
#include "../shapes/2d/rect.h"

namespace drawminal {

using namespace shapes;
using namespace vterm;

class Drawer : public VTerm {
public:
	Drawer();
	Drawer(void *context, const VTopt &opts);
	Drawer(void *context, const VTopt &opts, short w_ratio, short h_ratio);
	~Drawer();

	void draw(const std::vector<Point2D>& points);
	void draw(const std::vector<Point3D>& points);
	void draw(const Shape2D& shape);
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
    int _linear_length;
	DrawStrategy *_strategy = nullptr;

};

} // namespace drawminal

#endif // !_DRAWER_DRAWER_INCLUDED_H_
