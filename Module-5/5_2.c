#include <stdio.h>
#include <stdlib.h> // For malloc and free

// Define the structure for a node in the circular linked list
typedef struct Node {
    int data;          // Data stored in the node
    struct Node *next; // Pointer to the next node in the list
} Node;

// Global tail pointer for the circular linked list.
// In a circular linked list, it's often more convenient to keep track of the tail,
// as head can then be easily accessed via tail->next.
Node *tail = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for a new node
    if (newNode == NULL) {
        printf("Memory allocation failed for new node!\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->data = data; // Assign data to the new node
    newNode->next = NULL; // Initialize next pointer to NULL (will be set later for circularity)
    return newNode;        // Return the newly created node
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(int data) {
    Node *newNode = createNode(data); // Create the new node

    if (tail == NULL) {
        // If the list is empty, the new node becomes the first node.
        // It points to itself to form a circular list with one node.
        tail = newNode;
        tail->next = tail;
    } else {
        // If the list is not empty, insert the new node after the current tail.
        // The new node points to what the tail's next was (which is the head).
        newNode->next = tail->next;
        // The current tail points to the new node.
        tail->next = newNode;
        // The new node becomes the new tail.
        tail = newNode;
    }
    printf("Node %d inserted.\n", data);
}

// Function to display the elements of the circular linked list
void displayCircularList() {
    if (tail == NULL) {
        printf("Clinkedlist: List is empty.\n");
        return;
    }

    printf("Clinkedlist: ");
    Node *current = tail->next; // Start from the head (tail->next)

    // Traverse the list until we come back to the head
    do {
        printf("%d ", current->data); // Print node data
        current = current->next;      // Move to the next node
    } while (current != tail->next); // Continue until we loop back to the head
    printf("\n");
}

// Function to free all nodes in the circular linked list (to prevent memory leaks)
void freeCircularList() {
    if (tail == NULL) {
        return; // List is already empty
    }

    Node *current = tail->next; // Start from the head
    Node *temp;

    // Traverse and free nodes until we reach the head again
    while (current != tail) {
        temp = current;        // Store current node
        current = current->next; // Move to the next node
        free(temp);            // Free the stored node
    }
    free(tail); // Finally, free the tail node
    tail = NULL; // Set tail to NULL after freeing all nodes
    printf("Circular linked list freed.\n");
}

int main() {
    int num_nodes; // Number of initial nodes
    int element;   // Element to insert

    // Get the initial number of nodes
    printf("Enter no.of nodes: ");
    scanf("%d", &num_nodes);

    // Populate the circular linked list
    for (int i = 0; i < num_nodes; i++) {
        printf("Enter info of node%d: ", i + 1);
        scanf("%d", &element);
        insertAtEnd(element);
    }

    // Display the circular linked list
    displayCircularList();

    // Free all allocated memory before exiting the program
    freeCircularList();

    return 0; // Indicate successful execution
}
