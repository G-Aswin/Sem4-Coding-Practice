// 2. Write separate functions to delete a node from SLL based on i) position ii) based on name use the previously defined structure.


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

int getsize(NODE head)
{
    int c = 0;
    NODE curr = head;

    while(curr)
    {
        c++;
        curr = curr->link;
    }

    return c;
}

NODE delete_basedon_idx(NODE head)
{
    int idx;
    printf("\nEnter the index to delete : ");
    scanf("%d", &idx);

    if (idx < 0 || idx >= getsize(head))
    {
        printf("\nIndex out of bounds!");
        return head;
    }

    NODE curr = head, prev = NULL;

    while(idx != 0)
    {
        prev = curr;
        curr = curr->link;
        idx--;
    }

    if (!prev)
    {
        NODE temp = head;
        head = head->link;
        free(temp);
    }
    else
    {
        NODE temp = curr;
        prev->link = curr->link;
        free(temp);
    }

    printf("\nIndex deleted successfully.");
    return head;
}


NODE delete_basedon_name(NODE head)
{
    char name[20];
    printf("\nEnter the name to delete : ");
    scanf("%s", name);

    NODE curr = head, prev = NULL;

    if (!head)
    {
        printf("\nNo nodes!");
        return head;
    }

    while (curr != NULL)
    {
        if (strcmp(curr->name, name) == 0)
            break;

        prev = curr;
        curr = curr->link;
    }

    if (!curr)
    {
        printf("\nName not found!");
        return head;
    }
    else if (!prev)
    {
        NODE temp = head;
        head = head->link;
        free(temp);
        printf("\n%s deleted succesfully!", name);
        return head;
    }
    else
    {
        NODE temp = curr;
        prev->link = curr->link;
        free(temp);
        printf("\n%s deleted succesfully!", name);
        return head;
    }
}

int main()
{
    NODE head = NULL;
    int ch;
    char name[20];

    while (1)
    {
        printf("\n1. Insert a name\n2. Display\n3. Delete based on index\n4. Delete based on name\nAnything else : exit\n\n: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("\nEnter a name to insert : ");
                    scanf("%s", name);
                    head = insert_sorted(head, name);
                    break;

            case 2: display(head);
                    break;

            case 3: head = delete_basedon_idx(head);
                    break;
            
            case 4: head = delete_basedon_name(head);
                    break;
            
            default: return 0;
        }
    }
}