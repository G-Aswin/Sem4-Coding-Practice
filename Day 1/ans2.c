#include <stdio.h>



void accept(int *a, int *b)
{
    printf("Enter two numbers : ");
    scanf("%d %d", a, b);
}

int add(int a, int b)
{
	return a+b;
}

void display(int sum)
{
	printf("\nAnswer is %d\n", sum);
}

int main()
{
	int a, b;
	accept(&a, &b);
	display(add(a, b));
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
