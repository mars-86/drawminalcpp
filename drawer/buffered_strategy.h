#ifndef _DRAWER_BUFFERED_STRATEGY_INCLUDED_H_
#define _DRAWER_BUFFERED_STRATEGY_INCLUDED_H_

#include "draw_strategy.h"
#include "charmap.h"

namespace drawminal {

class BufferedStrategy : public DrawStrategy {
public:
    BufferedStrategy() {}
    ~BufferedStrategy() {}

private:
    inline void _draw(const Object &object) override
    {
        _base_draw(object.get_bounds());
    }

    inline void _draw(const Shape2D &shape) override
    {
        _base_draw(shape.get_bounds());
    }

    inline void _erase(const Shape2D &shape) override
	{
        _base_erase(shape.get_bounds());
	}

	inline void _print(void) override
	{
        std::string s;
        for (auto i : _buffer) s += (i ? braille_map[i] : " ");
        std::cout << s;
	}

};

} // namespace drawminal

#endif // !_DRAWER_BUFFERED_STRATEGY_INCLUDED_H_
