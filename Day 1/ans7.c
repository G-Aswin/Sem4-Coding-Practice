#include <stdio.h>

struct add
{
	int a, b;
};

void ans(struct add a)
{
	printf("\nThe answer is %d\n", a.a + a.b);
}

void accept(struct add *a1)
{
	printf("\nEnter two numbers : ");
	scanf("%d %d", &(a1->a), &(a1->b));
}

int main()
{
	struct add a1;
	accept(&a1);
	ans(a1);
}
