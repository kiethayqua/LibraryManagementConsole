//
// Created by Kiet Nguyen Dev on 5/11/24.
//
#pragma once

#include <iostream>
using namespace std;

/// <summary>
/// Check is leap year.
/// </summary>
/// <param name="year"></param>
/// <returns></returns>
bool is_leap_year(int year);

/// <summary>
/// Get number of days in a month.
/// </summary>
/// <param name="month"></param>
/// <param name="year"></param>
/// <returns></returns>
int get_days_in_month(int month, int year);

/// <summary>
/// Calculates the total number of days from the date 01/01/0000.
/// </summary>
/// <param name="day">The day of the month (1-31).</param>
/// <param name="month">The month of the year (1-12).</param>
/// <param name="year">The year (non-negative integer).</param>
/// <returns>
/// The total number of days elapsed from the start of the calendar from (01 / 01 / 0000) to the given date.
/// </returns>
int date_to_days(int day, int month, int year);

/// <summary>
/// Parses a date string in the format "dd/mm/yyyy" and extracts the day, month, and year into respective integer values.
/// </summary>
/// <param name="date">The date string in the format "dd/mm/yyyy".</param>
/// <param name="day">Reference to an integer where the day will be stored.</param>
/// <param name="month">Reference to an integer where the month will be stored.</param>
/// <param name="year">Reference to an integer where the year will be stored.</param>
/// <returns>true if the date string is in the correct format and the values were successfully parsed, false otherwise.</returns>
bool parse_date(const string& date, int& day, int& month, int& year);

/// <summary>
/// Get number of days late of the reader when borrowing the books.
/// </summary>
/// <param name="start_date">The borrowed date in the format "dd/mm/yyyy".</param>
/// <param name="end_date">The returned date in the format "dd/mm/yyyy".</param>
/// <returns>Number of days late.</returns>
int get_days_late(const string& start_date, const string& end_date);

/// <summary>
/// Get current date in format "dd/mm/yyyy";
/// </summary>
/// <returns></returns>
string get_current_date_string();
