#include <stdio.h>   // For input/output functions like printf, scanf
#include <stdlib.h>  // For dynamic memory allocation functions like malloc, free

// Function to check if a number is prime
// A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
// Since stdbool.h is removed, we'll use int for boolean return values (0 for false, 1 for true).
int isPrime(int num) {
    // Numbers less than or equal to 1 are not prime
    if (num <= 1) {
        return 0; // false
    }
    // Loop from 2 up to the square root of the number
    // We only need to check up to sqrt(num) because if a number 'num' has a divisor greater than its square root,
    // it must also have a divisor smaller than its square root.
    // Since math.h is removed, we'll use i * i <= num for the square root check.
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // false (If 'num' is divisible by 'i', it's not prime)
        }
    }
    return 1; // true (If no divisors are found, the number is prime)
}

// Function to calculate the sum of prime elements in an integer array
int sumOfPrimeElements(int *arr, int size) {
    int sum = 0; // Initialize sum to 0
    // Iterate through each element of the array
    for (int i = 0; i < size; i++) {
        // If the current element is prime, add it to the sum
        if (isPrime(arr[i])) { // isPrime now returns 0 or 1
            sum += arr[i];
        }
    }
    return sum; // Return the total sum of prime elements
}

int main() {
    int n;     // Variable to store the size of the array
    int *arr;  // Pointer to hold the base address of the dynamically allocated array

    // Prompt the user to enter the size of the array
    printf("Enter size of the array: ");
    scanf("%d", &n); // Read the size from the user

    // Dynamically allocate memory for 'n' integers
    // malloc(size_in_bytes) allocates a block of memory of specified size.
    // n * sizeof(int) calculates the total bytes needed for 'n' integers.
    // The result of malloc is a void pointer, which is then cast to (int *)
    arr = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    // If malloc fails (e.g., not enough memory), it returns NULL
    if (arr == NULL) {
        printf("Memory allocation failed! Exiting program.\n");
        return 1; // Return 1 to indicate an error
    }

    // Prompt the user to enter the array elements
    printf("Enter array elements: ");
    // Loop to read 'n' elements into the dynamically allocated array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Read each element
    }

    // Call the function to calculate the sum of prime elements
    int primeSum = sumOfPrimeElements(arr, n);

    // Display the calculated sum
    printf("Sum = %d\n", primeSum);

    // Deallocate the dynamically allocated memory
    // It's crucial to free memory after it's no longer needed to prevent memory leaks.
    free(arr);
    arr = NULL; // Set the pointer to NULL after freeing to avoid dangling pointer issues

    return 0; // Return 0 to indicate successful program execution
}
