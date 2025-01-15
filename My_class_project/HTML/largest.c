#include <stdio.h>

int main() 
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);

    printf("Enter the values of the array : ");
    int arr[n];
    for(int a = 0; a < n; a++)
    {
        scanf("%d", &arr[a]);
    }

    int max=arr[0];

    for(int i=1 ; i<n ; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }

    printf("the largest number in the array is : %d\n" , max);

    return 0;
}