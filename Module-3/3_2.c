<<<<<<< HEAD
// 3.2 WAP to perform addition of two given sparse matrix in 3–tuple format.

#include <stdio.h>

#define MAX 100 // Max terms allowed in each matrix (including header)

// Structure to hold one non-zero term
typedef struct 
{
    int row, col, value;
} Term;

// Defining Helper function to sort terms in row-major order (excluding header - TOO COMPLEX LOL)
void sortTerms(Term arr[], int n)
{
    for(int i = 1; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i].row > arr[j].row || 
              (arr[i].row == arr[j].row && arr[i].col > arr[j].col))
            {
                // Swapping elements if out of order
                Term temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    Term m1[MAX], m2[MAX], result[MAX]; // Arrays for input matrices and result
    int r1, c1, t1, r2, c2, t2; // Matrix metadata
    int i = 1, j = 1, k = 1;    // Indices for m1, m2, and result

    // Input for matrix 1
    printf("Enter sparse matrix-1 in 3-tuple format (rows cols non-zero-count):\n");
    if(scanf("%d %d %d", &r1, &c1, &t1) != 3 || t1 >= MAX)
    {
        printf("Error: Invalid input for matrix 1 header.\n");
        return 1;
    }

    m1[0] = (Term){r1, c1, t1}; // Storing header info

    for(int x = 1; x <= t1; x++)
    {
        if(scanf("%d %d %d", &m1[x].row, &m1[x].col, &m1[x].value) != 3)
        {
            printf("Error: Invalid input for matrix 1 term %d.\n", x);
            return 1;
        }
    }

    // Input for matrix 2
    printf("Enter sparse matrix-2 in 3-tuple format (rows cols non-zero-count):\n");
    if(scanf("%d %d %d", &r2, &c2, &t2) != 3 || t2 >= MAX)
    {
        printf("Error: Invalid input for matrix 2 header.\n");
        return 1;
    }

    m2[0] = (Term){r2, c2, t2};

    for(int x = 1; x <= t2; x++)
    {
        if(scanf("%d %d %d", &m2[x].row, &m2[x].col, &m2[x].value) != 3)
        {
            printf("Error: Invalid input for matrix 2 term %d.\n", x);
            return 1;
        }
    }

    // Check dimensions before adding
    if(r1 != r2 || c1 != c2)
    {
        printf("Error: Matrix dimensions do not match for addition.\n");
        return 1;
    }

    // Header for the result matrix
    result[0].row = r1;
    result[0].col = c1;

    // Adding matrices by merging sorted triples
    while(i <= t1 && j <= t2)
    {
        if(m1[i].row < m2[j].row || 
          (m1[i].row == m2[j].row && m1[i].col < m2[j].col))
        {
            result[k++] = m1[i++];
        }
        else if(m1[i].row > m2[j].row || 
               (m1[i].row == m2[j].row && m1[i].col > m2[j].col))
        {
            result[k++] = m2[j++];
        }
        else
        {
            int sum = m1[i].value + m2[j].value;
            if(sum != 0) // Only add to result if non-zero
            {
                result[k++] = (Term){m1[i].row, m1[i].col, sum};
            }
            i++;
            j++;
        }
    }

    // Copy remaining terms from m1 (if any)
    while(i <= t1)
    {
        result[k++] = m1[i++];
    }

    // Copy remaining terms from m2 (if any)
    while(j <= t2)
    {
        result[k++] = m2[j++];
    }

    result[0].value = k - 1; // Set total non-zero count

    // Sort result terms (row-major order)
    sortTerms(result, k);

    // Output the result
    printf("Resultant Matrix in 3-tuple format:\n");
    for(int x = 0; x < k; x++)
    {
        printf("%d %d %d\n", result[x].row, result[x].col, result[x].value);
    }

    return 0;
=======
#include <stdio.h> // Standard input-output library

// Function to add two sparse matrices represented in 3-tuple format.
// matrix1[101][3]: First sparse matrix in 3-tuple format.
// matrix2[101][3]: Second sparse matrix in 3-tuple format.
// result[202][3]: Array to store the sum of the two matrices in 3-tuple format.
//                Max possible non-zero elements is sum of non-zero elements from both + 1 for header.
void addSparseMatrices(int matrix1[101][3], int matrix2[101][3], int result[202][3]) {
    // Get header information from both input matrices.
    int rows1 = matrix1[0][0];
    int cols1 = matrix1[0][1];
    int nonZeroCount1 = matrix1[0][2];

    int rows2 = matrix2[0][0];
    int cols2 = matrix2[0][1];
    int nonZeroCount2 = matrix2[0][2];

    // Check if matrices can be added (must have same dimensions).
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Error: Matrices have different dimensions and cannot be added.\n");
        // Set result header to indicate an invalid operation or empty matrix.
        result[0][0] = 0; result[0][1] = 0; result[0][2] = 0;
        return;
    }

    // Initialize result matrix header with common dimensions.
    result[0][0] = rows1;
    result[0][1] = cols1;
    int k = 1; // Index for placing elements in the result matrix.

    int i = 1, j = 1; // Pointers for iterating through matrix1 and matrix2 elements.

    // Traverse both matrices simultaneously.
    while (i <= nonZeroCount1 && j <= nonZeroCount2) {
        // Compare elements based on their row and then column indices.
        if (matrix1[i][0] < matrix2[j][0]) { // Element from matrix1 comes first (smaller row)
            result[k][0] = matrix1[i][0];
            result[k][1] = matrix1[i][1];
            result[k][2] = matrix1[i][2];
            i++;
        } else if (matrix2[j][0] < matrix1[i][0]) { // Element from matrix2 comes first (smaller row)
            result[k][0] = matrix2[j][0];
            result[k][1] = matrix2[j][1];
            result[k][2] = matrix2[j][2];
            j++;
        } else { // Rows are same, compare columns.
            if (matrix1[i][1] < matrix2[j][1]) { // Element from matrix1 comes first (smaller col)
                result[k][0] = matrix1[i][0];
                result[k][1] = matrix1[i][1];
                result[k][2] = matrix1[i][2];
                i++;
            } else if (matrix2[j][1] < matrix1[i][1]) { // Element from matrix2 comes first (smaller col)
                result[k][0] = matrix2[j][0];
                result[k][1] = matrix2[j][1];
                result[k][2] = matrix2[j][2];
                j++;
            } else { // Both row and column indices are same (common element), so add their values.
                result[k][0] = matrix1[i][0];
                result[k][1] = matrix1[i][1];
                result[k][2] = matrix1[i][2] + matrix2[j][2]; // Add values
                i++;
                j++;
            }
        }
        // Only increment k if the added value is non-zero.
        // If a sum becomes zero, it's no longer a non-zero element in the sparse representation.
        if (result[k][2] != 0) {
            k++;
        }
    }

    // Add any remaining elements from matrix1 (if matrix2 finished first).
    while (i <= nonZeroCount1) {
        result[k][0] = matrix1[i][0];
        result[k][1] = matrix1[i][1];
        result[k][2] = matrix1[i][2];
        i++;
        k++;
    }

    // Add any remaining elements from matrix2 (if matrix1 finished first).
    while (j <= nonZeroCount2) {
        result[k][0] = matrix2[j][0];
        result[k][1] = matrix2[j][1];
        result[k][2] = matrix2[j][2];
        j++;
        k++;
    }

    // Update the non-zero count in the result matrix header.
    // (k-1) because k would have incremented one extra time after the last element.
    result[0][2] = k - 1;
}

