#include "object.h"
#include <iostream>
namespace animation {

Object::Object(const std::string &name)
    : _name(name) {}

Object::Object(const std::string &name, const std::vector<Point2D> &bounds)
    : _name(name), _bounds(bounds)
{
    // _bounds.insert(_bounds.end(), bounds.begin(), bounds.end());
}

Object::Object(const std::string &name, const std::vector<Point3D> &bounds)
    : _name(name)
{}

Object::~Object() {}

void Object::add_animation(const std::string &name, const Animation &anim)
{
    _animations.insert({name, anim});
}

const std::string& Object::get_name(void) const
{
    return _name;
}

const std::vector<Point2D>& Object::get_bounds(void) const
{
    return _bounds;
}

} //namespace animation
