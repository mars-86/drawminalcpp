#include "object.h"

namespace base {

Object::Object(const std::string &name)
    : _name(name) {}

Object::~Object() {}

void Object::add_animation(const std::string &name, const Animation &anim)
{
    _animations.insert({name, anim});
}

const std::string& Object::get_name(void) const
{
    return _name;
}

void Object::set_outer_color(const Color &color)
{
    _outer_color = color;
}

void Object::set_inner_color(const Color &color)
{
    _inner_color = color;
}

} //namespace base
