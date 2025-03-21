#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for(j + 0; j < n2; j++)
    {
        R[j] = arr[m + l + 1];
    }

    i = 0;
    j = 0;
    k = l;
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j]){
        arr[k] = L[i];
        i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int l,int r)
{
    if(l >= r)
    {
        return;
    }

    int m = l + (r - l) / 2;
    
    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);

    merge(arr, l, m, r);
}

/*void printArray(int arr[], int arr_size)
{
    int i;
    printf("Sorted array :\n");
    for(i = 0; i < arr_size; i++)
        printf("%d", arr[i]);
        printf("\n");
}*/

int main()
{
    int arr[] = {13 ,15 ,11 ,9 ,6 ,2};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    mergesort(arr, 0, arr_size - 1);
    //printArray(arr, arr_size);
     printf("Sorted array :\n");
    for(i = 0; i < arr_size; i++)
        printf("%d", arr[i]);
        printf("\n");

    return 0;
}