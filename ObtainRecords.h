/* Header File for Obtaining Purchase Records From Text File (PurchaseRecords.txt) */

#pragma once
#ifndef OBTAINRECORDS
#define OBTAINRECORDS

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Utils.h"

using namespace std;

// Linked-List Node
struct Purchase_Records {
	int order_id;
	int client_id;
	string client_name;
	int item_id;
	string item_name;
	string date;
	string time;
	string status;
	Purchase_Records* next;
};

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
				pr->order_id = stoi(string_token_list[0]);
				pr->client_id = stoi(string_token_list[1]);
				pr->client_name = string_token_list[2];
				pr->item_id = stoi(string_token_list[3]);
				pr->item_name = string_token_list[4];
				pr->date = string_token_list[5];
				pr->time = string_token_list[6];
				pr->status = string_token_list[7];
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
		cout << "Order ID: " << current->order_id << endl;
		cout << "Client ID: " << current->client_id << endl;
		cout << "Client Name: " << current->client_name << endl;
		cout << "Item ID: " << current->item_id << endl;
		cout << "Item_Name: " << current->item_name << endl;
		cout << "Date: " << current->date << endl;
		cout << "Time: " << current->time << endl;
		cout << "Status: " << current->status << endl << endl;

		current = current->next;
	}
}

#endif
