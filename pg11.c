/*Determinant of a Matrix
@SamJoseph 29-07*/
#include <stdio.h>
int main() {
    int matrix[3][3];
    int n ,i,j;

    printf("Enter the order of square matrix (2 or 3): ");
    scanf("%d", &n);

    if (n!=2&&n!=3) {
        printf("Error: This program only supports 2x2 and 3x3 matrices.\n");
        return 0;
    }

    printf("Enter elements of the %dx%d matrix:\n", n, n);
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int det=0;

    if (n==2) {
        det=(matrix[0][0]*matrix[1][1])-(matrix[0][1]*matrix[1][0]);
    } else if (n==3) {
        det=matrix[0][0]*(matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1])
        	-matrix[0][1]*(matrix[1][0]*matrix[2][2]-matrix[1][2]*matrix[2][0])
            +matrix[0][2]*(matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0]);
    }

    printf("Determinant=%d\n",	det);

    return 0;
}
