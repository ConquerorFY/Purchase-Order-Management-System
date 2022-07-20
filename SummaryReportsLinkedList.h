/* Header File for Summary Reports Linked List */

#pragma once
#include "SummaryReport.h"
#include "PurchaseRecordsLinkedList.h"
#include "Utils.h"
#ifndef SUMMARYREPORTSLINKEDLIST
#define SUMMARYREPORTSLINKEDLIST

class Summary_Reports_Linked_List {
	private:
		int size = 0;
		int id_generator = 0;
		Summary_Report* head = NULL;
		Purchase_Records_Linked_List* ll;

		// Sorting Function for LinkedList (Using Merge Sort)
		// ***********************************************************************************
		Summary_Report* merge(Summary_Report* left, Summary_Report* right, int order) {
			if (left == NULL) {
				return right;
			}
			if (right == NULL) {
				return left;
			}

			Summary_Report* counter = NULL;

			// Sort By Month & Year
			// Ascending Order (1): Latest -> Oldest
			// Descending Order (-1): Oldest -> Latest
			if (compare_month_year(left->get_month(), left->get_year(), right->get_month(), right->get_year()) > 0) {
				if (order == 1) {
					counter = left;
					counter->next = merge(left->next, right, order);
					counter->next->prev = counter;
				}
				else if (order == -1) {
					counter = right;
					counter->next = merge(left, right->next, order);
					counter->next->prev = counter;
				}
			}
			else {
				if (order == 1) {
					counter = right;
					counter->next = merge(left, right->next, order);
					counter->next->prev = counter;
				}
				else if (order == -1) {
					counter = left;
					counter->next = merge(left->next, right, order);
					counter->next->prev = counter;
				}
			}
			
			return counter;
		};

		Summary_Report* mid_point(Summary_Report* node) {
			if (node == NULL || node->next == NULL) {
				return node;
			}

			Summary_Report* fast = node;
			Summary_Report* slow = node;

			while (fast != NULL && fast->next != NULL) {
				fast = fast->next;

				if (fast->next == NULL) {
					break;
				}

				fast = fast->next;
				slow = slow->next;
			}

			return slow;
		};

		Summary_Report* merge_sort(Summary_Report* node, int order) {
			if (node == NULL || node->next == NULL) {
				return node;
			}

			Summary_Report* mid = mid_point(node);
			Summary_Report* left = node;
			Summary_Report* right = mid->next;

			mid->next = NULL;

			left = merge_sort(left, order);
			right = merge_sort(right, order);

			Summary_Report* merged = merge(left, right, order);
			return merged;
		};
		// ***********************************************************************************

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

		void sort_summary_report_list(int order) {
			head = merge_sort(head, order);
			head->prev = NULL;
		};

		void view_summary_report_list() {
			char option = 'x';
			Summary_Report* current = head;

			if (size <= 0) {
				cout << "No summary reports created yet!!" << endl;
				return;
			}

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