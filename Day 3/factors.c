// Print factors

#include <stdio.h>

int isFactor(int key, int num)
{
    if (num % key == 0)
        return 1;
    else
        return 0;
}


int main()
{
    int num;
    printf("\nEnter a number : ");
    scanf("%d", &num);
    
    printf("\nThe factors of the number are : \n");
    for (int i = 1; i <= num; i++)
    {
        if (isFactor(i, num))
            printf("%d ", i);
    }
    
    printf("\n");
    return 0;
}
