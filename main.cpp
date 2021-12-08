#include <iostream>
#include "drawminal.h"

using namespace std;
using namespace drawminal;

int main()
{
    Drawer dw(Drawer::DrawingStrategy::NATIVE_COLOR, {VTOPT_SCREEN_BUFFER_ALTERNATE, VTOPT_CURSOR_HIDE});
    shapes::Line ln(10, 10, 80, 20, {40, 10, 230});
    shapes::Circle cr(50, 50, 25, {130, 100, 30});
    dw.draw(cr);
    dw.draw(ln);
    dw.print();

    std::getchar();
    return 0;
}
