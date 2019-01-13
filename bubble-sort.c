#include <stdio.h>

int main() {

	/*Orders an array using bubble sort*/
	
	int array[5] = {12, 3, 4, 67, 89};
	int small = array[1];
	int j = 1, k, i;
	int buffer;
	
	for(k = 0; k < 5; k++) {
		for(i = 0; i < 5; i++) {
			if(array[i] < array[j]) {
				buffer = array[i];
				array[i] = array[j];
				array[j] = buffer;
			
			
			}
		
		}
	}
	
	for(i = 0; i < 5; i++) {
		printf("%d ", array[i]);
	}
	
		
	return 0;
	
}
