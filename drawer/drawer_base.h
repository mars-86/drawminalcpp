#ifndef _DRAWER_DRAWER_BASE_INCLUDED_H_
#define _DRAWER_DRAWER_BASE_INCLUDED_H_
#pragma once

#include <vector>
#include "drawing.h"
#include "../vterm/vterm.h"
#include "../shapes/shapes.h"

namespace drawminal {

using namespace vterm;

class DrawerBase : public VTerm {
public:
    DrawerBase() {}
	DrawerBase(const VTopt &opts) : VTerm(opts) {}
	virtual ~DrawerBase() {}

private:
    short _w_ratio = 2, _h_ratio = 4;
    int _linear_length;

};

} // namespace drawminal

#endif // !_DRAWER_DRAWER_BASE_INCLUDED_H_
