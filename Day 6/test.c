#include <stdio.h>
#include<stdlib.h>

struct node{
    int empid;
    struct node *link;
};
typedef struct node nd;

nd* insert(nd *L)
{
    int id;
    nd *t=NULL;
    nd *p,*n=NULL;
    printf("ENTER EMPLOYEE ID : ");
    scanf("%d",&id);
    
    t=(nd*)malloc(sizeof(nd));
    t->empid=id;
    t->link=NULL;
    
    p=NULL;n=L;
    while(n!=0)
    {
        while(t->empid>n->empid)
        {
            p=n;
            n=n->link;
        }
        if(p==0&&t->empid,n->empid)
        {
            n->link=t;
            return L;
        }
        if(p==0&&t->empid<n->empid)
        {
            t->link=n;
            return t;
        }
        p->link=t;
        t->link=n;
        return L;
        
    }
}

void display(nd *f)
{
    if(!f)
    {
        printf("LL is empty\n");
        return;
    }
    nd *cur=f;
    while(cur)
    {
        printf("%d  ",cur->empid);
        cur=cur->link;
    }
}

nd* merge(nd *L1,nd *L2,nd *res)
{
    nd *t1=L1,*t2=L2,*t=NULL,*last,*copy;
    
   
    while(t1!=NULL&&t2!=NULL)
    {
        if(t1->empid<t2->empid)
        {
           t=(nd*)malloc(sizeof(nd));
           t->empid=t1->empid;
           t->link=NULL; 
           
           if(res==0)
              res->link=t;
           else
            {
              for(last=res;last->link!=NULL;last=last->link);
              last->link=t;
            }
            t1=t1->link;
        }
        else
         {
           t=(nd*)malloc(sizeof(nd));
           t->empid=t2->empid;
           t->link=NULL; 
           
           if(res==0)
              res->link=t;
           else
            {
              for(last=res;last->link!=NULL;last=last->link);
              last->link=t;
            }
            t2=t2->link;
         }
    }
    if(t1==NULL)
    {
        while(t2!=NULL)
        {
            for(last=res;last->link!=NULL;last=last->link);
            last->link=t2->link;
            t2=t2->link;  
        }
    }
    if(t2==NULL)
    {
        while(t1!=NULL)
        {
            for(last=res;last->link!=NULL;last=last->link);
            last->link=t2->link;
            t1=t1->link;  
        }
    }

   return res; 
}




void main()
{
    nd *L1,*L2,*res;
    int ch,n1,n2,i;
    
  for(;;)
  {    
    printf("1.CREATION OF SLL 1\n2.CREATION OF SLL 2\n3.MERGING TWO LISTS\n4.EXIT\n");
    scanf("%d",&ch);
    
    switch(ch)
    {
        case 1:L1=NULL;
               printf("ENTER NUMBER OF ID IN LL 1\n");
               scanf("%d",&n1);
               for(i=0;i<n1;i++)
               {
                   L1=insert(L1);
               }
               printf("LL 1 : ");
               display(L1);
               break;

        case 2:L2=NULL;
               printf("ENTER NUMBER OF ID IN LL 2\n");
               scanf("%d",&n2);
               for(i=0;i<n2;i++)
               {
                   L2=insert(L2);
               }
               printf("LL 2 : ");
               display(L2);
               break;
               
        case 3:res=NULL;
               res=merge(L1,L2,res);    
               printf("AFTER MERGING : ");
               display(res);
               break;
               
        case 4:exit(0);
      
        
    }         
  }
}