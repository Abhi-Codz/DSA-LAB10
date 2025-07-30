#include <stdio.h>
#include <stdlib.h> // For malloc, realloc, free

// Define a structure for a term in the sparse matrix (row, column, value)
typedef struct {
    int row;
    int col;
    int value;
} Term;

// Function to read a sparse matrix in 3-tuple format
// The first line of input specifies total_rows, total_cols, num_terms
// Subsequent lines specify row, col, value for each non-zero term
void readSparseMatrix(Term **matrix, int *total_rows, int *total_cols, int *num_terms) {
    printf("Enter sparse matrix in 3-tuple format (total_rows total_cols num_terms):\n");
    scanf("%d %d %d", total_rows, total_cols, num_terms);

    // Allocate memory for the terms + 1 (for the header term)
    // The first element (index 0) will store the matrix dimensions and number of terms
    *matrix = (Term *)malloc((*num_terms + 1) * sizeof(Term));
    if (*matrix == NULL) {
        printf("Memory allocation failed for sparse matrix!\n");
        exit(1); // Exit if memory allocation fails
    }

    // Store the header information in the first element
    (*matrix)[0].row = *total_rows;
    (*matrix)[0].col = *total_cols;
    (*matrix)[0].value = *num_terms;

    // Read the actual terms
    for (int i = 1; i <= *num_terms; i++) {
        scanf("%d %d %d", &(*matrix)[i].row, &(*matrix)[i].col, &(*matrix)[i].value);
    }
}

// Function to display a sparse matrix in 3-tuple format
void displaySparseMatrix(Term *matrix) {
    if (matrix == NULL) {
        printf("Sparse matrix is NULL.\n");
        return;
    }
    if (matrix[0].value == 0 && matrix[0].row == 0 && matrix[0].col == 0) {
        // This case handles an empty matrix that was explicitly created as such
        printf("0 0 0\n"); // Represent an empty matrix
        return;
    }

    // Display header (total_rows, total_cols, num_terms)
    printf("%d %d %d\n", matrix[0].row, matrix[0].col, matrix[0].value);

    // Display each term
    for (int i = 1; i <= matrix[0].value; i++) {
        printf("%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

// Function to add two sparse matrices in 3-tuple format
// Assumes input matrices are sorted by row, then by column.
Term* addSparseMatrices(Term *matrix1, Term *matrix2) {
    // Check for NULL matrices
    if (matrix1 == NULL || matrix2 == NULL) {
        printf("One or both input matrices are NULL.\n");
        return NULL;
    }

    // Get header information
    int r1 = matrix1[0].row;
    int c1 = matrix1[0].col;
    int n1 = matrix1[0].value;

    int r2 = matrix2[0].row;
    int c2 = matrix2[0].col;
    int n2 = matrix2[0].value;

    // Check if dimensions are compatible for addition
    if (r1 != r2 || c1 != c2) {
        printf("Matrices have incompatible dimensions for addition.\n");
        return NULL;
    }

    // Allocate memory for the resultant matrix. Max possible terms = n1 + n2.
    // +1 for the header term.
    Term *resultant_matrix = (Term *)malloc((n1 + n2 + 1) * sizeof(Term));
    if (resultant_matrix == NULL) {
        printf("Memory allocation failed for resultant matrix!\n");
        exit(1);
    }

    // Initialize indices for iterating through matrices
    int i = 1; // Index for matrix1 (skip header)
    int j = 1; // Index for matrix2 (skip header)
    int k = 1; // Index for resultant_matrix (skip header)

    // Merge-like addition
    while (i <= n1 && j <= n2) {
        // Compare terms based on row first, then column
        if (matrix1[i].row < matrix2[j].row ||
            (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) {
            // Term from matrix1 comes first, copy it to result
            resultant_matrix[k++] = matrix1[i++];
        } else if (matrix1[i].row > matrix2[j].row ||
                   (matrix1[i].row == matrix2[j].row && matrix1[i].col > matrix2[j].col)) {
            // Term from matrix2 comes first, copy it to result
            resultant_matrix[k++] = matrix2[j++];
        } else {
            // Terms have the same (row, col) - add their values
            int sum_val = matrix1[i].value + matrix2[j].value;
            if (sum_val != 0) { // Only add to result if sum is non-zero
                resultant_matrix[k].row = matrix1[i].row;
                resultant_matrix[k].col = matrix1[i].col;
                resultant_matrix[k].value = sum_val;
                k++;
            }
            i++; // Move to next term in matrix1
            j++; // Move to next term in matrix2
        }
    }

    // Copy remaining terms from matrix1 (if any)
    while (i <= n1) {
        resultant_matrix[k++] = matrix1[i++];
    }

    // Copy remaining terms from matrix2 (if any)
    while (j <= n2) {
        resultant_matrix[k++] = matrix2[j++];
    }

    // Update the header of the resultant matrix
    resultant_matrix[0].row = r1; // Rows are same as original
    resultant_matrix[0].col = c1; // Cols are same as original
    resultant_matrix[0].value = k - 1; // Total number of non-zero terms in result

    // Reallocate to the exact size if needed to save memory
    // Check if k is greater than 0 before reallocating to avoid issues with 0-sized realloc
    if (k > 0) {
        Term *temp = (Term *)realloc(resultant_matrix, k * sizeof(Term));
        if (temp == NULL && k > 0) { // realloc can return NULL on failure, but old pointer is still valid
            printf("Memory reallocation failed for resultant matrix (shrinking)!\n");
            // In a real application, you might handle this more gracefully
        } else {
            resultant_matrix = temp;
        }
    } else { // If k is 0, it means no terms, so free the initial allocation
        free(resultant_matrix);
        resultant_matrix = NULL;
    }


    return resultant_matrix;
}

int main() {
    Term *matrix1 = NULL;
    Term *matrix2 = NULL;
    Term *resultant_matrix = NULL;

    int r1, c1, n1; // Dimensions for matrix 1
    int r2, c2, n2; // Dimensions for matrix 2

    printf("Enter sparse matrix-1 in 3-tuple format\n");
    readSparseMatrix(&matrix1, &r1, &c1, &n1);

    printf("\nEnter sparse matrix-2 in 3-tuple format\n");
    readSparseMatrix(&matrix2, &r2, &c2, &n2);

    // Perform addition
    resultant_matrix = addSparseMatrices(matrix1, matrix2);

    printf("\nResultant Matrix in 3-tuple format\n");
    if (resultant_matrix != NULL) {
        displaySparseMatrix(resultant_matrix);
    } else {
        printf("Could not compute resultant matrix or matrices were incompatible.\n");
    }

    // Free dynamically allocated memory
    if (matrix1 != NULL) {
        free(matrix1);
        matrix1 = NULL;
    }
    if (matrix2 != NULL) {
        free(matrix2);
        matrix2 = NULL;
    }
    if (resultant_matrix != NULL) {
        free(resultant_matrix);
        resultant_matrix = NULL;
    }

    return 0;
}
