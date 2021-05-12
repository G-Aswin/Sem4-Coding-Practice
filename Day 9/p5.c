#include <stdio.h>

void getArrayElements(int *arr, int n)
{
    printf("\nEnter %d elements in order : ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\nElements entered successfully.");
}

int getMaxIDX(int *arr, int n)
{
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[idx])
            idx = i;
    }

    return idx;
}

int main()
{
    int arr[20], n;
    printf("\nEnter the size of the array (max 20) : ");
    scanf("%d", &n);

    getArrayElements(arr, n);

    int maxidx = getMaxIDX(arr, n);
    
    printf("\nThe largest number is : %d", arr[maxidx]);
    
    printf("\nElements before largest : ");
    for (int i = 0; i < maxidx; i++)
        printf("%d ", arr[i]);

    printf("\nElements after largest : ");
    for (int i = maxidx + 1; i < n; i++)
        printf("%d ", arr[i]);
}