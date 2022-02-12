#include "lab04.h"


MapPoint* construct(const char* name, double x, double y){
	MapPoint *tmp=new MapPoint;
	tmp->_x=x;
	tmp->_y=y;
	tmp->_name=name;
	return tmp;
}

void print(const MapPoint* mp){
	std::cout<<"Position of "<< mp->_name<<". Latitude: "<<mp->_x<<". Longtitude: "<<mp->_y<<std::endl;
}

MapDist distance(const MapPoint* mp1, const MapPoint& mp2){
	MapDist tmp;
	tmp.latitude=mp1->_x-mp2._x;
	tmp.longitude=mp1->_y-mp2._y;
	return tmp;
}

double distanceMag(const MapDist& md){
	return sqrt(pow(md.latitude, 2)+pow(md.longitude, 2));
}

MapPoint inTheMiddle(const MapPoint* mp1, const MapPoint* mp2, const char* name){
	MapPoint tmp;
	tmp._name=name;
	tmp._x=(mp1->_x+mp2->_x)/2.;
	tmp._y=(mp1->_y+mp2->_y)/2.;
	return tmp;
}

MapPoint closestFrom(const MapPoint* mp1, const MapPoint* mp2, const MapPoint* mp3){
	return ((distanceMag(distance(mp1, *mp2))<distanceMag(distance(mp1, *mp3))) ? *mp2 : *mp3);
}

const char* name(const MapPoint& mp){
	return mp._name;
}

void clear(const MapPoint* mp){
	delete  mp;
}

void clear(const MapPoint* mp1, const MapPoint* mp2, const MapPoint* mp3){
	clear(mp1);
	clear(mp2);
	clear(mp3);
}