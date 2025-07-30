#include <stdio.h>
#include <stdlib.h> // For malloc, free

// Structure for a term in the polynomial
typedef struct PolyNode {
    int coefficient;
    int exponent;
    struct PolyNode *next;
} PolyNode;

// Function to create a new polynomial node
PolyNode* createPolyNode(int coeff, int exp) {
    PolyNode *newNode = (PolyNode *)malloc(sizeof(PolyNode));
    if (newNode == NULL) {
        printf("Memory allocation failed for polynomial node!\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to append a term to the end of a polynomial linked list
// This is used when reading input, building the list in descending order of exponents.
void appendTerm(PolyNode **head_ref, int coeff, int exp) {
    PolyNode *newNode = createPolyNode(coeff, exp);
    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        PolyNode *current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to read polynomial coefficients and build the linked list
// Prompts for coefficients from the maximum power down to 0.
void readPolynomial(PolyNode **head_ref, const char *poly_name) {
    int max_power;
    printf("Polynomial-%s:\n", poly_name);
    printf("Enter the Maximum power of x: ");
    scanf("%d", &max_power);

    // Initialize head to NULL for a new polynomial list
    *head_ref = NULL;

    // Read coefficients from highest degree down to 0
    for (int i = max_power; i >= 0; i--) {
        int coeff;
        printf("Enter the coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        if (coeff != 0) { // Only add non-zero terms to the linked list
            appendTerm(head_ref, coeff, i);
        }
    }
}

// Function to add two polynomial equations represented by linked lists
// Assumes poly1 and poly2 are sorted by exponent in descending order.
PolyNode* addPolynomials(PolyNode *poly1, PolyNode *poly2) {
    PolyNode *result_head = NULL;     // Head of the resultant polynomial list
    PolyNode *result_current = NULL;  // Pointer to the last node in the result list

    // Iterate while both input polynomials have terms
    while (poly1 != NULL && poly2 != NULL) {
        PolyNode *newTerm = NULL; // Temporary node for the current term to be added to result

        if (poly1->exponent > poly2->exponent) {
            // Term from poly1 has a higher exponent, append it to the result
            newTerm = createPolyNode(poly1->coefficient, poly1->exponent);
            poly1 = poly1->next; // Move to the next term in poly1
        } else if (poly2->exponent > poly1->exponent) {
            // Term from poly2 has a higher exponent, append it to the result
            newTerm = createPolyNode(poly2->coefficient, poly2->exponent);
            poly2 = poly2->next; // Move to the next term in poly2
        } else { // poly1->exponent == poly2->exponent
            // Exponents are the same, add their coefficients
            int sum_coeff = poly1->coefficient + poly2->coefficient;
            if (sum_coeff != 0) { // Only create a new term if the sum is non-zero
                newTerm = createPolyNode(sum_coeff, poly1->exponent);
            }
            poly1 = poly1->next; // Move to the next term in poly1
            poly2 = poly2->next; // Move to the next term in poly2
        }

        // If a new term was created (i.e., not a zero sum), append it to the result list
        if (newTerm != NULL) {
            if (result_head == NULL) {
                // If result list is empty, this new term becomes the head
                result_head = newTerm;
                result_current = newTerm;
            } else {
                // Otherwise, append to the end of the result list
                result_current->next = newTerm;
                result_current = newTerm;
            }
        }
    }

    // Append any remaining terms from poly1 (if poly2 finished first)
    while (poly1 != NULL) {
        PolyNode *newTerm = createPolyNode(poly1->coefficient, poly1->exponent);
        if (result_head == NULL) {
            result_head = newTerm;
            result_current = newTerm;
        } else {
            result_current->next = newTerm;
            result_current = newTerm;
        }
        poly1 = poly1->next;
    }

    // Append any remaining terms from poly2 (if poly1 finished first)
    while (poly2 != NULL) {
        PolyNode *newTerm = createPolyNode(poly2->coefficient, poly2->exponent);
        if (result_head == NULL) {
            result_head = newTerm;
            result_current = newTerm;
        } else {
            result_current->next = newTerm;
            result_current = newTerm;
        }
        poly2 = poly2->next;
    }

    return result_head; // Return the head of the resultant polynomial
}

// Function to display a polynomial from a linked list
void displayPolynomial(PolyNode *head) {
    if (head == NULL) {
        printf("Sum: 0.\n"); // Represents a zero polynomial
        return;
    }

    printf("Sum: ");
    PolyNode *current = head;
    int first_term = 1; // Flag to manage '+' signs between terms

    while (current != NULL) {
        if (current->coefficient != 0) { // Only print non-zero terms
            if (!first_term && current->coefficient > 0) {
                printf("+"); // Add '+' for positive terms after the first one
            }

            // Print coefficient
            if (current->exponent != 0) { // If it's not a constant term
                if (current->coefficient == 1) {
                    // Don't print '1' if it's 1x^n
                } else if (current->coefficient == -1) {
                    printf("-"); // Print '-' for -1x^n
                } else {
                    printf("%d", current->coefficient);
                }
            } else { // It's a constant term (x^0)
                printf("%d", current->coefficient);
            }


            // Print 'x' and exponent if not a constant term
            if (current->exponent > 1) {
                printf("x^%d", current->exponent);
            } else if (current->exponent == 1) {
                printf("x");
            }
            // For exponent 0, nothing else to print as coefficient is already handled.

            first_term = 0; // After printing the first term, set flag to 0
        }
        current = current->next;
    }
    printf(".\n"); // As per sample output
}

// Function to free all nodes in a polynomial linked list
void freePolynomial(PolyNode *head) {
    PolyNode *current = head;
    PolyNode *next_node;
    while (current != NULL) {
        next_node = current->next; // Store the next node before freeing current
        free(current);             // Free the current node
        current = next_node;       // Move to the next node
    }
}

int main() {
    PolyNode *poly1_head = NULL; // Head of the first polynomial
    PolyNode *poly2_head = NULL; // Head of the second polynomial
    PolyNode *result_head = NULL; // Head of the resultant polynomial

    // Read Polynomial 1 from user input
    readPolynomial(&poly1_head, "1");

    // Read Polynomial 2 from user input
    readPolynomial(&poly2_head, "2");

    // Add the two polynomials
    result_head = addPolynomials(poly1_head, poly2_head);

    // Display the resultant polynomial
    displayPolynomial(result_head);

    // Free all dynamically allocated memory to prevent memory leaks
    freePolynomial(poly1_head);
    freePolynomial(poly2_head);
    freePolynomial(result_head);

    return 0; // Indicate successful program execution
}
