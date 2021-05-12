#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *getstring(char *str)
{
    str = (char *)calloc(20, 1);
    printf("\nEnter the string : ");
    gets(str);

    return str;
}

int main()
{
    char *str = getstring(str);
    printf("\nThe string you just entered is : %s\n", str);    
}