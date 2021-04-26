#include <string.h>
#include <stdio.h>

int main()
{
    char str[50];
    printf("\nEnter a string to be broken down into words : ");
    gets(str);

    printf("\nThe individual words are ->\n");
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
            printf("%c", str[i]);
        else
            printf("\n");
    }
}