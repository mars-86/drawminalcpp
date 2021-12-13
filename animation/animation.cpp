#include "animation.h"

namespace animation {

Animation::Animation(const std::string &name)
    : _name(name) {}

Animation::Animation(const std::string &name, const std::vector<std::vector<Point2D>> &frames)
    : _name(name), _frames(frames) {}

Animation::~Animation() {}

void Animation::add_frame(const std::vector<Point2D> &frame)
{
    _frames.push_back(frame);
}

const std::vector<std::vector<Point2D>> &Animation::get_frames(void) const
{
    return _frames;
}

const std::string &Animation::get_name(void) const
{
    return _name;
}

} // namespace animation
