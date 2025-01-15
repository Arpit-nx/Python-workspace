//POSTFIX to INFIX conversion

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

//STRUCTURE FOR STACK NODE 
typedef struct StackNode{
    char*data;
    struct StackNode*next;
}StackNode;

//Function to create new Stack Node :
StackNode*createNode(char*data) {
    StackNode*newNode = (StackNode*)malloc(sizeof(StackNode));
    if(newNode == NULL ) {
        printf("Memory allocation failed !\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to check if the given character is an operator...
int IsOperator(char ch) {
    return(ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

//Function to covert postfix expression to infix expression...
char*postfixToInfix(char postfix[]) {
    StackNode*stack = NULL;
    int i;

    for(i=0 ; postfix[i] != '\0' ; i++)
  {
        if(isalnum(postfix[i])) {
            //operand
            char*Operand = (char*)malloc(2*sizeof(char)); //Allocate memory for operand
            Operand[0] = postfix[i];
            Operand[1] = '\0';
            StackNode*node = createNode(Operand);
            node->next = stack;
            stack = node;
        }
    else if(IsOperator(postfix[i])) 
    {
        //Operator
        char*Operand2 = stack->data;
        stack = stack->next;
        char*Operand1 = stack->data;
        stack = stack->next;

        //Combine operands and operator into infix expression
        char*infix = (char*)malloc((strlen(Operand1) + strlen(Operand2) + 4)*sizeof(char));
        sprintf(infix,"(%s %c %s)", Operand1, postfix[i], Operand2);
        StackNode*node = createNode(infix);
        node->next = stack;
        stack = node;   
    }
  }
    return stack->data; //Final infix expression...
}

int main() 
{
    char postfix[MAX_SIZE];
    char*infix;

    printf("Enter the postfix expression :");
    fgets(postfix , MAX_SIZE , stdin);
    postfix[strcspn(postfix, "\n")] = '\0'; //Remove newline character...

    infix=postfixToInfix(postfix);

    printf("Infix expression: %s\n", infix);

    //Free memory allocated in INFIX expression...
    free(infix);

    return 0;
}