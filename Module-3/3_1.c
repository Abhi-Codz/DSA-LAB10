// Q3.1 WAP to perform transpose of a given sparse matrix in 3-tuple format.

#include <stdio.h>
#include <stdlib.h> // Good old Stdlib lol

#define MAX 100 // Max number of terms (including metadata)

// Creating a structure to hold one non-zero entry
typedef struct 
{
    int row;
    int col;
    int val;
} Triple;

int main()
{
    Triple sparse[MAX], transpose[MAX];
    int nonZero = 0;        // Count of non-zero elements
    int maxRow = 0, maxCol = 0; // To track actual matrix size

    // Input: Using sentinel to stop
    printf("Enter sparse matrix in 3-tuple format (row col value)\n");
    printf("Enter -1 -1 -1 to stop:\n");

    while(1)
    {
        int r, c, v;
        scanf("%d %d %d", &r, &c, &v);

        if(r == -1 && c == -1 && v == -1)
        {
            break; // Sentinel check - I googled it
        }

        nonZero++; // Increase non-zero count

        sparse[nonZero].row = r;
        sparse[nonZero].col = c;
        sparse[nonZero].val = v;

        // Tracking the largest row and column index for dimensions
        if(r > maxRow)
        {
            maxRow = r;
        }

        if(c > maxCol)
        {
            maxCol = c;
        }
    }

    // First entry holds matrix metadata (rows, cols, non-zero count)
    sparse[0].row = maxRow + 1;
    sparse[0].col = maxCol + 1;
    sparse[0].val = nonZero;

    // Metadata for transpose
    transpose[0].row = sparse[0].col;
    transpose[0].col = sparse[0].row;
    transpose[0].val = nonZero;

    // Actual transpose logic: Swap row and col indices of each element
    for(int j = 1; j <= nonZero; j++)
    {
        transpose[j].row = sparse[j].col;
        transpose[j].col = sparse[j].row;
        transpose[j].val = sparse[j].val;
    }

    // Output Section YAY
    printf("\nTranspose of Sparse Matrix:\n");
    printf("R\tC\tElement\n");

    for(int i = 1; i <= nonZero; i++)
    {
        printf("%d\t%d\t%d\n", transpose[i].row, transpose[i].col, transpose[i].val);
    }

    return 0;
}

/*
> SAMPLE INPUT
_______________

    Enter sparse in 3-tuple format.
    Enter -1 -1 -1 to stop:
        4 5 4
        0 2 33
        1 1 17
        2 3 46
        3 4 51
        -1 -1 -1

> SAMPLE OUTPUT
_______________

    Transpose of sparse matrix:
        R     C     Element
        5        4       4
        2        0       33
        1        1       17
        3        2       46
        4        3       51
*/
