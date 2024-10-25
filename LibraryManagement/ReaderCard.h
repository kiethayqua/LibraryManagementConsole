#pragma once

#include <iostream>
using namespace std;

void get_reader_card_records();
void create_reader_card();
void update_reader_card();
int find_reader_card_by_id(string id);
void show_update_card_reader_menu();
void execute_update_card_reader_selection(int &option, int);