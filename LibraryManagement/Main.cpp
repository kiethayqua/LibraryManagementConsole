#include "Main.h"
#include "Common.h"
#include "Reader.h"
#include "Book.h"

void root_main() {
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
            break;
        case 4:
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
