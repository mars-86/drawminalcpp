#ifndef _DRAWER_DRAW_STRATEGY_INCLUDED_H_
#define _DRAWER_DRAW_STRATEGY_INCLUDED_H_
#pragma once

#include "drawer_base.h"

namespace drawminal {

using namespace vterm;
using namespace shapes;

class DrawStrategy : public DrawerBase {
public:
    DrawStrategy() : _w_ratio(2), _h_ratio(4) {}
    virtual ~DrawStrategy() {}

    void draw(const std::vector<Point2D> &points)
    {
        _draw(points);
    }

    void erase(const std::vector<Point2D> &points)
    {
        erase(points);
    }

    void set_color(int color)
    {
        _color = color;
    }

    short get_color(void) const
    {
        return _color;
    }

    void print(void)
    {
        _print();
    }

protected:
    short _w_ratio, _h_ratio;
    short _color = 7;

private:
    virtual inline void _draw(const std::vector<Point2D> &points) = 0;
    virtual inline void _erase(const std::vector<Point2D> &points) = 0;
    virtual inline void _print(void) = 0;
};

} // namespace drawminal

#endif // !_DRAWER_DRAW_STRATEGY_INCLUDED_H_
