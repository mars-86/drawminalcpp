#include <iostream>
#include "drawminal.h"

using namespace std;
using namespace drawminal;

int main()
{
    Drawer dw(Drawer::DrawingStrategy::BUFFERED_COLOR, {VTOPT_SCREEN_BUFFER_ALTERNATE, VTOPT_CURSOR_HIDE});

    shapes::Line ln(10, 10, 80, 20, {0, 0, 0});
    dw.draw(ln);
    dw.print();

    std::getchar();
    return 0;
}
