#include <stdio.h>
int a1[10], a2[10], sum[10];
int n1, n2;

void read(int a[],int n){
	int i;
	printf("Enter the coefficients\n");
	for(i=n;i>=0;i--){
		printf("Coefficient of x^%d: ",i);
		scanf("%d",&a[i]);
	}
}

void disp(int a[],int n){
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

void add(int a1[],int a2[],int sum[],int n1,int n2){
	int maxdeg = (n1 > n2) ? n1 : n2;
	int i;
	for (i=0;i<=maxdeg;i++){
		sum[i]+=0;
	}
	for (i=0;i<=maxdeg;i++){
		sum[i]+=a1[i];
	}
	for (i=0;i<=maxdeg;i++){
		sum[i]+=a2[i];
	}
}

int main(){
	int maxdeg;
	printf("Enter degree of polynomial 1: ");
	scanf("%d",&n1);
	printf("Enter degree of polynomial 2: ");
	scanf("%d",&n2);
	
	maxdeg=(n1 > n2) ? n1 : n2;
	
	read(a1,n1);
	printf("\n");
	read(a2,n2);
	printf("\n");
	
	add(a1,a2,sum,n1,n2);
	
	printf("\nPolynomial 1: \t");
	disp(a1,n1);
	printf("\nPolynomial 2: \t");
	disp(a2,n2);
	printf("\nSum: \t");
	disp(sum,maxdeg);
	return 0;
}
