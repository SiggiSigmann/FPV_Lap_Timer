#ifndef MENU_H
#define MENU_H

#include "Frame.h"

class Menu : public Frame{
	private:
		byte numberOfMenuEntries = 0;				//store number of entries
		byte drawingIdx = 0;
		byte currentMenuEntry = 0;
		byte entryOffsetToScrall=0;

		boolean isMenuEntryDrawingNeeded();
		void drawScrollBar();

	protected:
		byte activeEntry = 0;
		Menu(String name, GUI*);

	public:
		void buttonUp();
		void buttonDown();
		void drawPoint(String, int px=125);			//draw a menupoint (index, name)
		void drawInfo(String, int px=125);			//draw a menupoint (index, name)
		void draw() final;
		byte getNumberOfPoints();

		virtual void drawMenu()  = 0;
};

#endif