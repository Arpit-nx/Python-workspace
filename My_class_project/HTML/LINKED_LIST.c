#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node*next;
};

struct node* createnode(int data) 
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL) 
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertAtBeginning(struct node**head, int data) {
    struct node* newnode=createnode(data);
    newnode->next = *head;
    *head = newnode;
}

void insertAtEnd(struct node** head, int data) {
    struct node*newnode = createnode(data);
    if(*head == NULL) {
        *head = newnode;
        return;
    }
    struct node*temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    } 
    temp->next = newnode;
}

void deletenode(struct node** head, int key){
    struct node*temp = *head;
    struct node*prev = NULL;
    if(temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Key not found in the list");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void display(struct node*head) {
    struct node*temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverse(struct node**head){
    struct node*prev = NULL;
    struct node*current = *head;
    struct node*next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    struct node*head = NULL;
    int choice, data, key;

    while(1) {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete node\n");
        printf("4. Display list\n");
        printf("5. Reverse list\n");
        printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
            printf("Enter data to insert at Beginning : ");
            scanf("%d", &data);
            insertAtBeginning(&head , data);
            break;

            case 2:
            printf("Enter data to insert at end : ");
            scanf("%d", &data);
            insertAtEnd(&head , data);
            break;

            case 3:
            printf("Enter data to Delete : ");
            scanf("%d", &key);
            deletenode(&head , key);
            break;

            case 4:
            printf("Linked LIst : ");
            display(head);
            break;

            case 5:
            printf("Reversed Linked List : ");
            reverse(&head);
            display(head);
            //Reverse the list into its original form by using the furthur operation...
            reverse(&head);
            break;

            case 6:
            exit(0);

            default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}