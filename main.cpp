#include <iostream>
#include "drawminal.h"

using namespace std;
using namespace drawminal;

int main()
{
    Drawer dw(Drawer::DrawingStrategy::BUFFERED_COLOR, {VTOPT_SCREEN_BUFFER_ALTERNATE, VTOPT_CURSOR_HIDE});
    shapes::Line ln(10, 10, 80, 40, {40, 10, 230});
    shapes::Circle cr(50, 50, 25, {130, 100, 30});
    shapes::Rect rect(60, 60, 50, 30, {33, 80, 127});
    dw.draw(cr);
    dw.draw(ln);
    dw.print();

    dw.draw(rect);
    dw.print();

    std::getchar();
    return 0;
}
