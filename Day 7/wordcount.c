#include <stdio.h>
#include <string.h>

int wordCount(char *str)
{
    int c = 0;
    //every space signifies the end of a word

    for (int i = 0; i <= strlen(str); i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
            c++;
    }

    return c;
}

int main()
{
    char str[50];
    printf("\nEnter a string : ");
    scanf("%[^\n]", str);

    printf("\nNumber of words in this sentence is : %d", wordCount(str));
}