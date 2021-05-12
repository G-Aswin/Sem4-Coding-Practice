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

NODE insert_sorted(NODE head)
{
    int n;
    printf("\nEnter empno : ");
    scanf("%d", &n);

    NODE new = getnode();
    new->empid = n;
    new->link = NULL;

    if (!head)
        return new;
    
    NODE curr = head, prev = NULL;

    while(curr != NULL && n > curr->empid)
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
        printf("\n%d", curr->empid);
        curr = curr->link;
    }
}


NODE merge(NODE first, NODE second, NODE res)
{
    NODE p1 = first, p2 = second;
    res = getnode();
    res->link = NULL;
    
    NODE k = res;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->empid < p2->empid)
        {
            NODE temp = getnode();
            temp->empid = p1->empid;
            temp->link = NULL;
            p1 = p1->link;

            k->link = temp;
            k = k->link;
        }
        else
        {
            NODE temp = getnode();
            temp->empid = p2->empid;
            temp->link = NULL;
            p2 = p2->link;

            k->link = temp;
            k = k->link;
        }
    }

    if (p1 == NULL)
    {
        while (p2 != NULL)
        {
            NODE temp = getnode();
            temp->empid = p2->empid;
            temp->link = NULL;
            p2 = p2->link;

            k->link = temp;
            k = k->link;
        }
    }
    else
    {
        while (p1 != NULL)
        {
            NODE temp = getnode();
            temp->empid = p1->empid;
            temp->link = NULL;
            p1 = p1->link;

            k->link = temp;
            k = k->link;
        }
    }

    return res->link;
}

int main()
{
    NODE first, second, merged;
    int ch, n;
    char name[20];

    while (1)
    {
        printf("\n1. Fill first SLL\n2. Fill second SLL\n3. Merge two and display result\nAnything else : exit\n\n: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: first = NULL;
                    printf("\nNumber of nodes for List1? : ");
                    scanf("%d", &n);
                    for (int i = 0; i < n; i++)
                        first = insert_sorted(first);
                    
                    printf("\nFinished list 1:");
                    display(first);
                    break;

            case 2: second = NULL;
                    printf("\nNumber of nodes for List2? : ");
                    scanf("%d", &n);
                    for (int i = 0; i < n; i++)
                        second = insert_sorted(second);

                    printf("\nFinished list 2:");
                    display(second);
                    break;

            case 3: merged = NULL;
                    merged = merge(first, second, merged);
                    printf("\nThe merged SLL is : ");
                    display(merged);
                    break;

            default: return 0;
        }
    }
}