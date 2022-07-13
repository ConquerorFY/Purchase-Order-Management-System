/* Header File for the Summary Report Class */

#pragma once
#ifndef SUMMARYREPORT
#define SUMMARYREPORT

#include <iostream>
#include "PurchaseRecordsLinkedList.h"
using namespace std;

class Summary_Report {
private:
	Purchase_Records* filtered_pr;
	Purchase_Records** records_arr;
	int index = 0;

	int report_id;
	int month;
	int year;

	int completed_orders;
	int uncompleted_orders;
	int bulk_orders;
	int single_orders;
	int total_profit;

public:
	Summary_Report* next;
	Summary_Report* prev;

	int get_report_id() { return report_id; };
	int get_month() { return month; };
	int get_year() { return year; };

	void set_report_id(int id) { this->report_id = id; };
	void set_month(int month) { this->month = month; };
	void set_year(int year) { this->year = year; };

	void get_sorted_purchase_records(Purchase_Records_Linked_List* pr) {
		filtered_pr = pr->sort_records(3, 1);
		records_arr = new Purchase_Records * [pr->get_size()];

		Purchase_Records* current = filtered_pr;
		while (current != NULL) {
			if (compare_equal_month(current->get_date(), month) && compare_equal_year(current->get_date(), year)) {
				records_arr[index] = current;
				index++;
			}
		}
	}

	// View Summary Report Details
	void display_summary_report() {
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

		int count = 0;
		// create table of data 
		while (count <= index) {
			cout << setw(colWidth) <<
				records_arr[count]->get_order_id() << setw(colWidth) <<
				records_arr[count]->get_client_id() << setw(colWidth) <<
				records_arr[count]->get_client_name() << setw(colWidth) <<
				records_arr[count]->get_item_ids() << setw(colWidth) <<
				setprecision(2) << records_arr[count]->get_price() << setw(colWidth) <<
				records_arr[count]->get_date() << setw(colWidth) <<
				records_arr[count]->get_time() << setw(colWidth) <<
				records_arr[count]->get_type() << setw(colWidth) <<
				records_arr[count]->get_status() << setw(colWidth) << endl;

			count++;
		}
		cout << setfill('-') << setw(9 * colWidth) << "*" << endl;
	}
};

#endif
