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
	: DrawerBase(opts), _linear_length(get_width() * get_height())
{
    _set_strategy(stg);
    // for (int i = 0; i < _linear_length - 1; ++i) _dwable += " ";
}

Drawer::Drawer(DrawingStrategy stg, const VTopt &opts, short w_ratio, short h_ratio)
	: DrawerBase(opts), _w_ratio(w_ratio), _h_ratio(h_ratio), _linear_length(get_width() * get_height())
{
    _set_strategy(stg);
    // for (int i = 0; i < _linear_length - 1; ++i) _dwable += " ";
}

Drawer::~Drawer()
{
    if (_strategy) delete _strategy;
}

void Drawer::draw(const std::vector<Pixel2D>& pixels) const
{
    // _strategy->draw(drawing.get_points());
}
/*
void Drawer::draw(const Drawing3D &drawing) const
{
    // _strategy->draw(drawing.get_points());
}
*/
void Drawer::draw(const std::vector<Point2D>& points) const
{
    // _strategy->draw(points);
}

void Drawer::draw(const Object2D &object) const
{
    _strategy->draw(object);
}

void Drawer::draw(const Shape2D& shape) const
{
    _strategy->draw(shape);
}

void Drawer::erase(const std::vector<Point2D>& points) const
{
    // _strategy->erase(points);
}

void Drawer::erase(const Shape2D& shape) const
{
    _strategy->erase(shape);
}

void Drawer::print(void)
{
    set_cursor_pos(1, 1);
    _strategy->print();
}

void Drawer::_set_strategy(DrawingStrategy stg)
{
    if (stg == DrawingStrategy::BUFFERED) _strategy = new BufferedStrategy;
    else if (stg == DrawingStrategy::BUFFERED_COLOR) _strategy = new BufferedColorStrategy;
    else if (stg == DrawingStrategy::NATIVE) _strategy = new NativeStrategy;
    else _strategy = new NativeColorStrategy;
}

} // namespace drawminal
