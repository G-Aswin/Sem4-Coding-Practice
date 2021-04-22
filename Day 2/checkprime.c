// Question 4
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
    int x;
    printf("\nEnter any number to check if its prime or not : ");
    scanf("%d", &x);
    
    if (isprime(x))
        printf("\n%d is a prime number!\n", x);
    else
        printf("\n%d is not a prime number!\n", x);

    return 0;
}
