#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

extern int dest_id;

//kreiranje datoteke
int create_file(const char* const file_name) {
	FILE* fp = fopen(file_name, "ab+");
	if (fp == NULL) {
		perror("Greska pri kreiranju datoteke: ");
		return -1;
	}

	fclose(fp);
	return 0;
}

//dodjela id-a destinaciji
int get_id(const char* dest_file) {
	FILE* fp = fopen(dest_file, "rb");
	if (fp == NULL) {
		return 0;
	}

	DESTINATION dest;
	int counter = 0;

	while (fread(&dest, sizeof(DESTINATION), 1, fp) == 1) {
		counter++;
	}

	fclose(fp);

	dest_id = counter;
	printf("\n***********Kontrolni id koji je u funkciji get_id: %d", dest_id);

	return dest_id;
}


//unos destinacije i upis u datoteku destinations.bin
void add_destination(const char* dest_file) {
	DESTINATION dest;

	dest.id = get_id(dest_file) + 1;

	printf("Unesite naziv destinacije: ");
	scanf(" %49[^\n]%*c", dest.location.name);				//prima razmake u unosu
	printf("Unesite drzavu: ");
	scanf(" %49[^\n]%*c", dest.location.country);			//prima razmake u unosu
	printf("Unesite kontinent: ");
	scanf(" %49[^\n]%*c", dest.location.continent);			//prima razmake u unosu
	printf("Unesite udaljenost (u kilometrima): ");
	scanf("%f", &dest.location.distance);
	printf("Unesite cijenu (u eurima): ");
	scanf("%f", &dest.cost);
	printf("Unesite prijevozna sredstva: ");
	scanf(" %49[^\n]%*c", dest.travel_option);			//prima razmake u unosu
	printf("Unesite sezonu: ");
	scanf("%49s", dest.season);
	printf("Unesite popularnost (u postotcima): ");
	scanf("%d", &dest.popularity);
	printf("Unesite upozorenja: ");
	scanf(" %255[^\n]%*c", dest.warnings);			//prima razmake u unosu
	printf("Unesite atrakcije: ");
	scanf(" %255[^\n]%*c", dest.attractions);		//prima razmake u unosu

	FILE* fp = fopen(dest_file, "ab");
	if (fp == NULL) {
		perror("Greska pri otvaranju datoteke za pisanje: ");
		return;
	}

	fwrite(&dest, sizeof(DESTINATION), 1, fp);
	fclose(fp);
	get_id(dest_file);
	printf("\n****************Ja sam id iz funkcije add_destination:  %d\n", dest_id);
	return;
}

//citanje destinacija iz datoteke i ispis na ekran
void read_destinations(const char* dest_file) {
	FILE* fp = fopen(dest_file, "rb");
	if (fp == NULL) {
		perror("Greska pri otvaranju datoteke za citanje: ");
		return;
	}

	DESTINATION dest;

	while (fread(&dest, sizeof(DESTINATION), 1, fp) == 1) {
		printf("\nID: %d\n", dest.id);
		printf("Naziv destinacije: %s\n", dest.location.name);
		printf("Drzava: %s\n", dest.location.country);
		printf("Kontinent: %s\n", dest.location.continent);
		printf("Udaljenost: %.2f\n", dest.location.distance);
		printf("Cijena: %.2f\n", dest.cost);
		printf("Prijevozna sredstva: %s\n", dest.travel_option);
		printf("Sezona: %s\n", dest.season);
		printf("Popularnost: %d\n", dest.popularity);
		printf("Upozorenja: %s\n", dest.warnings);
		printf("Atrakcije: %s\n\n", dest.attractions);
	}
	fclose(fp);
}

//pitanje zeli li korisnik ispis svih destinacija
void dest_print_question() {
	char choice = 0;
	do {
		printf("\nZelite li prije odabira destinacije ispisati sve dostupne destinacije? (Y/N): ");
		scanf(" %c", &choice);
		while (getchar() != '\n');	//brisanje starih podataka iz medjuspremnika

		if (choice == 'Y' || choice == 'y') {
			read_destinations("destinations.bin");
		}
	} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
}

