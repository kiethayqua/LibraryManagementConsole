//
// Created by Kiet Nguyen Dev on 5/11/24.
//
#pragma once

#include <iostream>
using namespace std;

bool is_leap_year(int year);
int get_days_in_month(int month, int year);
int date_to_days(int day, int month, int year);
bool parse_date(const string& date, int& day, int& month, int& year);
int get_days_late(const string& start_date, const string& end_date);
