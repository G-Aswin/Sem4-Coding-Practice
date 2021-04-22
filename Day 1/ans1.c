#include <stdio.h>

int main()
{
	int a, b, *sum;
	printf("\nEnter the values of two numbers : ");
	scanf("%d %d", &a, &b);
	*sum = a + b;
	printf("\nThe result is : %d\n", *sum);
}

