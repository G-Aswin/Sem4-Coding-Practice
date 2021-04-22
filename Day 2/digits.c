// Question 1

#include <stdio.h>

int main()
{
    int x;
    printf("Enter a number to extract digits from : ");
    scanf("%d", &x);
    
    printf("\nThe digits are : ");
    
    while (x != 0)
    {
        printf("%d ", x % 10);
        x = x / 10;
    }

    return 0;
}