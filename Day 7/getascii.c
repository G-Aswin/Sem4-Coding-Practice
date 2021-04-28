#include <stdio.h>

int getascii(char ch)
{
    return ch;
}

int main()
{
    char ch;
    printf("\nEnter a character : ");
    scanf("%c", &ch);

    printf("\nThe ascii value of this char is : %d", getascii(ch));
}