#ifndef _DRAWMINAL_VTERM_COMMAND_INCLUDED_H_
#define _DRAWMINAL_VTERM_COMMAND_INCLUDED_H_
#pragma once

#include "sequences.h"

namespace vterm {

class Command {
public:
	Command() {}

	~Command() {}

	virtual inline void set_cursor_visibility(const char *visibility)
	{
		std::cout << visibility;
	}

	virtual inline void set_cursor_pos(const char pos, short n)
	{
		switch (pos){
		case 'U':
			std::cout << VTERM_CURSOR_POSITION_UP(n);
			break;
		case 'D':
			std::cout << VTERM_CURSOR_POSITION_DOWN(n);
			break;
		case 'F':
			std::cout << VTERM_CURSOR_POSITION_FWARD(n);
			break;
		case 'B':
			std::cout << VTERM_CURSOR_POSITION_BWARD(n);
			break;
		default:
			;
		}
	}

	virtual inline void set_cursor_pos(short x, short y)
	{
		std::cout << VTERM_ESCAPE << "[" << y << ";" << x << "H";
	}

	virtual inline void set_cursor_pos(int x, int y)
	{
		std::cout << VTERM_ESCAPE << "[" << y << ";" << x << "H";
	}

	virtual inline void set_screen_buffer(const char* s_buffer)
	{
		std::cout << s_buffer;
	}

	virtual inline void set_charset(const char* charset)
	{
		std::cout << charset;
	}

	virtual inline void set_icon_title(const char* title)
	{
		std::cout << VTERM_ESCAPE << "]0;" << title << VTERM_BELL;
	}

	virtual inline void set_title(const char* title)
	{
		std::cout << VTERM_ESCAPE << "]2;" << title << VTERM_BELL;
	}

};

} // namespace vterm

#endif // !_DRAWMINAL_VTERM_COMMAND_INCLUDED_H_
