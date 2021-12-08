#ifndef _DRAWER_BUFFERED_COLOR_STRATEGY_INCLUDED_H_
#define _DRAWER_BUFFERED_COLOR_STRATEGY_INCLUDED_H_

#include "draw_strategy.h"
#include "charmap.h"

namespace drawminal {

class BufferedColorStrategy : public DrawStrategy {
public:
    BufferedColorStrategy() {}
    ~BufferedColorStrategy() {}

private:
    inline void _draw(const Shape2D &shape) override
    {
        auto points = shape.get_bounds(); auto color = shape.get_color();
        int x, y, xr, yr;
        for (auto i : points) {
            int x = (i.get_x() - 1), y = (i.get_y() - 1), xr = x / _w_ratio, yr = y  / _h_ratio;
            // std::cout << "{" << (y % _h_ratio) << " " << (x % _w_ratio) << "} = " << pixel_map[y % _h_ratio][x % _w_ratio] << " ";
            _buffer[yr * get_width() + xr] |= pixel_map[y % _h_ratio][x % _w_ratio];
        }
        xr = (points[0].get_x() - 1) / _w_ratio, yr = (points[0].get_y() -1) / _h_ratio;
        int v_temp = _buffer[yr * get_width() + xr];
        _buffer[yr * get_width() + xr] |= (color.get_color() | v_temp);
    }

    inline void _erase(const Shape2D &shape) override
	{
        _base_erase(shape.get_bounds());
	}

	inline void _print(void) override
	{
        std::string s;
        for (auto i : _buffer) s += (i ? braille_map[i] : " ");
        text_format(vterm::text::FG_BLUE);
        std::cout << s;
        text_format(vterm::text::DEFAULT);
	}

};

} // namespace drawminal

#endif // !_DRAWER_BUFFERED_COLOR_STRATEGY_INCLUDED_H_
