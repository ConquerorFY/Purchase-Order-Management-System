/* Header File for Summary Reports Linked List */

#pragma once
#include "SummaryReport.h"
#include "PurchaseRecordsLinkedList.h"
#ifndef SUMMARYREPORTSLINKEDLIST
#define SUMMARYREPORTSLINKEDLIST

class Summary_Reports_Linked_List {
	private:
		int size = 0;
		int id_generator = 0;
		Summary_Report* head = NULL;
		Purchase_Records_Linked_List* ll;

		Summary_Report* merge(Summary_Report* left, Summary_Report* right, int order) {};
		Summary_Report* mid_point() {};
		Summary_Report* merge_sort(int order) {};
		bool check_duplicate_summary_report(int month, int year) {
			Summary_Report* current = head;
			while (current != NULL) {
				if (current->get_month() == month && current->get_year() == year) {
					return true;
				}
				current = current->next;
			}
			return false;
		};
		void overwrite_existing_summary_report(Summary_Report* new_report) {
			Summary_Report* current = head;
			while (current != NULL) {
				if (current->get_month() == new_report->get_month() && current->get_year() == new_report->get_year()) {
					break;
				}
				current = current->next;
			}

			if (current->prev == NULL) {
				// head of list
				new_report->prev = NULL;
				new_report->next = current->next;
				current->next->prev = new_report;
				head = new_report;
				current->next = NULL;
				delete current;
			}
			else if (current->next == NULL) {
				// tail of list
				new_report->prev = current->prev;
				current->prev->next = new_report;
				new_report->next = NULL;
				current->prev = NULL;
				delete current;
			}
			else {
				new_report->prev = current->prev;
				current->prev->next = new_report;
				new_report->next = current->next;
				current->next->prev = new_report;
				current->prev = NULL;
				current->next = NULL;
				delete current;
			}
		}
	public:
		void set_purchase_records_linked_list(Purchase_Records_Linked_List* ll) {
			this->ll = ll;
		}
		void update_summary_report_list(int month, int year) {
			Summary_Report* sr = new Summary_Report;
			size++;
			id_generator++;

			sr->set_report_id(id_generator);
			sr->set_month(month);
			sr->set_year(year);

			sr->get_sorted_purchase_records(ll);
			sr->get_report_data();

			if (head == NULL) {
				head = sr;
				sr->next = NULL;
				sr->prev = NULL;
			}
			else {
				if (check_duplicate_summary_report(month, year)) {
					overwrite_existing_summary_report(sr);
					size--;
				}
				else {
					Summary_Report* current = head;
					while (current->next != NULL) {
						current = current->next;
					}
					current->next = sr;
					sr->prev = current;
					sr->next = NULL;
				}
			}
		};
		void sort_summary_report_list(int order) {};
		void view_summary_report_list() {
			char option = 'x';
			Summary_Report* current = head;

			while (option != 'e') {
				cout << "Current Report: " << endl;
				cout << "**************************" << endl;

				current->display_summary_report();

				cout << endl;
				cout << "Please select what to do next (Next (n) / Previoud (p) / Exit (e)): ";
				cin >> option;

				if (option == 'n') {
					if (current->next != NULL) {
						current = current->next;
					}
					else {
						cout << "\n\nThis is the last summary report in the list!" << endl << endl;
					}
				}
				else if (option == 'p') {
					if (current->prev != NULL) {
						current = current->prev;
					}
					else {
						cout << "\n\nThis is the first summary report in the list!" << endl << endl;
					}
				}
				else if (option != 'e') {
					cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
			
		};
};

#endif