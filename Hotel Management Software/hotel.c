#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include<stdlib.h>

//add rooms back to total after checkout
// fix correct person[j] fetching issue

struct time {
  unsigned int hour;
  unsigned int minute;
};

struct date {
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

struct guest {
	char name[20];
	int bookingNo;
	struct time checkInTime;
	struct date checkInDate;
	unsigned int nightStay;
	unsigned int roomCount;
	unsigned int roomCost;
	unsigned int meals;
	char roomType[6];
	int roomNum;
	
} person[200];

int main() {
	
	FILE *fp;
	FILE *bookingArray;
	
	FILE *checkInTimeF;
	FILE *checkInDateF;
	FILE *nightStayF;
	FILE *roomCountF;
	FILE *roomCostF;
	FILE *roomTypeF;
	FILE *roomNumF;
	FILE *mealsF;
	
	char inp1, inp3, inp5; 
	int inp2, inp4, inp6;
	int l, j;
	char checkOutName[20]; int checkOutNo;
	
    int roomCount[3];
    int k;
    int num;
    
    FILE *count;
	count = fopen("roomCounter.txt", "r");
    
    for(k = 0; k < 4; k++) {
        fscanf(count, "%d", &roomCount[k]);
    }
    fclose(count);
    
	printf("Welcome to ABC Hotel!\n");
	
	FILE *booking = fopen("booking.txt", "r");
	char buff = fgetc(booking);
	fclose(booking);
	
	register int i = buff - '0';
	
	restart:
	printf("\nSelect one of the following actions:\n");
	printf("1. Check-in\n");
	printf("2. Check-out\n");
	printf("3. Book Reservation\n");
	printf("X. EXIT\n\n");
	scanf(" %c", &inp1);
		if(inp1 == '1') {
			printf("\nPlease enter your name: ");
			scanf("%s", &person[i].name);
			printf("\nPlease enter check-in date(dd/mm/yyyy): ");
			scanf("%02d/%02d/%04d", &person[i].checkInDate.day, &person[i].checkInDate.month, &person[i].checkInDate.year);
			printf("\nPlease enter check-in time(hh:mm): ");
			scanf("%02d:%02d", &person[i].checkInTime.hour, &person[i].checkInTime.minute);
			printf("\nWhich room would you like to stay in?\n");
			printf("1. Single-Bed Room(30$ per night)\n");
			printf("2. Double-Bed Room(54$ per night)\n");
			printf("3. Triple-Bed Room(75$ per night)\n");
			printf("4. Suite(120$ per night)\n\n");
		
			choose:
			scanf("%d", &inp2);
			printf("\nHow many rooms of this type do you want? ");
			scanf("%d", &person[i].roomCount);
			
			if(inp2 == 1) {
				if(roomCount[0] >= person[i].roomCount) {
					person[i].roomCost = 30;
					roomCount[0] -= person[i].roomCount;
					strcpy(person[i].roomType, "Single");
					person[i].roomNum = 0;	
				}
				else {
					printf("No rooms of this type are available. Please select another room\n");
					goto choose;
				}
				}
			else if(inp2 == 2) {
				if(roomCount[1] >= person[i].roomCount) {
					person[i].roomCost = 54;	
					roomCount[1] -= person[i].roomCount;
					strcpy(person[i].roomType, "Double");
					person[i].roomNum = 1;
				}
				else {
					printf("No rooms of this type are available. Please select another room\n");
					goto choose;
				
				}
				}		
			else if(inp2 == 3) {
				if(roomCount[2] >= person[i].roomCount) {
					person[i].roomCost = 75;
					roomCount[2] -= person[i].roomCount;
					strcpy(person[i].roomType, "Triple");
					person[i].roomNum = 2;	
				}
				else {
					printf("No rooms of this type are available. Please select another room\n");
					goto choose;
				}
			}
			else if(inp2 == 4) {
				if(roomCount[3] >= person[i].roomCount) {
					person[i].roomCost = 120;
					roomCount[3] -= person[i].roomCount;
					strcpy(person[i].roomType, "Suite");
					person[i].roomNum = 3;		
				}
				else {
					printf("No rooms of this type are available. Please select another room");
					goto choose;
				}
			}
			
			count = fopen("roomCounter.txt", "w +");
			for(l = 0; l < 4; l++) {
				fprintf(count, "%d\n", roomCount[l]);
			}
			fclose(count);
				
			printf("\nEnter the number of nights that you would like to stay for: ");
			scanf("%d", &person[i].nightStay);
			printf("\nWould you like to include meals as well? (Y/N) ");
			scanf(" %c", &inp5);
			if(inp5 == 'Y') {
				person[i].meals = 1;
			} 
			else {
				person[i].meals = 0;
			}
			
			printf("\nThank you for choosing us! Your booking number is %05d", i);
			person[i].bookingNo = i;
			
			
			fp = fopen("guestlist.txt", "a");
			if(strlen(person[i].name) > 7) {
				fprintf(fp, "\n%s\t", person[i].name);
			}
			else {
				fprintf(fp, "\n%s\t\t", person[i].name);
			}
			fprintf(fp, "%05d\t\t%02d:%02d\t\t%02d/%02d/%04d\t%d\t\t%s\t\t%d\t\t%d\t\t%c", person[i].bookingNo, person[i].checkInTime.hour, person[i].checkInTime.minute, person[i].checkInDate.day, person[i].checkInDate.month, person[i].checkInDate.year, person[i].nightStay, person[i].roomType, person[i].roomCount, person[i].roomCost * person[i].roomCount * person[i].nightStay, inp5 );
			fclose(fp);
			
			checkInTimeF = fopen("checkInTime.txt", "a");
			fprintf(checkInTimeF, "%02d:%02d\n", person[i].checkInTime.hour, person[i].checkInTime.minute);
			fclose(checkInTimeF);
			
			checkInDateF = fopen("checkInDate.txt", "a");
			fprintf(checkInDateF, "%02d/%02d/%04d\n", person[i].checkInDate.day, person[i].checkInDate.month, person[i].checkInDate.year);
			fclose(checkInDateF);
			
			nightStayF = fopen("nightStay.txt", "a");
			fprintf(nightStayF, "%d\n", person[i].nightStay);
			fclose(nightStayF);
			
			roomCostF = fopen("roomCost.txt", "a");
			fprintf(roomCostF, "%d\n", person[i].roomCost);
			fclose(roomCostF);
			
			roomCountF = fopen("roomCount.txt", "a");
			fprintf(roomCountF, "%d\n", person[i].roomCount);
			fclose(roomCountF);
			
			roomTypeF = fopen("roomType.txt", "a");
			fprintf(roomTypeF, "%s\n", person[i].roomType);
			fclose(roomTypeF);
			
			roomNumF = fopen("roomNum.txt", "a");
			fprintf(roomNumF, "%s\n", person[i].roomNum);
			fclose(roomNumF);
			
			mealsF = fopen("meals.txt", "a");
			fprintf(mealsF, "%d\n", person[i].meals);
			fclose(mealsF);
			
			bookingArray = fopen("bookingArray.txt", "a");
			fprintf(bookingArray, "%05d\n", person[i].bookingNo);
			fclose(bookingArray);
			
			booking = fopen("booking.txt", "w");
			i += 1;
			fprintf(booking, "%d", i);
			fclose(booking);
			
			goto restart;
		}
		
		else if(inp1 == '2') {
			
			j = 0;
			
			checkInTimeF = fopen("checkInTime.txt", "r");
			while(fscanf(checkInTimeF, "%02d:%02d\n", &person[j].checkInTime.hour, &person[j].checkInTime.minute) > 0) {
				j++;
			}
			fclose(checkInTimeF);
			
			j = 0;
			
			checkInDateF = fopen("checkInDate.txt", "r");
			while(fscanf(checkInDateF, "%02d/%02d/%04d\n", &person[j].checkInDate.day, &person[j].checkInDate.month, &person[j].checkInDate.year) > 0) {
				j++;
			}
			fclose(checkInDateF);
			
			j = 0;
			
			nightStayF = fopen("nightStay.txt", "r");
			while(fscanf(nightStayF, "%d\n", &person[j].nightStay) > 0) {
				j++;
			}
			fclose(nightStayF);
			
			j = 0;
			
			roomCostF = fopen("roomCost.txt", "r");
			while(fscanf(roomCostF, "%d\n", &person[j].roomCost) > 0) {
				j++;
			}
			fclose(roomCostF);
			
			j = 0;
			
			roomCountF = fopen("roomCount.txt", "r");
			while(fscanf(roomCountF, "%d\n", &person[j].roomCount) > 0) {
				j++;
			}
			fclose(roomCountF);
			
			j = 0;
			
			roomTypeF = fopen("roomType.txt", "a");
			while(fscanf(roomTypeF, "%s\n", &person[j].roomType) > 0) {
				j++;
			}
			fclose(roomTypeF);
		
			j = 0;
			
			mealsF = fopen("meals.txt", "a");
			while(fscanf(mealsF, "%d\n", &person[j].meals) > 0) {
				j++;
			}
			fclose(mealsF);
			
			printf("\nWhat type of checkout would you like to do?\n");
			printf("1. Scheduled checkout\n");
			printf("2. Early checkout\n\n");
			scanf(" %c", &inp3);
			if(inp3 == '1') {
				printf("\nEnter your booking number: ");
				scanf("%d", &inp6);
				bookingArray = fopen("bookingArray.txt", "r");
				while(fscanf(bookingArray, "%d\n", &checkOutNo) > 0) {
					if(inp6 == checkOutNo) {
						fclose(bookingArray);
						printf("\nThank you for staying with us! You stayed for %d nights in %d rooms starting %02d/%02d/%04d at %02d:%02d.", person[j].nightStay, person[j].roomCount, person[j].checkInDate.day, person[j].checkInDate.month, person[j].checkInDate.year, person[j].checkInTime.hour, person[j].checkInTime.minute);
						
						printf("\n%s\n", person[j].roomType);
						float roomBill = person[j].roomCount * person[j].nightStay * person[j].roomCost;
						float mealBill = (person[j].meals * 3) * person[j].nightStay * person[j].roomCount;
						float totalBill = roomBill + mealBill;
						float tax = totalBill * (17.5/100);
						totalBill = totalBill + tax;
						printf("\n\nRoom Bill:\t\t%0.2f", roomBill);
						printf("\nMeal Bill:\t+\t%0.2f", mealBill);
						printf("\nTaxation:\t+\t%0.2f", tax);
						printf("\n\t\t\t-----");
						printf("\nTotal Bill: \t\t%0.2f$\n\n\n\n", totalBill);
						
						if(person[j].roomNum == 0) {
							roomCount[0] += person[j].roomCount;
						}
						else if(person[j].roomNum == 1) {
							roomCount[1] += person[j].roomCount;
						}
						else if(person[j].roomNum == 2) {
							roomCount[2] += person[j].roomCount;
						}
						else if(person[j].roomNum == 3) {
							roomCount[3] += person[j].roomCount;
						}
						
						count = fopen("roomCounter.txt", "w");
						for(l = 0; l < 4; l++) {
							fprintf(count, "%d\n", roomCount[l]);
						}
						fclose(count);
									
						goto restart;
					}
					else {
						j++;
				 }
				
				}
   	 		}
						
}

		/* else if(inp3 == '2') {
				printf("Enter the number of nights that you stayed: ");
				scanf("%d", &person[i].nightStay);
					printf("Enter your booking number: ");
					scanf("%d", checkOutNo);
						while(check == 0) {
							if(person[j].bookingNo == checkOutNo) {
								printf("\nThank you for staying with us! You stayed for %d nights in %d rooms starting %02d/%02d/%04d at %02d:%02d.", person[j].nightStay, person[j].roomCount, person[j].checkInDate.day, person[j].checkInDate.month, person[j].checkInDate.year, person[j].checkInTime.hour, person[j].checkInTime.minute);
								float bill = (person[j].roomCount * person[j].nightStay * person[j].roomCost) + ((person[j].meals * 3) * person[j].nightStay * person[j].roomCount);
								printf("Your total bill is %0.2f$", bill);
								
								check = 1;
								goto restart;
								
								}
								j++;
							}
			}
		} */
		else if(inp1 == '3') {
			printf("\nPlease enter your name: ");
			scanf("%s", &person[i].name);
			printf("\nPlease enter check-in date(dd/mm/yyyy): ");
			scanf("%02d/%02d/%04d", &person[i].checkInDate.day, &person[i].checkInDate.month, &person[i].checkInDate.year);
			printf("\nPlease enter check-in time(hh:mm): ");
			scanf("%02d:%02d", &person[i].checkInTime.hour, &person[i].checkInTime.minute);
			printf("\nWhich room would you like to stay in?\n");
			printf("1. Single-Bed Room(30$ per night)\n");
			printf("2. Double-Bed Room(54$ per night)\n");
			printf("3. Triple-Bed Room(75$ per night)\n");
			printf("4. Suite(120$ per night)\n\n");
		
			choose1:
			scanf("%d", &inp2);
			printf("\nHow many rooms of this type do you want? ");
			scanf("%d", &person[i].roomCount);
			
			if(inp2 == 1) {
				if(roomCount[0] >= person[i].roomCount) {
					person[i].roomCost = 30;
					roomCount[0] -= person[i].roomCount;
					strcpy(person[i].roomType, "Single");	
				}
				else {
					printf("No rooms of this type are available. Please select another room\n");
					goto choose1;
				}
				}
			else if(inp2 == 2) {
				if(roomCount[1] >= person[i].roomCount) {
					person[i].roomCost = 54;	
					roomCount[1] -= person[i].roomCount;
					strcpy(person[i].roomType, "Double");
				}
				else {
					printf("No rooms of this type are available. Please select another room\n");
					goto choose1;
				
				}
				}		
			else if(inp2 == 3) {
				if(roomCount[2] >= person[i].roomCount) {
					person[i].roomCost = 75;
					roomCount[2] -= person[i].roomCount;
					strcpy(person[i].roomType, "Triple");	
				}
				else {
					printf("No rooms of this type are available. Please select another room\n");
					goto choose1;
				}
			}
			else if(inp2 == 4) {
				if(roomCount[3] >= person[i].roomCount) {
					person[i].roomCost = 120;
					roomCount[3] -= person[i].roomCount;
					strcpy(person[i].roomType, "Suite");		
				}
				else {
					printf("No rooms of this type are available. Please select another room");
					goto choose1;
				}
			}
			
			count = fopen("roomCounter.txt", "w +");
			for(l = 0; l < 4; l++) {
				fprintf(count, "%d\n", roomCount[l]);
			}
			fclose(count);
				
			printf("\nEnter the number of nights that you would like to stay for: ");
			scanf("%d", &person[i].nightStay);
			printf("\nWould you like to include meals as well? (Y/N) ");
			scanf(" %c", &inp5);
			if(inp5 == 'Y') {
				person[i].meals = 1;
			} 
			else {
				person[i].meals = 0;
			}
			
			printf("\nThank you for choosing us! Your booking number is %05d", i);
			person[i].bookingNo = i;
			
			
			fp = fopen("guestlist.txt", "a");
			if(strlen(person[i].name) > 7) {
				fprintf(fp, "\n%s\t", person[i].name);
			}
			else {
				fprintf(fp, "\n%s\t\t", person[i].name);
			}
			fprintf(fp, "%05d\t\t%02d:%02d\t\t%02d/%02d/%04d\t%d\t\t%s\t\t%d\t\t%d\t\t%c", person[i].bookingNo, person[i].checkInTime.hour, person[i].checkInTime.minute, person[i].checkInDate.day, person[i].checkInDate.month, person[i].checkInDate.year, person[i].nightStay, person[i].roomType, person[i].roomCount, person[i].roomCost * person[i].roomCount * person[i].nightStay, inp5 );
			fclose(fp);
			
			checkInTimeF = fopen("checkInTime.txt", "a");
			fprintf(checkInTimeF, "%02d:%02d\n", person[i].checkInTime.hour, person[i].checkInTime.minute);
			fclose(checkInTimeF);
			
			checkInDateF = fopen("checkInDate.txt", "a");
			fprintf(checkInDateF, "%02d/%02d/%04d\n", person[i].checkInDate.day, person[i].checkInDate.month, person[i].checkInDate.year);
			fclose(checkInDateF);
			
			nightStayF = fopen("nightStay.txt", "a");
			fprintf(nightStayF, "%d\n", person[i].nightStay);
			fclose(nightStayF);
			
			roomCostF = fopen("roomCost.txt", "a");
			fprintf(roomCostF, "%d\n", person[i].roomCost);
			fclose(roomCostF);
			
			roomCountF = fopen("roomCount.txt", "a");
			fprintf(roomCountF, "%d\n", person[i].roomCount);
			fclose(roomCountF);
			
			roomTypeF = fopen("roomType.txt", "a");
			fprintf(roomTypeF, "%s\n", person[i].roomType);
			fclose(roomTypeF);
			
			mealsF = fopen("meals.txt", "a");
			fprintf(mealsF, "%d\n", person[i].meals);
			fclose(mealsF);
			
			bookingArray = fopen("bookingArray.txt", "a");
			fprintf(bookingArray, "%05d\n", person[i].bookingNo);
			fclose(bookingArray);
			
			booking = fopen("booking.txt", "w");
			i += 1;
			fprintf(booking, "%d", i);
			fclose(booking);
			
			goto restart;
		}
		else if(inp1 == 'X') {
			exit(0);
		}
}  

