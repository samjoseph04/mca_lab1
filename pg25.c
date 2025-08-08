#include <stdio.h>
int a[15];
int n;

void read(){
	int i;
	printf("Enter the degree of polynomial : ");
	scanf("%d",&n);
	printf("Enter the coefficients\n");
	for(i=n;i>=0;i--){
		printf("Coefficient of x^%d: ",i);
		scanf("%d",&a[i]);
	}
}

void disp(){
	int i;
	for(i=n;i>=0;i--){
		if (a[i]!=0){
			if ((i!=n)&&(a[i]>0)){
				printf("+");
			}
			if (a[i]<0){
				printf("-");
			}
			if (i>1){
				printf(" %dx^%d ", a[i], i);
			}
			if (i==1){
				printf(" %dx ", a[i]);
			}
			if (i==0){
				printf(" %d ", a[i]);
			}
			
		}
	}
}

int main(){
	read();
	disp();
	return 0;
	
}

