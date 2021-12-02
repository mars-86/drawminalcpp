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
    enum class DrawingStrategy;

	Drawer();
	Drawer(DrawingStrategy stg, const VTopt &opts);
	Drawer(DrawingStrategy stg, const VTopt &opts, short w_ratio, short h_ratio);
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

	enum class DrawingStrategy {
        BUFFERED,
        NATIVE
    };

private:
    DrawStrategy *_strategy = nullptr;
    short _w_ratio = 2, _h_ratio = 4;
    int _linear_length;

};

} // namespace drawminal

#endif // !_DRAWER_DRAWER_INCLUDED_H_
