#include <stdio.h>

int main()
{
    int count, n;
    printf("Enter the number : ");
    scanf("%d", &n);

    if(n == 1)
    {
        printf("True");
    }

    else{
    for (int i = 2; i <= 100; i++)
    {
        count = n % 2;
    }
    if (count == 0)
    {
        printf("True");
    }
    else
        printf("False");
    }
}