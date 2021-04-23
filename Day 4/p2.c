//P2

#include <stdio.h>
void read_arr(int arr[], int arr_size);
void print_arr(int arr[], int arr_size);
void print_odd(int arr[], int arr_size);
int main()
{
    // array declaration 
    int arr[10], arr_size;
    printf("Enter the number of elements\n");
    scanf("%d", &arr_size);
    read_arr(arr, arr_size);
    
    printf("\nThe array elements are \n");
    print_arr(arr, arr_size);
    
    printf("\nThe  odd elements are\n");
    print_odd(arr, arr_size);
}  

void read_arr(int arr[], int arr_size)
{
    printf("\nEnter the elements :");
    for (int i = 0; i < arr_size; i++)
        scanf("%d", &arr[i]);
    printf("\nArray elements entered succesfully.\n");
}

void print_arr(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
        printf("%d\t", arr[i]);
}

void print_odd(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
        if (arr[i] % 2 == 1)
            printf("%d\t", arr[i]);
}