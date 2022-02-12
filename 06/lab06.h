#pragma once

class Bits{
public:
	int arr[32]={0};
	int len=0;
};

void set(Bits* data, int* tab, int size);

void print(const Bits* data);

const Bits add_up(Bits* data, Bits* data2x);

void bit_and(Bits* data, Bits* mask);

void bit_xor(Bits* data, Bits* mask);

void doOperation(void (*funPtr)(Bits*, Bits*),Bits* data, Bits* mask);

int to_decimal(Bits* data);

int to_decimal(const Bits* data);
