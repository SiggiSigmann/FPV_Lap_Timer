#ifndef TRACKRECORDER_H
#define TRACKRECORDER_H

#include "../../../Frame.h"

class TrackRecorder : public Frame{

	public:
		TrackRecorder(GUI*);
		void draw();
		void buttonNext();
		void buttonUp();
		void buttonDown();
};

#endif