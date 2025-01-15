#include <stdio.h>

int main() {
    FILE *fptr;

    fptr = fopen("SECIND-LARGEST.c" , "w"); //OPENING A FILE...

    //char ch;
    //fscanf(fptr, "%c", &ch);
    //printf("character = %c", ch);

    fclose(fptr); //CLOSING A FILE...
    return 0;
}