// Name: Ben Nakash
// I.D : 303140057


#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2)
{
	int temp = *num1;
	printf("Before Swap: Num1 = %d, Num2 = %d \n", *num1, *num2);
	*num1 = *num2;
	*num2 = temp;
	printf("After Swap : Num1 = %d, Num2 = %d \n", *num1, *num2);
}

void max(int *num1, int *num2)
{
	printf("Max: %d \n", *num1 > *num2 ? *num1 : *num2);	
}

void setBits(int num)
{
	int count=0;
	int temp = num;
	while(temp!=0) {
		if (temp % 2 == 1)
			count++;
		temp = temp/2;
	}
	printf("Set bits in %d : %d bits \n", num, count);
} 
