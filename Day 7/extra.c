#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void nextword(char *str, int *front, int *rear)
{
    int x = *front;
    while (str[x] != ' ' || str[x] != '\0')
        x++;
    x--;
    *rear = x;
}

int main()
{
    char first[50], second[50];

    printf("\nEnter the first and second strings : ");
    gets(first);
    gets(second);

    char code[50]; //"0100010"
    int k = 0;

    char finalstring[100];
    int p = 0;

    int f1 = 0, f2 = 0, r1 = 0, r2 = 0;
    int p1 = 0, p2 = 0, choice;

    while (f1 < strlen(first) && f2 < strlen(second))
    {
        choice = rand() % 2;
        if (choice == 0)
        {
            if (f1 >= strlen(first))
                continue;

            nextword(first, &f1, &r1);
            code[k++] = '0';
            for (int i = f1; i <= r1; i++)
                finalstring[p++] = first[i];

            f1 = r1 + 2;

            finalstring[p++] = ' ';
        }
        else
        {
            if (f2 >= strlen(second))
                continue;

            nextword(second, &f2, &r2);
            code[k++] = '1';
            for (int i = f2; i <= r2; i++)
                finalstring[p++] = second[i];

            f2 = r2 + 2;

            finalstring[p++] = ' ';
        }
    }

    finalstring[p] = '\0';
    printf("\n%s\n", finalstring);



}