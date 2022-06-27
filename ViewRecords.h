#pragma once
#ifndef VIEWRECORDS
#define VIEWRECORDS
#include <iostream> 
#include <iomanip>
#include <string>
#include "Utils.h"
#include "PurchaseRecords.h"
using namespace std;

//View Order Records (Iterate Orders and Display in Table Form in CLI)

void display_order_table(Purchase_Records* head) {
	Purchase_Records* current = head;

	double n = 1;
	int colWidth = 15;
	//table header 
	//set column width 
	cout << setfill('-') << setw(9 * colWidth) << "*" << endl;
	cout << setfill(' ') << fixed;
	//set column names
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

	// create table of data 
	while (current != NULL) {
		cout << setw(colWidth) <<
			current->get_order_id() << setw(colWidth) <<
			current->get_client_id() << setw(colWidth) <<
			current->get_client_name() << setw(colWidth) <<
			current->get_item_ids() << setw(colWidth) <<
			current->get_price() << setw(colWidth) <<
			current->get_date() << setw(colWidth) <<
			current->get_time() << setw(colWidth) <<
			current->get_type() << setw(colWidth) <<
			current->get_status() << setw(colWidth) << endl;

		current = current->next;
	}
	cout << setfill('-') << setw(9 * colWidth) << "*" << endl;
}


#endif
