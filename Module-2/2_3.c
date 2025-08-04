/*
Q2.3 WAP to represent a given sparse matrix in 3-tuple format using 2-D array.
*/

#include <stdio.h>

#define SIZE 10

void convertToTuple(int matrix[][SIZE], int rows, int cols, int tuple[][3]) {
    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                tuple[k][0] = i;
                tuple[k][1] = j;
                tuple[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    tuple[0][0] = rows;
    tuple[0][1] = cols;
    tuple[0][2] = k - 1;
}

void displayTuple(int tuple[][3], int count) {
    printf("\n3-Tuple Representation:\n");
    printf("Row  Col  Val\n");
    for (int i = 0; i < count; i++) {
        printf("%3d  %3d  %3d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }
}

int main() {
    int matrix[SIZE][SIZE];
    int tuple[SIZE * SIZE][3];
int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    convertToTuple(matrix, rows, cols, tuple);

    int nonZeroCount = tuple[0][2] + 1;
    displayTuple(tuple, nonZeroCount);

    return 0;
}

/*
> SAMPLE INPUT
______________

    Enter size of the sparse matrix: 45
    Enter elements of sparse matrix: 
        0 0 14 0   0 
        0 28 0 0   0
        0 0  0 35  0
        0 0  0  0  18

> SAMPLE OUTPUT
_______________

    Sparse matrix in 3 - tuple format:
        4 5 4
        0 2 14
        1 1 28
        2 3 35
        3 4 19
*/