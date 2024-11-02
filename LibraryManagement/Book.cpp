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
            update_book();
            system("pause");
            break;
        case 4:
            delete_book();
            system("pause");
            break;
        case 5:
            find_book_by_isbn();
            system("pause");
            break;
        case 6:
            find_books_by_name();
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

void update_book() {
    const string book_isbn = input_string("Please input ISBN: ", "");
    int book_index = find_book_by_isbn(book_isbn);
    if (book_index != -1) {
        clear_screen();
        show_update_book_menu();
        int option;
        do {
            option = select_menu_option(0, 8);
            execute_update_book(option, book_index);
        } while (option != 0);
    } else {
        cout << "The book is not exist!" << endl;
    }
}

void delete_book() {
    const string book_isbn = input_string("Please input ISBN: ", "");
    const int book_index = find_book_by_isbn(book_isbn);
    if (book_index != -1) {
        if (book_index == book_records - 1) {
            book_records--;
            return;
        }
        for (int i = book_index; i < book_records; i++) {
            book_isbn_records[i] = book_isbn_records[i + 1];
            book_title_records[i] = book_title_records[i + 1];
            book_author_records[i] = book_author_records[i + 1];
            book_publisher_records[i] = book_publisher_records[i + 1];
            book_year_records[i] = book_year_records[i + 1];
            book_category_records[i] = book_category_records[i + 1];
            book_price_records[i] = book_price_records[i + 1];
            book_quantity_records[i] = book_quantity_records[i + 1];
        }
        book_records--;
    } else {
        cout << "The book is not exist!" << endl;
    }
}

void find_book_by_isbn() {
    const string book_isbn = input_string("Please input ISBN: ", "");
    const int book_index = find_book_by_isbn(book_isbn);
    if (book_index != -1) {
        get_books(book_index, book_index + 1);
    } else {
        cout << "The book is not exist!" << endl;
    }
}

void find_books_by_name() {
    const string book_name = input_string("Please input name: ", "");
    bool have_book = false;
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

    for (int i = 0; i < book_records; i++) {
        const int first_found_index = str_contains(book_title_records[i], book_name);
        if (first_found_index != -1) {
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
            have_book = true;
        }
    }

    if (have_book) {
        vt.print(cout);
    } else {
        cout << "The reader is not exist!" << endl;
    }
}

int find_book_by_isbn(const string &isbn) {
    for (int i = 0; i < book_records; i++) {
        if (isbn == book_isbn_records[i]) return i;
    }
    return -1;
}

void show_update_book_menu() {
    cout << "=================UPDATE BOOK================\n";
    cout << "1. Update ISBN\n";
    cout << "2. Update Title\n";
    cout << "3. Update Author\n";
    cout << "4. Update Publisher\n";
    cout << "5. Update Published Year\n";
    cout << "6. Update Category\n";
    cout << "7. Update Price\n";
    cout << "8. Update Quantity\n";
    cout << "0. Exit!\n";
    cout << "============================================\n";
}

void execute_update_book(const int option, const int index) {
    switch (option) {
        case 1:
            book_isbn_records[index] = input_string("Input ISBN: ", "");
            break;
        case 2:
            book_title_records[index] = input_string("Input Title: ", "");
            break;
        case 3:
            book_author_records[index] = input_string("Input Author: ", INPUT_TYPE_NAME);
            break;
        case 4:
            book_publisher_records[index] = input_string("Input Publisher: ", INPUT_TYPE_NAME);
            break;
        case 5:
            book_year_records[index] = input_string("Input Published Year: ", INPUT_TYPE_YEAR);
            break;
        case 6:
            book_category_records[index] = input_string("Input Category: ", "");
            break;
        case 7:
            long _price;
            cout << "Please input Price: ";
            cin >> _price;
            cin.ignore();
            book_price_records[index] = _price;
            break;
        case 8:
            int _quantity;
            cout << "Please input Quantity: ";
            cin >> _quantity;
            cin.ignore();
            book_quantity_records[index] = _quantity;
            break;
        default:
            break;
    }
}
