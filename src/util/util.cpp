#include "util.h"

int scaleRSSI(int value, int biggestNumber, int maxValue){
	long level = value * biggestNumber ;
	return level/maxValue ;
}

void insertAtEnd(int* array, int value, int length){
	int o = value;
	for(int i = length-1; i>=0;i--){
		int ol = array[i];
		array[i] = o;
		o = ol;
	}
}

void insertAtFront(int* array, int value, int length){
	int o = value;
	for(int i = 0; i<length;i++){
		int ol = array[i];
		array[i] = o;
		o = ol;
	}
}