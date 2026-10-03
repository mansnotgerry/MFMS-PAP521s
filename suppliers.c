#include <stdio.h>
#include <string.h>
#include "suppliers.h"

void suppliersMenu(Supplier suppliers[], int *count) {
    int choice;

    do {
        printf("\n--- Supplier Management ---\n");
        printf("1. Add Supplier\n");
        printf("2. List Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addSupplier(suppliers, count); break;
            case 2: listSuppliers(suppliers, *count); break;
            case 3: searchSupplier(suppliers, *count); break;
            case 4: printf("Returning...\n"); break;
            default: printf("Invalid choice!\n"); break;
        }
    } while (choice != 4);
}

void addSupplier(Supplier suppliers[], int *count) {
    Supplier s;

    if (*count >= MAX_SUPPLIERS) {
        printf("Supplier list is full.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &s.id);

    for (int i = 0; i < *count; i++) {
        if (suppliers[i].id == s.id) {
            printf("A supplier with that ID already exists.\n");
            return;
        }
    }

    printf("Enter name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter email: ");
    scanf(" %[^\n]", s.email);
    printf("Enter telephone: ");
    scanf(" %[^\n]", s.telephone);
    printf("Enter location: ");
    scanf(" %[^\n]", s.location);

    suppliers[*count] = s;
    (*count)++;
    printf("Supplier added successfully!\n");
}

void listSuppliers(Supplier suppliers[], int count) {
    if (count == 0) {
        printf("No suppliers have been registered.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        Supplier s = suppliers[i];
        printf("ID: %d | Name: %s | Email: %s | Tel: %s | Location: %s\n",
               s.id, s.name, s.email, s.telephone, s.location);
    }
}

void searchSupplier(Supplier suppliers[], int count) {
    char name[50];

    if (count == 0) {
        printf("No suppliers have been registered.\n");
        return;
    }

    printf("Enter supplier name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(suppliers[i].name, name) == 0) {
            printf("Found: ID %d | Email %s | Tel %s | Location %s\n",
                   suppliers[i].id, suppliers[i].email,
                   suppliers[i].telephone, suppliers[i].location);
            return;
        }
    }

    printf("Supplier not found.\n");
}
