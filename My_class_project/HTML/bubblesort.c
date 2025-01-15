#include <stdio.h>

void bubblesort(int arr[], int n) {
    int temp;
    int swapped; // Flag to track whether any swap occurred in a pass

    for (int i = 0; i < n - 1; i++) {
        swapped = 0; // Initialize swapped to 0 at the beginning of each pass

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1; // Set swapped to 1 if a swap occurs
            }
        }

        // If no swap occurred, the array is already sorted, so break out of the loop
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubblesort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
