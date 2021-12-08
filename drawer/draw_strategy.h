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

    void draw(const Shape2D &shape)
    {
        _draw(shape);
    }

    void erase(const Shape2D &shape)
    {
        erase(shape);
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
    std::vector<const Shape2D*> _shape_buffer;

    inline void _base_draw(std::vector<Point2D> &points)
    {
        for (auto i : points) {
            int x = (i.get_x() - 1), y = (i.get_y() - 1), xr = x / _w_ratio, yr = y  / _h_ratio;
            // std::cout << "{" << (y % _h_ratio) << " " << (x % _w_ratio) << "} = " << pixel_map[y % _h_ratio][x % _w_ratio] << " ";
            _buffer[yr * get_width() + xr] |= pixel_map[y % _h_ratio][x % _w_ratio];
        }
    }

    inline void _base_erase(std::vector<Point2D> &points)
    {
        for (auto i : points) {
            int x = (i.get_x() - 1), y = (i.get_y() - 1), xr = x / _w_ratio, yr = y  / _h_ratio;
            // std::cout << "{" << (y % _h_ratio) << " " << (x % _w_ratio) << "} = " << pixel_map[y % _h_ratio][x % _w_ratio] << " ";
            _buffer[yr * get_width() + xr] &= ~pixel_map[y % _h_ratio][x % _w_ratio];
        }
    }

private:
    virtual inline void _draw(const Shape2D &shape) = 0;
    virtual inline void _erase(const Shape2D &shape) = 0;
    virtual inline void _print(void) = 0;

};

} // namespace drawminal

#endif // !_DRAWER_DRAW_STRATEGY_INCLUDED_H_
