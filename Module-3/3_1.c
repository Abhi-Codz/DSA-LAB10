#include <stdio.h>
#include <stdlib.h> // For malloc and free

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
    if (matrix == NULL || matrix[0].value == 0) {
        printf("Sparse matrix is empty or invalid.\n");
        return;
    }

    // Display header (total_rows, total_cols, num_terms)
    printf("%d %d %d\n", matrix[0].row, matrix[0].col, matrix[0].value);

    // Display each term
    for (int i = 1; i <= matrix[0].value; i++) {
        printf("%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

// Function to transpose a sparse matrix in 3-tuple format
// This function returns a new Term* pointer to the transposed matrix
Term* transposeSparseMatrix(Term *original_matrix) {
    if (original_matrix == NULL || original_matrix[0].value == 0) {
        return NULL; // Return NULL for empty or invalid matrix
    }

    int total_rows = original_matrix[0].row;
    int total_cols = original_matrix[0].col;
    int num_terms = original_matrix[0].value;

    // Allocate memory for the transposed matrix
    // It will have the same number of terms + 1 for the header
    Term *transposed_matrix = (Term *)malloc((num_terms + 1) * sizeof(Term));
    if (transposed_matrix == NULL) {
        printf("Memory allocation failed for transposed matrix!\n");
        exit(1);
    }

    // Set the header for the transposed matrix
    // Rows and columns are swapped compared to the original
    transposed_matrix[0].row = total_cols;
    transposed_matrix[0].col = total_rows;
    transposed_matrix[0].value = num_terms;

    // If there are no terms, return the header only matrix
    if (num_terms == 0) {
        return transposed_matrix;
    }

    // Simple transpose: just swap row and column
    // This doesn't sort the terms by row/column, which is usually desired for sparse matrix transpose.
    // For a more efficient and sorted transpose, a "fast transpose" algorithm is used,
    // which involves counting elements per column and then placing them directly.
    // For simplicity as per the sample output, we'll just swap and then sort.

    // Copy and swap row/col for each term
    for (int i = 1; i <= num_terms; i++) {
        transposed_matrix[i].row = original_matrix[i].col; // New row is old column
        transposed_matrix[i].col = original_matrix[i].row; // New column is old row
        transposed_matrix[i].value = original_matrix[i].value;
    }

    // Now, sort the transposed terms by row, then by column (as per typical sparse matrix representation)
    // This is a simple bubble sort for demonstration. For larger matrices, a more efficient sort
    // like quicksort or mergesort would be used.
    for (int i = 1; i <= num_terms; i++) {
        for (int j = i + 1; j <= num_terms; j++) {
            // Sort by row first
            if (transposed_matrix[i].row > transposed_matrix[j].row) {
                Term temp = transposed_matrix[i];
                transposed_matrix[i] = transposed_matrix[j];
                transposed_matrix[j] = temp;
            } else if (transposed_matrix[i].row == transposed_matrix[j].row) {
                // If rows are same, sort by column
                if (transposed_matrix[i].col > transposed_matrix[j].col) {
                    Term temp = transposed_matrix[i];
                    transposed_matrix[i] = transposed_matrix[j];
                    transposed_matrix[j] = temp;
                }
            }
        }
    }

    return transposed_matrix;
}

int main() {
    Term *original_matrix = NULL;
    Term *transposed_matrix = NULL;
    int total_rows, total_cols, num_terms;

    // Read the original sparse matrix
    readSparseMatrix(&original_matrix, &total_rows, &total_cols, &num_terms);

    // Display the original matrix (optional, for verification)
    // printf("\nOriginal Sparse Matrix:\n");
    // displaySparseMatrix(original_matrix);

    // Transpose the matrix
    transposed_matrix = transposeSparseMatrix(original_matrix);

    // Display the transposed matrix
    printf("\nTranspose of sparse matrix:\n");
    printf("R   C  Element\n"); // Header for output format
    displaySparseMatrix(transposed_matrix);

    // Free the dynamically allocated memory
    if (original_matrix != NULL) {
        free(original_matrix);
        original_matrix = NULL;
    }
    if (transposed_matrix != NULL) {
        free(transposed_matrix);
        transposed_matrix = NULL;
    }

    return 0;
}
