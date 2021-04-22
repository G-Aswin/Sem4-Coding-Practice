
//Pronic number 

#include <stdio.h>

int main()
{
    int num, ans = 0;
    printf("\nEnter a number to check if its pronic : ");
    scanf("%d", &num);
    
    for (int i = 1; i <= num/2 && !ans; i++)
    {
        ans = (i*(i + 1) == num) ? 1 : 0;
    }
    
    if (ans == 0)
        printf("\nThe number is not pronic.");
    else
        printf("\nThe number is pronic!");

    return 0;
}
