#ifndef TRACKMANAGER_H
#define TRACKMANAGER_H

#include <Arduino.h>

class TrackManager{
	
	
	private:
		byte storedTrack = 1;
		byte selectedTrack = 0;
		
		float minLng, maxLng;
		float minLat, maxLat;

		

	public:
		byte getTrackNumber();
		byte getSelected();
		void setselected(byte);
		void recordTrack();
};

extern  TrackManager* trackManager;

#endif