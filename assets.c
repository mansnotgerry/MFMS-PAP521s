#include <stdio.h>
#include <string.h>
#include "assets.h"

void assetsMenu(Asset assets[], int *count) {
    int choice;

    do {
        printf("\n--- Asset Management ---\n");
        printf("1. Add Asset\n");
        printf("2. List Assets\n");
        printf("3. Search Asset\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addAsset(assets, count); break;
            case 2: listAssets(assets, *count); break;
            case 3: searchAsset(assets, *count); break;
            case 4: printf("Returning...\n"); break;
            default: printf("Invalid choice!\n"); break;
        }
    } while (choice != 4);
}

void addAsset(Asset assets[], int *count) {
    Asset a;

    if (*count >= MAX_ASSETS) {
        printf("Asset list is full.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &a.id);

    for (int i = 0; i < *count; i++) {
        if (assets[i].id == a.id) {
            printf("An asset with that ID already exists.\n");
            return;
        }
    }

    printf("Enter name: ");
    scanf(" %[^\n]", a.name);
    printf("Enter type: ");
    scanf(" %[^\n]", a.type);
    printf("Enter purchase value: ");
    scanf("%f", &a.purchaseValue);
    printf("Enter department: ");
    scanf(" %[^\n]", a.department);
    printf("Enter condition: ");
    scanf(" %[^\n]", a.condition);

    if (a.purchaseValue < 0) {
        printf("Invalid input: purchase value cannot be negative.\n");
        return;
    }

    assets[*count] = a;
    (*count)++;
    printf("Asset added successfully!\n");
}

void listAssets(Asset assets[], int count) {
    if (count == 0) {
        printf("No assets have been registered.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        Asset a = assets[i];
        printf("ID: %d | Name: %s | Type: %s | Value: %.2f | Dept: %s | Condition: %s\n",
               a.id, a.name, a.type, a.purchaseValue, a.department, a.condition);
    }
}

void searchAsset(Asset assets[], int count) {
    char name[50];

    if (count == 0) {
        printf("No assets have been registered.\n");
        return;
    }

    printf("Enter asset name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(assets[i].name, name) == 0) {
            printf("Found: ID %d | Type %s | Value %.2f | Dept %s | Condition %s\n",
                   assets[i].id, assets[i].type, assets[i].purchaseValue,
                   assets[i].department, assets[i].condition);
            return;
        }
    }

    printf("Asset not found.\n");
}

