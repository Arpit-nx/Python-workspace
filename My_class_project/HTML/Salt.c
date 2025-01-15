# include <stdio.h>
# include <string.h>

int main()
{
    char str[100];
    printf("Enter the password : ");
    scanf("%s", &str);
     //fgets(str, sizeof(str), stdin);
    //THIS FUNCTION WILL CAUSE THE OUTPUT TURN INTO NEW LINE, BETTER TO USE "scanf"... 

    char str2[100]="123";
    printf("New Password : %s",strcat(str , str2));

    return 0;
}