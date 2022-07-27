/* Header File for the Summary Report Node Class */

#pragma once
#ifndef SUMMARYREPORT
#define SUMMARYREPORT

#include <iostream>
#include "PurchaseRecordsLinkedList.h"
using namespace std;

class Summary_Report {
private:
	Purchase_Records** records_arr;
	int index = 0;

	int report_id;
	int month;
	int year;
	string month_name[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	int completed_orders = 0;
	int uncompleted_orders = 0;
	int bulk_orders = 0;
	int single_orders = 0;
	double total_profit = 0;

public:
	Summary_Report* next;
	Summary_Report* prev;

	int get_report_id() { return report_id; };
	int get_month() { return month; };
	int get_year() { return year; };

	void set_report_id(int id) { this->report_id = id; };
	void set_month(int month) { this->month = month; };
	void set_year(int year) { this->year = year; };

	// Filter the Purchase Records based on month and year
	void get_sorted_purchase_records(Purchase_Records_Linked_List* pr) {
		records_arr = new Purchase_Records * [pr->get_size()];

		Purchase_Records* current = pr->get_head();
		while (current != NULL) {
			if (compare_equal_month(current->get_date(), month) && compare_equal_year(current->get_date(), year)) {
				records_arr[index] = current;
				index++;
			}
			current = current->next;
		}
	}

	// Get the different summary report data
	void get_report_data() {
		int count = 0;
		while (count < index) {
			if (records_arr[count]->get_status() == "Not Processed") {
				// Increment Unmanaged Orders Count
				uncompleted_orders++;
			}
			else if (records_arr[count]->get_status() == "Processed") {
				// Increment Managed Orders Count
				completed_orders++;
			}

			if (records_arr[count]->get_type() == "Bulky") {
				// Increment Bulky Orders Count
				bulk_orders++;
			}
			else if (records_arr[count]->get_type() == "Single") {
				// Increment Single Orders Count
				single_orders++;
			}

			// Calculate total profit earned
			total_profit += records_arr[count]->get_price();
			count++;
		}
	}

	// View Summary Report Details
	void display_summary_report() {
		double n = 1;
		int colWidth = 15;

		cout << "\n\t\t\t\t\t\t" << month_name[month - 1] << " " << year << " Summary Report for LiveOrder Sdn Bhd" << endl << endl;
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
		while (count < index) {
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

		cout << endl;
		cout << "\tTotal Completed / Managed Orders: " << completed_orders << endl;
		cout << "\tTotal Uncompleted / Unmanaged Orders: " << uncompleted_orders << endl;
		cout << "\tTotal Bulky Orders: " << bulk_orders << endl;
		cout << "\tTotal Single Orders: " << single_orders << endl;
		cout << "\tTotal Profit Earned: " << total_profit << endl;
	}
};

#endif
