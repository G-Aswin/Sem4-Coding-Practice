// Question 3


#include <stdio.h>

int main()
{
    int x;
    printf("Enter a number to extract digits from : ");
    scanf("%d", &x);
    
    int copy = x;
    
    printf("\nThe even digits are : ");
    
    while (x != 0)
    {
        if ((x % 10 ) % 2 == 0)
            printf("%d ", x % 10);
        x = x / 10;
    }
    
    x = copy;
    
    printf("\nThe odd digits are : ");
    
    while (x != 0)
    {
        if ((x % 10 ) % 2 != 0)
            printf("%d ", x % 10);
        x = x / 10;
    }

    return 0;
}
