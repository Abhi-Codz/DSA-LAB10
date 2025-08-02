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
        }
    }

    return sum; // Returning the final sum
}

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
