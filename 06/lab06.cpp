#include "lab06.h"
#include <iostream>
#include <cmath>
void set(Bits* strukt, int* arr, int rozm){
  int tmp=32-rozm;
  for(int i=0; i<rozm; i++)
    strukt->arr[tmp+i]=arr[i];
  strukt->len=rozm;
}

void print(const Bits* strukt){
  int i=0;
  while(strukt->arr[i]==0)
    i++;
  for(; i<32; i++)
    std::cout<<strukt->arr[i];
  std::cout<<std::endl;
}

const Bits add_up(Bits* data, Bits* data2){
  Bits sum;
  int c=0;
  sum.len=(data->len > data2->len) ? data->len : data2->len;
  for(int i=31; i>31-sum.len; i--){
  	sum.arr[i] = ((data->arr[i] ^ data2->arr[i]) ^ c);
  	 c = ((data->arr[i] & data2->arr[i]) | (data->arr[i] & c)) | (data2->arr[i] & c);
  }
  return sum;
}

void bit_and(Bits* data, Bits* mask){
	for(int i=31; i>31-data->len; i--)
		data->arr[i]=data->arr[i] & mask->arr[i];
}

void bit_xor(Bits* data, Bits* mask){
	for(int i=31; i>31-data->len; i--)
		data->arr[i]=data->arr[i] ^ mask->arr[i];
}

void doOperation(void (*funPtr)(Bits*, Bits*),Bits* data, Bits* mask){
	funPtr(data, mask);
}

int to_decimal(Bits* data){
	int wynik=0;
	for(int i=31; i>31-data->len; i--)
		wynik+=data->arr[i]*pow(2, 31-i);
	return wynik;
}

int to_decimal(const Bits* data){
	int wynik=0;
	for(int i=31; i>31-data->len; i--)
		wynik+=data->arr[i]*pow(2, 31-i);
	return wynik;
}