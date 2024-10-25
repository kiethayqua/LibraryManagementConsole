#include "ReaderCard.h"
#include "VariadicTable.h"
#include "Common.h"

string reader_name_records[MAX_RECORDS];
string reader_id_records[MAX_RECORDS];
string reader_dob_records[MAX_RECORDS];
// 0: male 1: female
int reader_gender_records[MAX_RECORDS];
string reader_email_records[MAX_RECORDS];
string reader_address_records[MAX_RECORDS];
string reader_card_created_date_records[MAX_RECORDS];
string reader_card_expired_date_records[MAX_RECORDS];

int reader_card_records = 0;

void create_reader_card() {
    string name = input_string("Please input name: ", INPUT_TYPE_NAME);
    string id = input_string("Please input ID: ", INPUT_TYPE_NUMBER);
    string dob = input_string("Please input date of birth: ", INPUT_TYPE_DATE);
    int gender = input_gender();
    string email = input_string("Please input email: ", INPUT_TYPE_EMAIL);
    string address = input_string("Please input address: ", "");
    string card_created_date = input_string("Please input created date: ", INPUT_TYPE_DATE);
    string card_expired_date = input_string("Please input expired date: ", INPUT_TYPE_DATE);

    if (reader_card_records < MAX_RECORDS) {
        reader_name_records[reader_card_records] = name;
        reader_id_records[reader_card_records] = id;
        reader_dob_records[reader_card_records] = dob;
        reader_gender_records[reader_card_records] = gender;
        reader_email_records[reader_card_records] = email;
        reader_address_records[reader_card_records] = address;
        reader_card_created_date_records[reader_card_records] = card_created_date;
        reader_card_expired_date_records[reader_card_records] = card_expired_date;
        reader_card_records++;
    }
}

void get_reader_card_records() {
    VariadicTable<string, string, string, string, string, string, string, string> vt({
            "Name",
            "Identification Card",
            "Date Of Birth",
            "Gender",
            "Email",
            "Address",
            "Created Date",
            "Expired Date"
        }, 30);
    for (int i = 0; i < reader_card_records; i++) {
        vt.addRow(
            reader_name_records[i],
            reader_id_records[i],
            reader_dob_records[i],
            (reader_gender_records[i] == 0) ? "Male" : "Female",
            reader_email_records[i],
            reader_address_records[i],
            reader_card_created_date_records[i],
            reader_card_expired_date_records[i]
        );
    }

    vt.print(cout);
}

void update_reader_card() {
    string reader_id = input_string("Please input ID: ", INPUT_TYPE_NUMBER);
    int reader_card_index = find_reader_card_by_id(reader_id);
    cout << "KIET_DEBUG_READER_CARD_INDEX: " << reader_card_index << endl;
    if (reader_card_index != -1) {
        system("cls");
        show_update_card_reader_menu();
        int option;
        do {
            execute_update_card_reader_selection(option, reader_card_index);
        } while (option != 0);
    } else {
    }
}

int find_reader_card_by_id(string id) {
    for (int i = 0; i < reader_card_records; i++) {
        if (id == reader_id_records[i]) return i;
    }
    return -1;
}

void show_update_card_reader_menu() {
    cout << "=================UPDATE CARD READER================\n";
    cout << "1. Update Name\n";
    cout << "2. Update ID\n";
    cout << "3. Update Date Of Birth\n";
    cout << "4. Update Gender\n";
    cout << "5. Update Email\n";
    cout << "6. Update Address\n";
    cout << "7. Update Created Date\n";
    cout << "8. Update Expired Date\n";
    cout << "0. Exit!\n";
    cout << "===================================================\n";
}

void execute_update_card_reader_selection(int &option,int index) {
    option = select_menu_option(0, 8);
    switch (option) {
        case 1:
            reader_name_records[index] = input_string("Input Name: ", INPUT_TYPE_NAME);
        break;
        case 2:
            reader_id_records[index] = input_string("Input ID: ", INPUT_TYPE_NUMBER);
        break;
        case 3:
            reader_dob_records[index] = input_string("Input Date: ", INPUT_TYPE_DATE);
        break;
        case 4:
            reader_gender_records[index] = input_gender();
        break;
        case 5:
            reader_email_records[index] = input_string("Input Email: ", INPUT_TYPE_EMAIL);
        break;
        case 6:
            reader_address_records[index] = input_string("Input Address: ", "");
        break;
        case 7:
            reader_card_created_date_records[index] = input_string("Input Date: ", INPUT_TYPE_DATE);
        break;
        case 8:
            reader_card_expired_date_records[index] = input_string("Input Date: ", INPUT_TYPE_DATE);
        break;
        case 0:
            system("cls");
        break;
    }
}
