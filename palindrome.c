#include <stdio.h>
#include <conio.h>

/*Checks if a word is a palindrome or not(same if read from left to right and right to left*/

int main() {
char str[30];
char *ptr1, *ptr2;
 
printf("Enter any word: ");
 
gets(str);
 
for(ptr1=str ; *ptr1 != NULL ; ptr1++);
	for(ptr2 = str, ptr1-- ; ptr1 >= ptr2; ) {
    	if(*ptr1 == *ptr2) {
        	ptr1--;
        	ptr2++;
    	}
    	else {
    		break;
		}
        
  	}
if(ptr2 > ptr1) {
	printf("\nWord is a palindrome");
}
else {
	printf("\Word is not a palindrome");
}
    
  getch();
  return 0;
}
