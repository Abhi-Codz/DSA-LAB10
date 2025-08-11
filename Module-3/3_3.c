<<<<<<< HEAD
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
=======
#include <stdio.h> // Standard input-output library

// Function to read polynomial coefficients into an array.
// poly[]: The array to store coefficients.
// degree: The maximum degree of the polynomial.
void readPolynomial(int poly[], int degree) {
    // Iterate from degree 0 (constant term) up to the maximum degree.
    for (int i = 0; i <= degree; i++) {
        printf("Enter the coefficient of degree %d: ", i);
        scanf("%d", &poly[i]);
>>>>>>> bc643be (Updated code with appropriate commenting to explain the code better)
    }

<<<<<<< HEAD
    // Inputting coefficients for Polynomial-2
    printf("Enter Polynomial-2:\n");
    for(int i = 0; i <= degree; i++)
    {
        scanf("%d", &poly2[i]);
=======
// Function to add two polynomials and store the result in a third array.
// poly1[]: Coefficients of the first polynomial.
// poly2[]: Coefficients of the second polynomial.
// resultPoly[]: Array to store the coefficients of the sum polynomial.
// maxDegree: The maximum degree of the resultant polynomial.
void addPolynomials(int poly1[], int poly2[], int resultPoly[], int maxDegree) {
    // Iterate from degree 0 up to the maximum degree of the resultant polynomial.
    // For each degree, add the corresponding coefficients from poly1 and poly2.
    for (int i = 0; i <= maxDegree; i++) {
        resultPoly[i] = poly1[i] + poly2[i];
>>>>>>> bc643be (Updated code with appropriate commenting to explain the code better)
    }

<<<<<<< HEAD
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
=======
// Function to display a polynomial in a readable format.
// poly[]: Coefficients of the polynomial to display.
// degree: The maximum degree of the polynomial.
void displayPolynomial(int poly[], int degree) {
    // Start from the highest degree and go down to degree 0.
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) { // Only print terms with non-zero coefficients.
            if (i == degree) { // For the first term (highest degree), don't print '+'.
                printf("%dx^%d", poly[i], i);
            } else if (i == 1) { // For x^1, print just x.
                if (poly[i] > 0) printf("+%dx", poly[i]);
                else printf("%dx", poly[i]);
            } else if (i == 0) { // For x^0 (constant term), print just the number.
                if (poly[i] > 0) printf("+%d", poly[i]);
                else printf("%d", poly[i]);
            } else { // For other degrees, print with x^degree.
                if (poly[i] > 0) printf("+%dx^%d", poly[i], i);
                else printf("%dx^%d", poly[i], i);
            }
>>>>>>> bc643be (Updated code with appropriate commenting to explain the code better)
        }
    }

<<<<<<< HEAD
    if(first)
    {
        // If all coefficients were zero
        printf("0");
=======

int main() {
    int degree1, degree2; // Maximum degrees of Polynomial 1 and Polynomial 2.
    int poly1[50] = {0};  // Coefficients of Polynomial 1, initialized to 0. Max degree 49.
    int poly2[50] = {0};  // Coefficients of Polynomial 2.
    int resultPoly[50] = {0}; // Coefficients of the resultant polynomial.

    printf("Polynomial-1:\n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &degree1);
    if (degree1 >= 50 || degree1 < 0) {
        printf("Invalid degree for Polynomial-1. Max degree is 49.\n");
        return 1;
>>>>>>> bc643be (Updated code with appropriate commenting to explain the code better)
    }
    readPolynomial(poly1, degree1); // Read coefficients for Polynomial 1.

<<<<<<< HEAD
    printf("\n");

    return 0;
=======
    printf("\nPolynomial-2:\n");
    printf("Enter the Maximum power of x: ");
    scanf("%d", &degree2);
    if (degree2 >= 50 || degree2 < 0) {
        printf("Invalid degree for Polynomial-2. Max degree is 49.\n");
        return 1;
    }
    readPolynomial(poly2, degree2); // Read coefficients for Polynomial 2.

    // Determine the maximum degree of the resultant polynomial.
    // It will be the highest degree among the two input polynomials.
    int maxDegree = (degree1 > degree2) ? degree1 : degree2;

    // Add the polynomials.
    addPolynomials(poly1, poly2, resultPoly, maxDegree);

    printf("\nResultant Polynomial: ");
    displayPolynomial(resultPoly, maxDegree); // Display the resultant polynomial.

    return 0; // Indicate successful program execution.
>>>>>>> bc643be (Updated code with appropriate commenting to explain the code better)
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
