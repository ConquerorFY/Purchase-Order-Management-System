/* Header File for the Order Update Queue Class (Use Arrays) */

#pragma once
#ifndef ORDERUPDATEQUEUE
#define ORDERUPDATEQUEUE

#include <iostream>
#include <iomanip>
#include "PurchaseRecords.h"
#include "Utils.h"
using namespace std;


class Order_Update_Queue {
private:
	int size;
	int front = 0;
	int rear = 0;
	Purchase_Records* linked_list;
	Purchase_Records** queue;

public:
	Order_Update_Queue(int size, Purchase_Records* head);

	void enqueue() {
		Purchase_Records* tmp_b = linked_list;
		Purchase_Records* tmp_s = linked_list;

		while (tmp_b != NULL)
		{
			if (tmp_b->get_type() == "Bulky") {
				queue[rear] = tmp_b;
				rear++;
			}
			tmp_b = tmp_b->next;
		}

		while (tmp_s != NULL)
		{
			if (tmp_s->get_type() == "Single") {
				queue[rear] = tmp_s;
				rear++;
			}

			tmp_s = tmp_s->next;
		}
	};

	void modifyOrder(Purchase_Records* pr) {
		// Display Individual Order Record 
		double n = 1;
		int colWidth = 15;

		cout << "\n\nUpdate Order #" << pr->get_order_id() << endl;
		cout << setfill('-') << setw(2 * colWidth) << endl;
		cout << setfill(' ') << fixed;

		cout << setfill('-') << setw(9 * colWidth) << "*" << endl;
		cout << setfill(' ') << fixed;

		cout << setw(colWidth) << "OrderID" << setw(colWidth)
			<< "ClientID" << setw(colWidth) <<
			"Client Name" << setw(colWidth)
			<< "Item IDs" << setw(colWidth)
			<< "Price" << setw(colWidth)
			<< "Date" << setw(colWidth)
			<< "Time" << setw(colWidth)
			<< "Type" << setw(colWidth)
			<< "Status" << setw(colWidth)
			<< endl;

		cout << setfill('-') << setw(9 * colWidth) << "*" << endl;
		cout << setfill(' ') << fixed;

		cout << setw(colWidth) <<
			pr->get_order_id() << setw(colWidth) <<
			pr->get_client_id() << setw(colWidth) <<
			pr->get_client_name() << setw(colWidth) <<
			pr->get_item_ids() << setw(colWidth) <<
			setprecision(2) << pr->get_price() << setw(colWidth) <<
			pr->get_date() << setw(colWidth) <<
			pr->get_time() << setw(colWidth) <<
			pr->get_type() << setw(colWidth) <<
			pr->get_status() << setw(colWidth) << endl;

		cout << setfill('-') << setw(9 * colWidth) << "*" << endl << endl;

		// Inputs to update order record data
		int client_id;
		string client_name, item_ids, date, time;
		double price;
		char type, process;

		while (true) {
			// Update Client ID
			cout << "Change Client ID? (Enter 0 to skip): ";
			cin >> client_id;
			if (!cin.fail()) {
				if (client_id != 0)
				{
					cin.ignore();
					cin.clear();

					cout << "Change Client Name: ";
					getline(cin, client_name);
					pr->set_client_id(client_id);
					pr->set_client_name(client_name);
				}
				else {
					cin.ignore();
					cin.clear();
				}
			}
			else {
				cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}

			// Update Item IDs
			cout << "Change Item IDs? (eg, 001,001,001) (Enter '-' to skip): ";
			getline(cin, item_ids);
			if (!cin.fail()) {
				if (item_ids != "-" && validate_item_ids(item_ids)) {
					pr->set_item_ids(item_ids);
				}
				else if (item_ids != "-" && !validate_item_ids(item_ids)) {
					cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
					continue;
				}
			}
			else {
				cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}

			// Update Price
			cout << "Change Price? (Enter 0 to skip): ";
			cin >> price;
			if (!cin.fail()) {
				if (price != 0) {
					pr->set_price(price);
				}
			}
			else {
				cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}

			// Update Date
			cin.ignore();
			cin.clear();
			cout << "Change Date? (Format: YYYY-MM-DD) (Enter '-' to skip): ";
			getline(cin, date);
			if (!cin.fail()) {
				if (date != "-" && validate_date(date)) {
					pr->set_date(date);
				}
				else if (date != "-" && !validate_date(date)) {
					cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
					continue;
				}
			}
			else {
				cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}

			// Update Time
			cout << "Change Time? (Format: HH:MM am / HH:MM pm) (Enter '-' to skip): ";
			getline(cin, time);
			if (!cin.fail()) {
				if (time != "-" && validate_time(time)) {
					pr->set_time(time);
				}
				else if (time != "-" && !validate_time(time)) {
					cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
					continue;
				}
			}
			else {
				cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}

			// Update Type
			cout << "Change Order Type? (Single (s) / Bulky (b)) (Enter '-' to skip): ";
			cin >> type;
			if (!cin.fail()) {
				if (type != '-') {
					if (type == 's') {
						pr->set_type("Single");
					}
					else if (type == 'b') {
						pr->set_type("Bulky");
					}
					else {
						cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
						cin.clear();
						cin.ignore(10000, '\n');
						continue;
					}
				}
			}
			else {
				cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}

			// Update Order Status
			cout << "Confirm to Process Order? (Y / N): ";
			cin >> process;
			if (!cin.fail()) {
				if (process == 'Y') {
					pr->set_status("Processed");
				}
				else if (process == 'N') {
					pr->set_status("Not Processed");
				}
				else {
					cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
					continue;
				}
			}
			else {
				cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}

			break;
		}
	}

	void dequeue() {
		Purchase_Records* current;
		for (int i = front; i < rear; i++)
		{
			current = queue[i];
			modifyOrder(current);
			queue[i] = NULL;
			front++;
		}
	}
};

Order_Update_Queue::Order_Update_Queue(int size, Purchase_Records* head) {
	this->size = size;
	this->linked_list = head;
	this->queue = new Purchase_Records * [size];		// create array with fixed size
}

#endif
