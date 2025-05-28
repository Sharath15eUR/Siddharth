#include <stdio.h>

// Function to rearrange array: evens before odds, relative order preserved
void rearrangeEvenOdd(int *arr, int size) {
    int *temp = (int *)malloc(size * sizeof(int));
    int *evenPtr = temp;
    int *oddPtr;

    // First pass: copy even numbers
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 == 0) {
            *evenPtr = *(arr + i);
            evenPtr++;
        }
    }

    // Mark where odds should start
    oddPtr = evenPtr;

    // Second pass: copy odd numbers
    for (int i = 0; i < size; i++) {
        if (*(arr + i) % 2 != 0) {
            *oddPtr = *(arr + i);
            oddPtr++;
        }
    }

    // Copy back to original array
    for (int i = 0; i < size; i++) {
        *(arr + i) = *(temp + i);
    }

    free(temp); // Clean up
}

// Function to print array using pointer arithmetic
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 8, 5, 2, 9, 4, 6, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    rearrangeEvenOdd(arr, size);

    printf("Rearranged array (evens first, order preserved):\n");
    printArray(arr, size);

    return 0;
}
