#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"

enum menu_items {
	ODABIR_DEST = 1,	//1. izbor
	DODAVANJE_DEST,		//2. izbor
	AZURIRANJE_DEST,	//3. izbor
	DODAVANJE_UPOZORENJA,	//4. izbor
	ISPIS_DEST,			//5. izbor
	BRISANJE_DEST		//6. izbor
};

int main_menu() {
	printf("\t=====================================\t\t");
	printf("\n\t\t======\tPUTOKAZ\t======\t\t\n");
	printf("\n\t\t1. Odabir destinacije\t\t\n");
	printf("\n\t\t2. Dodavanje destinacije\t\t\n");
	printf("\n\t\t3. Azuriranje destinacije\t\t\n");
	printf("\n\t\t4. Dodavanje upozorenja za destinaciju\t\t\n");
	printf("\n\t\t5. Ispis destinacije/a\t\t\n");
	printf("\n\t\t6. Brisanje destinacije/a\t\t\n");
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

	case AZURIRANJE_DEST:
		printf("\nJa sam 3. izbor.\n");
		break;

	case DODAVANJE_UPOZORENJA:
		printf("\nJa sam 4. izbor.\n");
		break;

	case ISPIS_DEST:
		printf("\nJa sam 5. izbor.\n");
		break;

	case BRISANJE_DEST:
		printf("\nJa sam 6. izbor.\n");
		break;
	}

	return choice;
}
