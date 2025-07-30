#include <stdio.h>   // Standard input/output functions
#include <stdlib.h>  // For dynamic memory allocation (malloc, free)
#include <string.h>  // For string manipulation (strcspn)

// Structure to hold employee details
typedef struct {
    char name[50];      // Employee's name
    char designation[50]; // Employee's designation
    float basic_salary; // Basic salary
    float hra_percent;  // House Rent Allowance percentage
    float da_percent;   // Dearness Allowance percentage
    float gross_salary; // Calculated gross salary
} Employee;

int main() {
    int n; // Number of employees
    Employee *employees; // Pointer to an array of Employee structures

    // Get the number of employees from the user
    printf("Enter no.of employees: ");
    scanf("%d", &n);

    // Clear the input buffer. This is important after scanf() and before fgets().
    while (getchar() != '\n');

    // Allocate memory for 'n' employees dynamically
    employees = (Employee *)malloc(n * sizeof(Employee));

    // Check if memory allocation was successful
    if (employees == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit with an error code
    }

    // Loop to get information for each employee
    for (int i = 0; i < n; i++) {
        printf("\nEnter employee %d information:\n", i + 1);

        printf("Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        // Remove the newline character that fgets might read
        employees[i].name[strcspn(employees[i].name, "\n")] = 0;

        printf("Designation: ");
        fgets(employees[i].designation, sizeof(employees[i].designation), stdin);
        employees[i].designation[strcspn(employees[i].designation, "\n")] = 0;

        printf("Basic Salary: ");
        scanf("%f", &employees[i].basic_salary);

        printf("HRA %%: "); // Use %% to print a literal %
        scanf("%f", &employees[i].hra_percent);

        printf("DA %%: ");
        scanf("%f", &employees[i].da_percent);

        // Clear the input buffer for the next iteration
        while (getchar() != '\n');

        // Calculate Gross Salary
        employees[i].gross_salary = employees[i].basic_salary +
                                    (employees[i].basic_salary * employees[i].hra_percent / 100.0) +
                                    (employees[i].basic_salary * employees[i].da_percent / 100.0);
    }

    // Display employee information
    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; i++) {
        printf("\nName: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2f\n", employees[i].basic_salary);
        printf("HRA %%: %.2f%%\n", employees[i].hra_percent);
        printf("DA %%: %.2f%%\n", employees[i].da_percent);
        printf("Gross Salary: %.2f\n", employees[i].gross_salary);
    }

    // Free the dynamically allocated memory
    free(employees);
    employees = NULL; // Good practice to set pointer to NULL after freeing

    return 0; // Program finished successfully
}
