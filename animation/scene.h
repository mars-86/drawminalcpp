#ifndef _DRAWMINAL_ANIMATION_SCENE_INCLUDED_H_
#define _DRAWMINAL_ANIMATION_SCENE_INCLUDED_H_

#include "frame.h"

class Scene {
public:
    Scene();
    ~Scene();

    void add_scene(const Frame &frames);
    const Scene &get_scene(void) const;
private:
    std::vector<Frame> _scenes;
};

#endif // _DRAWMINAL_ANIMATION_SCENE_INCLUDED_H_
