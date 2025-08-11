#include <stdio.h> // Standard input-output library

// Function to transpose a sparse matrix represented in 3-tuple format.
// A[101][3]: The input sparse matrix in 3-tuple format.
//            A[0][0]=rows, A[0][1]=cols, A[0][2]=nonZeroCount.
//            Subsequent rows are [row_index, col_index, value].
// B[101][3]: The output matrix, which will store the transpose in 3-tuple format.
void transposeSparseMatrix(int A[101][3], int B[101][3]) {
    int rows = A[0][0];          // Get total rows from input matrix header.
    int cols = A[0][1];          // Get total columns from input matrix header.
    int nonZeroCount = A[0][2];  // Get total non-zero elements from input matrix header.

    // The header for the transposed matrix:
    // Its rows will be the original matrix's columns.
    // Its columns will be the original matrix's rows.
    // The number of non-zero elements remains the same.
    B[0][0] = cols;
    B[0][1] = rows;
    B[0][2] = nonZeroCount;

    // If there are no non-zero elements, the transpose is also empty.
    if (nonZeroCount == 0) {
        return;
    }

    int k = 1; // Index for placing elements in the transposed matrix B.

    // To transpose, we iterate through columns of the original matrix A (which become rows in B).
    // For each column (c) in the original matrix:
    for (int c = 0; c < cols; c++) {
        // Iterate through the non-zero elements of the original matrix A.
        for (int i = 1; i <= nonZeroCount; i++) {
            // If the current element's column index in A matches the current column 'c' we are processing.
            if (A[i][1] == c) {
                // Then this element belongs to the current column 'c' of the original matrix.
                // In the transpose, its column 'c' becomes its new row.
                // Its row A[i][0] becomes its new column.
                B[k][0] = A[i][1]; // New row is old column.
                B[k][1] = A[i][0]; // New column is old row.
                B[k][2] = A[i][2]; // Value remains the same.
                k++;               // Move to the next position in the transposed matrix B.
            }
        }
    }
}

int main() {
    int A[101][3]; // Input sparse matrix in 3-tuple format.
    int B[101][3]; // Output transposed sparse matrix in 3-tuple format.

    int rows, cols, nonZeroCount;

    printf("Enter sparse matrix in 3-tuple format:\n");
    printf("Enter Total Rows, Total Columns, and Non-Zero Elements Count: ");
    scanf("%d %d %d", &rows, &cols, &nonZeroCount);

    // Store header in A[0]
    A[0][0] = rows;
    A[0][1] = cols;
    A[0][2] = nonZeroCount;

    printf("Enter %d non-zero elements (row col value):\n", nonZeroCount);
    // Read the non-zero elements.
    for (int i = 1; i <= nonZeroCount; i++) {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }

    // Call the function to transpose the sparse matrix.
    transposeSparseMatrix(A, B);

    // Display the transposed sparse matrix.
    printf("\nTranspose of sparse matrix:\n");
    printf("RC Element\n"); // Header as per sample output (Row, Column, Element)
    printf("%d %d %d\n", B[0][0], B[0][1], B[0][2]); // Print the transposed header

    for (int i = 1; i <= B[0][2]; i++) {
        printf("%d %d %d\n", B[i][0], B[i][1], B[i][2]);
    }

    return 0; // Indicate successful program execution.
}
