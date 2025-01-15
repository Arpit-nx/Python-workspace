#include <stdio.h>
#include <string.h>

struct students{
    char name[100];
    int roll;
    float cgpa;
};

int main() 
{
    struct students s1;
    s1.roll = 220014;
    s1.cgpa = 9.2;
    strcpy(s1.name , "ARPIT SINGH");

    printf("Student's name : %s\n", s1.name);
    printf("Student's roll : %d\n", s1.roll);
    printf("Student's cgpa : %f\n", s1.cgpa);
     
    return 0;
}