#include <stdio.h>
#include <string.h>

int main() {

	/*Concatenates two strings */

	char a[10], b[10], c[20];
	char *ptrA, *ptrB, *ptrC;
	
	int i, j;
	
	ptrA = &a[0];
	ptrB = &b[0];
	ptrC = &c[0];
	
	printf("Enter the first string: ");
	fgets(a, 10, stdin);
	printf("\nEnter the second string: ");
	fgets(b, 10, stdin);
	
	for(i = 0; i < strlen(a) - 1; i++) {
		*ptrC = *(ptrA + i);
		ptrC++;
	}
	
	for(j = 0; j < strlen(b) - 1; j++) {
		*ptrC = *(ptrB + j);
		ptrC++;
	}
	
	printf("\n\nFirst string: %s", a);
	printf("\nSecond string: %s", b);
	printf("\nConcatenated string: %s", c);
	
	return 0; 
}