/*//citanje podataka iz datoteke u dinamicki zauzeto polje
void* read_dest_to_field(const char* const dest_file) {
	FILE* fp = fopen(dest_file, "rb");
	if (fp == NULL) {
		perror("Greska pri otvaranju datoteke za ucitavanje u polje: ");
		exit(EXIT_FAILURE);
	}

	DESTINATION* dest_field = (DESTINATION*)calloc(dest_id, sizeof(DESTINATION));
	if (dest_field == NULL) {
		perror("Greska u dinamicki alociranoj memoriji za destinacije: ");
		exit(EXIT_FAILURE);
	}

	fread(dest_field, sizeof(DESTINATION), dest_id, fp);
	fclose(fp);
	return dest_field;
}	*/

DESTINATION* read_dest_to_field(const char* const file_name, int* dest_count) {
	FILE* fp = fopen(file_name, "rb");
	if (!fp) {
		perror("Greska pri otvaranju datoteke destinacija");
		return NULL;
	}

	fseek(fp, 0, SEEK_END);
	long file_size = ftell(fp);
	rewind(fp);

	*dest_count = file_size / sizeof(DESTINATION);
	DESTINATION* dest_array = (DESTINATION*)malloc(*dest_count * sizeof(DESTINATION));
	if (!dest_array) {
		perror("Greska pri alokaciji memorije za destinacije");
		fclose(fp);
		return NULL;
	}

	fread(dest_array, sizeof(DESTINATION), *dest_count, fp);
	fclose(fp);

	return dest_array;
}


//brisanje destinacije na temelju id-a				-->ubaci objasnjenje funkcije
void dest_delete(int delete_id, char* dest_file) {
	FILE* fp = fopen(dest_file, "rb");

	if (fp == NULL) {
		perror("Greska pri otvaranju datototeke za brisanje destinacije: ");
		exit(EXIT_FAILURE);
	}

	FILE* temp_fp = fopen("temp.bin", "wb");
	if (temp_fp == NULL) {
		perror("Greska pri otvaranju privremene datoteke: ");
		fclose(fp);
		return;
	}

	DESTINATION dest;
	int found = 0;

	while (fread(&dest, sizeof(DESTINATION), 1, fp) == 1) {
		if (dest.id != delete_id) {
			fwrite(&dest, sizeof(DESTINATION), 1, temp_fp);
		}
		else {
			found = 1;
		}
	}

	fclose(fp);
	fclose(temp_fp);


	if (found) {
		remove(dest_file);
		rename("temp.bin", dest_file);
		printf("Destinacija s ID %d je uspjesno obrisana.\n", delete_id);
		get_id(dest_file);			//azuriraj dest_id nakon brisanja
	}
	else {
		printf("Destinacija s ID %d nije pronadjena.\n", delete_id);
		remove("temp.bin");
	}
}


int match_criteria(DESTINATION dest, float budget, char travel_option, char season) {
	int match_count = 0;

	if (dest.cost <= budget) match_count++;
	if (dest.travel_option == travel_option) match_count++;
	if (dest.season == season) match_count++;

	// Additional criteria can be added here
	// if (other_criteria) match_count++;

	return match_count;
}

void find_best_destinations(DESTINATION* dest_array, int dest_count, float budget, char travel_option, char season) {
	int* match_counts = (int*)malloc(dest_count * sizeof(int));
	for (int i = 0; i < dest_count; i++) {
		match_counts[i] = match_criteria(dest_array[i], budget, travel_option, season);
	}

	for (int i = 0; i < 4 && i < dest_count; i++) {
		int max_index = -1;
		int max_value = -1;
		for (int j = 0; j < dest_count; j++) {
			if (match_counts[j] > max_value) {
				max_value = match_counts[j];
				max_index = j;
			}
		}

		if (max_index != -1) {
			printf("Destinacija: %s, Zemlja: %s, Kontinent: %s, Cijena: %.2f, Podudaranje kriterija: %d\n",
				dest_array[max_index].location.name,
				dest_array[max_index].location.country,
				dest_array[max_index].location.continent,
				dest_array[max_index].cost,
				max_value);
			match_counts[max_index] = -1; // Exclude this destination from further consideration
		}
	}

	free(match_counts);
}

void gather_user_preferences(float* budget, char* travel_option, char* season) {
	printf("Unesite vas budzet: ");
	scanf("%f", budget);

	printf("Unesite opciju putovanja (A za avion, T za vlak, B za autobus): ");
	scanf(" %c", travel_option);

	printf("Unesite preferirano godisnje doba (S za ljeto, W za zimu, A za jesen, F za proljece): ");
	scanf(" %c", season);
}

