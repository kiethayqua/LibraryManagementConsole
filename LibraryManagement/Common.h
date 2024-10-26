#pragma once

#include <iostream>
using namespace std;

#define EXIT 0
#define MAX_RECORDS 100
#define INPUT_TYPE_NAME "INPUT_TYPE_NAME"
#define INPUT_TYPE_EMAIL "INPUT_TYPE_EMAIL"
#define INPUT_TYPE_NUMBER "INPUT_TYPE_NUMBER"
#define INPUT_TYPE_DATE "INPUT_TYPE_DATE"

bool is_valid_name(string name);
bool is_valid_number(string number);
bool is_valid_email(string email);
bool is_valid_date(string date);
bool is_valid_gender(int gender);
string input_string(string message, string type);
int input_gender();
int select_menu_option(int from, int to);
void clear_screen();