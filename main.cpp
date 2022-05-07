#include <iostream>
#include "drawminal.h"
#include "base/object2d.h"
// #include <unistd.h>

using namespace std;
using namespace drawminal;

int main()
{
    os::_init_instance(nullptr);
    Drawer dw(Drawer::DrawingStrategy::BUFFERED, {VTOPT_SCREEN_BUFFER_ALTERNATE, VTOPT_CURSOR_HIDE});
    shapes::Line ln(50, 50, 100, 50);
    shapes::Circle cr(50, 50, 10);
    shapes::Rect *rect = new Rect(50, 50, 10, 10);
    // shapes::FreeHand fh({{50, 40}, {100, 40}, {100, 30}, {120, 50}, {100, 70}, {100, 60}, {50, 60}, {50, 41}}, {255, 255, 255});
    // shapes::FreeHand fh2({{50, 40}, {51, 40}, {51, 41}, {52, 42}, {53, 43}, {53, 44}, {54, 45}, {55, 45}}, {255, 255, 255});
    shapes::FreeHand fh2(ln.get_bounds());
    // dw.draw(cr);
    // dw.draw(ln);
    // dw.print();
    base::Object2D obj("box", rect->get_bounds());
    delete rect;

    // dw.draw(rect);
    // dw.draw(obj);
    obj.add_animation("static", animation::Animation("box_static", {obj.get_bounds()}));
    auto box = obj;
    std::vector<std::vector<Point2D>> box_move;
    for (int i = 0; i < 30; ++i) {
        box_move.push_back(box.get_bounds());
        box.translate({1, 1});
    }
    obj.add_animation("move", animation::Animation("box_move", box_move));
    // dw.draw(obj2);
    // obj.translate({70, 20});
    // dw.draw(obj);
/*
    for (auto i : box_move) {
        for (auto j : i)
            std::cout << j;
        std::cout << std::endl;
        std::getchar();
    }
    std::getchar();
*/
    for (auto i : box_move) {
        dw.draw(i);
        dw.print();
        // usleep(33333);v
        Sleep(30);
        dw.erase(i);
    }

    std::getchar();
    return 0;
}
