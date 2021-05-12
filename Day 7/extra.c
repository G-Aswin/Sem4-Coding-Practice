#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getwords(char str[100], char words[100][100])
{
    int p = 0;
    int i = 0, j = 0;
    while (p <= strlen(str))
    {
        j = 0;
        while (str[p] != ' ' && str[p] != '\0')
            words[i][j++] = str[p++];
        
        words[i][j] = '\0';
        i++;
        p++;
    }

    words[i][0] = '\0';
}

int transferword(char words[100][100], int row, char final[100], int start)
{
    int p = start, j = 0;
    while (words[row][j] != '\0')
        final[p++] = words[row][j++];
    
    final[p] = ' ';
    return p + 1;
}


int main()
{
    char first[100], second[100], final[200];
    char firstwords[100][100], secondwords[100][100];

    printf("\nEnter the first sentence : ");
    gets(first);

    printf("\nEnter the second sentence : ");
    gets(second);

    getwords(first, firstwords);
    getwords(second, secondwords);

    // int i = 0, j = 0;

    // while (firstwords[i][0] != '\0')
    // {
    //     j = 0;
    //     while(firstwords[i][j] != '\0')
    //     {
    //         printf("%c", firstwords[i][j]);
    //         j++;
    //     }
    //     printf("\n");
    //     i++;
    // }

    int r1 = 0, r2 = 0, p = 0;
    int choice;
    
    char code[50];
    int k = 0;

    while (firstwords[r1][0] != '\0' || secondwords[r2][0] != '\0')
    {
        if (firstwords[r1][0] == '\0')
            choice = 1;
        else if (secondwords[r2][0] == '\0')
            choice = 0;
        else
            choice = rand() % 2;

        if (choice == 0)
        {
            p = transferword(firstwords, r1, final, p);
            r1++;
            code[k++] = '0';
        }
        else
        {
            p = transferword(secondwords, r2, final, p);
            r2++;
            code[k++] = '1';
        }
    }

    final[p] = '\0';
    code[k] = '\0';
    printf("\nThe final string is : %s\nThe encrypt code is : %s\n", final, code);


}