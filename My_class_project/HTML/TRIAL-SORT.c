#include <stdio.h>

int main() 
{
   int m,n;

   printf("Enter the dimension of the array :");
   scanf("%d %d", &m,&n);
   
    int a[m][n];

   for(int i=0; i<m; i++)
   {
    for(int j=0; j<=n; j++)
    {
        scanf("%d", &a[i][j]);
         printf("%d", a[i][j]);
    }
   }

   for(int i=0; i<m; i++)
   {
     for(int j=0; j<n; j++)
     {
        for(int x=i; x<m; x++)
        {
            for(int y=j; y<n; y++)
            if(a[i][j]<a[x][y])
            {
                int t=a[i][j];
                a[i][j]=a[x][y];
                a[x][y]=t;
            }
        }
     }
   }
   for(int i=0; i<m; i++)
   {
    for(int j=0; j<n; j++)
    {
        printf("%d", a[i][j]);
    }
    printf("\n");
   }
}