<<<<<<< HEAD
/*
2.1 WAP to create a 1-D array of n elements and perform the following menu based operations using function.
    a. insert a given element at specific position.
    b. delete an element from a specific position of the array.
    c. linear search to search an element
    d. traversal of the array
*/

#include <stdio.h>

// Constant Size set to 100, setting max array
#define SIZE 100

// An Insert Function with variable
void insert(int arr[], int *n, int element, int pos) 
{
    if(pos < 0 || pos > *n) // Checking position
    {
        printf("Invalid position!\n");
        return;
    }

    // Shifts element to the right to provide space for new element
    for(int i = *n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
=======
#include <stdio.h> // Standard input-output library

// Function to insert an element at a specific position in the array.
// arr[]: The array itself.
// *size: Pointer to the current size of the array (allows modifying size in main).
// element: The value to be inserted.
// position: The 0-indexed position where the element should be inserted.
void insertElement(int arr[], int *size, int element, int position) {
    // Check if the array is full or the position is invalid.
    // Assuming a max capacity of 100 for the array.
    if (*size >= 100) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position for insertion. Position must be between 0 and %d.\n", *size);
        return;
    }

    // Shift elements to the right starting from the end of the current array
    // up to the insertion position to make space for the new element.
    for (int i = *size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = element; // Insert the new element at the specified position.
    (*size)++;               // Increment the array size.
    printf("Element inserted.\n");
}

// Function to delete an element from a specific position in the array.
// arr[]: The array itself.
// *size: Pointer to the current size of the array.
// position: The 0-indexed position from which the element should be deleted.
void deleteElement(int arr[], int *size, int position) {
    // Check if the array is empty or the position is invalid.
    if (*size <= 0) {
        printf("Array is empty. Cannot delete elements.\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Invalid position for deletion. Position must be between 0 and %d.\n", *size - 1);
        return;
    }

    // Shift elements to the left starting from the deletion position
    // to overwrite the element being deleted and fill the gap.
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--; // Decrement the array size.
    printf("Element deleted.\n");
}

// Function to perform a linear search for an element in the array.
// arr[]: The array itself.
// size: The current size of the array.
// element: The value to search for.
void linearSearch(int arr[], int size, int element) {
    // Iterate through each element of the array.
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) { // If the element is found.
            printf("Element %d found at position %d (0-indexed).\n", element, i);
            return; // Exit the function as soon as the element is found.
        }
    }
    // If the loop completes and the element was not found.
    printf("Element %d not found in the array.\n", element);
}

// Function to traverse and display all elements of the array.
// arr[]: The array itself.
// size: The current size of the array.
void traverseArray(int arr[], int size) {
    if (size == 0) { // Check if the array is empty.
        printf("Array is empty.\n");
        return;
    }
    printf("Array Elements: ");
    // Loop through and print each element.
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
>>>>>>> d99b03f (Further updates to Lab 1 and Lab 2 assignment codes)
    }

    arr[pos] = element;
    (*n)++; // Incrementing array size
}

// Delete function
void delete(int arr[], int *n, int pos) 
{
    if(pos < 0 || pos >= *n) // Checking whether the position is invalid
    {
        printf("Invalid position!\n");
        return;
    }

    // Shifts element to the left, over-writing the deleted item
    for(int i = pos; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
        (*n)--; // Decrementing array size
    }
}

// Search Function
void search(int arr[], int n, int element) 
{
    for(int i = 0; i < n; i++) // Iterates through array 
    {
        if(arr[i] == element) // Checking whether the element matches the search target
        {
            printf("Element found at index %d\n", i);
            return;
        }
    }
    printf("Element not found\n"); // Displays index
}


// Traversing Function: Printing all the elements of the array
// Traversing Function: Printing all the elements of the array
void traverse(int arr[], int n) 
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

<<<<<<< HEAD
int main() 
{
    // Arrays
    int arr[SIZE], n, choice, element, pos;

    // Taking input for initial size of the array
=======
int main() {
    int arr[100]; // Declare a static array with a maximum size of 100.
    int size = 0; // Initialize current size of the array to 0.
    int option, element, position; // Variables for menu choice, element, and position.

    // Prompt user for the initial size of the array.
>>>>>>> d99b03f (Further updates to Lab 1 and Lab 2 assignment codes)
    printf("Enter size n: ");
    scanf("%d", &size);

<<<<<<< HEAD
    // Inputting initial array elements
    printf("Enter Array elements:\n");
    for(int i = 0; i < n; i++)
=======
    // Ensure the entered size does not exceed the array's maximum capacity.
    if (size < 0 || size > 100) {
        printf("Invalid size. Please enter a size between 0 and 100.\n");
        return 1; // Exit if size is invalid.
    }

    // Prompt user to enter elements for the initial array.
    printf("Enter Array elements: ");
    for (int i = 0; i < size; i++) {
>>>>>>> d99b03f (Further updates to Lab 1 and Lab 2 assignment codes)
        scanf("%d", &arr[i]);

<<<<<<< HEAD

    // Menu Shell that loops until an individual chooses to exit
    do // Do While
    {
        printf("\n*** MENU ***\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Traverse\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Performance of Operations lol
        switch(choice) 
        {
=======
    // Menu-driven loop for array operations.
    do {
        printf("\n***MENU***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        // Perform action based on user's choice.
        switch (option) {
>>>>>>> d99b03f (Further updates to Lab 1 and Lab 2 assignment codes)
            case 1:
                // Insert Operation
                printf("Enter element to insert: ");
                scanf("%d", &element);
<<<<<<< HEAD
                printf("Enter position: ");
                scanf("%d", &pos);
                insert(arr, &n, element, pos);
=======
                printf("Enter Position (0-indexed): ");
                scanf("%d", &position);
                insertElement(arr, &size, element, position);
>>>>>>> d99b03f (Further updates to Lab 1 and Lab 2 assignment codes)
                break;

            case 2:
<<<<<<< HEAD
                // Delete Operation
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete(arr, &n, pos);
=======
                printf("Enter Position (0-indexed) to delete: ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
>>>>>>> d99b03f (Further updates to Lab 1 and Lab 2 assignment codes)
                break;

            case 3:
                // Search Operation
                printf("Enter element to search: ");
                scanf("%d", &element);
                search(arr, n, element);
                break;
<<<<<<< HEAD

            case 4:
                // Traverse Operation
                printf("Array Elements: ");
                traverse(arr, n);
                break;

            case 5:
                // Exit from the Program
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    while(choice != 5); // Repeatition until Exit
    return 0;
=======
            case 4:
                traverseArray(arr, size);
                break;
            case 5:
                printf("Exiting 1-D Array Operations.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 5); // Continue until the user chooses to exit.

    return 0; // Indicate successful program execution.
>>>>>>> d99b03f (Further updates to Lab 1 and Lab 2 assignment codes)
}


/*
>SAMPLE INPUT / OUTPUT
______________________
    Enter the size n: 5
    Enter array elements: 5 8 9 2 6

    ***MENU***
    1. INSERT
    2. DELETE
    3. SEARCH
    4. TRAVERSE

    Enter Choice: 1
    Enter Element to Insert: 7
    Enter Position: 3
    ---------------------------
    Array Elements: 5 8 9 2 7 6

    Enter Choice: 2
    Enter Position to Delete: 3
    ---------------------------
    Array Elements: 5 8 9 2 6

    Enter Choice: 3
    Enter Element to Search: 7
    ---------------------------
    Element not found

    Enter Choice: 4
    ---------------------------
    Array Elements: 5 8 9 2 6

    Enter Choice: 5
    ---------------------------
    Exiting...
*/
