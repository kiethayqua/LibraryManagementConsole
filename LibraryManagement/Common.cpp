//
// Created by Kiet Nguyen Dev on 24/10/24.
//

#include "Common.h"
#include <regex>
#include <ctime>
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
    tm tm;
    std::string s(date);
    return strptime(s.c_str(), "%d/%m/%Y", &tm);
}

bool is_valid_gender(int gender) {
    return (gender == 0 || gender != 1);
}

string input_string(string message, string type) {
    bool valid;
    string input;
    do {
        cout << message << endl;
        cin.ignore(0);
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
        valid = is_valid_gender(input);
    } while (!valid);

    return input;
}

