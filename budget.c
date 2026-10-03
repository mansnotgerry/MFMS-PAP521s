#include <stdio.h>
#include <string.h>
#include "budget.h"

void budgetMenu(Budget budgets[], int *count) {
    int choice;

    do {
        printf("\n--- Budget Management ---\n");
        printf("1. Add Department Budget\n");
        printf("2. List Budgets\n");
        printf("3. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBudget(budgets, count); break;
            case 2: listBudgets(budgets, *count); break;
            case 3: printf("Returning...\n"); break;
            default: printf("Invalid choice!\n"); break;
        }
    } while (choice != 3);
}

void addBudget(Budget budgets[], int *count) {
    Budget b;

    if (*count >= MAX_BUDGETS) {
        printf("Budget list is full.\n");
        return;
    }

    printf("Enter department: ");
    scanf(" %[^\n]", b.department);

    for (int i = 0; i < *count; i++) {
        if (strcmp(budgets[i].department, b.department) == 0) {
            printf("A budget for this department already exists.\n");
            return;
        }
    }

    printf("Enter allocated budget: ");
    scanf("%f", &b.allocated);
    printf("Enter expenditure: ");
    scanf("%f", &b.expenditure);

    if (b.allocated < 0 || b.expenditure < 0) {
        printf("Invalid input: budgets cannot be negative.\n");
        return;
    }

    budgets[*count] = b;
    (*count)++;
    printf("Budget added successfully!\n");
}

void listBudgets(Budget budgets[], int count) {
    if (count == 0) {
        printf("No budgets have been registered.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        Budget b = budgets[i];
        float remaining = b.allocated - b.expenditure;
        printf("Dept: %s | Allocated: %.2f | Expenditure: %.2f | Remaining: %.2f\n",
               b.department, b.allocated, b.expenditure, remaining);
        checkBudgetStatus(b);
    }
}

void checkBudgetStatus(Budget b) {
    if (b.expenditure > b.allocated) {
        printf("Status: OVER BUDGET\n");
    } else {
        printf("Status: WITHIN BUDGET\n");
    }
}
