#include <stdio.h>

int main() {
	
	/*Creating an array of its anti-diagonals from a given square matrix.*/   

	int colnum, rownum;
	int i, j;
	
	printf("Enter the number of columns in your matrix:\t");
	scanf("%d", &colnum);
	printf("Enter the number of rows in your matrix:\t");
	scanf("%d", &rownum);
	
	int matrix[colnum][rownum];
	
	for(i = 1; i < colnum + 1; i++)	{
		for(j = 1; j < rownum + 1; j++) {
			printf("Enter number at position %d, %d: ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
	i = 1; j = colnum;
	
	while(i < rownum + 1 && j > 0) {
		printf("\n%d", matrix[i][j]);
		i++;
		j--;
	}
	
	return 0;
}
