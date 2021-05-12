// 4. write a program in SLL to remove duplicate nodes 
// Input: 5, 8 , 7 , 1, 7, 8
// Output:
// Unique elem in SLL: 5, 8 , 7 , 1
// Elem which are repeated in SLL: 8,7


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node 
{ 
	int empid;
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

NODE insert_front(NODE head, int n)
{
    NODE new = getnode();
    new->empid = n;
    new->link = head;
    head = new;

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
        printf("\n%d", curr->empid);
        curr = curr->link;
    }
}

NODE remove_duplicates(NODE head)
{
    if (head == NULL || head->link == NULL)
        return head;

    NODE i = head;

    printf("\nDuplicates are : ");

    while (i)
    {
        NODE j = i;
        while (j->link)
        {
            if (j->link->empid == i->empid)
            {
                NODE temp = j->link;
                j->link = temp->link;
                free(temp);
                printf("%d ", i->empid);
            }
            else
            {
                j = j->link;
            }
        }
        i = i->link;
    }
    printf("\n");

    return head;
}


int main()
{
    NODE l1;
    int ch, n, x;
    char name[20];

    while (1)
    {
        printf("\n1. Enter a list\n2. Remove duplicates and display\nAnything else : exit\n\n: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: l1 = NULL;
                    printf("\nNumber of nodes for List1? : ");
                    scanf("%d", &n);
                    for (int i = 0; i < n; i++)
                    {
                        printf("\nEnter num : ");
                        scanf("%d", &x);
                        l1 = insert_front(l1, x);
                    }

                    printf("\nYou just entered : ");
                    display(l1);
                    break;

            case 2: l1 = remove_duplicates(l1);
                    printf("\nElements left after removal : ");
                    display(l1);
                    break;

            default: return 0;
        }
    }
}