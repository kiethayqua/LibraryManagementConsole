//
// Created by Kiet Nguyen Dev on 29/10/24.
//
#pragma once

#include <iostream>
using namespace std;

/// <summary>
/// Show book menu and execute actions.
/// </summary>
void book_main();

/// <summary>
/// Show book menu.
/// </summary>
void show_book_menu();

/// <summary>
/// Execute book option.
/// </summary>
/// <param name="option">The selected option.</param>
void execute_book(int);

/// <summary>
/// Get a range of books.
/// </summary>
/// <param name="from">Index of the first element.</param>
/// <param name="to">Number of books.</param>
void get_books(int from, int to);

/// <summary>
/// Create a book record.
/// </summary>
void create_book();

/// <summary>
/// Update a book record.
/// </summary>
void update_book();

/// <summary>
/// Delete a book record.
/// </summary>
void delete_book();

/// <summary>
/// Find book by ISBN.
/// </summary>
void find_book_by_isbn();

/// <summary>
/// Get the index of the book by ISBN.
/// </summary>
/// <param name="id">ISBN of the book.</param>
/// <returns>Index of the book record.</returns>
int find_book_by_isbn(const string& id);

/// <summary>
/// Find books by the title of the book.
/// </summary>
void find_books_by_name();

/// <summary>
/// Show the update book menu.
/// </summary>
void show_update_book_menu();

/// <summary>
/// Execute the update book option.
/// </summary>
/// <param name="option">Index of the option.</param>
/// <param name="book_index">Index of the book need to update.</param>
void execute_update_book(int option, int book_index);
