// Q3.1 WAP to perform transpose of a given sparse matrix in 3-tuple format.

#include <stdio.h>
#include <stdlib.h> // Just in case we later use dynamic stuff

#define MAX 100 // Max number of triples including metadata

// Defining a structure to hold a single non-zero element's info
typedef struct 
{
    int row;
    int col;
    int val;
} Triple;

int main()
{
    Triple sparse[MAX], transpose[MAX]; // Original and transposed arrays
    int rows, cols, nonZero;

    // Asking user for matrix metadata
    printf("Enter number of rows, columns, and non-zero elements: ");
    scanf("%d %d %d", &rows, &cols, &nonZero);

    // First entry is metadata: size info
    sparse[0].row = rows;
    sparse[0].col = cols;
    sparse[0].val = nonZero;

    // Taking input in 3-tuple format (row, col, value)
    printf("Enter the 3-tuple representation (row col value):\n");
    for(int i = 1; i <= nonZero; i++)
    {
        scanf("%d %d %d", &sparse[i].row, &sparse[i].col, &sparse[i].val);
    }

    // Setting metadata for transpose
    transpose[0].row = cols;   // Rows become columns
    transpose[0].col = rows;   // Columns become rows
    transpose[0].val = nonZero;

    int k = 1; // Index for transposed array

    // Transposing by switching row and col of matching elements
    for(int i = 0; i < cols; i++) // Go column-wise (original)
    {
        for(int j = 1; j <= nonZero; j++) // Scan all non-zero entries
        {
            if(sparse[j].col == i) // If element belongs to current column
            {
                transpose[k].row = sparse[j].col; // Swap col → row
                transpose[k].col = sparse[j].row; // Swap row → col
                transpose[k].val = sparse[j].val;
                k++;
            }
        }
    }

    // Printing transposed matrix in 3-tuple form
    printf("\nTransposed 3-tuple representation:\n");
    for(int i = 0; i <= nonZero; i++)
    {
        printf("%d \t %d \t %d \n", transpose[i].row, transpose[i].col, transpose[i].val);
    }

    return 0;
}

/*
> SAMPLE INPUT
______________

    Enter number of rows, columns, and non-zero elements: 3 3 4
    Enter the 3-tuple representation (row col value):
    0 0 5
    0 2 8
    1 1 3
    2 0 6

> SAMPLE OUTPUT
_______________

    Transposed 3-tuple representation:
    3 3	4
    0 0	5
    0 2	6
    1 1	3
    2 0	8
*/
