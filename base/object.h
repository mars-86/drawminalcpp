#ifndef _DRAWMINAL_BASE_OBJECT_INCLUDED_H_
#define _DRAWMINAL_BASE_OBJECT_INCLUDED_H_

#include "../animation/animation.h"
#include "../shapes/shapes.h"
#include <vector>

namespace base {

using namespace animation;
using namespace shapes;

class Object {
public:
    Object(const std::string &name);
    virtual ~Object();

    void add_animation(const std::string &name, const Animation &anim);
    const Animation &get_animation(const std::string &name) const;
    const Animation &get_animation(int position) const;
    bool is_animation_present(const std::string &name) const;
    const std::vector<std::pair<std::string, Animation>> &get_animations(void) const;
    const std::string &get_name(void) const;

    void set_outer_color(const Color &color);
    void set_inner_color(const Color &color);
    // const std::vector<shapes::Shape2D> get_frames(void) const;

private:
    std::string _name;
    Color _outer_color, _inner_color;
    std::vector<std::pair<std::string, Animation>> _animations;

};

} // namespace base

#endif // _DRAWMINAL_BASE_OBJECT_INCLUDED_H_
