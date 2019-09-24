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

void outputBinary(unsigned int x){
	printf("%d\n",x);
	int binaryrep [32];
	for(int i=31; i >= 0; i--) {
		//printf("%d\n",i);
		if(x>=pow (2.0, i)) {
			x-= pow (2.0, i);
			binaryrep [i] =1;
			printf("1");
		}
		else {
			binaryrep [i] =0;
			printf("0");
		}
	}

	cout<<endl;
	
}
	
	void overflow() {
		unsigned int max_unsigned_int_size = UINT_MAX + 1;
		printf("UINT_MAX + 1 = %d\n",max_unsigned_int_size);
		cout<<"It overflows when you add 1 because that's the max,there are no more integers after that, so it goes to zero.\n";

	}
int main(){
	int x;
	cout<<"Enter an integer\n";
	std::cin >> x;
	printf("-------------\n");
	printf("sizeOfTest\n");
	printf("-------------\n");
	sizeOfTest();
	printf("-------------\n");
	printf("outputBinary\n");
	printf("-------------\n");
	outputBinary(x);
	printf("-------------\n");
	printf("overflow\n");
	printf("-------------\n");
	overflow();
	return 0;

}