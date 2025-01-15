# include <stdio.h>
# include <string.h>

//FUNCTION WITH CALL BY REFERENCE...
/*void slice(char str[] , int* origin_index , int* end_index);

void slice(char str[] , int* origin_index , int* end_index)
{
    for(int i= *origin_index ; i<= *end_index-1 ; i++)
    {
       printf("%c" , str[i]);   
    }
}*/

//FUNCTION WITH CALL BY VALUE...
void slice(char str[] , int m , int n);

void slice(char str[] , int m , int n)
{
    for(int i= m ; i<= n-1 ; i++)
    {
       printf("%c" , str[i]);   
    }
}

int main() 
{
    char str[100];
    printf("Enter the string : ");
    fgets(str , sizeof(str) , stdin);
    int origin_index , end_index;

    printf("Enter the origin and ending indices :");
    scanf("%d%d", &origin_index, &end_index);

    //THIS IS FOR CALL BY VALUE...
    slice(str, origin_index , end_index);

    //THIS IS FOR CALL BY REFERENCE...
    //slice(str, &origin_index , &end_index);

    return 0;
}