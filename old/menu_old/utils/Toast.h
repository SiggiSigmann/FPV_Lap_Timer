#ifndef Toast_H
#define Toast_H

#include "../../periferal/display.h"

class Toast{
	private:
		String message;
		unsigned long activeTill;
		int length;
		byte xSpace;

	public:
		void setToast(String);
		void drawToast();
};

extern Toast* toast;

#endif