#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node 
{ 
	char name[20];
	struct node *link;
};

typedef struct node * NODE;

NODE getnode()
{
    NODE x = (NODE) malloc(sizeof(struct node));
    if (x)
        return x;
    exit(0);
}

NODE insert_sorted(NODE head, char *name)
{
    NODE new = getnode();
    strcpy(new->name, name);
    new->link = NULL;

    if (!head)
        return new;
    
    NODE curr = head, prev = NULL;

    while(curr != NULL && strcmp(new->name, curr->name) > 0)
    {
        prev = curr;
        curr = curr->link;
    }

    if (!prev)
    {
        new->link = head;
        return new;
    }

    prev->link = new;
    new->link = curr;

    return head;
}

void display(NODE head)
{
    if (!head)
    {
        printf("\nEmpty SLL!");
        return;
    }

    NODE curr = head;
    while(curr)
    {
        printf("\n%s", curr->name);
        curr = curr->link;
    }
}


int main()
{
    NODE head = NULL;
    int ch;
    char name[20];

    while (1)
    {
        printf("\n1. Insert a name\n2. Display\nAnything else : exit\n\n: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("\nEnter a name to insert : ");
                    scanf("%s", name);
                    head = insert_sorted(head, name);
                    break;

            case 2: display(head);
                    break;
            
            default: return 0;
        }
    }
}