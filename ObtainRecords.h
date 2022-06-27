/* Header File for Obtaining Purchase Records From Text File (PurchaseRecords.txt) */

#pragma once
#ifndef OBTAINRECORDS
#define OBTAINRECORDS

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Utils.h"
#include "PurchaseRecords.h"

using namespace std;

Purchase_Records* obtain_records(Purchase_Records* head) {
	fstream newfile;
	int line_no = 1;
	bool first = true;

	// Read Data
	newfile.open("PurchaseRecords.txt", ios::in);
	if (newfile.is_open()) {
		string line;

		Purchase_Records* current = head;
		while (getline(newfile, line)) {
			if (line_no > 1) {
				string* string_token_list = split_string(line, '%');

				Purchase_Records* pr = new Purchase_Records;
				pr->set_order_id(stoi(string_token_list[0]));
				pr->set_client_id(stoi(string_token_list[1]));
				pr->set_client_name(string_token_list[2]);
				pr->set_item_ids(string_token_list[3]);
				pr->set_price(stod(string_token_list[4]));
				pr->set_date(string_token_list[5]);
				pr->set_time(string_token_list[6]);
				pr->set_type(string_token_list[7]);
				pr->set_status(string_token_list[8]);
				pr->next = NULL;

				current->next = pr;
				current = pr;

				if (first) {
					head = current;
					first = false;
				}
			}
			line_no++;
		}
		newfile.close();
	}

	return head;
}

void debug_view_records(Purchase_Records* head) {
	Purchase_Records* current = head;

	while (current != NULL) {
		cout << "Order ID: " << current->get_order_id() << endl;
		cout << "Client ID: " << current->get_client_id() << endl;
		cout << "Client Name: " << current->get_client_name() << endl;
		cout << "Item IDs: " << current->get_item_ids() << endl;
		cout << "Price: " << current->get_price() << endl;
		cout << "Date: " << current->get_date() << endl;
		cout << "Time: " << current->get_time() << endl;
		cout << "Type: " << current->get_type() << endl;
		cout << "Status: " << current->get_status() << endl << endl;

		current = current->next;
	}
}

#endif
