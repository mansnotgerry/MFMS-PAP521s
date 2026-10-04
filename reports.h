#ifndef REPORTS_H
#define REPORTS_H

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void reportsMenu(Employee employees[], int empCount,
                 Budget budgets[], int budCount,
                 Supplier suppliers[], int supCount,
                 Asset assets[], int assetCount);

#endif

