#ifndef _DRAWER_TERMINAL_STRATEGY_INCLUDED_H_
#define _DRAWER_TERMINAL_STRATEGY_INCLUDED_H_

#include "draw_strategy.h"
#include "charmap.h"

class TerminalStrategy : public DrawStrategy {
public:
    TerminalStrategy() {}
    ~TerminalStrategy() {}

    inline void _draw(const std::vector<Point2D> &points) override
    {
        for (auto i : points) put(".", i.get_x(), i.get_i());
    }

    inline void _erase(const std::vector<Point2D> &points) override
    {
        for (auto i : points) put(" ", i.get_x(), i.get_i());
    }

    inline void _print(void) override {}

};

#endif // !_DRAWER_TERMINAL_STRATEGY_INCLUDED_H_
