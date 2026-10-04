#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    char department[30];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
} Employee;

void employeeMenu(Employee employees[], int *count);
void addEmployee(Employee employees[], int *count);
void listEmployees(Employee employees[], int count);
void searchEmployee(Employee employees[], int count);
float calculateSalary(Employee e);

#endif

