// Q-1.1 Write a program to read two numbers and compare the numbers using function call by address.

#include <stdio.h>

// Defining a function with pointer parameters
void compare(int *n_1, int *n_2)
{
    // Comparing the integer values
    if(*n_1 > *n_2)  
    {
        printf("%d is greater than %d", *n_1, *n_2);
    }
    else if(*n_1 < *n_2) 
    {
        printf("%d is greater than %d", *n_2, *n_1);
    }
    else
    {
        printf("Same numbers"); // Returns in case the entered input's the same
    }
}
 
// Main function
int main()
{
    int n1, n2; // Holds user input
    printf("Enter the First Number: ");
    scanf("%d", &n1);
    printf("Enter the Second Number: ");
    scanf("%d", &n2);
    
    compare(&n1, &n2); // Recalling the function
    return 0;
}

/*
> SAMPLE INPUT
______________

    Enter the First Number: 3
    Enter the Second Number: 5

> SAMPLE OUTPUT
_______________

    5 is greater than 3
*/