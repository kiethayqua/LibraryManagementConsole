#pragma once

#include <iostream>
using namespace std;

#define EXIT 0
#define MAX_RECORDS 100
#define INPUT_TYPE_NAME "INPUT_TYPE_NAME"
#define INPUT_TYPE_EMAIL "INPUT_TYPE_EMAIL"
#define INPUT_TYPE_NUMBER "INPUT_TYPE_NUMBER"
#define INPUT_TYPE_DATE "INPUT_TYPE_DATE"
#define INPUT_TYPE_YEAR "INPUT_TYPE_YEAR"
#define MAX_BOOKS_CAN_LOAN 3

/// <summary>
/// Check the input name is valid.
/// </summary>
/// <param name="name"></param>
/// <returns></returns>
bool is_valid_name(string name);

/// <summary>
/// Check the input number is valid.
/// </summary>
/// <param name="number"></param>
/// <returns></returns>
bool is_valid_number(string number);

/// <summary>
/// Check the email is valid.
/// </summary>
/// <param name="email"></param>
/// <returns></returns>
bool is_valid_email(string email);

/// <summary>
/// Check the input date is valid, the valid format is "dd/mm/yyyy".
/// </summary>
/// <param name="date"></param>
/// <returns></returns>
bool is_valid_date(string date);

/// <summary>
/// Check the input gender is valid, range (0, 1) - 0: Male, 1: Female.
/// </summary>
/// <param name="gender"></param>
/// <returns></returns>
bool is_valid_gender(int gender);

/// <summary>
/// Check the input year is valid.
/// </summary>
/// <param name="year"></param>
/// <returns></returns>
bool is_valid_year(string year);

/// <summary>
/// Show input message and return the input value.
/// </summary>
/// <param name="message">The message need to show.</param>
/// <param name="type">Type of input to validate.</param>
/// <returns>The string of valid input.</returns>
string input_string(string message, string type);

/// <summary>
/// Execute input gender.
/// </summary>
/// <returns></returns>
int input_gender();

/// <summary>
/// Ensure the selected option is valid in a range.
/// </summary>
/// <param name="from">Index of the first option.</param>
/// <param name="to">Number of options.</param>
/// <returns>The valid selected option.</returns>
int select_menu_option(int from, int to);

/// <summary>
/// Clear screen by OS.
/// </summary>
void clear_screen();

/// <summary>
/// Find the first index of the string is in another string.
/// </summary>
/// <param name="str1">The long string.</param>
/// <param name="str2">The string need to check.</param>
/// <returns>First index of the substring in the long string, otherwise -1. Example: str1 is "Hello World!", str2 is "World", the returned index is 6.</returns>
int str_contains(string, string);