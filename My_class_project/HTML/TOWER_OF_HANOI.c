#include <stdio.h>

int Tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod, int *count);

int main() {
    int n, count = 0;
    char from_rod = 'A', to_rod = 'B', aux_rod = 'C';

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    count = Tower_of_hanoi(n, from_rod, to_rod, aux_rod, &count);
    printf("\nTotal moves: %d", count);
    return 0;
}

int Tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod, int *count) {
    if (n == 1) {
        printf("\nMove disk 1 from rod %c to rod %c", from_rod, to_rod);
        (*count)++;
        return *count;
    }
    Tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod, count);
    printf("\nMove disk %d from rod %c to rod %c", n, from_rod, to_rod);
    (*count)++;
    Tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod, count);
    return *count;
}
