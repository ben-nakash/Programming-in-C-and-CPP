// Name: Ben Nakash
// I.D : 303140057

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int i;
	double avg=0;
	double num1,num2,num3, sum;
	
	if ((argc != 4) && (argc != 6))
		printf("The input is not valid. Please Enter a valid input \n");
		
	else if (argc == 4) {	
		for(i=0; i<argc ; i++) {
			avg += atof(argv[i]);
		}
		avg = avg/3;
		printf("Average = %.2f\n", avg);
	}
	
	else if (argc == 6) {
		if    (((strcmp(argv[2], "+")!=0) && (strcmp(argv[2], "-")!=0))	||
		       ((strcmp(argv[4], "+")!=0) && (strcmp(argv[4], "-")!=0)))
		{
			printf("The input is not valid. Please Enter a valid input: \n3 numbers and only '+' or '-' between 					them.\n");
			return 0;
		}
	
		
		num1 = atof(argv[1]);
		num2 = atof(argv[3]);
		num3 = atof(argv[5]);
		sum = num1;
	
		if (strcmp(argv[2], "+")==0)
			sum += num2;
		else if (strcmp(argv[2], "-")==0)
			sum -= num2;
		
		if (strcmp(argv[4], "+")==0)
			sum += num3;
		else if (strcmp(argv[4], "-")==0)
			sum -= num3;
		
		printf("Calculation is: %.2f %s %.2f %s %.2f = %.2f\n", num1, argv[2], num2, argv[4], num3, sum);
	}
		
	return 0;
}
