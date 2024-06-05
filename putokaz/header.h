#ifndef HEADER_H
#define HEADER_H

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

int create_file(const char* const file_name);
int main_menu(char* dest_file, char* traveler_file);
int get_id(const char* dest_file);
void add_destination(const char* dest_file);
void read_destinations(const char* dest_file);
void dest_print_question();
void* read_dest_to_field(const char* const dest_file);


#endif // HEADER_H