#include "Main.h"
#include "Common.h"
#include "Reader.h"
#include "Book.h"
#include "BookLoanSlip.h"
#include "BookReturnSlip.h"
#include "Globals.h"

void root_main() {
    init_mock_data();
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
            break;
        case 0:
            cout << "Exit!\n";
            break;
        default:
            break;
    }
}


/**
 * Call this function to use the mock data
 */
void init_mock_data() {
    // Mock data for readers
    reader_records = 1;
    reader_name_records[0] = "Nguyen Van A";
    reader_id_records[0] = "123";
    reader_dob_records[0] = "01/01/2001";
    reader_gender_records[0] = 0;
    reader_email_records[0] = "nguyenvana@gmail.com";
    reader_address_records[0] = "District 7, HCM City";
    reader_created_date_records[0] = "01/11/2024";
    reader_expired_date_records[0] = "01/11/2026";

    // Mock data for books
    book_records = 3;
    book_isbn_records[0] = "123";
    book_title_records[0] = "Ngoi Khoc Tren Cay";
    book_author_records[0] = "Nguyen Nhat Anh";
    book_publisher_records[0] = "Kim Dong";
    book_year_records[0] = "Tinh Cam";
    book_category_records[0] = "2001";
    book_price_records[0] = 50000;
    book_quantity_records[0] = 10;
    book_isbn_records[1] = "234";
    book_title_records[1] = "Mat Biec";
    book_author_records[1] = "Nguyen Nhat Anh";
    book_publisher_records[1] = "Kim Dong";
    book_year_records[1] = "Tinh Cam";
    book_category_records[1] = "2001";
    book_price_records[1] = 80000;
    book_quantity_records[1] = 10;
    book_isbn_records[2] = "345";
    book_title_records[2] = "Ngay Xua Co Mot Chuyen Tinh";
    book_author_records[2] = "Nguyen Nhat Anh";
    book_publisher_records[2] = "Kim Dong";
    book_year_records[2] = "Tinh Cam";
    book_category_records[2] = "2001";
    book_price_records[2] = 30000;
    book_quantity_records[2] = 10;

    // Mock book loan
    book_loan_records = 1;
    book_loan_reader_id_records[0] = "123";
    book_loan_loan_date_records[0] = "01/11/2024";
    book_loan_estimated_return_date_records[0] = "08/11/2024";
    book_loan_isbn_list_records[0][0] = "123";
    book_loan_isbn_list_records[0][1] = "234";
    book_loan_isbn_list_records[0][2] = "345";
}

