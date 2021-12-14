#ifndef _DRAWMINAL_ANIMATION_SCENE_INCLUDED_H_
#define _DRAWMINAL_ANIMATION_SCENE_INCLUDED_H_

#include "../base/object2d.h"

namespace animation {

using namespace base;

class Scene {
public:
    Scene();
    ~Scene();

    void add(const Object2D &object);
    void play(void) const;

private:
    std::vector<Object2D> _objects;
};

} // namespace animation

#endif // _DRAWMINAL_ANIMATION_SCENE_INCLUDED_H_
