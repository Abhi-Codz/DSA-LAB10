#include <stdio.h>
#include <stdlib.h> // For malloc and free

// Define the structure for a node in the double linked list
typedef struct Node {
    int data;          // Data stored in the node
    struct Node *prev; // Pointer to the previous node in the list
    struct Node *next; // Pointer to the next node in the list
} Node;

// Global head and tail pointers for the double linked list
Node *head = NULL;
Node *tail = NULL; // Keep track of the tail for efficient appending

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for a new node
    if (newNode == NULL) {
        printf("Memory allocation failed for new node!\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->data = data; // Assign data to the new node
    newNode->prev = NULL; // Initialize prev pointer to NULL
    newNode->next = NULL; // Initialize next pointer to NULL
    return newNode;        // Return the newly created node
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

// Function to insert a node at a specific position
void insertNode(int data, int position) {
    Node *newNode = createNode(data); // Create the new node
    int current_size = countNodes();

    // Handle insertion at the beginning (position 0)
    if (position == 0) {
        if (head == NULL) { // If list is empty
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head; // New node points to current head
            head->prev = newNode; // Current head's prev points to new node
            head = newNode;       // Head becomes the new node
        }
        printf("Node inserted.\n");
        return;
    }

    // Handle insertion at the end (position == current_size)
    if (position == current_size) {
        if (tail == NULL) { // Should only happen if list was empty and position was 0
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode; // Current tail points to new node
            newNode->prev = tail; // New node's prev points to current tail
            tail = newNode;       // Tail becomes the new node
        }
        printf("Node inserted.\n");
        return;
    }

    // Handle insertion at an intermediate position
    if (position > 0 && position < current_size) {
        Node *current = head;
        // Traverse to the node just before the desired position
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        
        newNode->next = current->next;   // New node points to current's next
        newNode->prev = current;         // New node's prev points to current
        current->next->prev = newNode;   // Node after current has its prev updated
        current->next = newNode;         // Current node points to new node
        printf("Node inserted.\n");
        return;
    }

    printf("Invalid position. Node not inserted.\n");
    free(newNode); // Free the allocated memory for the unused node
}

// Function to delete a node from a specific position
void deleteNode(int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    int current_size = countNodes();
    if (position < 0 || position >= current_size) {
        printf("Invalid position. Node not deleted.\n");
        return;
    }

    Node *temp; // Temporary pointer for deletion

    // If deleting the head node (position 0)
    if (position == 0) {
        temp = head;        // Store current head
        head = head->next;  // Head moves to the next node
        if (head != NULL) {
            head->prev = NULL; // New head's prev is NULL
        } else {
            tail = NULL; // List became empty
        }
        free(temp);         // Free the old head node
        printf("Node deleted.\n");
        return;
    }

    // If deleting the tail node (position == current_size - 1)
    if (position == current_size - 1) {
        temp = tail;        // Store current tail
        tail = tail->prev;  // Tail moves to the previous node
        if (tail != NULL) {
            tail->next = NULL; // New tail's next is NULL
        } else {
            head = NULL; // List became empty
        }
        free(temp);         // Free the old tail node
        printf("Node deleted.\n");
        return;
    }

    // Deleting from an intermediate position
    Node *current = head;
    for (int i = 0; i < position; i++) {
        current = current->next; // current points to the node to be deleted
    }

    current->prev->next = current->next; // Node before current skips current
    current->next->prev = current->prev; // Node after current has its prev updated
    free(current); // Free the deleted node's memory
    printf("Node deleted.\n");
}

// Function to traverse and display the double linked list elements
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
    tail = NULL; // Set tail to NULL as well
}

int main() {
    int num_nodes; // Number of initial nodes
    int element;   // Element to insert
    int position;  // Position for operations
    int choice;    // User's menu choice

    // Get the initial number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);

    // Populate the initial double linked list
    printf("Enter the elements: ");
    for (int i = 0; i < num_nodes; i++) {
        scanf("%d", &element);
        // Insert at the end for initial population
        insertNode(element, countNodes());
    }

    do {
        // Display the menu
        printf("\nMENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Traversal\n");
        printf("5. Exit\n"); // Note: Sample input has 5 for Exit, not 4
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
                traverseList();
                break;
            case 5: // Exit option
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5); // Loop until user chooses to exit

    // Free all allocated memory before exiting the program
    freeList();

    return 0; // Indicate successful execution
}
