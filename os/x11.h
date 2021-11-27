#ifndef OS_X11_H
#define OS_X11_H

#ifdef __linux__

// #include <X11/Xlib.h>
#include <unistd.h>
#include "platform.h"

namespace os {

void *get_std_handle(unsigned long handle);
void set_console_output_fm(unsigned int format);
int get_container_size(void *stdh, ContainerSize *cs);
void set_console_font(void *stdh, const wchar_t *name, int width, int height);
void set_console_mode(void *stdh, unsigned long mode, long *m);

void *_init_instance(ContainerSize* cs);
bool _change_window_message_filter_es(void *handle);

// int _init_event_handler(void);
// int _open_default_display(void);
// Display* _get_display_name(void);
// const char* _get_display_name(void);
// int _get_kb_mode(void);

} // namespace os

#endif // __linux__

#endif // OS_X11_H
