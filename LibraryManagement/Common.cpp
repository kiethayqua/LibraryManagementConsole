//
// Created by Kiet Nguyen Dev on 24/10/24.
//

#include "Common.h"
#include <regex>
#include <string>
using namespace std;

bool is_valid_name(string name) {
    regex name_pattern("^[a-zA-Z]{4,}(?: [a-zA-Z]+){0,2}$");
    return regex_match(name, name_pattern);
}

bool is_valid_number(string number) {
    regex number_pattern("^[0-9]+$");
    return regex_match(number, number_pattern);
}

bool is_valid_email(string email) {
    regex email_pattern("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
    return regex_match(email, email_pattern);
}

bool is_valid_date(string date) {
    regex date_parttern("^\\d{2}-\\d{2}-\\d{4}$");
    return regex_match(date, date_parttern);
}

bool is_valid_gender(int gender) {
    return (gender == 0 || gender == 1);
}

string input_string(string message, string type) {
    bool valid;
    string input;
    do {
        cout << message;
        getline(cin, input);
        if (type == INPUT_TYPE_NAME) {
            valid = is_valid_name(input);
        } else if (type == INPUT_TYPE_NUMBER) {
            valid = is_valid_number(input);
        } else if (type == INPUT_TYPE_EMAIL) {
            valid = is_valid_email(input);
        } else if (type == INPUT_TYPE_DATE) {
            valid = is_valid_date(input);
        } else {
            valid = true;
        }
    } while (!valid);
    return input;
}

int input_gender() {
    bool valid;
    int input;
    do {
        cout << "Please input the gender (0-Male 1-Female): \n";
        cin >> input;
        cin.ignore();
        valid = is_valid_gender(input);
    } while (!valid);

    return input;
}

int select_menu_option(int from, int to) {
    int n;
    cout << "\nPlease select a number: ";
    cin >> n;
    cin.ignore();
    if (n >= from && n <= to) return n;
    return select_menu_option(from, to);
}

void clear_screen() {
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}

int str_contains(string str1, string str2) {
    char first_char_of_str2 = str2.at(0);
    int size_of_str2 = str2.size();
    
    for (int i = 0; i < str1.size(); i++) {
        if (str1.at(i) == first_char_of_str2 && i + size_of_str2 - 1 < str1.size()) {
            int k = 0;
            for (int j = i; j < i + size_of_str2; j++) {
                if (str1.at(j) == str2.at(k)) {
                    k++;
                }
                else break;
            }
            if (k == size_of_str2) return i;
        }
    }

    return -1;
}
