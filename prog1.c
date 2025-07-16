//program to demonstrate the use of storage classes(global,local,static,register)
#include <stdio.h> 
int b=10;//global variable
static int c=7; // static variable
int main(){
	int d=5;//local variable
	register int  e=9; //register variable
	printf("Global Variable: %d\nStatic Variable: %d\nLocal Variable: %d\nRegister Variable: %d",b,c,d,e);
	return 0;
}
