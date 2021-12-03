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
        // osstream << _buffer
	}

};

} // namespace drawminal

#endif // !_DRAWER_BUFFERED_STRATEGY_INCLUDED_H_
