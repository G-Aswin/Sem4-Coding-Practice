#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main()
{
    char str[50] = "init";
    int max = INT_MIN, min = INT_MAX;
    int gotnum = 0, val;

    printf("\nStart the input sequence : ");

    while (1)
    {
        scanf("%s", str);
        if (strcmp(str, "done") == 0)
            break;

        val = atoi(str);

        if (val == 0 && strcmp(str, "0") != 0)
            continue;
        
        else
        {
            if (val > max)
                max = val;
            if (val < min)
                min = val;

            gotnum = 1;
        }
    }

    if (!gotnum)
        printf("\nNo valid integer was given!\n");
    else
        printf("\nThe minimum input was : %d\nThe maximum input was : %d\n", min, max);
}
