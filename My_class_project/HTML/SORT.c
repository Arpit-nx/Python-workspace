#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (used by qsort)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to sort each row of the 2D array
void sortRows(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        qsort(arr[i], cols, sizeof(int), compare);
    } 
}

// Function to display the 2D array
void displayArray(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];

    // Input array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Sort the rows of the 2D array
    sortRows(rows, cols, arr);

    // Display the sorted 2D array
    printf("\nSorted 2D Array:\n");
    displayArray(rows, cols, arr);

    return 0;
}