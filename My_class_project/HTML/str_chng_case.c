#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter the string : ");
    fgets(str , sizeof(str) , stdin);

    for(int i=0 ; str[i] != '\0' ; i++)
    {
        if(str[i] >= 97 && str[i] <= 122)
        str[i] = str[i] - 32;
    }

    printf("O/p after changed case : %s" , str);

    return 0;
}