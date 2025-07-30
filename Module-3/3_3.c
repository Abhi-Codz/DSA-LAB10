#include <stdio.h>
#include <stdlib.h> // For malloc and free

// Function to read polynomial coefficients into an array
// 'poly' is the array to store coefficients
// 'degree' is the maximum degree of the polynomial
void readPolynomial(int *poly, int degree, const char *poly_name) {
    printf("Enter Polynomial-%s from lowest degree to highest degree: ", poly_name);
    for (int i = 0; i <= degree; i++) {
        scanf("%d", &poly[i]);
    }
}

// Function to add two polynomials and store the result in a third array
// 'poly1' and 'poly2' are the input polynomial arrays
// 'result_poly' is the array to store the sum
// 'max_degree' is the maximum degree of the resultant polynomial
void addPolynomials(int *poly1, int *poly2, int *result_poly, int max_degree) {
    for (int i = 0; i <= max_degree; i++) {
        result_poly[i] = poly1[i] + poly2[i];
    }
}

// Function to display a polynomial from an array
// 'poly' is the array containing coefficients
// 'degree' is the maximum degree of the polynomial
void displayPolynomial(int *poly, int degree) {
    printf("Resultant Polynomial: ");
    int first_term_printed = 0; // Flag to handle '+' sign for subsequent terms

    // Iterate from the highest degree down to 0
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) { // Only print non-zero terms
            if (first_term_printed) {
                printf("+"); // Add '+' sign for terms after the first one
            }

            printf("%dx", poly[i]); // Print coefficient and 'x'
            if (i > 1) {
                printf("^%d", i); // Print power if degree > 1
            } else if (i == 1) {
                // For x^1, just print x, no need for ^1
            } else { // i == 0 (constant term)
                printf("^%d", i); // Print x^0 for consistency with sample output
            }
            first_term_printed = 1; // Set flag as a term has been printed
        }
    }
    printf("\n");
}

int main() {
    int max_degree; // Maximum degree of the polynomials
    int *poly1 = NULL; // Array for polynomial 1 coefficients
    int *poly2 = NULL; // Array for polynomial 2 coefficients
    int *result_poly = NULL; // Array for resultant polynomial coefficients

    // Get the maximum degree of x
    printf("Enter maximum degree of x: ");
    scanf("%d", &max_degree);

    // Allocate memory for polynomial arrays (degree + 1 elements for 0 to degree)
    poly1 = (int *)malloc((max_degree + 1) * sizeof(int));
    poly2 = (int *)malloc((max_degree + 1) * sizeof(int));
    result_poly = (int *)malloc((max_degree + 1) * sizeof(int));

    // Check for successful memory allocation
    if (poly1 == NULL || poly2 == NULL || result_poly == NULL) {
        printf("Memory allocation failed! Exiting program.\n");
        // Free any already allocated memory before exiting
        free(poly1);
        free(poly2);
        free(result_poly);
        return 1;
    }

    // Read coefficients for Polynomial 1
    readPolynomial(poly1, max_degree, "1");

    // Read coefficients for Polynomial 2
    readPolynomial(poly2, max_degree, "2");

    // Add the two polynomials
    addPolynomials(poly1, poly2, result_poly, max_degree);

    // Display the resultant polynomial
    displayPolynomial(result_poly, max_degree);

    // Free dynamically allocated memory
    free(poly1);
    free(poly2);
    free(result_poly);
    poly1 = NULL;
    poly2 = NULL;
    result_poly = NULL;

    return 0;
}
