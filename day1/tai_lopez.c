#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int here(int myGarage) {
    int fuelUnits = (myGarage / 3) - 2;
    return fuelUnits;
}

int main() {
    FILE *lamborghini;
    lamborghini = fopen("input", "r");
    // wc -m input
    char garage[653];
    fread(garage, 653, 1, lamborghini);
    fclose(lamborghini);
    char *knowledge, *garageClicker;
    // sol_1.c:19:8: warning: assignment from incompatible pointer type [-Wincompatible-pointer-types]
    garageClicker = &garage;
    int totalFuelUnits = 0;
    while((knowledge = strsep(&garageClicker, "\n")) != NULL) {
        char books[100];
        strcpy(books, knowledge);
        int bookshelf = atoi(books);
        int fuelUnits = here(bookshelf);
        totalFuelUnits += fuelUnits;
    }
    printf("%d\n", totalFuelUnits);
    return 0;
}