int main() {
    int matrix1[101][3], matrix2[101][3]; // Input matrices
    int result[202][3];                   // Result matrix

    int rows1, cols1, nonZeroCount1;
    int rows2, cols2, nonZeroCount2;

    // --- Input for Matrix 1 ---
    printf("Enter sparse matrix-1 in 3-tuple format:\n");
    printf("Enter Total Rows, Total Columns, and Non-Zero Elements Count: ");
    scanf("%d %d %d", &rows1, &cols1, &nonZeroCount1);

    matrix1[0][0] = rows1;
    matrix1[0][1] = cols1;
    matrix1[0][2] = nonZeroCount1;

    printf("Enter %d non-zero elements for matrix-1 (row col value):\n", nonZeroCount1);
    for (int i = 1; i <= nonZeroCount1; i++) {
        scanf("%d %d %d", &matrix1[i][0], &matrix1[i][1], &matrix1[i][2]);
    }

    // --- Input for Matrix 2 ---
    printf("\nEnter sparse matrix-2 in 3-tuple format:\n");
    printf("Enter Total Rows, Total Columns, and Non-Zero Elements Count: ");
    scanf("%d %d %d", &rows2, &cols2, &nonZeroCount2);

    matrix2[0][0] = rows2;
    matrix2[0][1] = cols2;
    matrix2[0][2] = nonZeroCount2;

    printf("Enter %d non-zero elements for matrix-2 (row col value):\n", nonZeroCount2);
    for (int i = 1; i <= nonZeroCount2; i++) {
        scanf("%d %d %d", &matrix2[i][0], &matrix2[i][1], &matrix2[i][2]);
    }

    // Call the function to add the sparse matrices.
    addSparseMatrices(matrix1, matrix2, result);

    // Display the resultant matrix.
    printf("\nResultant Matrix in 3-tuple format\n");
    printf("%d %d %d\n", result[0][0], result[0][1], result[0][2]); // Print header

    for (int i = 1; i <= result[0][2]; i++) {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }

    return 0; // Indicate successful program execution.
>>>>>>> bc643be (Updated code with appropriate commenting to explain the code better)
}

/*
> SAMPLE INPUT
______________

    Enter sparse matrix-1 in 3-tuple format
        4 5 4
        0 3 30
        1 1 10
        2 3 40
        3 4 21

    Enter sparse matrix-2 in 3-tuple format
        4 5 5
        0 2 65
        1 1 12
        2 3 45
        3 3 71
        3 4 0

> SAMPLE OUTPUT
_______________

    Resultant Matrix in 3-tuple format
        4 5 6
        0 2 65
        0 3 30
        1 1 22
        2 3 85
        3 3 71
        3 4 21
*/
