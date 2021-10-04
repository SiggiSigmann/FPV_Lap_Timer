#ifndef TRACKMANAGER_H
#define TRACKMANAGER_H

#include "../util/gps.h"

class TrackManager{
	
	
	private:
		byte storedTrack = 1;
		byte selectedTrack = 0;

		

	public:
		byte getTrackNumber();
		byte getSelected();
		void setselected(byte);
};

#endif