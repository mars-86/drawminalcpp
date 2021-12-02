#include "drawer.h"
#include "buffer_strategy.h"
#include "charmap.h"
#include <cmath>
#include <cstring>

namespace drawminal {

Drawer::Drawer()
	: _linear_length(get_width() * get_height())
{
    // for (int i = 0; i < _linear_length - 1; ++i) _dwable += " ";
}

Drawer::Drawer(void *context, const VTopt &opts)
	: VTerm(opts), _linear_length(get_width() * get_height())
{
    // for (int i = 0; i < _linear_length - 1; ++i) _dwable += " ";
    _strategy = new BufferStrategy;
}

Drawer::Drawer(void *context, const VTopt &opts, short w_ratio, short h_ratio)
	: VTerm(opts), _w_ratio(w_ratio), _h_ratio(h_ratio), _linear_length(get_width() * get_height())
{
    // for (int i = 0; i < _linear_length - 1; ++i) _dwable += " ";
}

Drawer::~Drawer() {}

void Drawer::draw(const std::vector<Point2D>& points)
{
    _strategy->draw(points);
    // _draw(points);
}

void Drawer::draw(const Shape2D& shape)
{
    _strategy->draw(shape);
}

void Drawer::erase(const std::vector<Point2D>& points)
{
    _strategy->erase(points);
}

void Drawer::erase(const Shape2D& shape)
{
    _strategy->erase(shape);
}

void Drawer::print(void)
{
    _strategy->print();
    set_cursor_pos(1, 1);
}

} // namespace drawminal
