#include <stdio.h>

int stringlength(char arr[])
{
    int l = 0;
    while (arr[l] != '\0')
        l++;
    return l;   
}

int main()
{
    char str[50];
    printf("\nEnter a string to be broken down into words : ");
    gets(str);

    printf("\nThe individual words are ->\n");
    for (int i = 0; i < stringlength(str); i++)
    {
        if (str[i] != ' ')
            printf("%c", str[i]);
        else
            printf("\n");
    }
}