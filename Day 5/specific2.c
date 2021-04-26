#include <stdio.h>
#include <string.h>


void reverse_string(char str[])
{
    char temp;
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main()
{
    char str[50], pat[50], rep[50];

    printf("\nEnter the main string : ");
    gets(str);
    printf("\nEnter the pattern string : ");
    gets(pat);
    printf("\nEnter the replacement string : ");
    gets(rep);

    int s = strlen(str), p = strlen(pat), r = strlen(rep), k = 0, x = 0, count = 2;
    char result[50];

    reverse_string(str);
    reverse_string(pat);
    reverse_string(rep);

    for (int i = 0; i < s; i++)
    {
        x = 0;
        while (pat[x] == str[i + x] && x < p && (i + x) < s)
            x++;
        
        if (x == p && count > 0)
        {
            for (int j = 0; j < r; j++)
                result[k++] = rep[j];
            i += (p - 1);
            count--;
        }
        else
        {
            result[k++] = str[i];
        }
    }
    result[k] = '\0';

    reverse_string(result);
    printf("\nThe result is %s\n", result);
}