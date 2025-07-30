#include <stdio.h>
#include <stdlib.h> // For malloc, free

// Define a structure for a term (non-zero element) in the sparse matrix
typedef struct Term {
    int row;
    int col;
    int value;
} Term;

// Define the structure for a node in the linked list
// Each node will hold a 'Term' and a pointer to the next node
typedef struct Node {
    Term data;         // Stores the row, column, and value of a term
    struct Node *next; // Pointer to the next node in the list
} Node;

// Function to create a new linked list node
Node* createNode(int row, int col, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for a new node
    if (newNode == NULL) {
        printf("Memory allocation failed for new node!\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->data.row = row;     // Set row
    newNode->data.col = col;     // Set column
    newNode->data.value = value; // Set value
    newNode->next = NULL;        // Initialize next pointer to NULL
    return newNode;              // Return the newly created node
}

// Function to read a sparse matrix and represent it using a header single linked list
// The header node (the first node in the list) will store the matrix dimensions
// (total rows, total columns) and the count of non-zero terms.
// Subsequent nodes will store the actual non-zero terms.
Node* readAndBuildSparseMatrix() {
    int total_rows, total_cols;
    printf("Enter size of the sparse matrix (rows cols): ");
    scanf("%d %d", &total_rows, &total_cols);

    printf("Enter elements of sparse matrix (row by row, space separated):\n");

    Node *head = NULL;       // Head of the linked list (will be the header node)
    Node *current = NULL;    // Pointer to the last node added to the list
    int num_terms = 0;       // Counter for non-zero terms

    // Temporarily create a dummy head or handle the header node creation after counting terms
    // For simplicity and to match 3-tuple format, we'll create the header node at the end
    // and link it to the first actual term.

    // Loop through each element of the matrix
    for (int r = 0; r < total_rows; r++) {
        for (int c = 0; c < total_cols; c++) {
            int element_value;
            scanf("%d", &element_value);

            if (element_value != 0) { // If the element is non-zero
                Node *newNode = createNode(r, c, element_value); // Create a node for it
                num_terms++; // Increment non-zero term count

                if (head == NULL) {
                    // This is the first non-zero term, so it will be the first actual term
                    // after the header node. We will link it to the header later.
                    head = newNode; // Temporarily use 'head' for the first actual term
                    current = newNode;
                } else {
                    // Append the new node to the end of the list of terms
                    current->next = newNode;
                    current = newNode;
                }
            }
        }
    }

    // Now, create the actual header node for the sparse matrix
    // This node stores total_rows, total_cols, and num_terms
    Node *headerNode = createNode(total_rows, total_cols, num_terms);
    headerNode->next = head; // The header node points to the first actual term node

    return headerNode; // Return the header node of the sparse matrix linked list
}

// Function to display the sparse matrix in 3-tuple format from the linked list
void displaySparseMatrix(Node *header) {
    if (header == NULL) {
        printf("Sparse matrix is empty or invalid.\n");
        return;
    }

    // Display the header information (total_rows, total_cols, num_terms)
    printf("sparse matrix in 3-tuple format\n");
    printf("%d %d %d\n", header->data.row, header->data.col, header->data.value);

    // Traverse and display each non-zero term
    Node *current = header->next; // Start from the first actual term node
    while (current != NULL) {
        printf("%d %d %d\n", current->data.row, current->data.col, current->data.value);
        current = current->next;
    }
}

// Function to free all nodes in the linked list (to prevent memory leaks)
void freeSparseMatrix(Node *header) {
    Node *current = header;
    Node *next_node;
    while (current != NULL) {
        next_node = current->next; // Store the next node before freeing current
        free(current);             // Free the current node
        current = next_node;       // Move to the next node
    }
    printf("\nSparse matrix linked list freed.\n");
}

int main() {
    Node *sparseMatrixHead = NULL; // Head of the sparse matrix linked list

    // Read and build the sparse matrix linked list
    sparseMatrixHead = readAndBuildSparseMatrix();

    // Display the sparse matrix
    displaySparseMatrix(sparseMatrixHead);

    // Free all dynamically allocated memory
    freeSparseMatrix(sparseMatrixHead);

    return 0; // Indicate successful execution
}
#include <stdio.h>
#include <stdlib.h> // For malloc, free

// Define a structure for a term (non-zero element) in the sparse matrix
typedef struct Term {
    int row;
    int col;
    int value;
} Term;

// Define the structure for a node in the linked list
// Each node will hold a 'Term' and a pointer to the next node
typedef struct Node {
    Term data;         // Stores the row, column, and value of a term
    struct Node *next; // Pointer to the next node in the list
} Node;

// Function to create a new linked list node
Node* createNode(int row, int col, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for a new node
    if (newNode == NULL) {
        printf("Memory allocation failed for new node!\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->data.row = row;     // Set row
    newNode->data.col = col;     // Set column
    newNode->data.value = value; // Set value
    newNode->next = NULL;        // Initialize next pointer to NULL
    return newNode;              // Return the newly created node
}

// Function to read a sparse matrix and represent it using a header single linked list
// The header node (the first node in the list) will store the matrix dimensions
// (total rows, total columns) and the count of non-zero terms.
// Subsequent nodes will store the actual non-zero terms.
Node* readAndBuildSparseMatrix() {
    int total_rows, total_cols;
    printf("Enter size of the sparse matrix (rows cols): ");
    scanf("%d %d", &total_rows, &total_cols);

    printf("Enter elements of sparse matrix (row by row, space separated):\n");

    Node *head = NULL;       // Head of the linked list (will be the header node)
    Node *current = NULL;    // Pointer to the last node added to the list
    int num_terms = 0;       // Counter for non-zero terms

    // Temporarily create a dummy head or handle the header node creation after counting terms
    // For simplicity and to match 3-tuple format, we'll create the header node at the end
    // and link it to the first actual term.

    // Loop through each element of the matrix
    for (int r = 0; r < total_rows; r++) {
        for (int c = 0; c < total_cols; c++) {
            int element_value;
            scanf("%d", &element_value);

            if (element_value != 0) { // If the element is non-zero
                Node *newNode = createNode(r, c, element_value); // Create a node for it
                num_terms++; // Increment non-zero term count

                if (head == NULL) {
                    // This is the first non-zero term, so it will be the first actual term
                    // after the header node. We will link it to the header later.
                    head = newNode; // Temporarily use 'head' for the first actual term
                    current = newNode;
                } else {
                    // Append the new node to the end of the list of terms
                    current->next = newNode;
                    current = newNode;
                }
            }
        }
    }

    // Now, create the actual header node for the sparse matrix
    // This node stores total_rows, total_cols, and num_terms
    Node *headerNode = createNode(total_rows, total_cols, num_terms);
    headerNode->next = head; // The header node points to the first actual term node

    return headerNode; // Return the header node of the sparse matrix linked list
}

// Function to display the sparse matrix in 3-tuple format from the linked list
void displaySparseMatrix(Node *header) {
    if (header == NULL) {
        printf("Sparse matrix is empty or invalid.\n");
        return;
    }

    // Display the header information (total_rows, total_cols, num_terms)
    printf("sparse matrix in 3-tuple format\n");
    printf("%d %d %d\n", header->data.row, header->data.col, header->data.value);

    // Traverse and display each non-zero term
    Node *current = header->next; // Start from the first actual term node
    while (current != NULL) {
        printf("%d %d %d\n", current->data.row, current->data.col, current->data.value);
        current = current->next;
    }
}

// Function to free all nodes in the linked list (to prevent memory leaks)
void freeSparseMatrix(Node *header) {
    Node *current = header;
    Node *next_node;
    while (current != NULL) {
        next_node = current->next; // Store the next node before freeing current
        free(current);             // Free the current node
        current = next_node;       // Move to the next node
    }
    printf("\nSparse matrix linked list freed.\n");
}

int main() {
    Node *sparseMatrixHead = NULL; // Head of the sparse matrix linked list

    // Read and build the sparse matrix linked list
    sparseMatrixHead = readAndBuildSparseMatrix();

    // Display the sparse matrix
    displaySparseMatrix(sparseMatrixHead);

    // Free all dynamically allocated memory
    freeSparseMatrix(sparseMatrixHead);

    return 0; // Indicate successful execution
}
