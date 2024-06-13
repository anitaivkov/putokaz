#ifndef HEADER_H
#define HEADER_H

extern int dest_id;

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
//void* read_dest_to_field(const char* const dest_file);
DESTINATION* read_dest_to_field(const char* const file_name, int* dest_count);
void dest_delete(int delete_id, char* dest_file);
int match_criteria(DESTINATION dest, float budget, char travel_option, char season);
void find_best_destinations(DESTINATION* dest_array, int dest_count, float budget, char travel_option, char season);
void gather_user_preferences(float* budget, char* travel_option, char* season);

#endif // HEADER_H