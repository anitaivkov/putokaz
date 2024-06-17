#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "data-types.h"
#include "functions.h"

extern int dest_id;

int main_menu(char* dest_file, char* traveler_file) {
	while (1) {
		dest_id = get_id(dest_file);

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
		case CHOOSE_DEST:
			dest_print_question();																							
			int dest_count = 0;
			dest_field = read_dest_to_field(dest_file, &dest_count);
			if (dest_field) {
				float budget;
				char travel_options[256];
				int season;

				gather_user_preferences(&budget, travel_options, &season);
				find_best_destinations(dest_field, dest_count, budget, travel_options, season);
			}
			break;

		case ADD_DEST:
			add_destination(dest_file);
			break;

		case UPDATE_DEST:
			dest_print_question();
			printf("\nJa sam 3. izbor.\n");
			//izmjena nekog podatka u strukturi DESTINATION
			break; 

		case PRINT_DEST:
			read_destinations(dest_file);
			break;

		case DELETE_DEST:
			dest_print_question();
			int delete_id = 0;
			printf("\nUnesite ID destinacije koju zelite izbrisati: ");
			scanf("%d", &delete_id);

			if (delete_id > dest_id+1) {
				printf("Unesite postojeci ID.\n");
				dest_print_question();
			}
			else {
				dest_delete(delete_id, dest_file);
			}

			//izbor: zeli li korisnik brisanje samo jedne destinacije ili vise; brisanje je po kljucnoj rijeci,
			//gdje cu od korisnika najprije traziti po kojem parametru zeli pretrazivanje (cijena, drzava itd)
			//ispravi brisanje t.d. se ispravno izvodi i nakon nekoliko pogresnih izbora (neka do-while petljica itd)
			break;

		case EXIT:
			free(dest_field);
			dest_field = NULL;
			return 0;

			break;

		default:
			main_choice = 0;
		}
	}

	return 0;
}
