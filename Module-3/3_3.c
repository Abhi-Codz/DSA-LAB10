// Q3.3 WAP to represent the polynomial of single variable using 1-D array and perform the addition of two polynomial equations.

#include <stdio.h>

#define SIZE 100 // Max degree allowed (can be adjusted.. Wish I was a good programmer.)

int main()
{
    int degree; // Highest degree of the polynomial

    // Arrays to hold coefficients of both polynomials and the result
    int poly1[SIZE], poly2[SIZE], result[SIZE];

    // Asking for max degree of the polynomials
    printf("Enter maximum degree of x: ");
    scanf("%d", &degree);

    // Inputting coefficients for Polynomial-1
    printf("Enter Polynomial-1 from lowest degree to highest degree:\n");
    for(int i = 0; i <= degree; i++)
    {
        scanf("%d", &poly1[i]);
    }

    // Inputting coefficients for Polynomial-2
    printf("Enter Polynomial-2:\n");
    for(int i = 0; i <= degree; i++)
    {
        scanf("%d", &poly2[i]);
    }

    // Adding the polynomials coefficient-wise
    for(int i = 0; i <= degree; i++)
    {
        result[i] = poly1[i] + poly2[i];
    }

    // Printing the final polynomial (in decreasing powers of x)
    printf("Resultant Polynomial: ");
    int first = 1; // To avoid leading '+' symbol

    for(int i = degree; i >= 0; i--)
    {
        if(result[i] != 0)
        {
            if(!first)
            {
                printf(" + ");
            }

            // Special formatting: skip power if x^0 or x^1
            if(i == 0)
            {
                printf("%d", result[i]);
            }
            else if(i == 1)
            {
                printf("%dx", result[i]);
            }
            else
            {
                printf("%dx^%d", result[i], i);
            }

            first = 0;
        }
    }

    if(first)
    {
        // If all coefficients were zero
        printf("0");
    }

    printf("\n");

    return 0;
}

/*
> SAMPLE INPUT
______________

    Enter maximum degree of x: 2
    Enter Polynomial-1 from lowest degree to highest degree : 4 2 3
    Enter Polynomial-2: 6 5 2

> SAMPLE OUTPUT
_______________

    Resultant Polynomial: 5x^2+7x^1+10x^0
*/
