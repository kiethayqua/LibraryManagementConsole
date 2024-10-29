#pragma once

#include <iostream>
using namespace std;

void reader_main();
void show_reader_menu();
void execute_reader(int);
void get_reader_records(int from, int to);
void create_reader();
void update_reader();
void delete_reader();
void find_reader_by_id();
int find_reader_by_id(const string& id);
void find_readers_by_name();
void show_update_reader_menu();
void execute_update_reader(int option, int reader_index);