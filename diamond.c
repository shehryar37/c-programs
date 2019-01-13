#include <stdio.h>

//Inputs number of rows
//Makes a diamond of the same number of rows as input

int main() {
	
	int rowMax;
	int i, j, k;
	int space;
	int numAst;
	
	printf("Enter the number of rows: ");
	scanf("%d", &rowMax);
	
	if(rowMax % 2 == 0) {
		rowMax = rowMax + 1;
	}
	
	space = (rowMax - 1) / 2;
	
	for(i = 0; i < rowMax; i += 2) {
		while(numAst <= rowMax) {
			for(j = 0; j < space; j++) {
				printf(" ");
				printf(" ");
				printf(" ");
			}
			
			space = space - 1;
			
			printf(" ");
			printf(" ");
			printf(" ");
				
			for(k = 1; k < numAst; k++) {
				printf(" * ");
			}
			
			numAst = numAst + 2;
			
			printf("\n");
		}
	}
	for(i = 0; i < rowMax; i += 2) {
		while(numAst >= 0) {
			for(j = 0; j < space; j++) {
				printf(" ");
				printf(" ");
				printf(" ");
			}
			
			space = space + 1;
			
			if(numAst != rowMax + 1) {
				printf(" ");
				printf(" ");
				printf(" ");
				for(k = 1; k < numAst; k++) {
					printf(" * ");
				}
			}
			else {
				for(k = 0; k < rowMax; k++) {
					printf(" * ");
				}
			}
			numAst = numAst - 2;
			
			printf("\n");
		
		}
	}

	return 0;
}
