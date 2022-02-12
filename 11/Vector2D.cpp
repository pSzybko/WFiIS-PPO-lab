#include "Vector2D.h"

int Vector2D::_counter=0;

Vector2D::Vector2D(){
	_counter++;
}

Vector2D::Vector2D(const Vector2D& other):_x(other._x), _y(other._y)
{_counter++;}

Vector2D::Vector2D(Vector2D&& other):_x(std::__exchange(other._x, 0.)), _y(std::__exchange(other._y, 0.))
{_counter++;}

Vector2D::~Vector2D(){
	_counter--;
}

Vector2D Vector2D::fromCarthesian(double x, double y){
	Vector2D tmp;
	tmp._x=x;
	tmp._y=y;
	return tmp;
}


Vector2D Vector2D::fromPolar(double r, double phi){
	Vector2D tmp;
	tmp._x=r*cos(M_PI*phi/180);
	tmp._y=r*sin(M_PI*phi/180);
	return tmp;
}

void Vector2D::print(const char* str) const{
	std::cout<<str<<"("<<_x<<", "<<_y<<")"<<std::endl;
}

int Vector2D::number_vertices(){
	return _counter;
}

double Vector2D::dot(const Vector2D& v) const{
	return _x*v._x+_y*v._y;
}

Vector2D Vector2D::add(const Vector2D& v) const{
	Vector2D tmp=Vector2D::fromCarthesian(_x+v._x, _y+v._y);
	return tmp;
}