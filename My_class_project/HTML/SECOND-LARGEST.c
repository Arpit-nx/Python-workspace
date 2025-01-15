#include <stdio.h>
#include <limits.h>

void SECOND_LARGEST(int arr[] , int n);

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements : ");
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d\t", &arr[i]);
    }

    SECOND_LARGEST(arr , n);

    return 0;
}

void SECOND_LARGEST(int arr[] , int n )
{
  /*  int temp;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
      {
        if(arr[i] > arr[j])
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
      }
    }

    printf("The second largest element in the array is %d...", arr[n-2]);*/

    if (n < 2) {
        printf("Array size is less than 2.\n");
        return;
    }

    int first, second;
    first = second = INT_MIN; // Initialize first and second largest elements

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == INT_MIN) {
        printf("There is no second largest element.\n");
    } else {
        printf("The second largest element in the array is %d.\n", second);
    }
}