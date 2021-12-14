#include <iostream>
#include "drawminal.h"
#include "base/object2d.h"

using namespace std;
using namespace drawminal;

int main()
{
    Drawer dw(Drawer::DrawingStrategy::BUFFERED, {VTOPT_SCREEN_BUFFER_ALTERNATE, VTOPT_CURSOR_HIDE});
    shapes::Line ln(10, 10, 80, 40, {40, 10, 230});
    shapes::Circle cr(50, 50, 25, {130, 100, 30});
    shapes::Rect *rect = new Rect(50, 50, 10, 10, {33, 80, 127});
    // shapes::FreeHand fh({{50, 40}, {100, 40}, {100, 30}, {120, 50}, {100, 70}, {100, 60}, {50, 60}, {50, 41}}, {255, 255, 255});
    // shapes::FreeHand fh2({{50, 40}, {51, 40}, {51, 41}, {52, 42}, {53, 43}, {53, 44}, {54, 45}, {55, 45}}, {255, 255, 255});
    shapes::FreeHand fh2(ln.get_bounds(), {33, 80, 127});
    // dw.draw(cr);
    // dw.draw(ln);
    // dw.print();
    base::Object2D obj("box", rect->get_bounds());

    delete rect;

    // dw.draw(rect);
    dw.draw(obj);
    dw.print();

    std::getchar();
    return 0;
}
