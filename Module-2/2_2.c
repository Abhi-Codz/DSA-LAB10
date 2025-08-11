<<<<<<< HEAD
/*
Q2.2 Write a program to perform the following operations on a given square matrix using functions:
    i. Find the no.of nonzero elements
    ii. Display upper triangular matrix
    iii. Display the elements of just above and below the main diagonal
*/

#include <stdio.h>

#define SIZE 10

int countNonZero(int matrix[][SIZE], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                count++;
=======
#include <stdio.h> // Standard input-output library
#include <stdbool.h>
// Function to count the number of non-zero elements in a square matrix.
// matrix[10][10]: The 2D array representing the matrix (assuming max size 10x10).
// size: The actual dimension of the square matrix (e.g., if it's 4x4, size is 4).
int countNonZero(int matrix[10][10], int size) {
    int count = 0; // Initialize a counter for non-zero elements.
    // Iterate through each row.
    for (int i = 0; i < size; i++) {
        // Iterate through each column in the current row.
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != 0) { // Check if the current element is not zero.
                count++;            // Increment the counter if it's non-zero.
>>>>>>> d99b03f (Further updates to Lab 1 and Lab 2 assignment codes)
            }
        }
    }
    return count; // Return the total count of non-zero elements.
}

// Function to display the upper triangular part of a square matrix.
// The upper triangular part includes elements on and above the main diagonal (where column index >= row index).
void displayUpperTriangular(int matrix[10][10], int size) {
    printf("Upper triangular matrix:\n");
    // Iterate through each row.
    for (int i = 0; i < size; i++) {
        // Iterate through each column.
        for (int j = 0; j < size; j++) {
            if (j >= i) { // If the element is on or above the main diagonal.
                printf("%d ", matrix[i][j]); // Print the element.
            } else {
                printf("  "); // Print two spaces for alignment for elements below the diagonal.
            }
        }
        printf("\n"); // Move to the next line after printing elements for a row.
    }
}

// Function to display elements located just above and just below the main diagonal.
// Elements just above the main diagonal have column index = row index + 1 (j = i + 1).
// Elements just below the main diagonal have column index = row index - 1 (j = i - 1).
void displayDiagonalNeighbors(int matrix[10][10], int size) {
    printf("Elements just above and below the main diagonal:\n");
    bool found = false; // Flag to check if any such elements are found

    // Iterate through each row.
    for (int i = 0; i < size; i++) {
        // Iterate through each column.
        for (int j = 0; j < size; j++) {
            if (j == i + 1) { // Check for elements just above the main diagonal.
                printf("Element above diagonal at (%d,%d): %d\n", i, j, matrix[i][j]);
                found = true;
            } else if (j == i - 1) { // Check for elements just below the main diagonal.
                printf("Element below diagonal at (%d,%d): %d\n", i, j, matrix[i][j]);
                found = true;
            }
        }
    }
    if (!found) {
        printf("No elements found just above or below the main diagonal (applies to 1x1 matrices or specific patterns).\n");
    }
}

int main() {
    int size; // Variable to store the size (dimension) of the square matrix.
    // Declare a 2D array to hold the matrix. Max size is 10x10.
    int matrix[10][10];

    // Prompt user for the size of the square matrix.
    printf("Enter size of the square matrix (e.g., 4 for a 4x4 matrix): ");
    scanf("%d", &size);

    // Input validation: Ensure the size is within reasonable bounds for the declared array.
    if (size <= 0 || size > 10) {
        printf("Invalid size. Please enter a size between 1 and 10.\n");
        return 1; // Exit with an error code.
    }

    // Prompt user to enter elements of the matrix.
    printf("Enter elements of the matrix (%d x %d):\n", size, size);
    // Nested loops to read elements row by row.
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Call function to count and display non-zero elements.
    int nonZeroCount = countNonZero(matrix, size);
    printf("\nNon-zero elements: %d\n", nonZeroCount);

    // Call function to display the upper triangular matrix.
    displayUpperTriangular(matrix, size);

<<<<<<< HEAD
    return 0;
}

/*
> SAMPLE INPUT
______________

    Enter size of square matrix: 4
    Enter elements of matrix:
        5 0 3 2
        0 7 1 0
        4 2 8 9
        0 6 0 3

> SAMPLE OUTPUT
_______________

    Non Zero ElementsL 13
    Upper Triangular Matrix:
        0 3 2
          1 0
            9
    Above diagonal: 0 1 9
    Below diagonal: 0 2 0
*/
=======
    // Call function to display elements just above and below the main diagonal.
    displayDiagonalNeighbors(matrix, size);

    return 0; // Indicate successful program execution.
}
>>>>>>> d99b03f (Further updates to Lab 1 and Lab 2 assignment codes)
