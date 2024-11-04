//
// Created by Kiet Nguyen Dev on 5/11/24.
//

#include "DateUtil.h"

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

bool parse_date(const string &dateStr, int &day, int &month, int &year) {
    if (dateStr.size() != 10 || dateStr[2] != '/' || dateStr[5] != '/') {
        return false; // Format must be exactly "dd/mm/yyyy"
    }
    day = stoi(dateStr.substr(0, 2));
    month = stoi(dateStr.substr(3, 2));
    year = stoi(dateStr.substr(6, 4));

    return true;
}

int get_days_late(const string &start_date, const string &end_date) {
    int startDay, startMonth, startYear;
    int endDay, endMonth, endYear;

    if (!parse_date(start_date, startDay, startMonth, startYear) ||
        !parse_date(end_date, endDay, endMonth, endYear)) {
        return -1;
    }

    const int startDays = date_to_days(startDay, startMonth, startYear);
    const int endDays = date_to_days(endDay, endMonth, endYear);

    return endDays - startDays;
}