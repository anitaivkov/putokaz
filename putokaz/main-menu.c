#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"

int dest_id;

enum menu_items {
	ODABIR_DEST = 1,	//1. izbor
	DODAVANJE_DEST,		//2. izbor
	AZURIRANJE_DEST,	//3. izbor
	ISPIS_DEST,			//4. izbor
	BRISANJE_DEST,		//5. izbor
	IZLAZ_IZ_PROGRAMA	//6.izbor
};

int main_menu(char* dest_file, char* traveler_file) {
	//get_id(dest_file);

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

		static DESTINATION* dest_field = NULL;

		switch (main_choice) {
		case ODABIR_DEST:
			dest_print_question();

			dest_field = (DESTINATION*)read_dest_to_field(dest_file);
			printf("ukupni id od destinacije je: %d\n", dest_id);

			/*
			//kontrolni printf
			printf("ukupni id od destinacije je: %d\n", dest_id);
			printf("Kontrolni printf:\n");
			for (int i = 0; i < dest_id; i++) {
				printf("\nID: % d\n", (dest_field+i)->id);
				printf("Naziv destinacije: %s\n", (dest_field + i)->location.name);
				printf("Drzava: %s\n", (dest_field + i)->location.country);
				printf("Kontinent: %s\n", (dest_field + i)->location.continent);
				printf("Udaljenost: %.2f\n", (dest_field + i)->location.distance);
				printf("Cijena: %.2f\n", (dest_field + i)->cost);
				printf("Prijevozna sredstva: %s\n", (dest_field + i)->travel_option);
				printf("Sezona: %s\n", (dest_field + i)->season);
				printf("Popularnost: %d\n", (dest_field + i)->popularity);
				//printf("Upozorenja: %s\n", dest.warnings);
				printf("Atrakcije: %s\n\n", (dest_field + i)->attractions);
			}		*/



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
