/* Header File for Detailed Reports Linked List */

#pragma once
#ifndef DETAILEDREPORTSLINKEDLIST
#define DETAILEDREPORTSLINKEDLIST

#include <iostream>
#include "PurchaseRecordsLinkedList.h"
#include "DetailedReport.h"
#include "Utils.h"
using namespace std;

class Detailed_Reports_Linked_List {
	private:
		int size = 0;
		int id_generator = 0;
		Detailed_Report* head = NULL;
		Purchase_Records_Linked_List* ll;

		// Sorting Algorith (Merge Sort)
		// Reference: https://www.journaldev.com/61310/sort-linked-lists-cpp
		// *********************************************************************************************************************
		Detailed_Report* merge(Detailed_Report* left, Detailed_Report* right, int order) {
			if (left == NULL) {
				return right;
			}
			if (right == NULL) {
				return left;
			}

			Detailed_Report* counter = NULL;

			// Sort By Order ID
			// Ascending Order (1): Small -> Big
			// Descending Order (-1): Big -> Small
		 
			if ((left->get_order_id()) < (right->get_order_id())) {
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

		Detailed_Report* mid_point(Detailed_Report* node) {
			if (node == NULL || node->next == NULL) {
				return node;
			}

			Detailed_Report* fast = node;
			Detailed_Report* slow = node;

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

		Detailed_Report* merge_sort(Detailed_Report* node, int order) {
			if (node == NULL || node->next == NULL) {
				return node;
			}

			Detailed_Report* mid = mid_point(node);
			Detailed_Report* left = node;
			Detailed_Report* right = mid->next;

			mid->next = NULL;

			left = merge_sort(left, order);
			right = merge_sort(right, order);

			Detailed_Report* merged = merge(left, right, order);
			return merged;
		};
		// *********************************************************************************************************************

		bool check_duplicate_detailed_report(int order_id) {
			Detailed_Report* current = head;
			while (current != NULL) {
				if (current->get_order_id() == order_id) {
					return true;
				}
				current = current->next;
			}
			return false;
		};

		void overwrite_existing_detailed_report(Detailed_Report* new_report) {
			Detailed_Report* current = head;
			while (current != NULL) {
				if (current->get_order_id() == new_report->get_order_id()) {
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

		void update_detailed_report_list(int order_id) {
			Detailed_Report* dr = new Detailed_Report;
			size++;
			id_generator++;

			dr->set_report_id(id_generator);
			dr->set_order_id(order_id);
			dr->get_records(ll);
	
			if (head == nullptr) {
				head = dr;
				dr->next = NULL;
				dr->prev = NULL;
			}
			else {
				if (check_duplicate_detailed_report(order_id)) {
					overwrite_existing_detailed_report(dr);
					size--;
				}
				else {
					Detailed_Report* current = head;
					while (current->next != NULL) {
						current = current->next;
					}
					current->next = dr;
					dr->prev = current;
					dr->next = NULL;
				}
			}
		};

		void sort_detailed_reports(int order) {
			if (size < 1) {
				cout << "\nNo Detailed Reports created yet!!" << endl;
				return;
			}
			head = merge_sort(head, order);
			head->prev = NULL;

			cout << "\n [*] The Detailed Order Reports List has been sorted successfully!!" << endl << endl;
		};

		void view_detailed_report_list() {
			char option = 'x';
			Detailed_Report* current = head;

			if (size <= 0) {
				cout << "No Detailed Reports created yet!!" << endl;
				return;
			}

			while (option != 'e') {
				cout << "Current Report: " << endl;
				cout << "**************************" << endl;

				current->display_detailed_report();

				cout << endl;
				cout << "Please select what to do next (Next (n) / Previous (p) / Exit (e)): ";
				cin >> option;

				if (option == 'n') {
					if (current->next != NULL) {
						current = current->next;
					}
					else {
						cout << "\n\nThis is the last detailed report in the list!" << endl << endl;
					}
				}
				else if (option == 'p') {
					if (current->prev != NULL) {
						current = current->prev;
					}
					else {
						cout << "\n\nThis is the first detailed report in the list!" << endl << endl;
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
