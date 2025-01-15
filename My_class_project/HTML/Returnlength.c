#include <stdio.h>
#include <string.h>
`
int main()
{
    char str[100];

    printf("Enter your full name : ");
    fgets(str, sizeof(str), stdin);

    int length;
    length = strlen(str);

    printf("No. of characters in your name is %d", length);

    return 0;
}