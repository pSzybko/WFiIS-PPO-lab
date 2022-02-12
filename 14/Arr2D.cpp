#include "Arr2D.h"

Arr2D Arr2D::adopt(int* data,int x,int y){
  Arr2D arr;
  arr._d=data;
  arr._x=x;
  arr._y=y;
  arr._p=false;
  return arr;
}

Arr2D::Arr2D(int x, int y){
  _p=true;
  _x=x;
  _y=y;
  _d=new int[x*y];
  for(int i=0; i<x*y; i++)
    _d[i]=0;
}

int* Arr2D::operator[](int index) const{
  return &_d[index*_x];
}

void operator<<=(const char*string, const Arr2D& data){
  std::cout<<string<<std::endl;
  for(int y=0; y<data._y; y++){
    std::cout<<data[y][0];
    for(int x=1; x<data._x; x++)
      std::cout<<" "<< data[y][x];
    std::cout<<std::endl;
  }
  std::cout<<string<<std::endl;
}

Arr2D::~Arr2D(){
  if(_p and _d !=nullptr){
    delete [] _d;
    _x=0;
    _y=0;
  }
}