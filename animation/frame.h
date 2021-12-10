#ifndef _DRAWMINAL_ANIMATION_FRAME_INCLUDED_H_
#define _DRAWMINAL_ANIMATION_FRAME_INCLUDED_H_

#include <vector>
#include "../shapes/base/shape2d.h"

class Frame {
public:
    Frame();
    ~Frame();

    void add_frame(const shapes::Shape2D &shape);
    // const std::vector<shapes::Shape2D> get_frames(void) const;
private:
    std::vector<shapes::Shape2D*> _frames;
};

#endif // _DRAWMINAL_ANIMATION_FRAME_INCLUDED_H_
