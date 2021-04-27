#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct str
{
    char cont[100];
};

void Counter(char *str, int *freq)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
            freq[26]++;
        else if (isupper(str[i]))
            freq[str[i] - 'A']++;
        else if (islower(str[i]))
            freq[str[i] - 'a']++;
        else if (isdigit(str[i]))
            freq[str[i] - '0' + 27];
    }
}

void report_anagram(int *f1, int *f2)
{
    for (int i = 0; i < 27; i++)
    {
        if (f1[i] != f2[i])
        {
            printf("\nThese two strings are not anagrams.\n");
            return;
        }
    }
    printf("\nThese two strings were anagrams!\n");
}

// format of freq array ['a - z', ' ', '0 - 9']

int main()
{
    struct str first, second;
    int f1[37] = {0}, f2[37] = {0};

    printf("\nEnter the first string : ");
    scanf("%[^\n]", first.cont);

    printf("\nEnter the second string : ");
    scanf(" %[^\n]", second.cont);

    Counter(first.cont, f1);
    Counter(second.cont, f2);

    report_anagram(f1, f2);
}