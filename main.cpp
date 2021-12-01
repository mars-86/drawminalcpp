#include <iostream>
#include "drawminal/drawminal.h"
#include "shapes/shapes.h"

using namespace std;

int main()
{
    drawminal::Drawminal dm(2, 4);

    shapes::Line ln(30, 50, 150, 80, {0, 0, 0});
    dm.draw(ln);
    dm.print();

    std::getchar();
    return 0;
}
