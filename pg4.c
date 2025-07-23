#include <stdio.h>
int a[10],n;
int read(){
	int i;
	printf("Enter the limit: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}
int disp(){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
int sort(){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
            if (a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main(){
	read();
	printf("Before Sorting\n");
	disp();
	printf("\n");
	printf("After Sorting\n");
	sort();
	disp();
	
	return 0;
}
	
