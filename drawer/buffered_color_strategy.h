#ifndef _DRAWER_BUFFERED_COLOR_STRATEGY_INCLUDED_H_
#define _DRAWER_BUFFERED_COLOR_STRATEGY_INCLUDED_H_

#include "draw_strategy.h"
#include "charmap.h"

namespace drawminal {

using namespace shapes;

class BufferedColorStrategy : public DrawStrategy {
public:
    BufferedColorStrategy() { _buffer.push_back(-1); /* buffer's end flag */ }
    ~BufferedColorStrategy() {}

private:

    inline void _draw(const Object &object) override
    {
        _base_draw(object.get_bounds());
    }

    inline void _draw(const Shape2D &shape) override
    {
        auto points = shape.get_bounds(); auto color = shape.get_color();
        for (auto i : points) {
            int x = (i.get_x() - 1), y = (i.get_y() - 1), xr = x / _w_ratio, yr = y  / _h_ratio;
            // std::cout << "{" << (y % _h_ratio) << " " << (x % _w_ratio) << "} = " << pixel_map[y % _h_ratio][x % _w_ratio] << " ";
            _buffer[yr * get_width() + xr] |= ((color.get_color() << 8) | pixel_map[y % _h_ratio][x % _w_ratio]);
        }
    }

    inline void _erase(const Shape2D &shape) override
	{
        _base_erase(shape.get_bounds());
	}

	// FIX: bad color in pixels when two or more shapes are drawing in same points.
	// print " " until a char is found then print char then repeat till buffer's end.
	inline void _print(void) override
	{
        int i = 0, c;
        while (true) {
            std::string s;
            while (!_buffer[i]) s += " ", ++i;
            std::cout << s;
            if (_buffer[i] == -1) break;
            while (_buffer[i] && (c = _buffer[i] & 0xFF) > -1) {
                text_color(
                    (_buffer[i] & rgba_r_mask) >> rgba_r_shift,
                    (_buffer[i] & rgba_g_mask) >> rgba_g_shift,
                    (_buffer[i] & rgba_b_mask) >> rgba_b_shift);
                std::cout << braille_map[c];
                ++i;
            }
        }
        text_format(vterm::text::DEFAULT);
    }

};

} // namespace drawminal

#endif // !_DRAWER_BUFFERED_COLOR_STRATEGY_INCLUDED_H_
