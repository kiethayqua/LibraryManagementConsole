#include "Reader.h"
#include "VariadicTable.h"
#include "Common.h"
#include "Globals.h"

Reader readers[MAX_RECORDS];
int reader_records = 0;

void reader_main() {
    int option;
    do {
        clear_screen();
        show_reader_menu();
        option = select_menu_option(0, 6);
        execute_reader(option);
    } while (option != EXIT);
}

void show_reader_menu() {
    cout << "=================READER MANAGEMENT================\n";
    cout << "1. View All Readers\n";
    cout << "2. Add A Reader\n";
    cout << "3. Update A Reader\n";
    cout << "4. Delete A Reader\n";
    cout << "5. Find A Reader By ID\n";
    cout << "6. Find Readers By Name\n";
    cout << "0. Exit!\n";
    cout << "==================================================\n";
}

void execute_reader(const int option) {
    switch (option) {
        case 1:
            get_reader_records(0, reader_records);
            system("pause");
            break;
        case 2:
            create_reader();
            system("pause");
            break;
        case 3:
            update_reader();
            system("pause");
            break;
        case 4:
            delete_reader();
            system("pause");
            break;
        case 5:
            find_reader_by_id();
            system("pause");
            break;
        case 6:
            find_readers_by_name();
            system("pause");
            break;
        default:
            break;
    }
}

void get_reader_records(const int from, const int to) {
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
    for (int i = from; i < to; i++) {
        const Reader reader = readers[i];
        vt.addRow(
            reader.id,
            reader.name,
            reader.dob,
            (reader.gender == 0) ? "Male" : "Female",
            reader.email,
            reader.address,
            reader.created_date,
            reader.expired_date
        );
    }

    vt.print(cout);
}

void create_reader() {
    string id = input_string("Please input ID: ", INPUT_TYPE_NUMBER);
    string name = input_string("Please input name: ", INPUT_TYPE_NAME);
    string dob = input_string("Please input date of birth: ", INPUT_TYPE_DATE);
    int gender = input_gender();
    string email = input_string("Please input email: ", INPUT_TYPE_EMAIL);
    string address = input_string("Please input address: ", "");
    string created_date = input_string("Please input created date: ", INPUT_TYPE_DATE);
    string expired_date = input_string("Please input expired date: ", INPUT_TYPE_DATE);

    if (reader_records < MAX_RECORDS) {
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
}

void update_reader() {
    const string reader_id = input_string("Please input ID: ", INPUT_TYPE_NUMBER);
    int reader_card_index = find_reader_by_id(reader_id);
    if (reader_card_index != -1) {
        clear_screen();
        show_update_reader_menu();
        int option;
        do {
            option = select_menu_option(0, 8);
            execute_update_reader(option, reader_card_index);
        } while (option != 0);
    } else {
        cout << "The reader is not exist!" << endl;
    }
}

void delete_reader() {
    const string reader_id = input_string("Please input ID: ", INPUT_TYPE_NUMBER);
    const int reader_card_index = find_reader_by_id(reader_id);
    if (reader_card_index != -1) {
        if (reader_card_index == reader_records - 1) {
            reader_records--;
            return;
        }
        for (int i = reader_card_index; i < reader_records; i++) {
            readers[i].name = readers[i + 1].name;
            readers[i].id = readers[i + 1].id;
            readers[i].dob = readers[i + 1].dob;
            readers[i].gender = readers[i + 1].gender;
            readers[i].email = readers[i + 1].email;
            readers[i].address = readers[i + 1].address;
            readers[i].created_date = readers[i + 1].created_date;
            readers[i].expired_date = readers[i + 1].expired_date;
        }
        reader_records--;
    } else {
        cout << "The reader is not exist!" << endl;
    }
}

void find_reader_by_id() {
    const string reader_id = input_string("Please input ID: ", INPUT_TYPE_NUMBER);
    const int reader_card_index = find_reader_by_id(reader_id);
    if (reader_card_index != -1) {
        get_reader_records(reader_card_index, reader_card_index + 1);
    } else {
        cout << "The reader is not exist!" << endl;
    }
}

void find_readers_by_name() {
    const string reader_name = input_string("Please input name: ", "");
    bool have_reader = false;
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

    for (int i = 0; i < reader_records; i++) {
        const int first_found_index = str_contains(readers[i].name, reader_name);
        if (first_found_index != -1) {
            const Reader reader = readers[i];
            vt.addRow(
                reader.id,
                reader.name,
                reader.dob,
                (reader.gender == 0) ? "Male" : "Female",
                reader.email,
                reader.address,
                reader.created_date,
                reader.expired_date
            );
            have_reader = true;
        }
    }

    if (have_reader) {
        vt.print(cout);
    } else {
        cout << "The reader is not exist!" << endl;
    }
}

int find_reader_by_id(const string &id) {
    for (int i = 0; i < reader_records; i++) {
        if (id == readers[i].id) return i;
    }
    return -1;
}

void show_update_reader_menu() {
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

void execute_update_reader(const int option, const int index) {
    switch (option) {
        case 1:
            readers[index].name = input_string("Input Name: ", INPUT_TYPE_NAME);
            break;
        case 2:
            readers[index].id = input_string("Input ID: ", INPUT_TYPE_NUMBER);
            break;
        case 3:
            readers[index].dob = input_string("Input Date: ", INPUT_TYPE_DATE);
            break;
        case 4:
            readers[index].gender = input_gender();
            break;
        case 5:
            readers[index].email = input_string("Input Email: ", INPUT_TYPE_EMAIL);
            break;
        case 6:
            readers[index].address = input_string("Input Address: ", "");
            break;
        case 7:
            readers[index].created_date = input_string("Input Date: ", INPUT_TYPE_DATE);
            break;
        case 8:
            readers[index].expired_date = input_string("Input Date: ", INPUT_TYPE_DATE);
            break;
        default:
            break;
    }
}
