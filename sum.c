#include <stdio.h>

int main() {

	/*Adds all the values stored in an array*/

	int array[5] = {1, 2, 3, 4, 5};
	int sum;
	int i;
	
	for(i = 0; i < 5; i ++) {
		sum = sum + array[i];
	}
	
	printf("%d", sum);
	
}
