#pragma once

#include "MapDistance.h"

class MapPoint{
public:
	void set_coordinates(double x, double y);
	void print() const;
	MapDistance distance(const MapPoint& mp);
	MapPoint half_way_to(const MapPoint& mp);
private:
	double _x;
	double _y;
};