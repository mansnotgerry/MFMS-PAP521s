#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

typedef struct {
    int id;
    char name[50];
    char type[30];
    float purchaseValue;
    char department[30];
    char condition[20];
} Asset;

void assetsMenu(Asset assets[], int *count);
void addAsset(Asset assets[], int *count);
void listAssets(Asset assets[], int count);
void searchAsset(Asset assets[], int count);

#endif
