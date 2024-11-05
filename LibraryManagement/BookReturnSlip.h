//
// Created by Kiet Nguyen Dev on 4/11/24.
//
#pragma once

#include <iostream>
using namespace std;

/// <summary>
/// Show the book return slip and remove the book loan record.
/// </summary>
void create_book_return_slip();

/// <summary>
/// Check the book loan slip is existed and return the index of the book loan slip record.
/// </summary>
/// <param name="reader_id">ID of the reader.</param>
/// <returns>Index of the book loan slip record.</returns>
int book_loan_slip_index(const string& reader_id);