#pragma once

#include <iostream>
#include <cmath>


class Vector2D{
public:
	Vector2D();
	Vector2D(const Vector2D& other);
	Vector2D(Vector2D&& other);
	~Vector2D();
	static Vector2D fromCarthesian(double x, double y);
	static Vector2D fromPolar(double r, double phi);
	void print(const char* str) const;
	static int number_vertices();
	double dot(const Vector2D& v) const;
	Vector2D add(const Vector2D& v) const;
private:
	double _x;
	double _y;
	static int _counter;
};