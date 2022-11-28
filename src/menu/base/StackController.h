#ifndef SATCK_CONTROLLER_H
#define SATCK_CONTROLLER_H

#include "../ui/Window.h"
#include <LinkedList.h>

class Window;

class StackController{
	private:
		LinkedList<Window*>* stack;
		int topidx = -1;

	public:
		StackController();
		~StackController();

		void push(Window*);
		Window* pop();

		int getSize();
};

#endif