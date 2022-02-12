#pragma once

#include <iostream>
#include <cstring>
#include <cmath>

struct MapPoint{
	double _x;
	double _y;
	const char* _name;
};

MapPoint* construct(const char*, double, double);

void print(const MapPoint*);

struct MapDist{
	double latitude;
	double longitude;
};

MapDist distance(const MapPoint* , const MapPoint&);

double distanceMag(const MapDist&);

MapPoint inTheMiddle(const MapPoint* , const MapPoint* , const char* );

MapPoint closestFrom(const MapPoint* , const MapPoint* , const MapPoint*);

const char* name(const MapPoint&);

void clear(const MapPoint* );

void clear(const MapPoint* , const MapPoint* , const MapPoint* );