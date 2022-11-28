#ifndef TOASTMANAGER_H
#define TOASTMANAGER_H

#include <LinkedList.h>
#include "../ui/Toast.h"
#include "../periferals/display.h"
#include "../periferals/pins.h"

class ToastManager{
	private:
		LinkedList<Toast*>* queue;
		Toast* momentaryToast = NULL;
		unsigned long endTimeForToast = 0;

		int length;
		byte xSpace;

		void getNextToast();
		bool needToDisplayToast();

	public:
		ToastManager();
		~ToastManager();

		void addToast(Toast*);
		bool drawToast();
};


extern ToastManager* toastManager;

#endif