#include <stdio.h>

void add(int a, int b);

int main()
{
	int a, b;
	printf("Enter two numbers : ");
	scanf("%d %d", &a, &b);
	
	add(a, b);
}

void add(int a, int b)
{
	printf("\nAnswer is %d\n", a + b);
}
