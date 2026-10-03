#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

int main(void) {
    Employee employees[MAX_EMPLOYEES];
    Budget budgets[MAX_BUDGETS];
    Supplier suppliers[MAX_SUPPLIERS];
    Asset assets[MAX_ASSETS];

    int employeeCount = 0;
    int budgetCount = 0;
    int supplierCount = 0;
    int assetCount = 0;
    int choice;

    do {
        printf("\n--- MFMS Main Menu ---\n");
        printf("1. Employees\n");
        printf("2. Budget\n");
        printf("3. Suppliers\n");
        printf("4. Assets\n");
        printf("5. Reports\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                employeeMenu(employees, &employeeCount);
                break;
            case 2:
                budgetMenu(budgets, &budgetCount);
                break;
            case 3:
                suppliersMenu(suppliers, &supplierCount);
                break;
            case 4:
                assetsMenu(assets, &assetCount);
                break;
            case 5:
                reportsMenu(employees, employeeCount,
                             budgets, budgetCount,
                             suppliers, supplierCount,
                             assets, assetCount);
                break;
            case 0:
                printf("Exiting MFMS...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
