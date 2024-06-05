#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

extern int dest_id = 0;

//kreiranje datoteke
int create_file(const char* const file_name) {
	FILE* fp = fopen(file_name, "ab+");
	if (fp == NULL) {
		perror("Greska pri kreiranju datoteke: ");
		return -1;
	}

	fwrite(&dest_id, sizeof(int), 1, fp);

	fclose(fp);
	return 0;
}

//dodjela id-a destinaciji
int get_id(const char* dest_file) {
	FILE* fp = fopen(dest_file, "rb");
	if (fp == NULL) {
		return 1;
	}

	DESTINATION dest;

	while (fread(&dest, sizeof(DESTINATION), 1, fp)) {
		if (dest.id > dest_id) {
			dest_id = dest.id;
		}
	}
	
	fclose(fp);
	return dest_id;
}

//unos destinacije i upis u datoteku destinations.bin
void add_destination(const char* dest_file) {
	FILE* fp = fopen(dest_file, "ab");
	if (fp == NULL) {
		perror("Greska pri otvaranju datoteke za pisanje: ");
		return;
	}
	DESTINATION dest = { 0 };

	//dest.id = get_id(dest_file);
	fread(&dest_id, sizeof(int), 1, fp);

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

	fseek(fp, sizeof(DESTINATION) * dest_id, SEEK_CUR);
	fwrite(&dest, sizeof(DESTINATION), 1, fp);
	rewind(fp);
	dest_id++;
	fwrite(&dest_id, sizeof(int), 1, fp);

	fwrite(&dest, sizeof(DESTINATION), 1, fp);
	fclose(fp);
	return;
}

//citanje destinacija iz datoteke i ispis na ekran
void read_destinations(const char* dest_file) {
	FILE* fp = fopen(dest_file, "rb");
	if (fp == NULL) {
		perror("Greska pri otvaranju datoteke za citanje: ");
		exit(EXIT_FAILURE);
	}

	DESTINATION dest;
	fread(&dest_id, sizeof(int), 1, fp);

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
		//printf("Upozorenja: %s\n", dest.warnings);
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

void* read_dest_to_field(const char* const dest_file) {
	FILE* fp = fopen(dest_file, "rb");
	if (fp == NULL) {
		perror("Greska pri otvaranju datoteke za ucitavanje u polje: ");
		exit(EXIT_FAILURE);
	}
	fread(&dest_id, sizeof(int), 1, fp);

	DESTINATION* dest_field = (DESTINATION*)calloc(dest_id, sizeof(DESTINATION));

	if (dest_field == NULL) {
		perror("Greska u dinamicki alociranoj memoriji za destinacije: ");
		exit(EXIT_FAILURE);
	}

	fread(dest_field, sizeof(DESTINATION), dest_id, fp);

	fclose(fp);
	return dest_field;
}

//pitanja korisniku za odabir destinacije 
void dest_choice(const DESTINATION* const dest_field) {
	//provjeri zelim li stvarno toliko zastititi dest_field


}
