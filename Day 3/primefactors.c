//Prime factors

#include <stdio.h>

int isFactor(int key, int num)
{
    if (num % key == 0)
        return 1;
    else
        return 0;
}

int isPrime(int num)
{
    if (num == 1)
        return 0;
        
    if (num == 2)
        return 1;
    
    for (int i = 2; i <= num/2; i++)
    {
        if (num % i == 0)
            return 0;
    }
    
    return 1;
}


int main()
{
    int num;
    printf("\nEnter a number : ");
    scanf("%d", &num);
    
    printf("\nThe prime factors of num is : ");
    for (int i = 1; i <= num; i++)
    {
        if (isPrime(i) && isFactor(i, num))
            printf("%d ", i);
    }

    return 0;
}
