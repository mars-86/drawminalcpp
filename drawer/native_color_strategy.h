#ifndef _DRAWER_NATIVE_COLOR_STRATEGY_INCLUDED_H_
#define _DRAWER_NATIVE_COLOR_STRATEGY_INCLUDED_H_

#include "draw_strategy.h"
#include "charmap.h"

namespace drawminal {

class NativeColorStrategy : public DrawStrategy {
public:
    NativeColorStrategy() {}
    ~NativeColorStrategy() {}

private:
    inline void _draw(const std::vector<Point2D> &points) override
    {
        _base_draw(points);
    }

    inline void _erase(const std::vector<Point2D> &points) override
    {
        _base_erase(points);
    }

    inline void _draw(const Object2D &object) override
    {
        _base_draw(object.get_bounds());
    }

    inline void _erase(const Object2D &object) override
    {
        _base_erase(object.get_bounds());
    }

    inline void _draw(const Shape2D &shape) override
    {
        _shape_buffer.push_back(&shape);
        _base_draw(shape.get_bounds());
    }

    inline void _erase(const Shape2D &shape) override
    {
        _base_erase(shape.get_bounds());
    }

    // FIX: some pixels missing.
    inline void _print(void) override
    {
        for (auto i : _shape_buffer) {
            // auto rgb = i->get_color();
            // text_color(rgb.get_red(), rgb.get_green(), rgb.get_blue());
            for (auto j : i->get_bounds()) {
                int yr = (j.get_y() - 1) / _h_ratio, xr = (j.get_x()) / _w_ratio;
                put(braille_map[_buffer[ yr * get_width() + xr]].c_str(), xr, yr);
            }
        }
        text_format(vterm::text::DEFAULT);
    }

};

} // namespace drawminal

#endif // !_DRAWER_NATIVE_COLOR_STRATEGY_INCLUDED_H_
