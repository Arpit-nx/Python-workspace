#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int c = 0;

struct stack {
    int a[SIZE];
    int top;
};

typedef struct stack st;

void ces(st *s) {
    s->top = -1;
}

int Isoverflow(st *s) {
    if (s->top == SIZE - 1)
        return 1;
    else
        return 0;
}

int Isunderflow(st *s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void push(st *s, int val) {
    if (Isoverflow(s))
        printf("STACK OVERFLOW !!\n");
    else {
        s->top++;
        s->a[s->top] = val;
        c++;
    }
}

void pop(st *s) {
    if (Isunderflow(s))
        printf("STACK UNDERFLOW !!\n");
    else {
        printf("Pop Element is %d\n", s->a[s->top]);
        s->top--;
        c--;
    }
}

void PrintStack(st *s) {
    printf("Current Stack\n");
    for (int i = 0; i <= s->top; i++) {
        printf("%d\t", s->a[i]);
    }
    printf("\n");
}

int main() {
    
    st *s = (st *)malloc(sizeof(st));
    if (s == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int n, j;
    while(n != 5){

    printf("\nPress 1 to create\n");
    printf("Press 2 to Push\n");
    printf("Press 3 to Pop\n");
    printf("Press 4 to print\n");
    printf("Press 5 to exit\n");

    printf("Enter your choice : ");
    scanf("%d", &n);

    switch (n) {
        case 1: 
            ces(s);
            break;

        case 2:
            printf("Enter the number to push : ");
            scanf("%d", &j);
            push(s, j);
            break;

        case 3:
            pop(s);
            break;

        case 4:
            PrintStack(s);
            break;

            case 5 : printf("Exiting...");
            //free(s);
            exit(0);
            break;

        default:
            printf("Please enter number between 1 to 5...\n");
            break;
        }
    }

    free(s); // Free the allocated memory
    return 0;
}
