<<<<<<< HEAD
// Q1.3 Write a program to create a structure to store the information of n number of Employees. Employee’s information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%. Display the information of employees with gross salary. Use array of structure.

#include <stdio.h>

int main()
{
    // Defining a structure to hold employee info
    typedef struct 
    {
        char name[50];
        char designation[50];
        float basic_salary;
        float hra_percentage;
        float da_percentage;
    } Employee;

    int n; // Holds number of employees

    // Asking user how many employees to process
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Declaring array of structures based on user input
    Employee emp[n];

    // Loop to input details for each employee
    for(int i = 0; i < n; i++)
    {
        printf("\nEnter details for employee %d:\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", emp[i].name); // Note the space before % to consume newline

        printf("Designation: ");
        scanf(" %[^\n]", emp[i].designation);

        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);

        printf("HRA %%: ");
        scanf("%f", &emp[i].hra_percentage);

        printf("DA %%: ");
        scanf("%f", &emp[i].da_percentage);
    }

    // Output Section
    printf("\n-----------------------------------\n");
    printf("Employee Details:\n");

    // Loop to calculate and display gross salary per employee
    for(int i = 0; i < n; i++)
    {
        float hra = (emp[i].hra_percentage / 100) * emp[i].basic_salary;
        float da = (emp[i].da_percentage / 100) * emp[i].basic_salary;
        float gross_salary = emp[i].basic_salary + hra + da;

        printf("Name: %s\n", emp[i].name);
        printf("Designation: %s\n", emp[i].designation);
        printf("Basic Salary: %.2f\n", emp[i].basic_salary);
        printf("HRA: %.2f\n", hra);
        printf("DA: %.2f\n", da);
        printf("Gross Salary: %.2f\n", gross_salary);
    }

    return 0;
=======
#include <stdio.h>   // Standard input-output library
#include <string.h>  // Required for string manipulation functions like strcpy()

// Define a structure named 'Employee' to hold employee information.
// Structures allow grouping of different data types under a single name.
struct Employee {
    int emp_id;          // Employee ID (integer)
    char name[50];       // Employee Name (character array/string)
    char designation[50]; // Employee Designation (character array/string)
    float basic_salary;  // Basic Salary (floating-point number)
    float hra_percent;   // House Rent Allowance percentage (floating-point number)
    float da_percent;    // Dearness Allowance percentage (floating-point number)
};

int main() {
    int num_employees; // Variable to store the number of employees

    // Prompt the user to enter the number of employees.
    printf("Enter no.of employees: ");
    scanf("%d", &num_employees);

    // Declare an array of 'Employee' structures.
    // This allows storing information for multiple employees.
    // Using Variable Length Array (VLA), which is a C99 feature.
    struct Employee employees[num_employees];

    // Loop to get information for each employee.
    for (int i = 0; i < num_employees; i++) {
        printf("\nEnter employee %d information:\n", i + 1);

        // Clear the input buffer. This is important after reading a number
        // (like num_employees or basic_salary) before reading a string with scanf("%s").
        // Otherwise, the newline character left in the buffer might be read by scanf("%s").
        while (getchar() != '\n');

        printf("Enter Name: ");
        // scanf("%s", employees[i].name) reads a string until a whitespace is encountered.
        // No '&' is needed for char arrays when reading strings because the array name
        // itself acts as a pointer to its first element.
        fgets(employees[i].name, sizeof(employees[i].name), stdin); // Use fgets for strings with spaces
        employees[i].name[strcspn(employees[i].name, "\n")] = 0; // Remove trailing newline from fgets

        printf("Enter Designation: ");
        fgets(employees[i].designation, sizeof(employees[i].designation), stdin);
        employees[i].designation[strcspn(employees[i].designation, "\n")] = 0;

        printf("Enter Basic Salary: ");
        scanf("%f", &employees[i].basic_salary);

        printf("Enter HRA %%: ");
        scanf("%f", &employees[i].hra_percent);

        printf("Enter DA %%: ");
        scanf("%f", &employees[i].da_percent);
    }

    // Display the information for all employees with calculated gross salary.
    printf("\nEmployee Information:\n");
    for (int i = 0; i < num_employees; i++) {
        // Calculate HRA and DA amounts based on percentages.
        // Divide by 100.0 to ensure floating-point division.
        float hra_amount = employees[i].basic_salary * (employees[i].hra_percent / 100.0);
        float da_amount = employees[i].basic_salary * (employees[i].da_percent / 100.0);

        // Calculate Gross Salary.
        float gross_salary = employees[i].basic_salary + hra_amount + da_amount;

        // Print employee details and gross salary.
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2f\n", employees[i].basic_salary);
        printf("HRA %%: %.0f%%\n", employees[i].hra_percent); // Display as whole number percentage
        printf("DA %%: %.0f%%\n", employees[i].da_percent);   // Display as whole number percentage
        printf("Gross Salary: %.2f\n\n", gross_salary);       // Display with 2 decimal places
    }

    return 0; // Indicate successful program execution.
>>>>>>> d99b03f (Further updates to Lab 1 and Lab 2 assignment codes)
}

/*
> SAMPLE INPUT
______________

    Enter the number of employees: 1

        Enter details for employee 1:
        Name: Matthew Murdock
        Designation: Lawyer
        Basic Salary: 80000
        HRA %: 10
        DA %: 5

> SAMPLE OUTPUT
_______________

-----------------------------------
Employee Details:
Name: Mathew Murdock
Designation: Lawyer
Basic Salary: 80000.00
HRA: 8000.00
DA: 4000.00
Gross Salary: 92000.00
*/
