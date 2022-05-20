#include "scene.h"
#include <string>
#include <vector>

namespace animation {

Scene::Scene(Drawer &drawer)
    : _drawer(drawer), _fps(30), _type(this->SceneType::STATIC)
{}

Scene::Scene(Drawer &drawer, int fps)
    : _drawer(drawer), _fps(fps), _type(SceneType::STATIC)
{}

Scene::Scene(Drawer &drawer, SceneType type)
    : _drawer(drawer), _fps(30), _type(type)
{}

Scene::Scene(Drawer &drawer, int fps, SceneType type)
    : _drawer(drawer), _fps(fps), _type(type)
{}

Scene::~Scene() {}

void Scene::add(const Object2D &object)
{
    _objects.push_back(object);
}

void Scene::play(void)
{
    if (_type == SceneType::STATIC) {
        while (true) {
            _draw_objects();
            _drawer.print();
            _erase_objects();
        }
    } else { // TODO refac this block
        std::vector<std::vector<std::vector<Point2D>>> frames;
        for (auto i : _objects) {
            auto anim = i.get_animations();
            for (auto j : anim) frames.push_back(j.second.get_frames());
        }
        std::vector<std::pair<std::vector<std::vector<Point2D>>, std::pair<int, const int>>> its;

        for (auto i : frames)
            its.push_back(std::make_pair(i, std::make_pair(0, i.size()))); // TODO create custom types

        while (true) {
            for (auto i : its) _drawer.draw(i.first.at(i.second.first));

            _drawer.print();
            Sleep(1000 / _fps);

            for (auto &i : its) {
                auto it = i.second;
                _drawer.erase(i.first.at(it.first));
                ++i.second.first;
                if (it.first == it.second - 1) i.second.first = 0;
            }
        }
    }
}

void Scene::_draw_objects(void) const
{
    for (auto i : _objects) _drawer.draw(i);
}

void Scene::_erase_objects(void) const
{
    for (auto i : _objects) _drawer.erase(i);
}

} // namespace animation
