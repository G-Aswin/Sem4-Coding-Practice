#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = (char *) calloc(20, 1);
    printf("\nEnter the string : ");
    gets(str);

    printf("\nThe string you just entered is : %s\n", str);    
}