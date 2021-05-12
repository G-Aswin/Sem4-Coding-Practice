#include <stdio.h>
#include <string.h>

int getMaxOccurance(char *str, int *freq)
{
    for (int i = 0; i < strlen(str); i++)
        freq[str[i]]++;
    int maxocc = 0;

    for (int i = 1; i < 256; i++)
    {
        if (freq[i] > maxocc)
            maxocc = freq[i];
    }

    return maxocc;
}

int main()
{
    char str[50];
    printf("\nEnter a string : ");
    scanf("%[^\n]", str);

    int freq[256] = {0};

    int maxocc = getMaxOccurance(str, freq);

    printf("Following are the max occuring characters (%d times) : ", maxocc);
    for (int i = 0; i < 256; i++)
        if(freq[i] == maxocc)
            printf("%c ", i);
}