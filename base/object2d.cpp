#include "object2d.h"
#include <cmath>

namespace base {

Object2D::Object2D(const std::string &name, const std::vector<Point2D> &bounds)
    : Object(name), _origin(bounds.at(0)), _bounds(bounds) {}

Object2D::~Object2D() {}

const std::vector<Point2D> &Object2D::get_bounds(void) const
{
    return _bounds;
}

const Point2D &Object2D::get_origin(void) const
{
    return _origin;
}

void Object2D::translate(const Point2D &offset)
{
    auto curr_orig = get_origin();
    // const Point2D new_orig = {new_pos.get_x() - curr_orig.get_x(), new_pos.get_y() - curr_orig.get_y()};
#ifdef __DEBUG
    std::cout << "Translate before: \n";
    for (auto i : _bounds) std::cout << i;
    std::cout << std::endl;
#endif // __DEBUG
    // for (auto &i : _bounds) i += new_orig;//= 0; i < _bounds.size(); ++i)
    for (auto &i : _bounds) i += offset;
#ifdef __DEBUG
    std::cout << "Translate after: \n";
    for (auto i : _bounds) std::cout << i;
    std::cout << std::endl;
#endif // __DEBUG
    // _set_origin(new_orig);
}

void Object2D::rotate(int angle)
{

}

const Point2D Object2D::_get_center(void)
{
    int x_max = _bounds.at(0).get_x(), x_min = _bounds.at(0).get_x(), y_max = _bounds.at(0).get_y(), y_min = _bounds.at(0).get_y();
    for (auto i = _bounds.begin(); i < _bounds.end(); ++i) {
        int x = i->get_x(), y = i->get_y();
        if (x >= x_max) x_max = x;
        else if (x < x_min) x_min = x;
        if (y >= y_max) y_max = y;
        else if (y < y_min) y_min = y;
    }
#ifdef __DEBUG
    std::cout << "X_MAX: " << x_max << "X_MIN: " << x_min << "Y_MAX: " << y_max << "Y_MIN: " << y_min << std::endl;
#endif // __DEBUG
    return {x_max - ((x_max - x_min) / 2), y_max - ((y_max - y_min) / 2)};
}

void Object2D::_set_origin(const Point2D &new_orig)
{
    _origin = new_orig;
}

} //namespace base
