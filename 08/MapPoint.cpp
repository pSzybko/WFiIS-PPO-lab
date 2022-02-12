#include "MapPoint.h"

void MapPoint::set_coordinates(double x, double y){
	_x=x;
	_y=y;
}

void MapPoint::print() const{
	std::cout<<"Point: ("<<_x<<", "<<_y<<")\n";
}

MapDistance MapPoint::distance(const MapPoint& mp){
	MapDistance tmp;
	tmp.set_distance(fabs(_x-mp._x), fabs(_y-mp._y));
	return tmp;
}

MapPoint MapPoint::half_way_to(const MapPoint& mp){
	MapPoint tmp;
	tmp.set_coordinates((_x+mp._x)/2., (_y+mp._y)/2.);
	return tmp;
}