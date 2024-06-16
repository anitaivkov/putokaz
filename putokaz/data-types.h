#pragma once

typedef struct location {
	char name[50];
	char country[50];
	char continent[50];
	float distance;
}LOCATION;

typedef struct destination {
	int id;
	LOCATION location;
	float cost;
	char travel_option[50];
	char season[50];
	int popularity;
	char warnings[256];
	char attractions[256];
}DESTINATION;

enum menu_items {
	ODABIR_DEST = 1,	//1. izbor
	DODAVANJE_DEST,		//2. izbor
	AZURIRANJE_DEST,	//3. izbor
	ISPIS_DEST,			//4. izbor
	BRISANJE_DEST,		//5. izbor
	IZLAZ_IZ_PROGRAMA	//6. izbor
};