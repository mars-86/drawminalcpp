#include "object2d.h"

namespace base {

Object2D::Object2D(const std::string &name, const std::vector<Point2D> &bounds)
    : Object(name), _bounds(bounds) {}

Object2D::~Object2D() {}

const std::vector<Point2D> &Object2D::get_bounds(void) const
{
    return _bounds;
}

} //namespace base

