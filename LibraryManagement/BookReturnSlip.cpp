//
// Created by Kiet Nguyen Dev on 4/11/24.
//

#include "BookReturnSlip.h"
#include "Common.h"
#include "Globals.h"
#include "DateUtil.h"
#include "Book.h"
#include "VariadicTable.h"
#include <string>

void create_book_return_slip() {
    const string reader_id = input_string("Input the reader ID: ", INPUT_TYPE_NUMBER);
    int loan_index = book_loan_slip_index(reader_id);
    if (loan_index != -1) {
        string return_date = input_string("Input the return date: ", INPUT_TYPE_DATE);
        int days_late = get_days_late(book_loan_loan_date_records[loan_index], return_date);
        int number_of_books, book_count = 0;
        do {
            cout << "Input number of books need to return (Upto 3 books): ";
            cin >> number_of_books;
            cin.ignore();
        } while (number_of_books <= 0 || number_of_books > MAX_BOOKS_CAN_LOAN);

        string return_book_isbn_list[MAX_BOOKS_CAN_LOAN], lost_books[MAX_BOOKS_CAN_LOAN];
        int lost_book_count = 0;
        while (book_count < number_of_books) {
            string msg = "Input the book ISBN (" + to_string(book_count + 1) + "): ";
            string book_isbn = input_string(msg, "");
            return_book_isbn_list[book_count] = book_isbn;
            book_count++;
        }

        for (int i = 0; i < MAX_BOOKS_CAN_LOAN; i++) {
            bool is_exist = false;
            for (int j = 0; j < book_count; j++) {
                if (book_loan_isbn_list_records[loan_index][i] == return_book_isbn_list[j]) {
                    is_exist = true;
                    break;
                }
            }
            if (!is_exist) {
                lost_books[lost_book_count] = book_loan_isbn_list_records[loan_index][i];
                lost_book_count++;
            }
        }

        string note, book_list;
        long fees = 0;

        if (days_late > 0) {
            note += "- The reader late " + to_string(days_late) + " days.\n";
            fees += days_late * 5000;
        }
        if (lost_book_count > 0) {
            note += "- The reader lost " + to_string(lost_book_count) + " books.\n";
            for (int i = 0; i < lost_book_count; i++) {
                int book_index = find_book_by_isbn(lost_books[i]);
                if (book_index != -1) {
                    book_list += book_isbn_records[book_index] + " - " + book_title_records[book_index];
                    fees += book_price_records[book_index] * 2;
                }
            }
        }
        note += "Fees: " + to_string(fees) + ".\n";

        cout << "===============BOOK RETURN SLIP===============" << endl;
        VariadicTable<string, string, string, string> vt({
                                                             "Reader ID",
                                                             "Loan Date",
                                                             "Return Date",
                                                             "Return Books"
                                                         }, 30);
        vt.addRow(
            reader_id,
            book_loan_loan_date_records[loan_index],
            return_date,
            book_list
        );
        vt.print(cout);
        cout << endl;
        cout << note;

        if (loan_index == book_loan_records - 1) {
            book_loan_records--;
            return;
        }
        for (int i = loan_index; i < book_loan_records; i++) {
            book_loan_reader_id_records[i] = book_loan_reader_id_records[i + 1];
            book_loan_loan_date_records[i] = book_loan_loan_date_records[i + 1];
            book_loan_estimated_return_date_records[i] = book_loan_estimated_return_date_records[i + 1];
            for (int j = 0; j < MAX_BOOKS_CAN_LOAN; j++) {
                book_loan_isbn_list_records[i][j] = book_loan_isbn_list_records[i + 1][j];
            }
        }
        book_loan_records--;
    }
}

int book_loan_slip_index(const string &reader_id) {
    int result = -1;
    bool is_reader_exists = false;
    bool is_loan_exists = false;

    for (int i = 0; i < reader_records; i++) {
        if (reader_id_records[i] == reader_id) {
            is_reader_exists = true;
            break;
        }
    }

    if (!is_reader_exists) {
        cout << "Reader is not existed!" << endl;
        return result;
    }

    for (int i = 0; i < book_loan_records; i++) {
        if (book_loan_reader_id_records[i] == reader_id) {
            is_loan_exists = true;
            result = i;
            break;
        }
    }

    if (!is_loan_exists) {
        cout << "Book loan slip is not found!" << endl;
        return result;
    }

    return result;
}
