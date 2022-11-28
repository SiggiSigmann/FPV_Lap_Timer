#ifndef MENUENTRY_H
#define MENUENTRY_H

#include <Arduino.h>

struct MenuEntry{
	String text;
	short type;
	byte actionId;
};
/*
type:
	0 : invoe method
	1 : info
	2 : value change

*/
#endif