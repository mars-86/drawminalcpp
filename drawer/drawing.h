#ifndef _DRAWER_DRAWING_INCLUDED_H_
#define _DRAWER_DRAWING_INCLUDED_H_
#pragma once

#include <vector>
#include "../shapes/coords/point2d.h"
#include "../shapes/coords/point3d.h"

namespace drawminal {

template <typename T>
class Drawing {
public:
    Drawing();
    ~Drawing();

    const std::vector<T> get_points(void) const
    {
        return _points;
    }

    void set_points(std::vector<T> points)
    {
        _points = points;
    }

    int get_color(void) const
    {
        return _color;
    }

    void set_color(int color)
    {
        _color = color;
    }

private:
    std::vector<T> _points;
    int _color;
};

typedef Drawing<shapes::Point2D> Drawing2D;
typedef Drawing<shapes::Point3D> Drawing3D;

} // namespace drawminal

#endif // !_DRAWER_DRAWING_INCLUDED_H_
