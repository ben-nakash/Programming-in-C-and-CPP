// Name: Ben Nakash
// I.D : 303140057

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	char string[8];
	int date, day, month, year;
		
	printf("Please enter your birthday in the following format: MMDDYYYY.\n");
	scanf("%s", string);
	date = atoi(string);
	printf("%s\n", string);
	
	month = date/1000000;
	day = (date%1000000)/10000;
	year = (date%1000000)%10000;
	
	if(month<1 || month>12 || day<1 || day>31 || year>2013) {
		printf("Invalid input. Please enter your birth date as MMDDYYYY.\n");
		return;
	}
	
	printf("Month of birth: %d \n", month);
	printf("Day of birth: %d \n", day);
	printf("Year of birth: %d \n", year);
	return 0;
}


