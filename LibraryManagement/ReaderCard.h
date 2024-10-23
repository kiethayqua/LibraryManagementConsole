#pragma once

#include <iostream>
#include "Common.h"
#include <string>
using namespace std;

string reader_name_records[MAX_RECORDS];
string reader_id_records[MAX_RECORDS];
string reader_dob_records[MAX_RECORDS];
// 0: male 1: female
int reader_gender_records[MAX_RECORDS];
string reader_email_records[MAX_RECORDS];
string reader_address_records[MAX_RECORDS];
string reader_card_created_date_records[MAX_RECORDS];
string reader_card_expired_date_records[MAX_RECORDS];

void get_reader_card_records();
void create_reader_card(string name, string id, string dob, int gender, string email, string address, string created_date, string expired_date);