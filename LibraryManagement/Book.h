//
// Created by Kiet Nguyen Dev on 29/10/24.
//
#pragma once

#include <iostream>
using namespace std;

void book_main();
void show_book_menu();
void execute_book(int);
void get_books(int from, int to);
void create_book();
void update_book();
void delete_book();
void find_book_by_isbn();
int find_book_by_isbn(const string& id);
void find_books_by_name();
void show_update_book_menu();
void execute_update_book(int option, int book_index);
