#ifndef _DRAWMINAL_ANIMATION_SCENE_INCLUDED_H_
#define _DRAWMINAL_ANIMATION_SCENE_INCLUDED_H_

#include "../base/object2d.h"
#include "../drawer/drawer.h"

namespace animation {

using namespace base;
using namespace drawminal;

class Scene {
public:
    enum class SceneType;

    Scene(Drawer &drawer);
    Scene(Drawer &drawer, int fps);
    Scene(Drawer &drawer, SceneType type);
    Scene(Drawer &drawer, int fps, SceneType type);
    ~Scene();

    void add(const Object2D &object);
    void play(void);
    void set_fps(int fps);

    enum class SceneType {
        STATIC,
        ANIMATED
    };

private:
    std::vector<Object2D> _objects;
    int _fps;
    SceneType _type;
    Drawer _drawer;

    void _draw_objects(void) const;
    void _erase_objects(void) const;
};

} // namespace animation

#endif // _DRAWMINAL_ANIMATION_SCENE_INCLUDED_H_
