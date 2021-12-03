#include "drawer.h"
#include "buffered_color_strategy.h"
#include "buffered_strategy.h"
#include "native_color_strategy.h"
#include "native_strategy.h"
#include "charmap.h"

namespace drawminal {

Drawer::Drawer()
	: _strategy(new BufferedStrategy), _linear_length(get_width() * get_height())
{
    // for (int i = 0; i < _linear_length - 1; ++i) _dwable += " ";
}

Drawer::Drawer(DrawingStrategy stg, const VTopt &opts)
	: VTerm(opts), _linear_length(get_width() * get_height())
{
    _set_strategy(stg);
    // for (int i = 0; i < _linear_length - 1; ++i) _dwable += " ";
}

Drawer::Drawer(DrawingStrategy stg, const VTopt &opts, short w_ratio, short h_ratio)
	: VTerm(opts), _w_ratio(w_ratio), _h_ratio(h_ratio), _linear_length(get_width() * get_height())
{
    _set_strategy(stg);
    // for (int i = 0; i < _linear_length - 1; ++i) _dwable += " ";
}

Drawer::~Drawer()
{
    if (_strategy) delete _strategy;
}

void Drawer::draw(const std::vector<Point2D>& points)
{
    _strategy->draw(points);
}

void Drawer::draw(const Shape2D& shape)
{
    _strategy->draw(shape.get_bounds());
}

void Drawer::erase(const std::vector<Point2D>& points)
{
    _strategy->erase(points);
}

void Drawer::erase(const Shape2D& shape)
{
    _strategy->erase(shape.get_bounds());
}

void Drawer::print(void)
{
    _strategy->print();
    set_cursor_pos(1, 1);
}

void Drawer::_set_strategy(DrawingStrategy stg)
{
    if (stg == DrawingStrategy::BUFFERED) _strategy = new BufferedStrategy;
    else if (stg == DrawingStrategy::BUFFERED_COLOR) _strategy = new BufferedColorStrategy;
    else if (stg == DrawingStrategy::NATIVE) _strategy = new NativeStrategy;
    else _strategy = new NativeColorStrategy;
}

} // namespace drawminal
