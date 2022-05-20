#include "object.h"
#include <algorithm>

namespace base {

Object::Object(const std::string &name)
    : _name(name) {}

Object::~Object() {}

void Object::add_animation(const std::string &name, const Animation &anim)
{
    if (is_animation_present(name)) return;
    _animations.push_back(std::make_pair(name, anim));
}

const Animation& Object::get_animation(const std::string &name) const
{
    auto anim = std::find_if(
        _animations.begin(), _animations.end(), [&name](const std::pair<std::string, Animation>&elem){return elem.first == name;});
    if (anim == _animations.end())
        throw "Animation do not exists";
    return anim->second;
}

const Animation& Object::get_animation(int position) const
{
    if (position > _animations.size() - 1)
        throw "Animation do not exists";
    auto anim = _animations.at(position);
    return anim.second;
}

bool Object::is_animation_present(const std::string &name) const
{
    auto anim = std::find_if(
        _animations.begin(), _animations.end(), [&name](const std::pair<std::string, Animation>&elem){return elem.first == name;});
    return anim != _animations.end();
}

const std::vector<std::pair<std::string, Animation>>& Object::get_animations(void) const
{
    return _animations;
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
