
// Question 5


#include <stdio.h>

int isprime(int num)
{
    if (num == 2)
        return 1; // indicating TRUE
        
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            return 0; //indicating false
    }
    
    return 1;
}

int main()
{
    int n;
    printf("\nEnter the value of n : ");
    scanf("%d", &n);
    
    printf("\nThe prime number list from 2 to n is : ");
    for (int i = 2; i <= n; i++)
    {
        if (isprime(i))
            printf("%d ", i);
    }

    return 0;
}
