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
extern string reader_name_records[MAX_RECORDS];
extern string reader_id_records[MAX_RECORDS];
extern string reader_dob_records[MAX_RECORDS];
extern int reader_gender_records[MAX_RECORDS]; // Only 0 or 1 (0: Male, 1: Female)
extern string reader_email_records[MAX_RECORDS];
extern string reader_address_records[MAX_RECORDS];
extern string reader_created_date_records[MAX_RECORDS];
extern string reader_expired_date_records[MAX_RECORDS];
extern int reader_records;

/**
 * Global variables represent the books
 */
extern string book_isbn_records[MAX_RECORDS];
extern string book_title_records[MAX_RECORDS];
extern string book_author_records[MAX_RECORDS];
extern string book_publisher_records[MAX_RECORDS];
extern string book_year_records[MAX_RECORDS];
extern string book_category_records[MAX_RECORDS];
extern long book_price_records[MAX_RECORDS];
extern int book_quantity_records[MAX_RECORDS];
extern int book_records;

/**
 * Global variables represent the book loan slip
 */
extern string book_loan_reader_id_records[MAX_RECORDS];
extern string book_loan_loan_date_records[MAX_RECORDS];
extern string book_loan_estimated_return_date_records[MAX_RECORDS];
extern string book_loan_isbn_list_records[MAX_RECORDS][MAX_BOOKS_CAN_LOAN];
extern int book_loan_records;

#endif //GLOBALS_H
