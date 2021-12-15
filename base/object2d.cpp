#include "object2d.h"

namespace base {

Object2D::Object2D(const std::string &name, const std::vector<Point2D> &bounds)
    : Object(name), _bounds(bounds) {}

Object2D::~Object2D() {}

const std::vector<Point2D> &Object2D::get_bounds(void) const
{
    return _bounds;
}

void Object2D::translate(const Point2D &new_pos)
{
    for (auto i : _bounds) i += new_pos;
}

void Object2D::rotate(int angle)
{

}

} //namespace base

