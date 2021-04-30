#include<stdio.h>
#include<math.h>

int main(void)
{
    int num, sum = 0, flag = 1;
    printf("Enter the required number: ");
    scanf("%d", &num);
    while (num != 0 && sum != 1)
    {
        int digit = num % 10;
        sum = sum + (digit * digit);
        num = num / 10;
        if (num == 0)
        {
            if (sum == 4)
            {
                flag = 0;
            }
            if (sum != 1 && sum != 4)
            {
                num = sum;
                sum = 0;
            }
        }
    }
    if (sum == 1)
    {
        printf("\nHAPPY NUMBER");
    }
    else if (flag == 0)
    {
        printf("UNHAPPY NUMBER");
    }
    
}