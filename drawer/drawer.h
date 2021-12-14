#ifndef _DRAWER_DRAWER_INCLUDED_H_
#define _DRAWER_DRAWER_INCLUDED_H_
#pragma once

#include <vector>
#include "draw_strategy.h"

namespace drawminal {

using namespace shapes;
using namespace base;
using namespace vterm;

class Drawer : public DrawerBase {
public:
    enum class DrawingStrategy;

	Drawer();
	Drawer(DrawingStrategy stg, const VTopt &opts);
	Drawer(DrawingStrategy stg, const VTopt &opts, short w_ratio, short h_ratio);
	~Drawer();

	void draw(const Object2D& object) const;
	void draw(const std::vector<Pixel2D>& pixels) const;
	void draw(const std::vector<Point2D>& points) const;
	void draw(const std::vector<Point3D>& points) const;
	void draw(const Shape2D& shape) const;
	// void draw(const std::vector<Pixel3D> &pixels) const;
	void erase(const std::vector<Point2D>& points) const;
	void erase(const std::vector<Point3D>& points) const;
	void erase(const Shape2D& shape) const;
	void print(void);
	void draw_rect(const Rect& rect, const Color& color);
	void fill_rect(const Rect& rect, const Color& color);
	// const void set_region(const UIComponent& uic, const gfx::Rect& rect);
	// const Region& get_region(const gfx::Rect& rect);

	enum class DrawingStrategy {
        BUFFERED,
        BUFFERED_COLOR,
        NATIVE,
        NATIVE_COLOR
    };

private:
    DrawStrategy *_strategy = nullptr;
    short _w_ratio = 2, _h_ratio = 4;
    int _linear_length;

    void _set_strategy(DrawingStrategy stg);
};

} // namespace drawminal

#endif // !_DRAWER_DRAWER_INCLUDED_H_
