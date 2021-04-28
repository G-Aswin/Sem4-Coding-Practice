// 2.	Write a program to check if two given String is the anagram of
//	each other( string is saved in a structure)

#include<stdio.h>
struct str
{
    char a[100];
    char b[100];

};
typedef struct str st;
int slen(char a[])
{
    int len;
    for(len=0;a[len]!='\0';len++);
    // printf("\nlength string : %s\n", a);
    return len;
    
}
void accept(st *s1)
{
    printf("Enter the strings a and b\n");
    gets(s1->a); gets(s1->b);
}

void anagram(st *s1)
{
    //Calculate string length
    int n=slen(s1->a);
    int n1=slen(s1->b);

    // printf("\nafter len : %s %s\n", s1->a, s1->b);

    if(n!=n1)
    {
        printf("The strings are not anagrams\n"); return ;
    }
    //Sort the characters in increasing order such that wen we compare if there are same characters forming 2 words then its anagram

    //Bubble sort

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n-1;j++)
        {
            int temp;
            if(s1->a[i]>s1->a[j])
            {
                temp=s1->a[i];
                s1->a[i]=s1->a[j];
                s1->a[j]=temp;
            }
        }
    }
     for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n-1;j++)
        {
            int temp;
            if(s1->b[i]>s1->b[j])
            {
                temp=s1->b[i];
                s1->b[i]=s1->b[j];
                s1->b[j]=temp;
            }
        }
    }

    // printf("\n%s %s\n", s1->a, s1->b);

    //Comparing each character
    for(int i=0;i<n;i++)
    {
        if(s1->a[i]!=s1->b[i])
        {
            printf("The strings are not anagrams\n"); return ;
        }
    }
    printf("The strings are anagrams\n");
}
int main()
{
    st s1;
    accept(&s1);
    // printf("\n%s %s\n", s1.a, s1.b);
    anagram(&s1);

}