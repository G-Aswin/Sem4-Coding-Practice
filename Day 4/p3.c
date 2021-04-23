//P3

#include <stdio.h>

//function prototypes 
void read_arr(int arr[], int arr_size);
void print_arr(int arr[], int arr_size);
int ret_max(int arr[], int arr_size);

int main()
{
    // array declaration 
    int arr[10], arr_size;
    printf("Enter the number of elements \n");
    scanf("%d", &arr_size);
    
    printf("Enter the elements\n");
    read_arr(arr, arr_size);
    
    printf("The array elements are \n");
    print_arr(arr, arr_size);
    
    printf("\nThe  maximum element in the arrays is %d\n", ret_max(arr, arr_size));
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
    
 int ret_max(int arr[], int arr_size)
 {
    int max=arr[0];
    
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    
    return max;
 }
