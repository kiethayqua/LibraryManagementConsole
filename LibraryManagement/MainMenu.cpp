#include "MainMenu.h"
#include "ReaderMenu.h"

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

int select_main_option() {
    int n;
    cout << "\nPlease select a number: ";
    cin >> n;
    if (n >= 0 && n <= 5) return n;
    else return select_main_option();
}

void execute_main_selection() {
    int option = select_main_option();
    switch (option) {
    case 1:
        system("cls");
        show_reader_menu();
        int reader_option;
        do {
            execute_reader_selection(reader_option);
        } while (reader_option != 0);
        show_main_menu();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 0:
        cout << "Exit!\n";
        exit(1);
        break;
    }
}