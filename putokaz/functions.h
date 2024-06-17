#pragma once

int create_file(const char* const file_name);
int main_menu(char* dest_file, char* traveler_file);
int get_id(const char* dest_file);
void add_destination(const char* dest_file);
void read_destinations(const char* dest_file);
void dest_print_question();
DESTINATION* read_dest_to_field(const char* const file_name, int* dest_count);
void dest_delete(int delete_id, char* dest_file);
int match_criteria(DESTINATION dest, float budget, const char* travel_options, int season);
void gather_user_preferences(float* budget, char* travel_options, int* season);
void find_best_destinations(DESTINATION* dest_array, int dest_count, float budget, const char* travel_options, int season);