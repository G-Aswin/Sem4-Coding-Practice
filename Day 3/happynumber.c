//Happy Number

#include <stdio.h>

int next_happy_number(int num)
{
    int sum = 0, digit;
    while(num)
    {
        digit = num % 10;
        sum += (digit*digit);
        num /= 10;
    }
    
    // printf("%d\n", sum);
    
    if (sum != 4)
        return sum;
    else
        return -1;
}

int main()
{
    int num;
    printf("\nEnter a number to check if its a happy number : ");
    scanf("%d", &num);
    
    while (num != -1 && num != 1)
    {
        num = next_happy_number(num);
    }
    
    if (num == -1)
        printf("\nIts an unhappy number.\n");
    else 
        printf("\nIt is a happy number!\n");

    return 0;
}
