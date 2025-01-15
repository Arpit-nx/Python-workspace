#include <stdio.h>
#include <stdlib.h>

///Define the structure of the node
struct Node
{
    int data;
    struct Node* next;
};

//Function to create a new node
struct Node*createNode(int data)
{
    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed !\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to insert a node at beginning of the list
void insertAtBeginning(struct Node**head, int data)
{
    struct Node*newNode = createNode(data);
    if(*head == NULL)
    {
        newNode->next = newNode;// Circular link
        *head = newNode;
    }
    else
    {
        struct Node*temp = *head;
        while(temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

//Function to insert a node at the end of the list
void insertAtEnd(struct Node**head, int data)
{
    struct Node*newNode = createNode(data);
    if(*head == NULL)
    {
        newNode->next = newNode;//Circular list
        *head = newNode;
    }
    else
    {
        struct Node*temp = *head;
        while(temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

//Function to insert a node at the middle of the list
void insertAtMid(struct Node**head, int data, int position)
{
    if(position <= 0)
    {
        printf("Invalid position !");
        return;
    }
    if(position == 1)
    {
        insertAtBeginning(head, data);
        return;
    }
    struct Node*newNode = createNode(data);
    struct Node*temp = *head;
    for(int i = 1; i < position-1 && temp != NULL; i++)
    {
        temp =  temp->next;
    }
    if(temp == NULL)
    {
        printf("Position out of range !\n");
        return;
    }
    newNode->next =  temp->next;
    temp->next = newNode;
} 

//Function to delete node at the beginning of the list
void deleteAtbeginning(struct Node**head)
{
    if(*head == NULL)
    {
        printf("List is empty !");
        return;
    }
    if((*head)->next == *head)
    {
        //Only one node
        free(*head);
        *head = NULL;
    }
    else{
        struct Node*temp = *head;
        while(temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        struct Node*delNode = *head;
        *head = (*head)->next;
        free(delNode);
    }
}

//Function to delete node at the end of the list
void deleteAtEnd(struct Node** head)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->next == *head)
    {
        // Only one node
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp->next != *head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

//Function to delete a node at the middle list by value
void deleteByValue(struct Node**head, int value)
{
    if(*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node*temp = *head;
    struct Node*prev = NULL;
    do{
        if(temp->data == value)
        {
            if(prev == NULL)
            {
                //Node to be deleted is the head node
                deleteAtbeginning(head);
                return;
            }
            else 
            {
                prev->next = temp->next;
                free(temp);
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    }
    while(temp != *head);
    printf("Value not found in the list!\n");
}

//Function to search for a value in the list
int search(struct Node*head, int value)
{
    if(head == NULL)
    {
        printf("List is empty!\n");
        return 0;
    }
    struct Node*temp = head;
    int position = 1;
    do{
        if(temp->data == value)
        {
            printf("%d found at position %d\n", value,position);
            return 1;
        }
        position++;
        temp = temp->next;
    }
    while(temp != head);
    printf("%d not found in the list.\n", value);
    return 0;
}

//Function to display the circular linked list
void display(struct Node*head) {
    if(head == NULL)
    {
        printf("List is empty !");
        return;
    }

    struct Node*temp = head;
    do{
        printf("%d->", temp->data);
        temp = temp->next;
    }
    while(temp != head);
    printf("(Head)\n");
}

int main()
{
    struct Node*head = NULL;
    int choice, data, position, value;

    while(1)
    {
        printf("\n\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at mid\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete by value\n");
        printf("7. search\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
{
    case 1: 
        printf("Enter the value to be inserted in the beginning: ");
        scanf("%d", &data);
        insertAtBeginning(&head, data);
        break;
    case 2: 
        printf("Enter the value to be inserted in the end: ");
        scanf("%d", &data);
        insertAtEnd(&head, data);
        break;
    case 3: 
        printf("Enter the value to be inserted and the position of insertion: ");
        scanf("%d%d", &data, &position);
        insertAtMid(&head, data, position);
        break;
    case 4: 
        deleteAtbeginning(&head);
        break;
    case 5: 
        deleteAtEnd(&head);
        break;
    case 6: 
        printf("Enter the value to be deleted: ");
        scanf("%d", &value);
        deleteByValue(&head, value);
        break;
    case 7: 
        printf("Enter the value for search: ");
        scanf("%d", &value);
        search(head, value);
        break;
    case 8: 
        display(head);
        break;
    case 9:
        exit(0);
        break;
    default:
        printf("Enter a valid choice!\n");
        break;
        }
    }
}