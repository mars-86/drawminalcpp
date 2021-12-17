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
    const Point2D &get_origin(void) const;
    // const std::vector<shapes::Shape2D> get_frames(void) const;
    void translate(const Point2D &new_pos);
    void rotate(int angle);

private:
    Point2D _origin;
    std::vector<Point2D> _bounds;

    const Point2D _get_center(void);
    void _set_origin(const Point2D &new_orig);

};

} // namespace base

#endif // _DRAWMINAL_BASE_OBJECT_2D_INCLUDED_H_

