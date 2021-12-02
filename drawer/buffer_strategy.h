#ifndef _DRAWER_BUFFER_STRATEGY_INCLUDED_H_
#define _DRAWER_BUFFER_STRATEGY_INCLUDED_H_

#include "draw_strategy.h"
#include "charmap.h"

namespace drawminal {

class BufferStrategy : public DrawStrategy {
public:
    BufferStrategy() {}
    ~BufferStrategy() {}

    inline void _draw(const std::vector<Point2D> &points) override
    {
        for (auto i : points) {
            int x = (i.get_x() - 1), y = (i.get_y() - 1), xr = x / _w_ratio, yr = y  / _h_ratio;
            // std::cout << "{" << (y % _h_ratio) << " " << (x % _w_ratio) << "} = " << pixel_map[y % _h_ratio][x % _w_ratio] << " ";
            _buffer[yr * get_width() + xr] |= pixel_map[y % _h_ratio][x % _w_ratio];
        }
    }

    inline void _erase(const std::vector<Point2D> &points) override
	{
        for (auto i : points) {
            int x = (i.get_x() - 1), y = (i.get_y() - 1), xr = x / _w_ratio, yr = y  / _h_ratio;
            // std::cout << "{" << (y % _h_ratio) << " " << (x % _w_ratio) << "} = " << pixel_map[y % _h_ratio][x % _w_ratio] << " ";
            _buffer[yr * get_width() + xr] &= ~pixel_map[y % _h_ratio][x % _w_ratio];
        }
	}

	inline void _print(void) override
	{
        std::string s;
        for (auto i : _buffer) s += (i ? braille_map[i] : " ");
        std::cout << s;
	}

};

} // namespace drawminal

#endif // !_DRAWER_BUFFER_STRATEGY_INCLUDED_H_
