//
// Created by Kiet Nguyen Dev on 3/11/24.
//
#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// Create a book loan slip record.
/// </summary>
void create_book_loan_slip();

/// <summary>
/// Check the reader is existed and the reader is not borrowing any books.
/// </summary>
/// <param name="reader_id">ID of the reader.</param>
/// <returns>true when the reader is existed and the reader is not borrowing any books, otherwise false</returns>
bool check_reader(const string& reader_id);

/// <summary>
/// Check the book is existed.
/// </summary>
/// <param name="book_isbn">ISBN of the book.</param>
/// <returns></returns>
bool check_book(const string& book_isbn);

/// <summary>
/// Get the book info and combine the book ISBN and the book title.
/// </summary>
/// <param name="book_isbn">ISBN of the book.</param>
/// <returns>The string is combined by the book ISBN and book title, Example: ABC123 - Thinking in C</returns>
string get_book_by_isbn(const string& book_isbn);
