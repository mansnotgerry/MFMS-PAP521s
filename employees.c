#include <stdio.h>
#include <string.h>
#include "employees.h"

void employeeMenu(Employee employees[], int *count) {
    int choice;

    do {
        printf("\n--- Employee Management ---\n");
        printf("1. Add Employee\n");
        printf("2. List Employees\n");
        printf("3. Search Employee\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(employees, count); break;
            case 2: listEmployees(employees, *count); break;
            case 3: searchEmployee(employees, *count); break;
            case 4: printf("Returning...\n"); break;
            default: printf("Invalid choice!\n"); break;
        }
    } while (choice != 4);
}

void addEmployee(Employee employees[], int *count) {
    Employee e;

    if (*count >= MAX_EMPLOYEES) {
        printf("Employee list is full.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &e.id);

    for (int i = 0; i < *count; i++) {
        if (employees[i].id == e.id) {
            printf("An employee with that ID already exists.\n");
            return;
        }
    }

    printf("Enter name: ");
    scanf(" %[^\n]", e.name);
    printf("Enter department: ");
    scanf(" %[^\n]", e.department);
    printf("Enter basic salary: ");
    scanf("%f", &e.basicSalary);
    printf("Enter housing allowance: ");
    scanf("%f", &e.housingAllowance);
    printf("Enter transport allowance: ");
    scanf("%f", &e.transportAllowance);

    if (e.basicSalary < 0 || e.housingAllowance < 0 || e.transportAllowance < 0) {
        printf("Invalid input: salaries/allowances cannot be negative.\n");
        return;
    }

    employees[*count] = e;
    (*count)++;
    printf("Employee added successfully!\n");
}

void listEmployees(Employee employees[], int count) {
    if (count == 0) {
        printf("No employees have been registered.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        Employee e = employees[i];
        printf("ID: %d | Name: %s | Dept: %s | Total Salary: %.2f\n",
               e.id, e.name, e.department, calculateSalary(e));
    }
}

void searchEmployee(Employee employees[], int count) {
    char name[50];

    if (count == 0) {
        printf("No employees have been registered.\n");
        return;
    }

    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].name, name) == 0) {
            printf("Found: ID %d | Dept %s | Salary %.2f\n",
                   employees[i].id, employees[i].department,
                   calculateSalary(employees[i]));
            return;
        }
    }

    printf("Employee not found.\n");
}

float calculateSalary(Employee e) {
    return e.basicSalary + e.housingAllowance + e.transportAllowance;
}

