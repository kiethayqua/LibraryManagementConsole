//
// Created by Kiet Nguyen Dev on 5/11/24.
//

#include "DateUtil.h"
#include <ctime>
#include <iomanip>
#include <sstream>

bool is_leap_year(const int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int get_days_in_month(const int month, const int year) {
    switch (month) {
        case 2: return is_leap_year(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11: return 30;
        default: return 31;
    }
}

int date_to_days(const int day, const int month, const int year) {
    int days = day;

    for (int y = 0; y < year; ++y) {
        days += is_leap_year(y) ? 366 : 365;
    }

    for (int m = 1; m < month; ++m) {
        days += get_days_in_month(m, year);
    }

    return days;
}

bool parse_date(const string &date, int &day, int &month, int &year) {
    if (date.size() != 10 || date[2] != '/' || date[5] != '/') {
        return false; // Format must be exactly "dd/mm/yyyy"
    }
    day = stoi(date.substr(0, 2));
    month = stoi(date.substr(3, 2));
    year = stoi(date.substr(6, 4));

    return true;
}

int get_days_late(const string &start_date, const string &end_date) {
    int start_day, start_month, start_year;
    int end_day, end_month, end_year;

    if (!parse_date(start_date, start_day, start_month, start_year) ||
        !parse_date(end_date, end_day, end_month, end_year)) {
        return -1;
    }

    const int start_days = date_to_days(start_day, start_month, start_year);
    const int end_days = date_to_days(end_day, end_month, end_year);

    return end_days - start_days - 7;
}

string get_current_date_string() {
    struct tm newtime;
    const time_t now = time(0);
    localtime_s(&newtime, &now);
    ostringstream date_stream;
    date_stream << setw(2) << setfill('0') << newtime.tm_mday << "/"
            << setw(2) << setfill('0') << (newtime.tm_mon + 1) << "/"
            << (1900 + newtime.tm_year);
    return date_stream.str();
}
