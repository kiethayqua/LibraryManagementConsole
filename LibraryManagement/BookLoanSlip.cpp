//
// Created by Kiet Nguyen Dev on 3/11/24.
//
#include "BookLoanSlip.h"
#include "Common.h"
#include "Globals.h"
#include "VariadicTable.h"
#include <sstream>

BookLoan book_loans[MAX_RECORDS];
int book_loan_records = 0;

void create_book_loan_slip() {
    const string reader_id = input_string("Input the reader ID: ", INPUT_TYPE_NUMBER);
    const bool valid_reader = check_reader(reader_id);
    if (valid_reader) {
        const string loan_date = input_string("Input loan date: ", INPUT_TYPE_DATE);
        const string estimated_return_date = input_string("Input estimated return date: ", INPUT_TYPE_DATE);
        book_loans[book_loan_records].reader_id = reader_id;
        book_loans[book_loan_records].loan_date = loan_date;
        book_loans[book_loan_records].estimated_return_date = estimated_return_date;
        int number_of_books, book_count = 0;
        string book_list;
        do {
            cout << "Input number of books (Upto 3 books): ";
            cin >> number_of_books;
            cin.ignore();
        } while (number_of_books <= 0 || number_of_books > MAX_BOOKS_CAN_LOAN);

        while (book_count < number_of_books) {
            string msg = "Input the book ISBN (" + to_string(book_count + 1) + "): ";
            string book_isbn = input_string(msg, "");
            const bool valid_book = check_book(book_isbn);
            if (valid_book) {
                book_loans[book_loan_records].isbn_list[book_count] = book_isbn;
                book_list += get_book_by_isbn(book_isbn) + ", ";
                book_count++;
            }
        }
        book_loan_records++;
        cout << "===============BOOK LOAN SLIP===============" << endl;
        VariadicTable<string, string, string, string> vt({
                                                             "Reader ID",
                                                             "Loan Date",
                                                             "Estimated Return Date",
                                                             "Books"
                                                         }, 30);
        vt.addRow(
            reader_id,
            loan_date,
            estimated_return_date,
            book_list
        );
        vt.print(cout);
    }
}

bool check_reader(const string &reader_id) {
    bool is_reader_exists = false;
    bool is_loan_exists = false;

    for (int i = 0; i < reader_records; i++) {
        if (readers[i].id == reader_id) {
            is_reader_exists = true;
            break;
        }
    }

    if (!is_reader_exists) {
        cout << "Reader is not existed!" << endl;
        return false;
    }

    for (int i = 0; i < book_loan_records; i++) {
        if (book_loans[i].reader_id == reader_id) {
            is_loan_exists = true;
            break;
        }
    }

    if (is_loan_exists) {
        cout << "The reader has borrowed the books, please return the books before borrowing new books!" << endl;
        return false;
    }

    return true;
}

bool check_book(const string &book_isbn) {
    bool is_book_exists = false;

    for (int i = 0; i < book_records; i++) {
        if (books[i].isbn == book_isbn) {
            is_book_exists = true;
            break;
        }
    }

    if (!is_book_exists) {
        cout << "Book is not exist!" << endl;
        return false;
    }

    return true;
}

string get_book_by_isbn(const string &book_isbn) {
    string result;
    for (int i = 0; i < book_records; i++) {
        if (books[i].isbn == book_isbn) {
            result += books[i].isbn + " - " + books[i].title;
        }
    }

    return result;
}
