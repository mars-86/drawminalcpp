#ifndef _DRAWER_NATIVE_STRATEGY_INCLUDED_H_
#define _DRAWER_NATIVE_STRATEGY_INCLUDED_H_

#include "draw_strategy.h"
#include "charmap.h"

namespace drawminal {

class NativeStrategy : public DrawStrategy {
public:
    NativeStrategy() {}
    ~NativeStrategy() {}

private:

    inline void _draw(const Object &object) override
    {
        _base_draw(object.get_bounds());
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
            for (auto j : i->get_bounds()) {
                int yr = (j.get_y() - 1) / _h_ratio, xr = (j.get_x()) / _w_ratio;
                put(braille_map[_buffer[yr * get_width() + xr]].c_str(), xr, yr);
            }
        }
    }

};

} // namespace drawminal

#endif // !_DRAWER_NATIVE_STRATEGY_INCLUDED_H_
