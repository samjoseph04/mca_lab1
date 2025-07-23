/*Display the array elements in the same order using recursive function*/
#include <stdio.h>
int a[10],n;
void read(){
	int i;
	printf("Enter the limit: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
void arrayElements(int a[],int i,int n){
	if(i>n){
		return;
	}
	printf("%d ",a[i]);
	arrayElements(a,i+1,n);
}
int main(){
	read();
	printf("Array elements\n");
	arrayElements(a,0,n-1);
	printf("\n");
	
	return 0;
}
	
