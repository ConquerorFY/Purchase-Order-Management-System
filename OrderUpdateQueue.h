/* Header File for the Order Update Queue Class (Use Arrays) */

#pragma once
#ifndef ORDERUPDATEQUEUE
#define ORDERUPDATEQUEUE

#include <iostream>
#include <iomanip>
#include "PurchaseRecords.h"
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
			cout << "Here" << endl;
			if (tmp_b->get_type() == "Bulky") {
				queue[front] = tmp_b;
				front--;
			}
			tmp_b = tmp_b->next;
		}

		while (tmp_s != NULL)
		{
			if (tmp_s->get_type() == "Single") {
				queue[front] = tmp_s;
				front--;
			}

			tmp_s = tmp_s->next;
		}
	};

	void modifyOrder(Purchase_Records* pr) {
		double n = 1;
		int colWidth = 15;

		cout << "Update Order #" << pr->get_order_id() << endl;
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

		char input;
		cout << "Process Order? (Y / N): ";
		cin >> input;
		if (input == 'Y') {
			pr->set_status("Processed");
		}
		else {
			pr->set_status("Not Processed");
		}
	}

	void dequeue() {
		Purchase_Records* current;
		for (int i = rear; i > front; i--)
		{
			current = queue[i];
			modifyOrder(current);
			queue[i] = NULL;
			rear--;
		}
	}
};

Order_Update_Queue::Order_Update_Queue(int size, Purchase_Records* head) {
	this->size = size;
	this->linked_list = head;
	this->queue = new Purchase_Records * [size];		// create array with fixed size

	this->rear = this->size - 1;
	this->front = this->rear;
}

#endif
