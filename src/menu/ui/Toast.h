#ifndef TOAST_H
#define TOAST_H

#include <Arduino.h>

class Toast{
	public:
		String message = "";
		int duration = -1;

		Toast(String message, int duration){
			this->message = message;
			this->duration = duration;
		}
};

#endif