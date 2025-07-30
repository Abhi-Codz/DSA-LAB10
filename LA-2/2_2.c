#include <stdio.h>

#define SIZE 10

int countNonZero(int matrix[][SIZE], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

void displayUpperTriangular(int matrix[][SIZE], int n) {
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i)
                printf("%d ", matrix[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
void displayAdjacentDiagonals(int matrix[][SIZE], int n) {
    printf("Elements just above and below the main diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i + 1 || j == i - 1)
                printf("%d ", matrix[i][j]);
            else
                printf("  ");
        }
        printf("\n");
    }
}

int main() {
    int matrix[SIZE][SIZE];
    int n;

    printf("Enter size of square matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int nonZero = countNonZero(matrix, n);
printf("\nNumber of non-zero elements: %d\n\n", nonZero);
 displayUpperTriangular(matrix, n);
    printf("\n");

    displayAdjacentDiagonals(matrix, n);

    return 0;
}