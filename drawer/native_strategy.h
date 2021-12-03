#ifndef _DRAWER_NATIVE_STRATEGY_INCLUDED_H_
#define _DRAWER_NATIVE_STRATEGY_INCLUDED_H_

#include "draw_strategy.h"
#include "charmap.h"

namespace drawminal {

class NativeStrategy : public DrawStrategy {
public:
    NativeStrategy() {}
    ~NativeStrategy() {}

private:

    inline void _draw(const std::vector<Point2D> &points) override
    {
        for (auto i : points) put(".", i.get_x(), i.get_y());
    }

    inline void _erase(const std::vector<Point2D> &points) override
    {
        for (auto i : points) put(" ", i.get_x(), i.get_y());
    }

    inline void _print(void) override {}

};

} // namespace drawminal

#endif // !_DRAWER_NATIVE_STRATEGY_INCLUDED_H_