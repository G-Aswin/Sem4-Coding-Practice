// EMP(empid,ename{efname,emidname,elastname}, esal{ebasic,ehra,eallow, etotalsal},edesig,edeptno)
// ebasic is dependent on edesig if Manager basic is 500000 , Sr Manager 80000,
// ehra is based on edno , if edno =1 then hra is 10% of basic , edno=2 then hra is 20 % of basic
// write functions for accept, display and search based on dno , esal, edesig

#include <stdio.h>
#include <string.h>
#define MAX 20


struct name
{
    char first[50], middle[50], last[50];
};

struct salary
{
    float basic, hra, allow, totalsal;
};

struct EMP
{
    int id;
    struct name ename;
    struct salary esal;
    char designation[50];
    int dno;
};

typedef struct EMP E;

void askname(E *emp)
{
    printf("\nFirst Name : ");
    scanf("%s", emp->ename.first);
    printf("\nMiddle Name : ");
    scanf("%s", emp->ename.middle);
    printf("\nLast Name : ");
    scanf("%s", emp->ename.last);
}

void filldetails(E *emp)
{
    if (strcmp(emp->designation, "manager") == 0)
        emp->esal.basic = 50000;
    else if  (strcmp(emp->designation, "sr manager") == 0)
        emp->esal.basic = 80000;
    else
        emp->esal.basic = 35000;

    if (emp->dno == 1)
        emp->esal.hra = 0.1*emp->esal.basic;
    else if (emp->dno == 2)
        emp->esal.hra = 0.2*emp->esal.basic;
    else
        emp->esal.hra = 0.05*emp->esal.basic;

    emp->esal.totalsal = emp->esal.allow + emp->esal.basic + emp->esal.hra;
}

void accept(E *group, int *n)
{
    printf("\nEnter the number of employees : ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++)
    {
        printf("\nEnter emp id, allowance, designation and dept no resp : ");
        scanf("%d %f %s %d", &group[i].id, &group[i].esal.allow, group[i].designation, &group[i].dno);
        askname(&group[i]);
        filldetails(&group[i]);
    }
}

void display(E *group, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nName : %s %s %s\nID : %d\nDesignation : %s", group[i].ename.first, group[i].ename.middle, group[i].ename.last, group[i].id, group[i].designation);
        printf("\nTotal sal : %f, Breakup(basic, hra, allow) : %f %f %f\n\n", group[i].esal.totalsal, group[i].esal.basic, group[i].esal.hra, group[i].esal.allow);
    }    
}

void search(E *group, int n)
{
    int ch;
    int dno;
    float tsal;
    char tdes[50];

    printf("\nBasis for search? 1. Deptno 2. Salary 3. Designation : ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1: printf("\nEnter the dept no :");
                scanf("%d", &dno);
                for (int i = 0; i < n; i++)
                {
                    if (dno == group[i].dno)
                        display(&group[i], 1);
                }
                break;

        case 2: printf("\nEnter the minimum salary : ");
                scanf("%f", &tsal);
                for (int i = 0; i < n; i++)
                {
                    if (tsal <= group[i].esal.totalsal)
                        display(&group[i], 1);
                }
                break;
        
        case 3: printf("\nEnter the designation : ");
                scanf("%s", tdes);
                for (int i = 0; i < n; i++)
                {
                    if (strcmp(tdes, group[i].designation) == 0)
                        display(&group[i], 1);
                }
                break;
        
        default: return;
    }
}

int main()
{
    int ch, n = 0;
    E group[MAX];

    while (1)
    {
        printf("\n1. Accept n employees\n2. Display all employees\n3. Search\n\n: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: accept(group, &n);
                    break;
            
            case 2: display(group, n);
                    break;
            
            case 3: search(group, n);
                    break;
            
            default: return 0;
        }
    }

}