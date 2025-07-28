/*Display the array elements in the reverse order using recursive function
@SamJoseph 29-07*/
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
void arrayElements(int a[],int i){
	if(i<0){
		return;
	}
	printf("%d ",a[i]);
	arrayElements(a,i-1);
}
int main(){
	read();
	printf("Array elements\n");
	arrayElements(a,n-1);
	printf("\n");
	
	return 0;
}
	
