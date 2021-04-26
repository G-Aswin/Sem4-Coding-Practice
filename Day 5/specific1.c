#include <stdio.h>
#include <string.h>

int main()
{
    char *tens[] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char *teens[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *ones[] = {"one", "two", "three", "four", "five", "six", "seven","eight", "nine", "ten"};

    int num;
    printf("\nEnter the number to convert into words (0 to 99) : ");
    scanf("%d", &num);

    printf("\nThe answer is : ");
    if (num == 0)
        printf(" zero\n");

    else if (num > 0 && num <= 10)
        printf(" %s\n", ones[num - 1]);

    else if (num >= 11 && num < 20)
        printf(" %s\n", teens[num - 11]);

    else if (num >= 20 && num < 100)
    {
        printf(" %s", tens[(num / 10) - 2]);
        if (num % 10 != 0)
            printf(" %s", ones[(num % 10) - 1]);
    }
}