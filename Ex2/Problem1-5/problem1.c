// Name: Ben Nakash
// I.D : 303140057

#include <stdio.h>

void forLoop()
{
	int i,j;
	for (i=1 ; i<=8 ; i++) {
		for(j=1 ; j<=i ; j++)
			printf("*");
		printf("\n");
	}
}

void whileLoop()
{
	int i=1, j=1;
	while(i<=8) {
		while (j<=i) {
			printf("*");
			j++;
		}
		printf("\n");
		j=1;
		i++;

	}
}
int main()
{
	printf("Printing with 'for' loop: \n");
	forLoop();
	printf("Printing with 'while' loop: \n");
	whileLoop();
	return 0;
}

