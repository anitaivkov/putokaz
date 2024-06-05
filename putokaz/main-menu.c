#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"

enum menu_items {
	ODABIR_DEST = 1,	//1. izbor
	DODAVANJE_DEST,		//2. izbor
	AZURIRANJE_DEST,	//3. izbor
	ISPIS_DEST,			//4. izbor
	BRISANJE_DEST,		//5. izbor
	IZLAZ_IZ_PROGRAMA	//6.izbor
};

int main_menu(char* dest_file, char* traveler_file) {
	while (1) {
		printf("\t=====================================\t\t");
		printf("\n\t\t======\tPUTOKAZ\t======\t\t\n");
		printf("\n\t\t1. Odabir destinacije\t\t\n");
		printf("\n\t\t2. Dodavanje destinacije\t\t\n");
		printf("\n\t\t3. Azuriranje destinacije\t\t\n");
		printf("\n\t\t4. Ispis destinacija\t\t\n");
		printf("\n\t\t5. Brisanje destinacije\t\t\n");
		printf("\n\t\t6. Izlaz iz programa\t\t\n");
		printf("\t=====================================\t\t\n");

		int main_choice = 0;

		printf("Unesite svoj odabir: ");
		scanf("%d", &main_choice);

		switch (main_choice) {
		case ODABIR_DEST:
			dest_print_question();
			//sva pitanja za sortiranje kroz destinacije
			//odgovore na pitanja spremam u traveler
			static DESTINATION* dest_field = NULL;

			dest_field = (DESTINATION*)read_dest_to_field(dest_file);

			//delociraj memoriju!
			break;

		case DODAVANJE_DEST:
			add_destination(dest_file);
			break;

		case AZURIRANJE_DEST:
			dest_print_question();
			printf("\nJa sam 3. izbor.\n");
			//izmjena nekog podatka u strukturi DESTINATION
			break; 

		case ISPIS_DEST:
			read_destinations(dest_file);
			break;

		case BRISANJE_DEST:
			dest_print_question();
			printf("\nJa sam 6. izbor.\n");

			//izbor: zeli li korisnik brisanje samo jedne destinacije ili vise; brisanje je po kljucnoj rijeci,
			//gdje cu od korisnika najprije traziti po kojem parametru zeli pretrazivanje (cijena, drzava itd)
			break;

		case IZLAZ_IZ_PROGRAMA:
			free(dest_field);

			return 0;
			break;

		default:
			main_choice = 0;
		}
	}

	return 0;
}
