#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];..
    printf("Enter the string statement : ");
    fgets(str , sizeof(str) , stdin);

    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';


    char ch;
    printf("Enter the character to get checked : ");
    scanf(" %c", &ch);

    int count=0;
    for(int i=0 ; str[i]!='\0' ; i++)
    //(IF U R USING \0 WITH STRING, FIRSTLY INITIALIZE THE LAsT ELEMENT i.e '\n' -> '\0')
    {
       if(str[i] == ch)
       count++;
    }

    if(count == 1)
    printf("Yes! The character exists in the string");

    else
    printf("No! The character does not exist in the string");

    return 0;
}