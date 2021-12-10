#include "frame.h"

Frame::Frame() {}

Frame::~Frame() {}

void Frame::add_frame(const shapes::Shape2D &shape)
{
    _frames.push_back(shape);
}
/*
const std::vector<shapes::Shape2D> Frame::get_frames(void) const
{
    return _frames;
}*/
