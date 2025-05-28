#include <stdio.h>

#define N 4  // Matrix size (N x N)

int searchMatrix(int matrix[N][N], int key) {
    int row = 0, col = N - 1;

    while (row < N && col >= 0) {
        if (matrix[row][col] == key) {
            return 1;  // Key found
        } else if (matrix[row][col] > key) {
            col--;  // Move left
        } else {
            row++;  // Move down
        }
    }

    return 0;  // Key not found
}

int main() {
    int matrix[N][N] = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int key = 9;

    if (searchMatrix(matrix, key)) {
        printf("Key %d found in the matrix.\n", key);
    } else {
        printf("Key %d not found in the matrix.\n", key);
    }

    return 0;
}
