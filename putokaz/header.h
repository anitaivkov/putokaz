#ifndef HEADER_H
#define HEADER_H

typedef struct location {
	char name;
	char country;
	char continent;
	float distance;
}LOCATION;

typedef struct destination {
	LOCATION location;
	float cost;
	char travel_option;
	char season;
	int popularity;
	char warnings;
}DESTINATION;



int main_menu();



#endif // HEADER_H