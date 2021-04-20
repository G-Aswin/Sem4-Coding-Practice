#include <stdio.h>
#include <stdlib.h>

void add(int a, int b);

int main()
{
	int *a = (int *)malloc(sizeof(int)), *b = (int *)malloc(sizeof(int));
	printf("Enter two numbers : ");
	scanf("%d %d", a, b);
	
	add(*a, *b);
}

void add(int a, int b)
{
	printf("\nAnswer is %d\n", a + b);
}
