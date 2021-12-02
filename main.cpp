#include <iostream>
#include "drawminal.h"

using namespace std;

int main()
{
    drawminal::Drawer dw(nullptr, {VTOPT_SCREEN_BUFFER_ALTERNATE, VTOPT_CURSOR_HIDE});

    shapes::Line ln(10, 50, 80, 80, {0, 0, 0});
    dw.draw(ln);
    dw.print();

    std::getchar();
    return 0;
}
