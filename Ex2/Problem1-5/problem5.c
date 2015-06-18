// Name: Ben Nakash
// I.D : 303140057

#include <stdio.h>
#include <stdlib.h>

void gcd (int num1, int num2);

int main ()
{
	int num1,num2;
	printf("Please enter two numbers: \n");
	scanf("%d %d", &num1, &num2);
	gcd(num1, num2);
	return 0;
}

void gcd(int num1, int num2)
{
	int min, max, i, gcd;
	
	min = num1<num2 ? num1:num2;
	max = num1>num2 ? num1:num2;
	
	if (num1==0 || num2==0) {
		printf("The greatest common divisor is: %d \n", max);
		return;
	}
	
	for (i=1 ; i<=min ; i++) {
		if ((num1 % i == 0) && (num2 % i == 0))
			gcd = i;
	}
	printf("The greatest common divisor is: %d \n", gcd);
}
