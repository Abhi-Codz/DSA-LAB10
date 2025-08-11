<<<<<<< HEAD
/*
Q2.3 WAP to represent a given sparse matrix in 3-tuple format using 2-D array.
*/

#include <stdio.h>
=======
#include <stdio.h> // Standard input-output library
>>>>>>> d99b03f (Further updates to Lab 1 and Lab 2 assignment codes)

// Function to convert a sparse matrix into its 3-tuple (or triplet) representation.
// sparseMatrix[10][10]: The original sparse matrix (assuming max size 10x10).
// rows: The number of rows in the sparse matrix.
// cols: The number of columns in the sparse matrix.
void convertTo3Tuple(int sparseMatrix[10][10], int rows, int cols) {
    // Declare a 2D array to store the 3-tuple representation.
    // The first row will be for metadata (rows, cols, nonZeroCount).
    // Subsequent rows (up to 100 non-zero elements + 1 for header) will store (row_index, col_index, value).
    int threeTuple[101][3];
    int k = 1; // Index for storing non-zero elements in threeTuple, starts from 1.
               // Row 0 of threeTuple is reserved for the header.

    // First, count the number of non-zero elements in the sparse matrix.
    int nonZeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparseMatrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    // Store the header information in the first row (index 0) of the threeTuple array.
    // Format: [Total Rows, Total Columns, Total Non-Zero Elements]
    threeTuple[0][0] = rows;
    threeTuple[0][1] = cols;
    threeTuple[0][2] = nonZeroCount;

    // Populate the rest of the threeTuple array with the non-zero elements.
    // Iterate through the original sparse matrix.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparseMatrix[i][j] != 0) {
                // If an element is non-zero, store its details in the threeTuple.
                threeTuple[k][0] = i;           // Row index of the non-zero element.
                threeTuple[k][1] = j;           // Column index of the non-zero element.
                threeTuple[k][2] = sparseMatrix[i][j]; // Value of the non-zero element.
                k++; // Move to the next row in threeTuple for the next non-zero element.
            }
        }
    }

    // Display the sparse matrix in 3-tuple format.
    printf("sparse matrix in 3-tuple format\n");
    // Print the header row.
    printf("%d %d %d\n", threeTuple[0][0], threeTuple[0][1], threeTuple[0][2]);
    // Print all the non-zero element rows.
    for (int i = 1; i <= nonZeroCount; i++) {
        printf("%d %d %d\n", threeTuple[i][0], threeTuple[i][1], threeTuple[i][2]);
    }
}

int main() {
    int rows, cols; // Variables for the dimensions of the sparse matrix.
    // Declare a 2D array to hold the sparse matrix. Max size 10x10.
    int sparseMatrix[10][10];

    // Prompt user for the dimensions of the sparse matrix.
    printf("Enter size of the sparse matrix (rows cols): ");
    scanf("%d %d", &rows, &cols);

    // Input validation: Ensure dimensions are within reasonable bounds for the declared array.
    if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10) {
        printf("Invalid matrix dimensions. Please enter rows and columns between 1 and 10.\n");
        return 1; // Exit with an error code.
    }

    // Prompt user to enter elements of the sparse matrix.
    printf("Enter elements of sparse matrix (%d x %d):\n", rows, cols);
    // Nested loops to read elements row by row.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &sparseMatrix[i][j]);
        }
    }

    // Call the function to convert and display the sparse matrix in 3-tuple format.
    convertTo3Tuple(sparseMatrix, rows, cols);

<<<<<<< HEAD
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
=======
    return 0; // Indicate successful program execution.
}
>>>>>>> d99b03f (Further updates to Lab 1 and Lab 2 assignment codes)
