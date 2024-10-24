#include "ReaderMenu.h"
#include "ReaderCard.h"
#include "Common.h"

void show_reader_menu() {
    cout << "=================READER MANAGEMENT================\n";
    cout << "1. View All Readers\n";
    cout << "2. Add Reader Card\n";
    cout << "3. Update Reader Card\n";
    cout << "4. Delete Reader Card\n";
    cout << "5. Find A Reader Card (Id or Name)\n";
    cout << "0. Exit!\n";
    cout << "==================================================\n";
}

int select_reader_option() {
    int n;
    cout << "\nPlease select a number: ";
    cin >> n;
    if (n >= 0 && n <= 5) return n;
    return select_reader_option();
}

void execute_reader_selection(int &option) {
    option = select_reader_option();
    switch (option) {
        case 1:
            get_reader_card_records();
            break;
        case 2:
            create_reader_card();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 0:
            system("cls");
            break;
    }
}
