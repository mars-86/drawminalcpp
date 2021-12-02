#include "drawer.h"
#include "charmap.h"
#include <cmath>
#include <cstring>

namespace drawminal {

Drawer::Drawer()
	: _linear_length(get_width() * get_height())
{
    for (int i = 0; i < _linear_length - 1; ++i) _dwable += " ";
}

Drawer::Drawer(void *context, const VTopt &opts)
	: VTerm(opts), _linear_length(get_width() * get_height())
{
    for (int i = 0; i < _linear_length - 1; ++i) _dwable += " ";
}

Drawer::Drawer(void *context, const VTopt &opts, short w_ratio, short h_ratio)
	: VTerm(opts), _w_ratio(w_ratio), _h_ratio(h_ratio), _linear_length(get_width() * get_height())
{
    for (int i = 0; i < _linear_length - 1; ++i) _dwable += " ";
}

Drawer::~Drawer() {}

void Drawer::draw(const char *s, int x, int y)
{
    put(s, x, y);
}

void Drawer::draw(const std::vector<Point2D>& points)
{
    _draw(points);
}

/*
void Drawer::draw(const std::vector<Point2D>& points)
{
    for (auto i : points) set_buffer(i.get_x(), i.get_y());
    std::string s;
    for (auto i : get_screen_buffer()) s += (i ? u8"\u2550" : " ");
    std::cout << s;
    set_cursor_pos(1, 1);
}

void Drawer::draw(const std::vector<Point2D>& points)
{
    for (auto i : points) set_buffer(i.get_x(), i.get_y());
    std::string shape("");
    // for (auto i : get_screen_buffer()) s += (i ? u8"\u2550" : " ");
    auto sb = get_screen_buffer(points);
    for (int i = 0; i < sb.size(); ++i) {
        set_cursor_pos(points[i].get_x(), points[i].get_y());
        std::cout << (sb[i] ? u8"\u2550" : " ");
        // std::cout << sb[points] << std::flush;
    }
    set_cursor_pos(1, 1);

}
*/

void Drawer::draw(const Shape2D& shape)
{
    _draw(shape.get_bounds());
}

void Drawer::erase(const std::vector<Point2D>& points)
{
    _erase(points);
}

void Drawer::erase(const Shape2D& shape)
{
    _erase(shape.get_bounds());
}

void Drawer::print(void)
{
    std::string s;
    for (auto i : _buffer)
        s += (i ? braille_map[i] : " ");
    std::cout << s;
    set_cursor_pos(1, 1);
}

} // namespace drawminal
