#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 50

typedef struct {
    char department[30];
    float allocated;
    float expenditure;
} Budget;

void budgetMenu(Budget budgets[], int *count);
void addBudget(Budget budgets[], int *count);
void listBudgets(Budget budgets[], int count);
void checkBudgetStatus(Budget b);

#endif
