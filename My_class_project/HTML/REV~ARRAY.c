#include <stdio.h>

int rev(int arr[], int n);

int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter  the  values of the array : ");
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d", &arr[i]);
    }
    rev(arr,n);
    // printarr(arr,5);
    return 0;
}

int rev(int arr[], int n)
{
    for(int i=0; i<n/2; i++)
    {
        int first = arr[i];
        int second = arr[n-i-1];
        arr[i] = second;
        arr[n-i-1] = first;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}


// int REVARRAY(int arr[] ,int n)
//   {
//     for(int i=0 ; i<n/2 ; i++)
//     {
//         int firstvalue = arr[i];
//         int secondvalue = arr[n-i-1]; 
//         arr[i] = secondvalue;
//         arr[n-i-1] = firstvalue;
//     }
//     for(int i = 0 ; i<n ; i++);
//     {
//         printf("%d", arr[i]);
//     }
//     return
//   }

// int main() 
// {
//     int n;
//     printf("Enter the size of the array : ");
//     scanf("%d", &n);
//     int arr[n];
//     printf("Enter  the  values of the array : ");
//     for(int i=0 ; i<n ; i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     REVARRAY(arr , n);

//  for(int i=0 ; i<n ; i++)
//  {
//     {
//      printf("%d\t", arr[i]);
//     }
//     printf("\n");
//  }

// }

