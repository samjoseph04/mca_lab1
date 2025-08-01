#include <stdio.h>
void main(){
	int a[10][10];
	int i, j, m, n;
	int c=0;
	printf("Enter rows and columns: ");
	scanf ("%d %d",&m,&n);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);	
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i][j]==0){
				c++;
			}	
		}
	}
	int b=(m*n)/2;
	if (c>b){
		printf("The given Matrix is sparse\n");
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				printf("%d\t",a[i][j]);	
			}
			printf("\n");
		}
	}
	else{
		printf("Not a sparse matrix");
	}
	
}
