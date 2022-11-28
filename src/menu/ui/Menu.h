#ifndef MENUE_H
#define MENUE_H

#include "Window.h"
#include <Arduino.h>
#include <LinkedList.h>
#include "MenuEntry.h"

class Menu : public Window{
	private:
		LinkedList<MenuEntry>* entries;
		short drawingIdx = 0;
		short selectedIdx = 0;
		short scrollingOffset = 0;
		bool editValue = false;
		bool disableFunctionality = false;

		void drawScrollBar();
		void drawPoint(String);			//draw a menupoint (index, name)
		void drawInfo(String);			//draw a menupoint (index, name)
		void clearPoint(short);

		void executeButtonAction();
		void updateMenueEntry();

	public:
		Menu(String name);

		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
		void buttonPrev();

		void addEntry(MenuEntry);
		void remove(short);
		void setDisabled(bool);

		virtual void buttonAction(byte){}
		virtual String updateEntry(byte){return "";}
		virtual void valueChangeUp(byte){}
		virtual void valueChangeDown(byte){}
		void onStorageChange(){};

		virtual void menuDraw(){}
		virtual void menuButtonUp(){}
		virtual void menuButtonDown(){}
		virtual void menuButtonNext(){}
		virtual void menuButtonPrev(){}

		void updateAll();
};

#endif