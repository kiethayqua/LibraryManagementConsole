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
