#include <stdio.h> // Standard input/output functions

// Define a structure to represent a complex number
typedef struct {
    float real; // Real part of the complex number
    float imag; // Imaginary part of the complex number
} Complex;

// Function to add two complex numbers (call by value)
// This function takes two Complex structures as arguments and returns a new Complex structure
// representing their sum. The original complex numbers are not modified.
Complex addComplex(Complex num1, Complex num2) {
    Complex result; // Declare a Complex structure to store the sum
    result.real = num1.real + num2.real; // Add the real parts
    result.imag = num1.imag + num2.imag; // Add the imaginary parts
    return result; // Return the resulting complex number
}

// Function to multiply two complex numbers (call by address)
// This function takes pointers to two Complex structures as arguments and a pointer to
// a third Complex structure where the result will be stored.
// Using call by address allows the function to modify the content of the result variable
// directly, rather than returning a copy.
void multiplyComplex(Complex *num1_ptr, Complex *num2_ptr, Complex *result_ptr) {
    // Dereference the pointers to access the real and imaginary parts
    // (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
    result_ptr->real = (num1_ptr->real * num2_ptr->real) - (num1_ptr->imag * num2_ptr->imag);
    result_ptr->imag = (num1_ptr->real * num2_ptr->imag) + (num1_ptr->imag * num2_ptr->real);
}

int main() {
    Complex c1, c2;     // Declare two complex numbers
    Complex sum_result; // To store the result of addition
    Complex mul_result; // To store the result of multiplication
    int choice;         // To store user's menu choice

    // Get the first complex number from the user
    printf("Enter complex number 1 (real imaginary): ");
    scanf("%f %f", &c1.real, &c1.imag);

    // Get the second complex number from the user
    printf("Enter complex number 2 (real imaginary): ");
    scanf("%f %f", &c2.real, &c2.imag);

    // Display the menu
    printf("\nMENU\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    printf("Enter your choice: ");
    scanf("%d", &choice); // Read user's choice

    // Perform operation based on user's choice
    switch (choice) {
        case 1:
            // Call addComplex using call by value
            sum_result = addComplex(c1, c2);
            // Display the sum
            printf("Sum=%.0f+%.0fi\n", sum_result.real, sum_result.imag);
            break;
        case 2:
            // Call multiplyComplex using call by address
            // Pass the addresses of c1, c2, and mul_result
            multiplyComplex(&c1, &c2, &mul_result);
            // Display the product
            printf("Sum=%.0f+%.0fi\n", mul_result.real, mul_result.imag);
            break;
        default:
            printf("Invalid choice! Please enter 1 or 2.\n");
            break;
    }

    return 0; // Indicate successful execution
}
