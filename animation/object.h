#ifndef _DRAWMINAL_ANIMATION_OBJECT_INCLUDED_H_
#define _DRAWMINAL_ANIMATION_OBJECT_INCLUDED_H_

#include "animation.h"
#include <map>

namespace animation {

using namespace shapes;

class Object {
public:
    Object(const std::string &name);
    Object(const std::string &name, const std::vector<Point2D> &bounds);
    Object(const std::string &name, const std::vector<Point3D> &bounds);
    ~Object();

    void add_animation(const std::string &name, const Animation &anim);
    const std::string &get_name(void) const;

    const std::vector<Point2D> &get_bounds(void) const;

    // const std::vector<shapes::Shape2D> get_frames(void) const;

private:
    std::string _name;
    std::vector<Point2D> _bounds;
    std::map<std::string, Animation> _animations;

};

} // namespace animation

#endif // _DRAWMINAL_ANIMATION_OBJECT_INCLUDED_H_
