//
// Created by Kiet Nguyen Dev on 5/11/24.
//
#pragma once

#include <iostream>
#include "Common.h"
using namespace std;

void main_statistics();
void books_statistics();
void reader_statistics();
void book_loan_statistics();
int index_of_category(const string (&categories)[MAX_RECORDS], const int &category_count, const string& category);