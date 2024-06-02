#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"

//koncepti: STATIC!!(5.), extern(7.), makro i inline fcije(8.), const(12.), 
//staticka polja(13.),fseek itd (18.), (19.), upravljanje errorima (20.),  (23.), def jednostruko povezana lista

//biljeske: koristi const!, staticko polje, malloc != calloc, mozda implementirati 
//pravu rekurziju, mozda premjesti strukture u svoj header


int main() {

	//stvaranje datoteke
	FILE* fp_dest = fopen("destinations.bin", "ab+");
	FILE* fp_traveler = fopen("traveler.bin", "ab+");

	int condition = 1;
	while (condition) {
		main_menu();

	}

	return 0;
}