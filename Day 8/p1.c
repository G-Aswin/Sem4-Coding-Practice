#include <stdio.h>

struct book
{
    int bookid;
    char booktitle[50], author[50];
    int price;
};

typedef struct book B;

void printBook(B book)
{
    printf("\nThe book with ID : %d, \"%s\" is written by \"%s\" and costs Rupees %d.\n", book.bookid, book.booktitle, book.author, book.price);
}

int main()
{
    B book1 = {1, "BookName", "The Author", 500};
    printBook(book1);
}