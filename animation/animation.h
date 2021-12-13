#ifndef _DRAWMINAL_ANIMATION_ANIMATION_INCLUDED_H_
#define _DRAWMINAL_ANIMATION_ANIMATION_INCLUDED_H_

#include <string>
#include <vector>
#include "../shapes/lib/coords/point2d.h"
#include "../shapes/lib/coords/point3d.h"

namespace animation {

using namespace shapes;

class Animation {
public:
    Animation(const std::string &name);
    Animation(const std::string &name, const std::vector<std::vector<Point2D>> &frames);
    ~Animation();

    void add_frame(const std::vector<Point2D> &frame);
    const std::vector<std::vector<Point2D>> &get_frames(void) const;
    const std::string &get_name(void) const;

private:
    std::string _name;
    std::vector<std::vector<Point2D>> _frames;

};

} // namespace animation

#endif // _DRAWMINAL_ANIMATION_ANIMATION_INCLUDED_H_
