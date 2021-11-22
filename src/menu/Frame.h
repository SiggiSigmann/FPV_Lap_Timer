#ifndef FRAME_H
#define FRAME_H

#include "GUI.h"

/**
 * MenuPoint can be inhered from to create and entry in the menu structure
 */
class Frame : public GUI{
	private:
		GUI* parentMenu;								//if prev was pressed go to this menu entry
														//usualy this is the windows where this wone was ativated

	protected:
		Frame(String name, GUI* parentMenu);

	public:
		void setParent(GUI*);
		void acitvate(GUI* activateion);
		void acitvateMe();
		void buttonPrev();

		//sup class newds to implement:
		//virtual void buttonNext()  = 0;
		//virtual void buttonUp()  = 0;
		//virtual void buttonDown()  = 0;

};

#endif