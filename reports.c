#include <stdio.h>
#include "reports.h"

void reportsMenu(Employee employees[], int empCount,
                 Budget budgets[], int budCount,
                 Supplier suppliers[], int supCount,
                 Asset assets[], int assetCount) {
    int choice;
    do {
        printf("\n--- Reports ---\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                float total = 0, max = 0, min = 999999;
                for(int i = 0; i < empCount; i++) {
                    float salary = calculateSalary(employees[i]);
                    total += salary;
                    if(salary > max) max = salary;
                    if(salary < min) min = salary;
                }
                printf("Total Employees: %d\n", empCount);
                if(empCount > 0) {
                    printf("Average Salary: %.2f\n", total/empCount);
                    printf("Highest Salary: %.2f\n", max);
                    printf("Lowest Salary: %.2f\n", min);
                }
                break;
            }
            case 2: {
                float totalAlloc = 0, totalExp = 0;
                for(int i = 0; i < budCount; i++) {
                    totalAlloc += budgets[i].allocated;
                    totalExp += budgets[i].expenditure;
                }
                printf("Total Allocated: %.2f\n", totalAlloc);
                printf("Total Expenditure: %.2f\n", totalExp);
                printf("Remaining: %.2f\n", totalAlloc - totalExp);
                for(int i = 0; i < budCount; i++) {
                    if(budgets[i].expenditure > budgets[i].allocated) {
                        printf("Dept %s exceeded budget!\n", budgets[i].department);
                    }
                }
                break;
            }
            case 3: {
                for(int i = 0; i < supCount; i++) {
                    printf("Supplier: %s | Email: %s | Tel: %s | Location: %s\n",
                           suppliers[i].name, suppliers[i].email,
                           suppliers[i].telephone, suppliers[i].location);
                }
                break;
            }
            case 4: {
                for(int i = 0; i < assetCount; i++) {
                    printf("Asset: %s | Type: %s | Value: %.2f | Dept: %s | Condition: %s\n",
                           assets[i].name, assets[i].type,
                           assets[i].purchaseValue, assets[i].department,
                           assets[i].condition);
                }
                break;
            }
            case 5: printf("Returning...\n"); break;
            default: printf("Invalid choice!\n"); break;
        }
    } while(choice != 5);
}

