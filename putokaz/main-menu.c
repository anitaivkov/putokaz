#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"

enum menu_items {
	ODABIR_DEST = 1,		//1. izbor
	DODAVANJE_DEST,		//2. izbor
	ISPIS_DEST,			//3. izbor
	AZURIRANJE_DEST,	//4. izbor
	BRISANJE_DEST		//5. izbor
};

int main_menu() {
	printf("\t=====================================\t\t");
	printf("\n\t\t======\tPUTOKAZ\t======\t\t\n");
	printf("\n\t\t1. Odaberi destinaciju\t\t\n");
	printf("\n\t\t2. Dodaj destinaciju\t\t\n");
	printf("\n\t\t3. Ispisi destinaciju/e\t\t\n");
	printf("\n\t\t4. Azuriraj destinaciju\t\t\n");
	printf("\n\t\t5. Izbrisi destinaciju/e\t\t\n");
	printf("\t=====================================\t\t\n");

	int choice = 0;
	printf("Unesite svoj odabir: ");
	scanf("%d", &choice);
	printf("%d", choice);

	switch (choice) {
	case ODABIR_DEST:
		printf("\nJa sam 1. izbor.\n");
		break;

	case DODAVANJE_DEST:
		printf("\nJa sam 2. izbor.\n");
		break;

	case ISPIS_DEST:
		printf("\nJa sam 3. izbor.\n");
		break;

	case AZURIRANJE_DEST:
		printf("\nJa sam 4. izbor.\n");
		break;

	case BRISANJE_DEST:
		printf("\nJa sam 5. izbor.\n");
		break;
	}

	return choice;
}
