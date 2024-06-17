#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data-types.h"
#include "functions.h"

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

	while (fread(&dest, sizeof(DESTINATION), 1, fp)) {
		counter++;
	}

	fclose(fp);
	dest_id = counter;

	return dest_id;
}

//unos destinacije i upis u datoteku destinations.bin
void add_destination(const char* dest_file) {
	DESTINATION dest;
	int continent_choice;
	int season_choice;
	int travel_option_choice;
	char travel_options[50] = "\0";

	const char* continent_names[] = {
	"Europa",
	"Azija",
	"Afrika",
	"Sjeverna Amerika",
	"Juzna Amerika",
	"Australija",
	"Antarktika",
	"Nepoznato"
	};

	dest.id = get_id(dest_file) + 1;

	printf("Unesite naziv destinacije: ");
	scanf(" %49[^\n]%*c", dest.location.name);				//prima razmake u unosu
	printf("Unesite drzavu: ");
	scanf(" %49[^\n]%*c", dest.location.country);			//prima razmake u unosu

	//izmjena u izbor
	//printf("Unesite kontinent: ");
	//scanf(" %49[^\n]%*c", dest.location.continent);			//prima razmake u unosu

	// Unos za kontinent
	printf("Odaberite kontinent:\n");
	printf("1. Europa\n");
	printf("2. Azija\n");
	printf("3. Afrika\n");
	printf("4. Sjeverna Amerika\n");
	printf("5. Juzna Amerika\n");
	printf("6. Australija\n");
	printf("7. Antarktika\n");
	printf("Unesite svoj odabir: ");
	scanf("%d", &continent_choice);

	if (continent_choice >= 1 && continent_choice <= 7) {
		strcpy(dest.location.continent, continent_names[continent_choice - 1]);
	}
	else {
		strcpy(dest.location.continent, continent_names[7]); // "Nepoznato"
	}

	printf("Unesite udaljenost (u kilometrima): ");
	scanf("%f", &dest.location.distance);
	printf("Unesite cijenu (u eurima): ");
	scanf("%f", &dest.cost);

	/*
	//izmjena u izbor
	printf("Unesite prijevozna sredstva: ");
	scanf(" %49[^\n]%*c", dest.travel_option);			//prima razmake u unosu
	//izmjena u izbor
	printf("Odaberite najbolje godisnje doba za posjet:\n1.) Proljece\n2.) Ljeto\n3.) Jesen\n4.) Zima");
	scanf("%49s", dest.season);

	printf("Unesite popularnost (u postotcima): ");
	scanf("%d", &dest.popularity);
	printf("Unesite upozorenja: ");
	scanf(" %255[^\n]%*c", dest.warnings);			//prima razmake u unosu
	printf("Unesite atrakcije: ");
	scanf(" %255[^\n]%*c", dest.attractions);		//prima razmake u unosu
	*/

	// Unos za prijevozna sredstva
	printf("Odaberite prijevozna sredstva (unesite 0 za kraj):\n");
	printf("1. Automobil\n");
	printf("2. Avion\n");
	printf("3. Vlak\n");
	printf("4. Autobus\n");
	do {
		printf("Unesite svoj odabir: ");
		scanf("%d", &travel_option_choice);
		if (travel_option_choice >= 1 && travel_option_choice <= 4) {
			if (strlen(travel_options) > 0) {
				strcat(travel_options, ", ");
			}
			switch (travel_option_choice) {
			case CAR:
				strcat(travel_options, "Automobil");
				break;
			case PLANE:
				strcat(travel_options, "Avion");
				break;
			case TRAIN:
				strcat(travel_options, "Vlak");
				break;
			case BUS:
				strcat(travel_options, "Autobus");
				break;
			}
		}
	} while (travel_option_choice != 0);

	strcpy(dest.travel_option, travel_options);

	// Unos za sezonu
	printf("Odaberite sezonu:\n");
	printf("1. Ljeto\n");
	printf("2. Zima\n");
	printf("3. Jesen\n");
	printf("4. Proljece\n");
	printf("Unesite svoj odabir: ");
	scanf("%d", &season_choice);

	if (season_choice >= 1 && season_choice <= 4) {
		dest.season[0] = '\0';
		switch (season_choice) {
		case SPRING:
			strcpy(dest.season, "Proljece");
			break;
		case SUMMER:
			strcpy(dest.season, "Ljeto");
			break;
		case AUTUMN:
			strcpy(dest.season, "Jesen");
			break;
		case WINTER:
			strcpy(dest.season, "Zima");
			break;
		}
	}

	FILE* fp = fopen(dest_file, "ab");
	if (fp == NULL) {
		perror("Greska pri otvaranju datoteke za pisanje: ");
		return;
	}

	fwrite(&dest, sizeof(DESTINATION), 1, fp);
	fclose(fp);
	get_id(dest_file);
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


DESTINATION* read_dest_to_field(const char* const file_name, int* dest_count) {
	FILE* fp = fopen(file_name, "rb");
	if (fp == NULL) {
		perror("Greska pri otvaranju datoteke za ucitavanje u polje: ");
		exit(EXIT_FAILURE);
	}

	fseek(fp, 0, SEEK_END);
	long file_size = ftell(fp);
	rewind(fp);

	*dest_count = file_size / sizeof(DESTINATION);

	DESTINATION* dest_array = (DESTINATION*)calloc(*dest_count, sizeof(DESTINATION));
	if (!dest_array) {
		perror("\nGreska pri alokaciji memorije za destinacije");
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

int match_criteria(DESTINATION dest, float budget, const char* travel_options, int season) {
	if (dest.cost > budget) {
		return 0;
	}

	// Provjera putnih opcija
	if (strlen(travel_options) > 0 && !strstr(travel_options, dest.travel_option)) {
		return 0;
	}

	// Provjera sezone
	if (strcmp(dest.season, "Ljeto") == 0 && season != SUMMER) return 0;
	if (strcmp(dest.season, "Zima") == 0 && season != WINTER) return 0;
	if (strcmp(dest.season, "Jesen") == 0 && season != AUTUMN) return 0;
	if (strcmp(dest.season, "Proljece") == 0 && season != SPRING) return 0;

	return 1;
}


void gather_user_preferences(float* budget, char* travel_options, int* season) {
	int travel_option_choice;

	printf("Unesite svoj budzet (u eurima): ");
	scanf("%f", budget);

	printf("Odaberite prijevozna sredstva (unosite redom, zavrsite s 0):\n");
	printf("1. Automobil\n");
	printf("2. Avion\n");
	printf("3. Vlak\n");
	printf("4. Autobus\n");
	travel_options[0] = '\0';
	do {
		printf("Unesite svoj odabir: ");
		scanf("%d", &travel_option_choice);
		if (travel_option_choice >= 1 && travel_option_choice <= 4) {
			if (strlen(travel_options) > 0) {
				strcat(travel_options, ", ");
			}
			switch (travel_option_choice) {
			case CAR:
				strcat(travel_options, "Automobil");
				break;
			case PLANE:
				strcat(travel_options, "Avion");
				break;
			case TRAIN:
				strcat(travel_options, "Vlak");
				break;
			case BUS:
				strcat(travel_options, "Autobus");
				break;
			}
		}
	} while (travel_option_choice != 0);

	printf("Odaberite sezonu:\n");
	printf("1. Ljeto\n");
	printf("2. Zima\n");
	printf("3. Jesen\n");
	printf("4. Proljece\n");
	printf("Unesite svoj odabir: ");
	scanf("%d", season);
}

void find_best_destinations(DESTINATION* dest_array, int dest_count, float budget, const char* travel_options, int season) {
	int found = 0;
	for (int i = 0; i < dest_count; i++) {
		if (match_criteria(dest_array[i], budget, travel_options, season)) {
			printf("\nID: %d\n", dest_array[i].id);
			printf("Naziv destinacije: %s\n", dest_array[i].location.name);
			printf("Drzava: %s\n", dest_array[i].location.country);
			printf("Kontinent: %d\n", dest_array[i].location.continent);
			printf("Udaljenost: %.2f\n", dest_array[i].location.distance);
			printf("Cijena: %.2f\n", dest_array[i].cost);
			printf("Prijevozna sredstva: %s\n", dest_array[i].travel_option);
			printf("Sezona: %s\n", dest_array[i].season);
			printf("Popularnost: %d\n", dest_array[i].popularity);
			printf("Upozorenja: %s\n", dest_array[i].warnings);
			printf("Atrakcije: %s\n", dest_array[i].attractions);
			found = 1;
		}
	}

	if (!found) {
		printf("Nema destinacija koje zadovoljavaju zadane kriterije.\n");
	}
}