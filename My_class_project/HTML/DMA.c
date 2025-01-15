#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *ptr;
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(char));

    ptr = (int*)malloc(5 * sizeof(int));

    ptr[0] = 1;
    ptr[1] = 2;
    ptr[2] = 5;
    ptr[3] = 7;

    for(int i=0 ; i<4 ; i++)
    {
        printf("%d\n", ptr[i]);
    }

    //FOR CALLOC FUNCTION :
    ptr=(int*)calloc(5,sizeof(int));
    //property : Automatically assigns 0 as the basic element...

    //FOR FREE FUNCTION :
    free(ptr);
    //property : used to free memory that is allocated using 'MALLOC or CALLOC' function.

    //FOR REALLOC FUNCTION :
    ptr=realloc(ptr, newsize);
    //property : reallocates(increase or decrease) memory using the same pointer & size.

    return 0;
}