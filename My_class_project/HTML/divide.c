#include <stdio.h>

void Divide(int dividend , int divisor);

void Divide(int dividend , int divisor)
{
    int quotient, remainder;
    quotient = dividend / divisor;
    remainder = dividend % divisor;

    printf("Quotient is %ld", quotient);
    printf("Remainder is %ld", remainder);
}

int main()
{
    int dividend , divisor;
    printf("Enter dividend and divisor : ");
    scanf("%ld %ld", dividend, divisor);

    Divide(dividend , divisor);
    
    return 0;
}