#include "ReaderCard.h"
#include "VariadicTable.h"

int reader_card_records = 0;

void create_reader_card(string name, string id, string dob, int gender, string email, string address, string card_created_date, string card_expired_date)
{
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

void get_reader_card_records()
{
    VariadicTable<string, string, string, string> vt({ "Name", "Identification Card", "Date Of Birth", "Email" }, 30);

    for (int i = 0; i < reader_card_records; i++) {
        vt.addRow(reader_name_records[i], reader_id_records[i], reader_dob_records[i], reader_email_records[i]);
    }

    vt.print(cout);
}