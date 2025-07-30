#include <stdio.h>   // For input/output functions
#include <stdlib.h>  // For dynamic memory allocation (malloc, realloc, free)

// Function to traverse and display the array elements
void traverseArray(int *arr, int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific position
// This function takes a pointer to the array pointer (int **arr) because the array's
// memory might need to be reallocated (resized) if a new element is added,
// and 'size' needs to be updated.
void insertElement(int **arr, int *size, int element, int position) {
    // Check for valid position
    if (position < 0 || position > *size) {
        printf("Invalid position for insertion.\n");
        return;
    }

    // Increase the size of the array by 1
    // realloc tries to resize the existing memory block. If it can't, it allocates
    // a new block, copies the old data, and frees the old block.
    *arr = (int *)realloc(*arr, (*size + 1) * sizeof(int));

    // Check if realloc was successful
    if (*arr == NULL) {
        printf("Memory reallocation failed for insertion!\n");
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = *size; i > position; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }

    // Insert the element at the specified position
    (*arr)[position] = element;

    // Increment the size of the array
    (*size)++;
    printf("Element inserted.\n");
}

// Function to delete an element from a specific position
// This function also takes a pointer to the array pointer (int **arr) because
// the array's memory might be reallocated (shrunk) after deletion,
// and 'size' needs to be updated.
void deleteElement(int **arr, int *size, int position) {
    // Check for valid position
    if (position < 0 || position >= *size) {
        printf("Invalid position for deletion.\n");
        return;
    }

    // Shift elements to the left to overwrite the deleted element
    for (int i = position; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    // Decrease the size of the array by 1
    (*size)--;

    // Shrink the memory allocated to the array
    // It's good practice to reallocate to the new smaller size to free up unused memory.
    if (*size > 0) {
        *arr = (int *)realloc(*arr, (*size) * sizeof(int));
        if (*arr == NULL) {
            printf("Memory reallocation failed after deletion! (Array might still be valid)\n");
            // In a real application, you might handle this more robustly
        }
    } else {
        // If the array becomes empty, free the memory entirely
        free(*arr);
        *arr = NULL;
    }
    printf("Element deleted.\n");
}

// Function to perform a linear search for an element
void linearSearch(int *arr, int size, int element) {
    int found = 0; // Flag to indicate if element is found
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element %d found at position %d.\n", element, i);
            found = 1; // Set flag to true
            break;     // Exit loop once found
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", element);
    }
}

int main() {
    int *arr = NULL; // Pointer to the dynamically allocated array, initially NULL
    int size = 0;    // Current size of the array
    int n;           // Initial size input by user
    int choice;      // User's menu choice
    int element;     // Element to insert/search
    int position;    // Position for insert/delete

    // Get the initial size of the array from the user
    printf("Enter size n: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the initial 'n' elements
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed! Exiting.\n");
        return 1;
    }
    size = n; // Set the current size

    // Get initial array elements from the user
    printf("Enter Array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        // Display the menu
        printf("\n***MENU***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Element to insert: ");
                scanf("%d", &element);
                printf("Enter Position (0 to %d): ", size);
                scanf("%d", &position);
                insertElement(&arr, &size, element, position);
                break;
            case 2:
                printf("Enter Position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                deleteElement(&arr, &size, position);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                linearSearch(arr, size, element);
                break;
            case 4:
                traverseArray(arr, size);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    // Free the dynamically allocated memory before exiting
    if (arr != NULL) {
        free(arr);
        arr = NULL;
    }

    return 0; // Indicate successful execution
}
