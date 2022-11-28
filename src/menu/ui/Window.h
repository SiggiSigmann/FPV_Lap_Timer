#ifndef WINDOW_H
#define WINDOW_H

#include <Arduino.h>
#include "../periferals/display.h"
#include "../MenuController.h"

/**
 * Can be inhered from to create a MenuPoint
 */
class Window{
	private:
		String headline, extraInformation = "";

	public:
		Window(String headline);
		String getHeadline();
		String getExtraInfromation();
		void setExtraInfromation(String);

		//drwaing
		virtual void draw() = 0;
		
		//buttonhandler
		virtual void buttonNext() = 0;
		virtual void buttonPrev();
		virtual void buttonUp() = 0;
		virtual void buttonDown() = 0;

		//actions before and after
		void preActions();
		void postActions();

		//storge
		virtual void onStorageChange() = 0;
};
#endif