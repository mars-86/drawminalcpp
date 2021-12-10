#ifndef _DRAWER_STREAM_STRATEGY_INCLUDED_H_
#define _DRAWER_STREAM_STRATEGY_INCLUDED_H_

#include "draw_strategy.h"
#include "charmap.h"

// FIX: inherit from buffered

namespace drawminal {

class StreamStrategy : public DrawStrategy {
public:
    StreamStrategy() {}
    ~StreamStrategy() {}

private:
    inline void _draw(const Shape2D &shape) override
    {
        auto points = shape.get_bounds();
        for (auto i : points) {
            int x = (i.get_x() - 1), y = (i.get_y() - 1), xr = x / _w_ratio, yr = y  / _h_ratio;
            // std::cout << "{" << (y % _h_ratio) << " " << (x % _w_ratio) << "} = " << pixel_map[y % _h_ratio][x % _w_ratio] << " ";
            _buffer[yr * get_width() + xr] |= pixel_map[y % _h_ratio][x % _w_ratio];
        }
    }

    inline void _erase(const Shape2D &shape) override
	{
        auto points = shape.get_bounds();
        for (auto i : points) {
            int x = (i.get_x() - 1), y = (i.get_y() - 1), xr = x / _w_ratio, yr = y  / _h_ratio;
            // std::cout << "{" << (y % _h_ratio) << " " << (x % _w_ratio) << "} = " << pixel_map[y % _h_ratio][x % _w_ratio] << " ";
            _buffer[yr * get_width() + xr] &= ~pixel_map[y % _h_ratio][x % _w_ratio];
        }
	}

	inline void _print(void) override
	{
        for (auto i : _buffer) std::cout << i;
	}

    std::ostream &operator<<(std::ostream &o, const Shape2D shape)
    {
        return o << &shape;
    }

};

} // namespace drawminal

#endif // !_DRAWER_BUFFERED_STRATEGY_INCLUDED_H_
