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
