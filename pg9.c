/* Matrix multiplication
@SamJoseph 29-07*/
#include <stdio.h>
int main(){
	int a[10][10],b[10][10],result[10][10];
	int i,j,k,r1,c1,r2,c2;
	
	printf("Enter the rows and columns of first matrix: ");
	scanf("%d %d",&r1,&c1);
	
	printf("Enter the rows and columns of second matrix: ");
	scanf("%d %d",&r2,&c2);	
	
	if(c1!=r2){
		printf("Multiplication not possible\n");
		return 0;
	}
	
	printf("Enter elements for first matrix: ");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&a[i][j]);
		}
	}
		
	printf("Enter elements for second matrix: ");
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			scanf("%d",&b[i][j]);
		}
	}
	
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			result[i][j]=0;
		}
	}
	
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			for(k=0;k<c1;k++){
				result[i][j]=a[i][k]*b[k][j];
			}
		}
	}
	
	printf("Result Matrix: \n");
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			printf("%d\t", result[i][j]);
		}
		printf("\n");
	}
	
	return 0;
	
}
