#include "scene.h"

namespace animation {

Scene::Scene() {}

Scene::~Scene() {}

void Scene::add(const Object2D &object)
{
    _objects.push_back(object);
}

void Scene::play(void) const
{
    for (auto i : _objects) i.get_bounds();
    // return &_scenes;
}

} // namespace animation
