#ifndef _DRAWER_DRAW_STRATEGY_INCLUDED_H_
#define _DRAWER_DRAW_STRATEGY_INCLUDED_H_
#pragma once

#include "../vterm/vterm.h"
#include "../shapes/base/shape2d.h"
#include "../shapes/coords/point2d.h"

namespace drawminal {

using namespace vterm;
using namespace shapes;

class DrawStrategy : public VTerm {
public:
    DrawStrategy() : _w_ratio(2), _h_ratio(4) {}
    virtual ~DrawStrategy() {}

    void draw(const std::vector<Point2D> &points) {
        _draw(points);
    }

    void erase(const std::vector<Point2D> &points) {
        erase(points);
    }

    void print(void) {
        _print();
    }

protected:
    short _w_ratio, _h_ratio;

private:
    virtual inline void _draw(const std::vector<Point2D> &points) = 0;
    virtual inline void _erase(const std::vector<Point2D> &points) = 0;
    virtual inline void _print(void) = 0;
};

} // namespace drawminal

#endif // !_DRAWER_DRAW_STRATEGY_INCLUDED_H_
