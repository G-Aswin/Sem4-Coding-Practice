//Structure question


#include <stdio.h>

struct student
{
    int usn;
    char name[50];
};
typedef struct student s;

void insert_at(s data[], int *size, s temp, int pos);
void insert(s data[], int *size, int n);
void printdata(s data[], int size);
void delete_at(s data[], int *size, int usn);



int main()
{
    int n, ch, size = 0;
    s data[15];
    
    
    while (1)
    {
        printf("\n1. Insert n values\n2. Display\n3. Delete a value\n: ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1: printf("\nEnter the number of entries : ");
                    scanf("%d", &n);
                    insert(data, &size, n);
                    break;
                    
            case 2: printdata(data, size);
                    break;
                    
            case 3: printf("\nEnter the usn to delete : ");
                    scanf("%d", &n);
                    delete_at(data, &size, n);
                    break;
                
            default: return 0;
        }
    }

    return 0;
}

void insert_at(s data[], int *size, s temp, int pos)
{    
    for (int i = *size - 1; i != pos - 1; i--)
        data[i + 1] = data[i];
    
    data[pos] = temp;
    *size = *size + 1;
    return;
}


void insert(s data[], int *size, int n)
{
    s temp;
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the name and usn respectively : ");
        scanf("%s %d", temp.name, &temp.usn);
        int i = 0;
        while(i < *size && data[i].usn < temp.usn)
            i++;
            
        insert_at(data, size, temp, i);
    }
}

void printdata(s data[], int size)
{
    int ch;
    printf("\n1 for ascending and 2 for descending.\nchoice: ");
    scanf("%d", &ch);
    
    if (ch == 1)
    {
        for (int i = 0; i < size; i++)
        {
            printf("\n%d %s", data[i].usn, data[i].name);
        }
        printf("\n");
    }
    else
    {
        for (int i = size - 1; i >= 0; i--)
        {
            printf("\n%d %s", data[i].usn, data[i].name);
        }
        printf("\n");
    }
    
}

void delete_at(s data[], int *size, int usn)
{
    int pos = -1;
    for (int i = 0; i < *size; i++)
    {
        if (data[i].usn == usn)
        {
            pos = i;
            break;
        }
    }
    
    if (pos == -1)
    {
        printf("\nNot found!.\n");
        return;
    }
    
    for (int i = pos; i < *size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    *size = *size - 1;
    
    return;
}
