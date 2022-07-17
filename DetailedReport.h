/* Header File for the Detailed Report Class */

#pragma once
#ifndef DETAILEDREPORT
#define DETAILEDREPORT

#include <iostream>
#include "PurchaseRecordsLinkedList.h"
using namespace std;

class Detailed_Report {
private:
	int report_id;
	int order_id;
	int i = 0;
	Purchase_Records** records;
public:
	Detailed_Report* next;
	Detailed_Report* prev;
	int get_report_id() { return this->report_id; };
	int get_order_id() { return this->order_id; };

	void set_report_id(int id) { this->report_id = id; };
	void set_order_id(int id) { this->order_id = id; };
	
	//get records based on order ID 
	void get_records(Purchase_Records_Linked_List* pr) {

		records = new Purchase_Records * [pr->get_size()];
		Purchase_Records* current = pr->get_head();
	
		while (current != NULL) {
			if (order_id == current->get_order_id()) {
				// cout << "order is obtained"<<endl;
				records[i] = current;
				i++;
			}
			current = current->next;
		}
		
	}

	//display_detailed_report 
	void display_detailed_report() {
		//Purchase_Records* current = records;

		double n = 1;
		int colWidth = 15;
		//table header 
		cout << "\n\t\t\t\t\t\t" << "Order #" << order_id << " Detailed Report for LiveOrder Sdn Bhd" << endl << endl;

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

		int count = 0;
		// create table of data 
		while (count < i) {
			cout << setw(colWidth) <<
				records[count]->get_order_id() << setw(colWidth) <<
				records[count]->get_client_id() << setw(colWidth) <<
				records[count]->get_client_name() << setw(colWidth) <<
				records[count]->get_item_ids() << setw(colWidth) <<
				records[count]->get_price() << setw(colWidth) <<
				records[count]->get_date() << setw(colWidth) <<
				records[count]->get_time() << setw(colWidth) <<
				records[count]->get_type() << setw(colWidth) <<
				records[count]->get_status() << setw(colWidth) << endl;

			count++;
		}
		cout << setfill('-') << setw(9 * colWidth) << "*" << endl;
	
	
	}
};

#endif
