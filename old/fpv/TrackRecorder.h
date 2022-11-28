#ifndef TRACKRECORDER_H
#define TRACKRECORDER_H

#include <Arduino.h>

class TrackRecorder{

	float coordinates[20][2] = {{0.0}};

	float minCoordinate[2] = {0.0};
	float maxCoordinate[2] = {0.0};

	float xlengt=0;
	float ylengt=0;

	byte addingIdx=0;

	public:
		TrackRecorder();

		void fillArrayWithCoordintes(float*, byte);
		void addCoordinates(float, float);

		float calcDistanceBetween(byte first, byte second);

		float getXLength();
		float getYLength();

		float getMinLat();
		float getMinLng();
};

#endif