#include <stdio.h>
 
void transpose(int arr[][2] , int n);

int main() {
    int n,i,j;

    printf("Enter the order of the square matrix : ");
    scanf("%d", &n);

    int arr[n][n];
    printf("Enter the elements of the matrix : ");

    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Original Matrix : \n");
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }

    printf("Tranpose of Matrix : \n");
    transpose(arr , n);

    return 0;
}

void transpose(int arr[][2] , int n)
{
     for(int i=0 ; i<n ; i++)
     {
        for(int j=0 ; j<n ; j++)
        {
            printf("%d  ", arr[j][i]);
        }
        printf("\n");
     }
}