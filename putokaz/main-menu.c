#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"

enum menu_items {
	ODABIR_DEST = 1,	//1. izbor
	DODAVANJE_DEST,		//2. izbor
	AZURIRANJE_DEST,	//3. izbor
	DODAVANJE_UPOZORENJA,	//4. izbor
	ISPIS_DEST,			//5. izbor
	BRISANJE_DEST,		//6. izbor
	IZLAZ_IZ_PROGRAMA
};

int main_menu(char* destinations_file, char* traveler_file) {
	printf("\t=====================================\t\t");
	printf("\n\t\t======\tPUTOKAZ\t======\t\t\n");
	printf("\n\t\t1. Odabir destinacije\t\t\n");
	printf("\n\t\t2. Dodavanje destinacije\t\t\n");
	printf("\n\t\t3. Azuriranje destinacije\t\t\n");
	printf("\n\t\t4. Dodavanje upozorenja za destinaciju\t\t\n");
	printf("\n\t\t5. Ispis destinacije/a\t\t\n");
	printf("\n\t\t6. Brisanje destinacije/a\t\t\n");
	printf("\n\t\t7. Izlaz iz programa/a\t\t\n");
	printf("\t=====================================\t\t\n");

	int main_choice = 0;

	printf("Unesite svoj odabir: ");
	scanf("%d", &main_choice);

	switch (main_choice) {
	case ODABIR_DEST:
		dest_print_question();
		//sva pitanja za sortiranje kroz destinacije
		//odgovore na pitanja spremam u traveler, ali i u jednostruko povezanu listu
		break;

	case DODAVANJE_DEST:
		printf("\nJa sam 2. izbor.\n");
		//dodavanje destinacija u datoteku destinations.txt
		//dodaj redni broj destinacije u datoteku!!!
		break;

	case AZURIRANJE_DEST:
		dest_print_question();
		printf("\nJa sam 3. izbor.\n");
		//izmjena nekog podatka u strukturi DESTINATION
		break;

	case DODAVANJE_UPOZORENJA:
		dest_print_question();
		printf("\nJa sam 4. izbor.\n");
		//dodavanje upzorenja kao string u destination.warning
		//MOZDA: staviti nekakvu povezanu listu ili još jednu ugnijezdenu strukturu
		break;

	case ISPIS_DEST:
		printf("\nJa sam 5. izbor.\n");

		//izbor: zeli li korisnik ispis samo jedne destinacije ili vise; 
		//ako zeli odreden broj ispisanih destinacija --> previse posla!
		break;

	case BRISANJE_DEST:
		dest_print_question();
		printf("\nJa sam 6. izbor.\n");

		//izbor: zeli li korisnik brisanje samo jedne destinacije ili vise; brisanje je po kljucnoj rijeci,
		//gdje cu od korisnika najprije traziti po kojem parametru zeli pretrazivanje (cijena, drzava itd)
		break;

	case IZLAZ_IZ_PROGRAMA:
		return 0;
	}

	return 0;
}
