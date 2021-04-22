//Decimal to binary

#include <stdio.h>
#include <string.h>

void stringrev(char str[])
{
    char temp;
    for (int i = 0; i < strlen(str)/2; i++)
    {
        temp = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = temp;
    }
}

int main()
{
    int num, copy;
    printf("\nEnter a number to convert to binary : ");
    scanf("%d", &num);
    copy = num;
    
    char bin[50];
    int k = 0;
    
    while(num)
    {
        if (num % 2 == 0)
            bin[k++] = '0';
        else
            bin[k++] = '1';
        
        num /= 2;
    }
    
    bin[k] = '\0';
    
    stringrev(bin);
    
    printf("\nThe binary equivalent of %d is %s\n.", copy, bin);

    return 0;
}
