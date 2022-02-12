#include "lab03.h"

int* initFibonacci(const int n){
	int* tmp=new int[n+1];
	tmp[0]=0;
	tmp[1]=1;
	for(int i=2; i<n+1; i++)
		tmp[i]=tmp[i-1]+tmp[i-2];
	return tmp;
}

void print(const int* arr, const int n){
	std::cout<<"(";
	for(int i=0; i<n; i++)
		std::cout<<arr[i]<<", ";
	std::cout<<arr[n]<<")"<<std::endl;
}

void deleteSequence(const int* arr){
	delete [] arr;
}

void addSequence(int* n1, int*** sl, int** slen, int n2){
	(*n1)++;
	int** tmp1=*sl;
	int* tmp2=*slen;

	*sl=new int*[*n1];
	*slen=new int[*n1];

	(*sl)[*n1-1]=initFibonacci(abs(n2));
	(*slen)[*n1-1]=abs(n2);

	for(int i=0; i<(*n1)-1; i++){
		(*sl)[i]=tmp1[i];
		(*slen)[i]=tmp2[i];
	}

	delete [] tmp1;
	delete [] tmp2;
}

void printSequence(int** arr,int* lenarr, int n){
	std::cout<<"Ciag nr "<<n<<": ";
	print(arr[n], lenarr[n]);
}

void printAllSequences(int** arr,int* lenarr, int n){
	for(int i=0; i<n; i++)
		printSequence(arr, lenarr, i);
}

void swapSequence(int* n1, int*** sl, int** slen, int n2){
	if(n2>(*n1))
		return;
	for(int i=0; i<(*slen)[n2]/2; i++){
		int tmp=(*sl)[n2][i];
		(*sl)[n2][i]=(*sl)[n2][(*slen)[n2]-i];
		(*sl)[n2][(*slen)[n2]-i]=tmp;
	}
}

void deleteSequences(int* n, int*** sl, int** slen){
	for(int i=0; i<(*n); i++)
		deleteSequence((*sl)[i]);
	delete [] *sl;
	delete [] *slen;
}