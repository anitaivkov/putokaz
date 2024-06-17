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
	CHOOSE_DEST = 1,	//1. izbor
	ADD_DEST,			//2. izbor
	UPDATE_DEST,		//3. izbor
	PRINT_DEST,			//4. izbor
	DELETE_DEST,		//5. izbor
	EXIT				//6. izbor
};

enum continent {
	EUROPE = 1,
	ASIA,
	AFRICA,
	NORTH_AMERICA,
	SOUTH_AMERICA,
	AUSTRALIA,
	ANTARCTICA,
	UNKNOWN_CONTINENT
};

enum travel_option {
	CAR = 1,
	PLANE,
	TRAIN,
	BUS,
	UNKNOWN_TRAVEL_OPTION
};

enum season {
	SPRING = 1,
	SUMMER,
	AUTUMN,
	WINTER,
	UNKNOWN_SEASON
};