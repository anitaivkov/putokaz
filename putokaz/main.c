#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "data-types.h"
#include "functions.h"

int dest_id = 0;

int main() {

	//stvaranje datoteke
	char dest_file[] = "destinations.bin";
	char traveler_file[] = "traveler.bin";

	create_file(dest_file);

	int condition = 1;
	while (condition) {
		condition = main_menu(dest_file, traveler_file);
	}

	return 0;
}