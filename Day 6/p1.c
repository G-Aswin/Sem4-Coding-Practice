#include <stdio.h>
#include <string.h>

void reverse_specific(char *str, int front, int rear)
{
    //front and rear are the indices between which it will reverse
    char temp;
    while (front < rear)
    {
        temp = str[front];
        str[front] = str[rear];
        str[rear] = temp;

        front++;
        rear--;
    }
}

int main()
{
    char str[50];
    printf("\nEnter a string for individual word reversal : ");
    scanf("%[^\n]", str);

    int front = 0, rear = 0;
    for (int i = 0; i <= strlen(str); i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            rear = i - 1;
            reverse_specific(str, front, rear);
            front = i + 1;
        }
    }

    printf("\nThe resultant string is : %s\n", str);


}