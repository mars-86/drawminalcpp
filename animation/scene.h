#ifndef _DRAWMINAL_ANIMATION_SCENE_INCLUDED_H_
#define _DRAWMINAL_ANIMATION_SCENE_INCLUDED_H_

#include "object.h"

namespace animation {

class Scene {
public:
    Scene();
    ~Scene();

    void add(const Object &object);
    void play(void) const;

private:
    std::vector<Object> _objects;
};

} // namespace animation

#endif // _DRAWMINAL_ANIMATION_SCENE_INCLUDED_H_
