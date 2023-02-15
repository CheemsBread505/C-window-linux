//to compile the app
//gcc window_text.c -o window_text -lX11 -g

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Display *display = XOpenDisplay(NULL);

    if (display == NULL) {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    int screen_num = DefaultScreen(display);
    Window root_window = RootWindow(display, screen_num);
    unsigned long border_color = BlackPixel(display, screen_num);
    unsigned long background_color = WhitePixel(display, screen_num);
    Window window = XCreateSimpleWindow(display, root_window, 0, 0, 200, 200, 2, border_color, background_color);

    XStoreName(display, window, "Texts");

    XSelectInput(display, window, ExposureMask | KeyPressMask);
    XMapWindow(display, window);

    XEvent event;
    while (1) {
        XNextEvent(display, &event);
        if (event.type == Expose) {
            XFontStruct *font_info;
            GC gc = DefaultGC(display, screen_num);
            font_info = XLoadQueryFont(display, "fixed");
            if (font_info == NULL) {
                fprintf(stderr, "Error loading font\n");
                exit(1);
            }
            XSetFont(display, gc, font_info->fid);
            char *msg = "Hello, World!";
            XDrawString(display, window, gc, 50, 50, msg, strlen(msg));
        }
    }

    XDestroyWindow(display, window);
    XCloseDisplay(display);

    return 0;
}
