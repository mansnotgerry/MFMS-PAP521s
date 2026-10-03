#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

typedef struct {
    int id;
    char name[50];
    char email[50];
    char telephone[20];
    char location[30];
} Supplier;

void suppliersMenu(Supplier suppliers[], int *count);
void addSupplier(Supplier suppliers[], int *count);
void listSuppliers(Supplier suppliers[], int count);
void searchSupplier(Supplier suppliers[], int count);

#endif
