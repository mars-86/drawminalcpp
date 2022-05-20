#ifndef _DRAWER_PIXEL_INCLUDED_H_
#define _DRAWER_PIXEL_INCLUDED_H_
#pragma once

#include <vector>
#include "../shapes/lib/coords/point2d.h"
#include "../shapes/lib/coords/point3d.h"
#include "../shapes/lib/color/color.h"

namespace drawminal {

using namespace shapes;

class Pixel2D : public Point2D {
public:
    Pixel2D(short x, short y) : Point2D(x, y), _color({0, 0, 0}) {};
    Pixel2D(short x, short y, const Color color) : Point2D(x, y), _color(color) {};
    ~Pixel2D() {};

    int get_color(void)
    {
        return _color.get_rgb_color();
    }

    void set_color(int r, int g, int b)
    {
        _color.set_red(r);
        _color.set_green(g);
        _color.set_blue(b);
    }

private:
    Color _color;
};

} // namespace drawminal

#endif // !_DRAWER_PIXEL_INCLUDED_H_
