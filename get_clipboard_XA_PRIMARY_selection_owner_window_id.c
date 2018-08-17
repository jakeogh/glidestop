// adapted from http://michael.toren.net/mirrors/doc/X-copy+paste.txt

// gcc -L/usr/X11R6/lib -lX11 get_clipboard_XA_PRIMARY_selection_owner_window_id.c -o get_clipboard_XA_PRIMARY_selection_owner_window_id


#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <stdio.h>

main()
{
	Display *dpy = XOpenDisplay(NULL);

	Window Sown;

	Sown = XGetSelectionOwner(dpy, XA_PRIMARY);
	printf("%i\n", (int)Sown);
}



/*
 if I make a selection in firefox, and then run this, I get a window ID, feeding that window id to:
 xprop -id (windowid)

 The result looks like:


GDK_TIMESTAMP_PROP(GDK_TIMESTAMP_PROP) = 0x61
WM_CLIENT_LEADER(WINDOW): window id # 0x400001
_NET_WM_PID(CARDINAL) = 24774
WM_LOCALE_NAME(STRING) = "en_US.UTF-8"
WM_CLIENT_MACHINE(STRING) = "localhost"
WM_NORMAL_HINTS(WM_SIZE_HINTS):
                program specified size: 10 by 10
WM_PROTOCOLS(ATOM): protocols  WM_DELETE_WINDOW, WM_TAKE_FOCUS, _NET_WM_PING, _NET_WM_SYNC_REQUEST
WM_ICON_NAME(STRING) = "Firefox"
_NET_WM_ICON_NAME(UTF8_STRING) = "Firefox"
WM_NAME(STRING) = "Firefox"
_NET_WM_NAME(UTF8_STRING) = "Firefox"


if I do the same thing to a xterm window, the result looks like:





*/



