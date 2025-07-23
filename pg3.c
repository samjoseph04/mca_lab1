#include <stdio.h>

int main(){
	int a[10],b,i,n;
	int c=0;
	printf("Enter the limit: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the value to be found: ");
	scanf("%d",&b);
	for(i=0;i<n;i++){
		if(a[i]==b){
			printf("Element found at position %d\n",i);
			c++;
		}
	}
	if(c==0){
		printf("Element not found");
	}
	return 0;
}
