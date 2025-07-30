#include <stdio.h>
#include <stdlib.h> // For malloc and free

// Define the structure for a node in the linked list
typedef struct Node {
    int data;          // Data stored in the node
    struct Node *next; // Pointer to the next node in the list
} Node;

// Global head pointer for the linked list
Node *head = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for a new node
    if (newNode == NULL) {
        printf("Memory allocation failed for new node!\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->data = data; // Assign data to the new node
    newNode->next = NULL; // Initialize next pointer to NULL
    return newNode;        // Return the newly created node
}

// Function to insert a node at a specific position
void insertNode(int data, int position) {
    Node *newNode = createNode(data); // Create the new node
    
    // If inserting at the beginning (position 0)
    if (position == 0) {
        newNode->next = head; // New node points to the current head
        head = newNode;       // Head becomes the new node
        printf("Node inserted.\n");
        return;
    }

    // Traverse to the node just before the desired position
    Node *current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    // Check if the position is valid (within or just beyond the list bounds)
    if (current == NULL) {
        printf("Invalid position. Node not inserted.\n");
        free(newNode); // Free the allocated memory for the unused node
        return;
    }

    // Insert the new node
    newNode->next = current->next; // New node points to what current was pointing to
    current->next = newNode;       // Current node points to the new node
    printf("Node inserted.\n");
}

// Function to delete a node from a specific position
void deleteNode(int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node *temp; // Temporary pointer for deletion

    // If deleting the head node (position 0)
    if (position == 0) {
        temp = head;        // Store current head
        head = head->next;  // Head moves to the next node
        free(temp);         // Free the old head node
        printf("Node deleted.\n");
        return;
    }

    // Traverse to the node just before the desired position
    Node *current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    // Check if the position is valid and if there's a node to delete
    if (current == NULL || current->next == NULL) {
        printf("Invalid position. Node not deleted.\n");
        return;
    }

    // Delete the node
    temp = current->next;         // Store the node to be deleted
    current->next = temp->next;   // Current node skips over the deleted node
    free(temp);                   // Free the deleted node's memory
    printf("Node deleted.\n");
}

// Function to count the total number of nodes in the list
int countNodes() {
    int count = 0;
    Node *current = head; // Start from the head
    while (current != NULL) {
        count++;           // Increment count for each node
        current = current->next; // Move to the next node
    }
    return count; // Return the total count
}

// Function to traverse and display the linked list elements
void traverseList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("The list is: ");
    Node *current = head; // Start from the head
    while (current != NULL) {
        printf("%d", current->data); // Print node data
        current = current->next;     // Move to the next node
        if (current != NULL) {
            printf("->"); // Print arrow if it's not the last node
        }
    }
    printf("\n");
}

// Function to search for an element in the list
void searchElement(int element) {
    Node *current = head;
    int position = 1; // Start position from 1 as per sample output
    while (current != NULL) {
        if (current->data == element) {
            printf("Element found at node-%d\n", position);
            return; // Element found, exit function
        }
        current = current->next;
        position++;
    }
    printf("Element %d not found in the list.\n", element);
}

// Function to sort the list in ascending order (using bubble sort logic)
void sortList() {
    Node *current = head;
    Node *index = NULL;
    int temp;

    if (head == NULL) {
        printf("List is empty. Cannot sort.\n");
        return;
    } else {
        for (current = head; current->next != NULL; current = current->next) {
            for (index = current->next; index != NULL; index = index->next) {
                if (current->data > index->data) {
                    // Swap data of nodes
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }
    }
    printf("List sorted in ascending order.\n");
}

// Function to reverse the list
void reverseList() {
    Node *prev = NULL;
    Node *current = head;
    Node *next_node = NULL;

    while (current != NULL) {
        next_node = current->next; // Store next node
        current->next = prev;      // Reverse current node's pointer
        prev = current;            // Move pointers one position ahead
        current = next_node;
    }
    head = prev; // Update head to the new front of the list
    printf("List reversed.\n");
}

// Function to free all nodes in the linked list (to prevent memory leaks)
void freeList() {
    Node *current = head;
    Node *next;
    while (current != NULL) {
        next = current->next; // Store the next node
        free(current);        // Free the current node
        current = next;       // Move to the next node
    }
    head = NULL; // Set head to NULL after freeing all nodes
}

int main() {
    int num_nodes; // Number of initial nodes
    int element;   // Element to insert/search
    int position;  // Position for operations
    int choice;    // User's menu choice

    // Get the initial number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);

    // Populate the initial linked list
    printf("Enter the elements: ");
    for (int i = 0; i < num_nodes; i++) {
        scanf("%d", &element);
        insertNode(element, i); // Insert at the end initially
    }

    do {
        // Display the menu
        printf("\nMENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Count\n");
        printf("4. Traverse\n");
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7. Reverse\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", countNodes());
                scanf("%d", &position);
                insertNode(element, position);
                break;
            case 2:
                printf("Enter position to delete (0 to %d): ", countNodes() - 1);
                scanf("%d", &position);
                deleteNode(position);
                break;
            case 3:
                printf("The total number of nodes: %d\n", countNodes());
                break;
            case 4:
                traverseList();
                break;
            case 5:
                printf("Enter element to be searched: ");
                scanf("%d", &element);
                searchElement(element);
                break;
            case 6:
                sortList();
                break;
            case 7:
                reverseList();
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 8.\n");
        }
    } while (choice != 8); // Loop until user chooses to exit (option 8)

    // Free all allocated memory before exiting the program
    freeList();

    return 0; // Indicate successful execution
}
