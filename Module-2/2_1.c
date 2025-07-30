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

int main() 
{
    // Arrays
    int arr[SIZE], n, choice, element, pos;

    // Taking input for initial size of the array
    printf("Enter size n: ");
    scanf("%d", &n);

    // Inputting initial array elements
    printf("Enter Array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);


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
            case 1:
                // Insert Operation
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert(arr, &n, element, pos);
                break;

            case 2:
                // Delete Operation
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;

            case 3:
                // Search Operation
                printf("Enter element to search: ");
                scanf("%d", &element);
                search(arr, n, element);
                break;

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
