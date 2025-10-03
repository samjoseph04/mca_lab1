/*Program to read and display sparse matrix and add them
@SamJoseph 
Roll No 51
Date 03-10-2025
*/

#include <stdio.h>
#define MAX 50

int main(){
	int matrix1[MAX][MAX], matrix2[MAX][MAX];
	int triplet1[MAX][3], triplet2[MAX][3], result[MAX][3];
	int rows1, cols1, rows2, cols2;
	int i, j, k1 = 1, k2 = 1, k3 = 1;

	// Input Matrix 1
	printf("Matrix 1\n");
	printf("Enter the number of rows and columns: ");
	scanf("%d %d", &rows1, &cols1);
	
	printf("Enter the elements:\n");
	for(i=0; i<rows1; i++){
		for(j=0; j<cols1; j++){
			scanf("%d", &matrix1[i][j]);
		}
	}

	// Input Matrix 2
	printf("\nMatrix 2\n");
	printf("Enter the number of rows and columns: ");
	scanf("%d %d", &rows2, &cols2);
	
	printf("Enter the elements:\n");
	for(i=0; i<rows2; i++){
		for(j=0; j<cols2; j++){
			scanf("%d", &matrix2[i][j]);
		}
	}

	// Convert Matrix 1 to Triplet
	triplet1[0][0] = rows1;
	triplet1[0][1] = cols1;
	triplet1[0][2] = 0;
	for(i=0; i<rows1; i++){
		for(j=0; j<cols1; j++){
			if(matrix1[i][j] != 0){
				triplet1[k1][0] = i;
				triplet1[k1][1] = j;
				triplet1[k1][2] = matrix1[i][j];
				k1++;
			}
		}
	}
	triplet1[0][2] = k1 - 1;

	// Convert Matrix 2 to Triplet
	triplet2[0][0] = rows2;
	triplet2[0][1] = cols2;
	triplet2[0][2] = 0;
	for(i=0; i<rows2; i++){
		for(j=0; j<cols2; j++){
			if(matrix2[i][j] != 0){
				triplet2[k2][0] = i;
				triplet2[k2][1] = j;
				triplet2[k2][2] = matrix2[i][j];
				k2++;
			}
		}
	}
	triplet2[0][2] = k2 - 1;

	// Print Triplet Matrix 1
	printf("\nTriplet Representation of Matrix 1:\n");
	printf("row\tcol\tval\n");
	for(i = 0; i < k1; i++){
		printf("%d\t%d\t%d\n", triplet1[i][0], triplet1[i][1], triplet1[i][2]);
	}

	// Print Triplet Matrix 2
	printf("\nTriplet Representation of Matrix 2:\n");
	printf("row\tcol\tval\n");
	for(i = 0; i < k2; i++){
		printf("%d\t%d\t%d\n", triplet2[i][0], triplet2[i][1], triplet2[i][2]);
	}

	// Check if addition is possible
	if(triplet1[0][0] != triplet2[0][0] || triplet1[0][1] != triplet2[0][1]){
		printf("\nMatrix addition not possible! Dimensions are not same.\n");
		return 0;
	}

	// Add the two triplet matrices
	i = 1; j = 1;
	result[0][0] = rows1;
	result[0][1] = cols1;

	while(i < k1 && j < k2){
		// Compare positions
		if(triplet1[i][0] == triplet2[j][0] && triplet1[i][1] == triplet2[j][1]){
			// Same position, add the values
			result[k3][0] = triplet1[i][0];
			result[k3][1] = triplet1[i][1];
			result[k3][2] = triplet1[i][2] + triplet2[j][2];
			i++; j++; k3++;
		}
		else if((triplet1[i][0] < triplet2[j][0]) || 
		        (triplet1[i][0] == triplet2[j][0] && triplet1[i][1] < triplet2[j][1])){
			// triplet1 comes before
			result[k3][0] = triplet1[i][0];
			result[k3][1] = triplet1[i][1];
			result[k3][2] = triplet1[i][2];
			i++; k3++;
		}
		else {
			// triplet2 comes before
			result[k3][0] = triplet2[j][0];
			result[k3][1] = triplet2[j][1];
			result[k3][2] = triplet2[j][2];
			j++; k3++;
		}
	}

	// Copy remaining entries
	while(i < k1){
		result[k3][0] = triplet1[i][0];
		result[k3][1] = triplet1[i][1];
		result[k3][2] = triplet1[i][2];
		i++; k3++;
	}

	while(j < k2){
		result[k3][0] = triplet2[j][0];
		result[k3][1] = triplet2[j][1];
		result[k3][2] = triplet2[j][2];
		j++; k3++;
	}

	result[0][2] = k3 - 1;

	// Print Resultant Triplet Matrix
	printf("\nResultant Triplet Matrix after Addition:\n");
	printf("row\tcol\tval\n");
	for(i = 0; i < k3; i++){
		printf("%d\t%d\t%d\n", result[i][0], result[i][1], result[i][2]);
	}

	return 0;
}

