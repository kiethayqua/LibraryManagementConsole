//
// Created by Kiet Nguyen Dev on 29/10/24.
//

#include "Book.h"
#include "Common.h"
#include "VariadicTable.h"
#include "Globals.h"

Book books[MAX_RECORDS];
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
        const Book book = books[i];
        vt.addRow(
            book.isbn,
            book.title,
            book.author,
            book.publisher,
            book.year,
            book.category,
            book.price,
            book.quantity
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
        books[book_records].isbn = isbn;
        books[book_records].title = book_title;
        books[book_records].author = author;
        books[book_records].publisher = publisher;
        books[book_records].year = publish_year;
        books[book_records].category = category;
        books[book_records].price = price;
        books[book_records].quantity = quantity;
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
            books[i].isbn = books[i + 1].isbn;
            books[i].title = books[i + 1].title;
            books[i].author = books[i + 1].author;
            books[i].publisher = books[i + 1].publisher;
            books[i].year = books[i + 1].year;
            books[i].category = books[i + 1].category;
            books[i].price = books[i + 1].price;
            books[i].quantity = books[i + 1].quantity;
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
        const int first_found_index = str_contains(books[i].title, book_name);
        if (first_found_index != -1) {
            const Book book = books[i];
            vt.addRow(
                book.isbn,
                book.title,
                book.author,
                book.publisher,
                book.year,
                book.category,
                book.price,
                book.quantity
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
        if (isbn == books[i].isbn) return i;
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
            books[index].isbn = input_string("Input ISBN: ", "");
            break;
        case 2:
            books[index].title = input_string("Input Title: ", "");
            break;
        case 3:
            books[index].author = input_string("Input Author: ", INPUT_TYPE_NAME);
            break;
        case 4:
            books[index].publisher = input_string("Input Publisher: ", INPUT_TYPE_NAME);
            break;
        case 5:
            books[index].year = input_string("Input Published Year: ", INPUT_TYPE_YEAR);
            break;
        case 6:
            books[index].category = input_string("Input Category: ", "");
            break;
        case 7:
            long _price;
            cout << "Please input Price: ";
            cin >> _price;
            cin.ignore();
            books[index].price = _price;
            break;
        case 8:
            int _quantity;
            cout << "Please input Quantity: ";
            cin >> _quantity;
            cin.ignore();
            books[index].quantity = _quantity;
            break;
        default:
            break;
    }
}
