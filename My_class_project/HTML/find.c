/*#include <stdio.h>

int main()
{
    int n,num,count=0;
    printf("Enter the size of the array : ");
    scanf("%d", &n);

    printf("Enter the number for finding : ");
    scanf("%d", &num);

    printf("Enter the values of the array : ");
    int find[n];
    for(int a=0 ; a<n ; a++)
    {
        scanf("%d  ", &find[a]);
    }

    for(int i=0 ; i<n ; i++)
    {
        if(find[i] == num)
        count++;
    }

    printf("The no. of times %d occcurs int the array is %d", num, count);

    return 0;
}*/

#include <stdio.h>

int main()
{
    int n, num, count = 0;
    printf("Enter the size of the array : ");
    scanf("%d", &n);

    printf("Enter the values of the array : ");
    int find[n];
    for(int a = 0; a < n; a++)
    {
        scanf("%d", &find[a]);
    }

    printf("Enter the number for finding : ");
    scanf("%d", &num);

    for(int i = 0; i < n; i++)
    {
        if(find[i] == num)
            count++;
    }

    printf("The number %d appears %d times in the array.\n", num, count);
    
    return 0;
}