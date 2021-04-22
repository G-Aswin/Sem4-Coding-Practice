#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a, *b;
	a = (int *) malloc(sizeof(int));
	b = (int *) malloc(sizeof(int));
	
	printf("\nEnter two numbers : ");
	scanf("%d %d", a, b);
	
	printf("\nThe sum is %d\n", *a + *b);
}
