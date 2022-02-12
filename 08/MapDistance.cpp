#include "MapDistance.h"

void MapDistance::print() const{
	std::cout<<"Distance: ("<<_distX<<", "<<_distY<<")\n";
}

void MapDistance::set_distance(double distX, double distY){
	_distX=distX;
	_distY=distY;
}

