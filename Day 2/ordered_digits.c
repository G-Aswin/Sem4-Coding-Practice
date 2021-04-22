// Question 2

#include <stdio.h>
#include <math.h>

int main()
{
    int x;
    printf("\nEnter the num : ");
    scanf("%d", &x);
    
    int copy = x, size = 0;
    while (copy != 0)
    {
        size++;
        copy /= 10;
    }
    
    printf("\nThe digits in the same order are : ");
    for (int i = size - 1; i >= 0; i--)
    {
        int digit = x / (pow(10, i));
        printf("%d ", digit % 10);
    }
}

