/*Transpose of a Matrix
@SamJoseph 29-07*/
#include <stdio.h>

int main(){
	int a[10][10],transpose[10][10];
	int i,j,m,n;
	
	printf("Enter the rows and columns: ");
	scanf("%d %d",&m,&n);
	
	printf("Enter the matrix elements: \n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &a[i][j]);
		}
	}

    for(i=0;i<;i++) {
        for(j=0;j<cols;j++) {
            transpose[j][i]=a[i][j];
        }
    }

    printf("\nOriginal Matrix:\n");
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("\nTranspose of the Matrix:\n");
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
