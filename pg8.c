/* Matrix addition and subtraction
@SamJoseph 29-07*/
#include <stdio.h>
void main(){
	int a[10][10],b[10][10],sum[10][10],diff[10][10];
	int i,j,m,n;
	
	printf("Enter the rows and columns: ");
	scanf("%d %d",&m,&n);
	
	printf("Enter value for first matrix: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("Enter value for second matrix: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			sum[i][j]=a[i][j]+b[i][j];
			diff[i][j]=a[i][j]-b[i][j];
		}
	}
	
	printf("Sum Matrix: \n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d\t", sum[i][j]);
		}
		printf("\n");
	}
	
	printf("Difference of Matrix: \n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d\t", diff[i][j]);
		}
		printf("\n");
	}
}
