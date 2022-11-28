#include "TrackManager.h"

byte TrackManager::getTrackNumber(){
	return storedTrack;
}

byte TrackManager::getSelected(){
	return selectedTrack;
}
void TrackManager::setselected(byte sel){
	selectedTrack = sel;
}