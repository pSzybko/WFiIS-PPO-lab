#pragma once

#include <iostream>
#include <cmath>

class MapDistance{
public:
	void print() const;
	void set_distance(double distX, double distY);
private:	
	double _distX;
	double _distY;
};