#include <stdio.h>

struct string
{
    char str[50];
};

int stringlength(struct string word)
{
    int l = 0;
    while (word.str[l] != '\0')
        l++;
    
    return l;
}

int isVowel(char ch)
{
    switch(ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U': return 1;
        default: return 0;
    }
}

void convert(struct string *word)
{
    for (int i = 0; i < stringlength(*word); i++)
    {
        if ((word->str[i] >= 97 && word->str[i] <= 123) && isVowel(word->str[i]))
            word->str[i] -= 32;
            
        if ((word->str[i] >= 65 && word->str[i] <= 91) && !isVowel(word->str[i]))
            word->str[i] += 32;
    }
}

int main()
{
    struct string word;
    printf("\nEnter the string : ");
    gets(word.str);
    
    convert(&word);
    printf("%s\n", word.str);
}