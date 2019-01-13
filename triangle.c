#include <stdio.h>

/* Prints a triangle of the number of rows specified */

int main() {
	
	int num;
	int i, j;
	
	printf("Enter a number: ");
	scanf("%d", &num);
	
	for(i = 0; i <= num; i++) {
		for(j = i; j > 0; j--) {
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
