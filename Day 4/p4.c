// WAP to get the first and last occurance of an element in a random array of integers

//P4

#include <stdio.h>

void read_arr(int arr[], int arr_size);
void print_arr(int arr[], int arr_size);
int linear_search(int arr[], int arr_size, int key);

int main()
{
    // array declaration 
    int arr[10], arr_size, key;
    printf("Enter the number of elements \n");
    scanf("%d", &arr_size);
    
    printf("Enter the elements\n");
    read_arr(arr, arr_size);
    
    printf("The array elements are \n");
    print_arr(arr, arr_size);
    
    printf("\nEnter the number to search : ");
    scanf("%d", &key);
    linear_search(arr, arr_size, key);
    return 0;
}  

void read_arr(int arr[], int arr_size) 
{
    for(int i = 0; i < arr_size; i++)
    {
        scanf("%d", &arr[i]);
    }
}
    
void print_arr(int arr[], int arr_size) 
{
    for(int i = 0; i < arr_size; i++)
    {
        printf("%d\t", arr[i]);
    }
}
    
 int linear_search(int arr[], int arr_size, int key)
 {
    int first = -1, last = -1;
    
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] == key)
        {
            if (first == -1)
                first = i;
            last = i;
        }
    }
    
    if (last == -1)
        printf("\nSearch unsuccessful.\n");
    else
    {
        printf("\nSearch Successful.");
        printf("\nFirst occurance of the key is = %d", first + 1);
        printf("\nLast occurance of the key is = %d", last + 1);
    }
 }