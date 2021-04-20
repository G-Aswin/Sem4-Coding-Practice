#include <stdio.h>

struct add
{
	int a, b;
};

int main()
{
	struct add a1;
	printf("\nEnter two numbers : ");
	scanf("%d %d", &(a1.a), &(a1.b));
	printf("\nThe sum is %d\n", a1.a + a1.b);
}
