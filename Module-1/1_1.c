#include <stdio.h> // Standard input-output library

// Function to compare two numbers using call by address.
// It takes pointers to two integers, meaning it receives their memory addresses.
void compareNumbers(int *num1, int *num2) {
    // Dereference the pointers (*num1, *num2) to access the actual values
    // stored at those memory addresses.
    if (*num1 < *num2) {
        printf("%d is smaller than %d\n", *num1, *num2);
    } else if (*num1 > *num2) {
        printf("%d is greater than %d\n", *num1, *num2);
    } else {
        printf("Both numbers are same\n");
    }
}

int main() {
    int number1, number2;

    // Prompt the user to enter two numbers.
    printf("Enter two numbers: ");
    // Read the numbers. The '&' operator gets the memory address of the variables,
    // which are then passed to scanf.
    scanf("%d %d", &number1, &number2);

    // Call the compareNumbers function, passing the addresses of number1 and number2.
    // This is 'call by address' because the function can directly access and
    // operate on the original variables in the main function's memory space.
    compareNumbers(&number1, &number2);

    return 0; // Indicate successful program execution.
}
