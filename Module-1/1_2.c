<<<<<<< HEAD
// Q1.2 Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of all the prime elements of the array using function and de-allocate the memory of the array after its use.

#include <stdio.h>
#include <stdlib.h>  // For malloc() and free(), and so on that I don't even know its usercase

// Function to check whether a number is Prime or not
int isPrime(int num)
{
    // 1 and below aren't prime
    if(num <= 1)
    {
        return 0;
    }

    for(int i = 2; i * i <= num; i++) // Looping to check till the square-root of the number
    {
        if(num % i == 0)
        {
            return 0; 
        }
    }
    return 1; 
}

// Definfing a function to calculate sum of all prime numbers in the array
int sumOfPrimes(int *arr, int size)
{
    int sum = 0;

    for(int i = 0; i < size; i++) // Looping through the array
    {
        if(isPrime(arr[i])) // Only add if it's prime
        {
            sum += arr[i];
=======
#include <stdio.h>   // Standard input-output library
#include <stdlib.h>  // Required for malloc() and free() for dynamic memory allocation
#include <stdbool.h> // Required for boolean data type (true/false)

// Function to check if a given number is prime.
// Returns true if n is prime, false otherwise.
bool isPrime(int n) {
    if (n <= 1) { // Numbers less than or equal to 1 are not prime
        return false;
    }
    // Loop from 2 up to the square root of n.
    // We only need to check up to sqrt(n) because if n has a divisor greater than sqrt(n),
    // it must also have a divisor smaller than sqrt(n).
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) { // If n is divisible by i, it's not prime
            return false;
        }
    }
    return true; // If no divisors are found, n is prime
}

// Function to calculate the sum of all prime elements in an array.
// Takes a pointer to the array (int *arr) and its size (int size) as input.
int sumPrimeElements(int *arr, int size) {
    int sum = 0; // Initialize sum to 0
    for (int i = 0; i < size; i++) {
        // Check if the current element of the array is prime using the isPrime function.
        if (isPrime(arr[i])) {
            sum += arr[i]; // If it's prime, add it to the sum
>>>>>>> d99b03f (Further updates to Lab 1 and Lab 2 assignment codes)
        }
    }

    return sum; // Returning the final sum
}

<<<<<<< HEAD
int main()
{
    int n; // Size of the array

    // Asking user for array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocating memory dynamically (This is the part even I've hard time understanding)
    int *arr = (int *)malloc(n * sizeof(int));

    // Checking on Malloc's functionality
    if(arr == NULL)
    {
        printf("Memory allocation failed! Exiting...\n");
        return 1;
    }

    // Taking input for array elements
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Calling function and printing the result
    int result = sumOfPrimes(arr, n);
    printf("Sum of prime elements = %d\n", result);

    // Freeing up dynamically allocated memory
    free(arr);
    return 0;
=======
int main() {
    int size; // Variable to store the size of the array
    int *arr; // Pointer to an integer, which will point to the dynamically allocated array

    // Prompt user for the size of the array.
    printf("Enter size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for an array of 'size' integers.
    // malloc returns a void pointer, so it's cast to (int *).
    // If memory allocation fails, malloc returns NULL.
    arr = (int *)malloc(size * sizeof(int));

    // Check if memory allocation was successful.
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit with an error code
    }

    // Prompt user to enter array elements and read them into the dynamically allocated array.
    printf("Enter array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]); // arr[i] is equivalent to *(arr + i)
    }

    // Calculate the sum of prime elements using the sumPrimeElements function.
    int sum = sumPrimeElements(arr, size);
    printf("Sum = %d\n", sum);

    // De-allocate the dynamically allocated memory.
    // It's crucial to free memory once it's no longer needed to prevent memory leaks.
    free(arr);
    printf("Memory de-allocated.\n");

    return 0; // Indicate successful program execution.
>>>>>>> d99b03f (Further updates to Lab 1 and Lab 2 assignment codes)
}

/*
> SAMPLE INPUT
______________

    Enter the size of the array: 10
    Enter 10 elements:
    1
    6
    8
    6
    4
    3
    1
    7
    8
    9

> SAMPLE OUTPUT
_______________

    Sum of prime elements = 10
*/
