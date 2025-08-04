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
