#include <stdio.h> // Standard input-output library

// Define a structure named 'Complex' to represent a complex number.
// A complex number has a real part and an imaginary part.
struct Complex {
    float real;
    float imaginary;
};

// Function to add two complex numbers using 'call by value'.
// It takes two 'Complex' struct variables as arguments.
// Changes to c1 and c2 inside this function do NOT affect the original variables.
struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex sum; // Create a new Complex struct to store the result.
    sum.real = c1.real + c2.real;         // Add the real parts.
    sum.imaginary = c1.imaginary + c2.imaginary; // Add the imaginary parts.
    return sum; // Return the resulting complex number.
}

// Function to multiply two complex numbers using 'call by address'.
// It takes pointers to two 'Complex' struct variables (c1 and c2) for input,
// and a pointer to a 'Complex' struct variable (result) to store the product.
// This allows the function to directly modify the 'result' variable in the calling function.
void multiplyComplex(struct Complex *c1, struct Complex *c2, struct Complex *result) {
    // Formula for complex number multiplication: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
    // Access members using the arrow operator (->) for pointers to structures.
    result->real = (c1->real * c2->real) - (c1->imaginary * c2->imaginary);
    result->imaginary = (c1->real * c2->imaginary) + (c1->imaginary * c2->real);
}

int main() {
    struct Complex c_num1, c_num2; // Declare two complex number variables for input.
    struct Complex c_sum, c_product; // Declare variables to store the sum and product.
    int choice; // Variable for menu choice.

    // Prompt user to enter the first complex number.
    printf("Enter complex number 1 (real imaginary): ");
    scanf("%f %f", &c_num1.real, &c_num1.imaginary);

    // Prompt user to enter the second complex number.
    printf("Enter complex number 2 (real imaginary): ");
    scanf("%f %f", &c_num2.real, &c_num2.imaginary);

    // Display the menu options.
    printf("\nMENU\n");
    printf("1. addition\n");
    printf("2. multiplication\n");
    printf("Enter your choice: ");
    scanf("%d", &choice); // Read user's choice.

    // Use a switch statement to perform the chosen operation.
    switch (choice) {
        case 1:
            // Call the addComplex function. Since it's call by value,
            // copies of c_num1 and c_num2 are passed. The function returns the sum.
            c_sum = addComplex(c_num1, c_num2);
            printf("Sum=%.0f+%.0fi\n", c_sum.real, c_sum.imaginary);
            break;
        case 2:
            // Call the multiplyComplex function. Since it's call by address,
            // memory addresses of c_num1, c_num2, and c_product are passed.
            // The function directly modifies c_product.
            multiplyComplex(&c_num1, &c_num2, &c_product);
            printf("Product=%.0f+%.0fi\n", c_product.real, c_product.imaginary);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0; // Indicate successful program execution.
}
