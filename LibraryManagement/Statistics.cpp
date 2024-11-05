//
// Created by Kiet Nguyen Dev on 5/11/24.
//

#include "Statistics.h"

#include "DateUtil.h"
#include "Globals.h"
#include "VariadicTable.h"
#include "Reader.h"

void main_statistics() {
    cout << "=================STATISTICS================\n";
    cout << "Book statistics" << endl;
    books_statistics();
    cout << endl;
    cout << "Reader statistics" << endl;
    reader_statistics();
    cout << endl;
    cout << "Book loan statistics" << endl;
    book_loan_statistics();
    cout << endl;
    cout << "===========================================\n";
}

void books_statistics() {
    int number_of_books = 0, category_count = 0;
    string categories[MAX_RECORDS];
    int books_by_category[MAX_RECORDS];

    for (int i = 0; i < book_records; i++) {
        const int quantity = book_quantity_records[i];
        string category = book_category_records[i];
        number_of_books += quantity;
        const int cat_index = index_of_category(categories, category_count, category);
        if (cat_index != -1) {
            books_by_category[cat_index] += quantity;
        } else {
            categories[category_count] = category;
            books_by_category[category_count] = quantity;
            category_count++;
        }
    }

    cout << "Number of books in the library: " << to_string(number_of_books) << endl;

    for (int i = 0; i < category_count; i++) {
        cout << "Category " << categories[i] << " have: " << to_string(books_by_category[i]) << " books" << endl;
    }
}

void reader_statistics() {
    int number_of_readers = 0, number_of_males = 0, number_of_females = 0;
    for (int i = 0; i < reader_records; i++) {
        number_of_readers++;
        if (reader_gender_records[i] == 0) {
            number_of_males++;
        } else {
            number_of_females++;
        }
    }
    cout << "Number of readers in the library: " << to_string(number_of_readers) << endl;
    cout << "Male: " << to_string(number_of_males) << endl;
    cout << "Female: " << to_string(number_of_females) << endl;
}

void book_loan_statistics() {
    int number_loaning_books = 0;
    string current_date = get_current_date_string();
    int index_of_late[MAX_RECORDS];
    int late_count = 0;

    for (int i = 0; i < book_loan_records; i++) {
        for (int j = 0; j < MAX_BOOKS_CAN_LOAN; j++) {
            if (!book_loan_isbn_list_records[i][j].empty()) {
                number_loaning_books++;
            }
        }

        if (get_days_late(book_loan_loan_date_records[i], current_date) > 0) {
            index_of_late[late_count] = i;
            late_count++;
        }
    }

    cout << "Loaning books: " << to_string(number_loaning_books) << endl;

    VariadicTable<string, string, string, string, string, string, string, string> vt({
            "Identification Card",
            "Name",
            "Date Of Birth",
            "Gender",
            "Email",
            "Address",
            "Created Date",
            "Expired Date"
        }, 30);

    for (int i = 0; i < late_count; i++) {
        const int reader_index = find_reader_by_id(book_loan_reader_id_records[index_of_late[i]]);
        vt.addRow(
            reader_id_records[reader_index],
            reader_name_records[reader_index],
            reader_dob_records[reader_index],
            (reader_gender_records[reader_index] == 0) ? "Male" : "Female",
            reader_email_records[reader_index],
            reader_address_records[reader_index],
            reader_created_date_records[reader_index],
            reader_expired_date_records[reader_index]
        );
    }

    cout << "Late Readers: " << to_string(late_count) << endl;
    vt.print(cout);
}

int index_of_category(const string (&categories)[MAX_RECORDS], const int &category_count, const string &category) {
    for (int i = 0; i < category_count; i++) {
        if (categories[i] == category) return i;
    }

    return -1;
}
