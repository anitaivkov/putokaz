#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "header.h"


//kreiranje datoteke
int create_file(const char* const file_name) {
	FILE* fp = fopen(file_name, "ab+");
	if (fp == NULL) {
		perror("Greska: ");
		return -1;
	}

	fclose(fp);
	return 0;
}

int add_to_file(const char* const file_name) {

}


void dest_print_question() {
	char choice = 0;
	do {
		printf("\nZelite li prije odabira destinacije ispisati sve dostupne destinacije? (Y/N)\n");
		scanf("%c", &choice);
		if (choice == 'Y' || choice == 'y') {
			//ispis cijele datoteke koja sadrzi destinacije za putovanje --> DOPUNITI
			printf("Ja sam potvrdni odgovor za ispis svih destinacija prije odabira neke destinacije.\n");
		}
	} while (choice != 'Y', choice != 'y', choice != 'N', choice != 'n');
}



