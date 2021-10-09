#ifndef ABSTRACTMENU_H
#define ABSTRACTMENU_H

#include "../util/display.h"

/**
 * Can be inhered from to create a MenuPoint
 */
class AbstractMenu{
	protected:
		String name, extra = "";
	
	public:
		AbstractMenu(String name);

		virtual void draw()  = 0;
		virtual void buttonNext()  = 0;
		virtual void buttonPrev()  = 0;
		virtual void buttonUp()  = 0;
		virtual void buttonDown()  = 0;
		virtual void acitvate(AbstractMenu* activateion) = 0;
		virtual void acitvateMe() = 0;

		String getName();
		String getExtra();
		void setExtra(String);

};
#endif