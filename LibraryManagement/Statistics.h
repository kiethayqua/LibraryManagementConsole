//
// Created by Kiet Nguyen Dev on 5/11/24.
//
#pragma once

#include <iostream>
#include "Common.h"
using namespace std;

/// <summary>
/// Show all statistics.
/// </summary>
void main_statistics();

/// <summary>
/// Show the books statistics.
/// </summary>
void books_statistics();

/// <summary>
/// Show the reader statistics.
/// </summary>
void reader_statistics();

/// <summary>
/// Show the book loan statistics.
/// </summary>
void book_loan_statistics();

/// <summary>
/// Check the category is existed in list categories and return the index, otherwise return -1.
/// </summary>
int index_of_category(const string (&categories)[MAX_RECORDS], const int &category_count, const string& category);