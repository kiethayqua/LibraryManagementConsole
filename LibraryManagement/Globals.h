//
// Created by Kiet Nguyen Dev on 4/11/24.
//

#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
#include "Common.h"

using namespace std;

/**
 * Global variables represent the readers
 */
struct Reader {
    string id;
    string name;
    string dob;
    int gender;
    string email;
    string address;
    string created_date;
    string expired_date;
};
extern Reader readers[MAX_RECORDS];
extern int reader_records;

/**
 * Global variables represent the books
 */
struct Book {
    string isbn;
    string title;
    string author;
    string publisher;
    string year;
    string category;
    long price;
    int quantity;
};
extern Book books[MAX_RECORDS];
extern int book_records;

/**
 * Global variables represent the book loan slip
 */
struct BookLoan {
    string reader_id;
    string loan_date;
    string estimated_return_date;
    string isbn_list[MAX_BOOKS_CAN_LOAN];
};
extern BookLoan book_loans[MAX_RECORDS];
extern int book_loan_records;

#endif //GLOBALS_H
