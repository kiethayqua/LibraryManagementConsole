//
// Created by Kiet Nguyen Dev on 29/10/24.
//

#include "Book.h"
#include "Common.h"
#include "VariadicTable.h"

string book_isbn_records[MAX_RECORDS];
string book_title_records[MAX_RECORDS];
string book_author_records[MAX_RECORDS];
string book_publisher_records[MAX_RECORDS];
string book_year_records[MAX_RECORDS];
string book_category_records[MAX_RECORDS];
long book_price_records[MAX_RECORDS];
int book_quantity_records[MAX_RECORDS];

int book_records = 0;

void book_main() {
    int option;
    do {
        clear_screen();
        show_book_menu();
        option = select_menu_option(0, 6);
        execute_book(option);
    } while (option != EXIT);
}

void show_book_menu() {
    cout << "=================BOOK MANAGEMENT================\n";
    cout << "1. View All Books\n";
    cout << "2. Add A Book\n";
    cout << "3. Update A Book\n";
    cout << "4. Delete A Book\n";
    cout << "5. Find A Book By ISBN\n";
    cout << "6. Find Books By Name\n";
    cout << "0. Exit!\n";
    cout << "================================================\n";
}

void execute_book(const int option) {
    switch (option) {
        case 1:
            get_books(0, book_records);
            system("pause");
            break;
        case 2:
            create_book();
            system("pause");
            break;
        case 3:
            system("pause");
            break;
        case 4:
            system("pause");
            break;
        case 5:
            system("pause");
            break;
        case 6:
            system("pause");
            break;
        default:
            break;
    }
}

void get_books(int from, int to) {
    VariadicTable<string, string, string, string, string, string, long, int> vt({
            "ISBN",
            "Book Title",
            "Author",
            "Publisher",
            "Publish Year",
            "Category",
            "Price",
            "Quantity",
        }, 30);
    for (int i = from; i < to; i++) {
        vt.addRow(
            book_isbn_records[i],
            book_title_records[i],
            book_author_records[i],
            book_publisher_records[i],
            book_year_records[i],
            book_category_records[i],
            book_price_records[i],
            book_quantity_records[i]
        );
    }

    vt.print(cout);
}

void create_book() {
    string isbn = input_string("Please input ISBN: ", "");
    string book_title = input_string("Please input Title: ", "");
    string author = input_string("Please input Author: ", INPUT_TYPE_NAME);
    string publisher = input_string("Please input Publisher: ", "");
    string publish_year = input_string("Please input Publish year: ", INPUT_TYPE_YEAR);
    string category = input_string("Please input Category: ", "");
    long price;
    int quantity;
    cout << "Please input Price: ";
    cin >> price;
    cin.ignore();
    cout << "Please input Quantity: ";
    cin >> quantity;
    cin.ignore();

    if (book_records < MAX_RECORDS) {
        book_isbn_records[book_records] = isbn;
        book_title_records[book_records] = book_title;
        book_author_records[book_records] = author;
        book_publisher_records[book_records] = publisher;
        book_year_records[book_records] = publish_year;
        book_category_records[book_records] = category;
        book_price_records[book_records] = price;
        book_quantity_records[book_records] = quantity;
        book_records++;
    }
}

