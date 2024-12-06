#pragma warning(disable : 4996)

#include "Main.h"
#include "Common.h"
#include "Reader.h"
#include "Book.h"
#include "BookLoanSlip.h"
#include "BookReturnSlip.h"
#include "Globals.h"
#include "Statistics.h"

void root_main() {
    init_data();
    int option;
    do {
        clear_screen();
        show_main_menu();
        option = select_menu_option(0, 5);
        execute_main(option);
    } while (option != EXIT);
}

void show_main_menu() {
    cout << "=================LIBRARY MANAGEMENT================\n";
    cout << "1. Reader Management\n";
    cout << "2. Book Management\n";
    cout << "3. Book Loan\n";
    cout << "4. Book Return\n";
    cout << "5. Statistics\n";
    cout << "0. Exit!\n";
    cout << "===================================================\n";
}

void execute_main(const int option) {
    switch (option) {
        case 1:
            clear_screen();
            reader_main();
            break;
        case 2:
            clear_screen();
            book_main();
            break;
        case 3:
            create_book_loan_slip();
            system("pause");
            break;
        case 4:
            create_book_return_slip();
            system("pause");
            break;
        case 5:
            main_statistics();
            system("pause");
            break;
        case 0:
            save_readers();
            save_books();
            save_book_loans();
            cout << "Exit!\n";
            break;
        default:
            break;
    }
}


/**
 * Call this function to load the data from file
 */
void init_data() {
    load_readers();
    load_books();
    load_book_loans();
}

void load_readers() {
    FILE* fp;
    fopen_s(&fp, "READERS.txt", "rt");
    if (fp == NULL) {
        printf("File is not existed!");
        return;
    }

    const int MAX = 500;
    char line[MAX];
    while (fgets(line, MAX, fp) != NULL) {
        // Temporary C-style buffers
        char id[50], name[100], dob[15], email[100], address[200], created_date[15], expired_date[15];
        int gender;
        sscanf(line, "%[^|]|%[^|]|%[^|]|%d|%[^|]|%[^|]|%[^|]|%[^|]", id, name, dob, &gender, email, address, created_date, expired_date);
        readers[reader_records].id = id;
        readers[reader_records].name = name;
        readers[reader_records].dob = dob;
        readers[reader_records].gender = gender;
        readers[reader_records].email = email;
        readers[reader_records].address = address;
        readers[reader_records].created_date = created_date;
        readers[reader_records].expired_date = expired_date;
        reader_records++;
    }

    fclose(fp);
}

void save_readers() {
    FILE* fp;
    fopen_s(&fp, "READERS.txt", "w");
    if (fp == NULL) return;

    for (int i = 0; i < reader_records; i++) {
        const Reader reader = readers[i];
        fprintf(fp, "%s|%s|%s|%d|%s|%s|%s|%s", reader.id.c_str(), reader.name.c_str(), reader.dob.c_str(),
                reader.gender, reader.email.c_str(), reader.address.c_str(), reader.created_date.c_str(),
                reader.expired_date.c_str());
    }

    fclose(fp);
}

void load_books() {
    FILE* fp;
    fopen_s(&fp, "BOOKS.txt", "rt");
    if (fp == NULL) {
        printf("File is not existed!");
        return;
    }

    const int MAX = 500;
    char line[MAX];
    while (fgets(line, MAX, fp) != NULL) {
        // Temporary C-style buffers
        char isbn[100], title[100], author[100], publisher[100], year[20], category[100];
        long price;
        int quantity;
        sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%ld|%d", isbn, title, author, publisher, year, category, &price, &quantity);
        books[book_records].isbn = isbn;
        books[book_records].title = title;
        books[book_records].author = author;
        books[book_records].publisher = publisher;
        books[book_records].year = year;
        books[book_records].category = category;
        books[book_records].price = price;
        books[book_records].quantity = quantity;
        book_records++;
    }

    fclose(fp);
}

void save_books() {
    FILE* fp;
    fopen_s(&fp, "BOOKS.txt", "w");
    if (fp == NULL) return;

    for (int i = 0; i < book_records; i++) {
        const Book book = books[i];
        fprintf(fp, "%s|%s|%s|%s|%s|%s|%ld|%d\n", book.isbn.c_str(), book.title.c_str(), book.author.c_str(),
                book.publisher.c_str(), book.year.c_str(), book.category.c_str(), book.price, book.quantity);
    }

    fclose(fp);
}

void load_book_loans() {
    FILE* fp;
    fopen_s(&fp, "BOOK_LOANS.txt", "rt");
    if (fp == NULL) {
        printf("File is not existed!");
        return;
    }

    const int MAX = 500;
    char line[MAX];

    while (fgets(line, MAX, fp) != NULL) {
        BookLoan& loan = book_loans[book_loan_records];
        char reader_id[50], loan_date[20], estimated_return_date[20];
        char isbn[MAX_BOOKS_CAN_LOAN][20] = {{0}};

        int fields_read = sscanf(
            line, "%49[^|]|%19[^|]|%19[^|]|%19[^|]|%19[^|]|%19[^|]",
            reader_id, loan_date, estimated_return_date,
            isbn[0], isbn[1], isbn[2]
        );
        loan.reader_id = reader_id;
        loan.loan_date = loan_date;
        loan.estimated_return_date = estimated_return_date;

        for (int i = 3; i < fields_read; ++i) {
            if (i - 3 < MAX_BOOKS_CAN_LOAN) {
                loan.isbn_list[i - 3] = isbn[i - 3];
            }
        }

        ++book_loan_records;
    }

    fclose(fp);
}

void save_book_loans() {
    FILE* fp;
    fopen_s(&fp, "BOOK_LOANS.txt", "w");
    if (fp == NULL) return;

    for (int i = 0; i < book_loan_records; i++) {
        const BookLoan book_loan = book_loans[i];
        fprintf(fp, "%s|%s|%s",
                book_loan.reader_id.c_str(),
                book_loan.loan_date.c_str(),
                book_loan.estimated_return_date.c_str());
        for (const auto& isbn : book_loan.isbn_list) {
            if (!isbn.empty()) {
                fprintf(fp, "|%s", isbn.c_str());
            }
        }
    }

    fclose(fp);
}
