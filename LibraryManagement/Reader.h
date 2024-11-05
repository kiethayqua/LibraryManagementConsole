#pragma once

#include <iostream>
using namespace std;

/// <summary>
/// Show reader menu and execute.
/// </summary>
void reader_main();

/// <summary>
/// Show reader menu.
/// </summary>
void show_reader_menu();

/// <summary>
/// Execute the selected reader option.
/// </summary>
/// <param name="option">Selected option.</param>
void execute_reader(int);

/// <summary>
/// Get a range of reader records.
/// </summary>
/// <param name="from">Index of the first element.</param>
/// <param name="to">Number of records.</param>
void get_reader_records(int from, int to);

/// <summary>
/// Create a reader.
/// </summary>
void create_reader();

/// <summary>
/// Update a reader.
/// </summary>
void update_reader();

/// <summary>
/// Delete a reader.
/// </summary>
void delete_reader();

/// <summary>
/// Find a reader by ID.
/// </summary>
void find_reader_by_id();

/// <summary>
/// Get the index of the reader record by ID.
/// </summary>
/// <param name="id">ID of the reader.</param>
/// <returns>Index of the reader record.</returns>
int find_reader_by_id(const string& id);

/// <summary>
/// Find readers by name.
/// </summary>
void find_readers_by_name();

/// <summary>
/// Show the menu to update the reader info.
/// </summary>
void show_update_reader_menu();

/// <summary>
/// Execute update reader menu.
/// </summary>///
void execute_update_reader(int option, int reader_index);