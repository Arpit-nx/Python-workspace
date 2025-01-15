#include <stdio.h>
#include <stdlib.h>

#define MIN 2
#define MAX 3

struct BTreeNode {
    int val[MAX + 1], count;
    struct BTreeNode *link[MAX + 1];
};

struct BTreeNode *root;

struct BTreeNode *createnode(int val, struct BTreeNode *child) {
    struct BTreeNode *newnode;
    newnode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    newnode->val[1] = val;
    newnode->count = 1;
    newnode->link[0] = root;
    newnode->link[1] = child;
    return newnode;
}

void insertnode(int value, int pos, struct BTreeNode *node, struct BTreeNode *child) {
    int j = node->count;
    while (j > pos) {
        node->val[j + 1] = node->val[j];
        node->link[j + 1] = node->link[j];
        j--;
    }
    node->val[j + 1] = value;
    node->link[j + 1] = child;
    node->count++;
}

void splitnode(int val, int *pval, int pos, struct BTreeNode *node, struct BTreeNode **newnode, struct BTreeNode *child) {
    int median, j;
    if (pos < MIN)
        median = MIN;
    else
        median = MIN + 1;
    *newnode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    j = median + 1;
    while (j <= MAX) {
        (*newnode)->val[j - median] = node->val[j];
        (*newnode)->link[j - median] = node->link[j];
        j++;
    }
    node->count = median;
    (*newnode)->count = MAX - median;
    insertnode(val, pos, node, child);
    *pval = node->val[node->count];
    (*newnode)->link[0] = node->link[node->count];
    node->count--;
}

int setValue(int val, int *pval, struct BTreeNode *node, struct BTreeNode **child) {
    int pos;
    if (!node) {
        *pval = val;
        *child = NULL;
        return 1;
    }
    if (val < node->val[1])
        pos = 0;
    else {
        for (pos = node->count; (val < node->val[pos] && pos > 1); pos--);
        if (val == node->val[pos]) {
            printf("Duplicates are not permitted\n");
            return 0;
        }
    }
    if (setValue(val, pval, node->link[pos], child)) {
        if (node->count < MAX) {
            insertnode(*pval, pos, node, *child);
        } else {
            struct BTreeNode *newchild;
            splitnode(*pval, pval, pos, node, &newchild, *child);
            if (pos > MIN)
                insertnode(*pval, pos, node, *child);
            else
                insertnode(*pval, pos, node, newchild);
        }
    }
    return 0;
}

void insert(int val) {
    int flag, i;
    struct BTreeNode *child;
    flag = setValue(val, &i, root, &child);
    if (flag) {
        root = createnode(i, child);
    }
}

void search(int val, int *pos, struct BTreeNode *mynode) {
    if (!mynode)
        return;
    if (val < mynode->val[1])
        *pos = 0;
    else {
        for (*pos = mynode->count; (val < mynode->val[*pos] && *pos > 1); (*pos)--);
        if (val == mynode->val[*pos]) {
            printf("%d is found.\n", val);
            return;
        } else {
            printf("%d not found !\n", val);
            return;
        }
    }
    search(val, pos, mynode->link[*pos]);
    return;
}

void traversal(struct BTreeNode *mynode) {
    int i;
    if (mynode) {
        for (i = 0; i < mynode->count; i++) {
            traversal(mynode->link[i]);
            printf("%d ", mynode->val[i + 1]);
        }
        traversal(mynode->link[i]);
    }
}

int main() {
    int choice, ch, val;
    while (1) {
        printf("\n1. Insert a value into the B-tree\n");
        printf("2. Search for a value in B-tree\n");
        printf("3. Traverse the B-tree\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insert(val);
                printf("\n%d inserted into the B-tree.\n", val);
                break;

            case 2:
                printf("\nEnter the value to search: ");
                scanf("%d", &val);
                search(val, &ch, root);
                break;

            case 3:
                printf("\nB-tree traversal: ");
                traversal(root);
                printf("\n");
                break;

            case 4:
                printf("\nExiting the program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}