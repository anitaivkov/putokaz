#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "header.h"

static int dest_id = 0;

int create_file(const char* const file_name) {
	FILE* fp = fopen(file_name, "ab+");
	if (fp == NULL) {
		perror("Greska pri kreiranju datoteke: ");
		return -1;
	}

	fclose(fp);
	return 0;
}


int get_id(const char* dest_file) {
	FILE* fp = fopen(dest_file, "rb");
	if (fp == NULL) {
		return 1;
	}

	DESTINATION dest;

	//int max_id = 0;
	while (fread(&dest, sizeof(DESTINATION), 1, fp)) {
		if (dest.id > dest_id) {
			dest_id = dest.id;
		}
	}
	fclose(fp);
	return dest_id + 1;
}

void add_destination(const char* dest_file) {
	DESTINATION dest;

	dest.id = get_id(dest_file);


	printf("Unesite naziv destinacije: ");
	scanf("%49s", dest.location.name);
	printf("Unesite drzavu: ");
	scanf("%49s", dest.location.country);
	printf("Unesite kontinent: ");
	scanf("%49s", dest.location.continent);
	printf("Unesite udaljenost: ");
	scanf("%f", &dest.location.distance);
	printf("Unesite cijenu: ");
	scanf("%f", &dest.cost);
	printf("Unesite prijevozna sredstva: ");
	scanf("%49s", dest.travel_option);
	printf("Unesite sezonu: ");
	scanf("%49s", dest.season);
	printf("Unesite popularnost: ");
	scanf("%d", &dest.popularity);
	printf("Unesite upozorenja: ");
	scanf(" %255[^\n]%*c", dest.warnings);  
	printf("Unesite atrakcije: ");
	scanf(" %255[^\n]%*c", dest.attractions);  

	FILE* fp = fopen(dest_file, "ab");
	if (fp == NULL) {
		perror("Greska pri otvaranju datoteke za pisanje: ");
		return;
	}

	fwrite(&dest, sizeof(DESTINATION), 1, fp);
	fclose(fp);
	return;
}

void read_destinations(const char* dest_file) {
	FILE* fp = fopen(dest_file, "rb");
	if (fp == NULL) {
		perror("Greska pri otvaranju datoteke za citanje: ");
		return;
	}
	rewind(fp);

	DESTINATION dest;


	while (fread(&dest, sizeof(DESTINATION), 1, fp) == 1); {
		printf("ID: %d\n", dest.id);
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


void dest_print_question() {
	char choice = 0;
	do {
		printf("\nZelite li prije odabira destinacije ispisati sve dostupne destinacije? (Y/N)\n");
		scanf(" %c", &choice);
		if (choice == 'Y' || choice == 'y') {
			read_destinations("destinations.bin");
		}
	} while (choice != 'Y', choice != 'y', choice != 'N', choice != 'n');
}



