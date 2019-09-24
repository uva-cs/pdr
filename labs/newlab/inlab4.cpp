// Name: Haidder Ali Chatha Date: 9/24/2019 File name: inlab4.cpp
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<bits/stdc++.h>
#include <limits>
using namespace std;

void sizeOfTest(){
	int sizeofint= sizeof(int);
	printf("int: %d\n",sizeofint ) ;
	

	int unsignint= sizeof(unsigned int);
	printf("unsigned int: %d\n",unsignint);

	int sizeoffloat= sizeof(float);
	printf("float: %d\n",sizeoffloat);

	int sizeofdouble= sizeof(double);
	printf("double: %d\n",sizeofdouble);

	int sizeofchar= sizeof(char);
	printf("char: %d\n",sizeofchar);

	int sizeofbool= sizeof(bool);

	int sizeofintPointer= sizeof(int*);

	int sizeofcharPointer= sizeof(char*);

	int sizeofdoublePointer= sizeof(double*);
	printf("bool: %d\nint*: %d\nchar*: %d\ndouble*: %d\n", sizeofbool,sizeofintPointer,sizeofcharPointer,sizeofdoublePointer);

	

}

void maxValue() {
		cout<<"Unsigned int max:"<<UINT_MAX<<endl;
		cout<<"Int max:"<<INT_MAX<<endl;
		cout<<"Float max:"<<FLT_MAX<<endl;
		cout<<"Double max:"<<DBL_MAX<<endl;
		cout<<"Char max:"<<CHAR_MAX<<endl;
		cout<< numeric_limits<bool>::max() << endl;
		cout<<"Int* max:"<<INT_MAX<<endl;

}

void maxPointerValues() {
	int max;
	int* p;
	p = &max;
	*p = UINT_MAX;
	*p = 0;

	char max2;
	char* p2;
	p2 = &max2;
	*p2 = 'a';
	*p2 = CHAR_MAX;



	double max3;
	double* p3;
	p3 = &max3;
	*p3 = 0.0;
	*p3 = DBL_MAX;


}

void oneandzero() {
	
	int z = 0;
	z = 1;
	unsigned int z2 = 0;
	z2 = 1;
	float z3 = 0;
	z3 = 1;
	double z4 = 0;
	z4 = 1;
	char z5 = '0';
	z5 = '1';
	bool z6 = true;
	z6 = false;

	int *z7;
	z7 = NULL;
	char *z8;
	z8 = NULL;
	double *z9;
	z9 = NULL;




}

void primitiveArray() {
	int IntArray[10];
	char CharArray[10];
	int IntArray2D[6][5];
	char CharArray2D[6][5];
	for(int i=0; i<10; i++) {
		IntArray[i] = i;
		CharArray[i] = i+11;
	}
	for (int i=0; i<6; i++) {
		for(int j=0; j<5; j++) {
			IntArray2D[i][j] = (i+2) * (j+3);
			CharArray2D[i][j] = ((i+2)*10) * ((j+3)*10);
		}
	}

}

int main() {
	sizeOfTest();
	maxValue(); 
	maxPointerValues();
	oneandzero();
	cout<<"-----------------------------------------------------\n";
	primitiveArray();
	return 0;
}