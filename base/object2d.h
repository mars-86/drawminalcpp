#ifndef _DRAWMINAL_BASE_OBJECT_2D_INCLUDED_H_
#define _DRAWMINAL_BASE_OBJECT_2D_INCLUDED_H_

#include "object.h"

namespace base {

using namespace shapes;

class Object2D : public Object {
public:
    Object2D(const std::string &name, const std::vector<Point2D> &bounds);
    ~Object2D();

    const std::vector<Point2D> &get_bounds(void) const;
    // const std::vector<shapes::Shape2D> get_frames(void) const;

private:
    std::vector<Point2D> _bounds;

};

} // namespace base

#endif // _DRAWMINAL_BASE_OBJECT_2D_INCLUDED_H_

