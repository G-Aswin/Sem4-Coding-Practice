// 2. Write a program to do the following (Use  array of structures)
//     a. Create a book database (title, author, rice, no_pages)
//     b. Update the book price based on the title.
//     c. Display appropriate message if updation fails.

#include <stdio.h>
#include <string.h>

#define MAX 20

struct book
{
    char title[50], author[50];
    int price, pages;
};

typedef struct book B;

void fill_database(B database[], int *n)
{
    printf("\nEnter the number of entries : ");
    scanf("%d", n);

    if (*n > MAX)
    {
        printf("\nNot enough space! Try again with a smaller number.");
        return;
    }

    for (int i = 0; i < *n; i++)
    {
        printf("\nEnter title, author, price and no. of pages resp : ");
        scanf("%s %s %d %d", database[i].title, database[i].author, &database[i].price, &database[i].pages);
    }

    printf("\n%d Entries successful!", *n);
}

void update(B database[], int n)
{
    char target[50];
    int newprice;
    printf("\nName of the target book ? ");
    scanf("%s", target);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(database[i].title, target) == 0)
        {
            printf("\nBook found! Enter the new price for it : ");
            scanf("%d", &newprice);
            database[i].price = newprice;
            printf("\nPrice updated!");
            return;
        }
    }

    printf("\nTarget book not found!");
}

void printBook(B book)
{
    printf("\nThe book with name \"%s\" is written by \"%s\". Costs Rupees %d and has %d pages.", book.title, book.author, book.price, book.pages);
}

void display(B *database, int n)
{
    for (int i = 0; i < n; i++)
        printBook(database[i]);
}

int main()
{
    int ch, n = 0;
    B database[MAX];

    while (1)
    {
        printf("\n1. Create fresh database\n2. Update a book entry\n3. Display all\nAnything else : exit\n\n: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: fill_database(database, &n);
                    break;

            case 2: update(database, n);
                    break;

            case 3: display(database, n);
                    break;

            default: return 0;            
        }
    }
}