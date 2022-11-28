#ifndef GUI_H
#define GUI_H

#include "../periferal/display.h"
#include <Arduino.h>

/**
 * Can be inhered from to create a MenuPoint
 */
class GUI{
	private:
		String headline, extraInformation = "";

	protected:
		GUI(String headline);

	public:
		virtual void draw()  = 0;
		
		//buttonhandler
		virtual void buttonNext()  = 0;
		virtual void buttonPrev()  = 0;
		virtual void buttonUp()  = 0;
		virtual void buttonDown()  = 0;

		//activation
		virtual void acitvate(GUI* activateion) = 0;
		virtual void acitvateMe() = 0;

		//actions before and after
		virtual void preActions();
		virtual void postActions();

		String getHeadline();
		String getExtraInfromation();
		void setExtraInfromation(String);

};
#endif