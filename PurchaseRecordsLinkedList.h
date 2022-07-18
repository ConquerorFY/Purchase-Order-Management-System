/* Header File for the Purchase_Records Linked List Class */

#pragma once
#ifndef PURCHASERECORDSLINKEDLIST
#define PURCHASERECORDSLINKEDLIST

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include "PurchaseRecords.h"
#include "OrderUpdateQueue.h"
#include "Utils.h"
using namespace std;

// Linked List Class for Purchase Records
class Purchase_Records_Linked_List {
	private:
		int size;
		// Purchase_Records* head = NULL;
		Purchase_Records* head = new Purchase_Records;

		Purchase_Records* merge(Purchase_Records* left, Purchase_Records* right, int criteria, int order);
		Purchase_Records* mid_point(Purchase_Records* node);
		Purchase_Records* merge_sort(Purchase_Records* node, int criteria, int order);
		Purchase_Records* clone_list();

	public:
		int get_size();
		Purchase_Records* get_head();
		void obtain_records();
		void update_records();
		void display_order_table();
		void display_order_table(Purchase_Records* new_head);
		Purchase_Records* sort_records(int option, int order);
		Purchase_Records* search_records(int criteria, int parameter);
		void delete_clone_list(Purchase_Records* clone_head);
};

int Purchase_Records_Linked_List::get_size() {
	return size;
}

Purchase_Records* Purchase_Records_Linked_List::get_head() {
	return head;
}

//  Obtaining Purchase Records From Text File (PurchaseRecords.txt)
void Purchase_Records_Linked_List::obtain_records() {
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
				pr->set_order_id(stoi(string_token_list[0]));
				pr->set_client_id(stoi(string_token_list[1]));
				pr->set_client_name(string_token_list[2]);
				pr->set_item_ids(string_token_list[3]);
				pr->set_price(stod(string_token_list[4]));
				pr->set_date(string_token_list[5]);
				pr->set_time(string_token_list[6]);
				pr->set_type(string_token_list[7]);
				pr->set_status(string_token_list[8]);
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
		size = line_no - 2;
		newfile.close();
	}
}

void Purchase_Records_Linked_List::update_records() {
	Order_Update_Queue q(get_size(), head);
	q.enqueue();
	q.dequeue();
}

// View Order Records (Iterate Orders and Display in Table Form in CLI) (For Original Lists)
void Purchase_Records_Linked_List::display_order_table() {
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
			setprecision(2) << current->get_price() << setw(colWidth) <<
			current->get_date() << setw(colWidth) <<
			current->get_time() << setw(colWidth) <<
			current->get_type() << setw(colWidth) <<
			current->get_status() << setw(colWidth) << endl;

		current = current->next;
	}
	cout << setfill('-') << setw(9 * colWidth) << "*" << endl;
}

// View Order Records (Iterate Orders and Display in Table Form in CLI) (For Cloned Lists)
void Purchase_Records_Linked_List::display_order_table(Purchase_Records* new_head) {
	Purchase_Records* current = new_head;

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


// Sorting Function for LinkedList (Using Merge Sort)
// ***********************************************************************************

Purchase_Records* Purchase_Records_Linked_List::merge(Purchase_Records* left, Purchase_Records* right, int criteria, int order) {
	if (left == NULL) {
		return right;
	}
	if (right == NULL) {
		return left;
	}

	Purchase_Records* counter = NULL;

	// Option 0: Order ID
	// Ascending Order (1): Small -> Big
	// Descending Order (-1): Big -> Small
	if (criteria == 0) {
		if (left->get_order_id() < right->get_order_id()) {
			if (order == 1) {
				counter = left;
				counter->next = merge(left->next, right, criteria, order);
			}
			else if (order == -1) {
				counter = right;
				counter->next = merge(left, right->next, criteria, order);
			}
		}
		else {
			if (order == 1) {
				counter = right;
				counter->next = merge(left, right->next, criteria, order);
			}
			else if (order == -1) {
				counter = left;
				counter->next = merge(left->next, right, criteria, order);
			}
		}
	}

	// Option 1: Client ID
	// Ascending Order (1): Small -> Big
	// Descending Order (-1): Big -> Small
	else if (criteria == 1) {
		if (left->get_client_id() < right->get_client_id()) {
			if (order == 1) {
				counter = left;
				counter->next = merge(left->next, right, criteria, order);
			}
			else if (order == -1) {
				counter = right;
				counter->next = merge(left, right->next, criteria, order);
			}
		}
		else {
			if (order == 1) {
				counter = right;
				counter->next = merge(left, right->next, criteria, order);
			}
			else if (order == -1) {
				counter = left;
				counter->next = merge(left->next, right, criteria, order);
			}
		}
	}

	// Option 2: Price
	// Ascending Order (1): Small -> Big
	// Descending Order (-1): Big -> Small
	else if (criteria == 2) {
		if (left->get_price() < right->get_price()) {
			if (order == 1) {
				counter = left;
				counter->next = merge(left->next, right, criteria, order);
			}
			else if (order == -1) {
				counter = right;
				counter->next = merge(left, right->next, criteria, order);
			}
		}
		else {
			if (order == 1) {
				counter = right;
				counter->next = merge(left, right->next, criteria, order);
			}
			else if (order == -1) {
				counter = left;
				counter->next = merge(left->next, right, criteria, order);
			}
		}
	}

	// Option 3: Date
	// Ascending Order (1): Latest -> Oldest
	// Descending Order (-1): Oldest -> Latest
	else if (criteria == 3) {
		if (compare_date(left->get_date(), right->get_date()) > 0) {
			if (order == 1) {
				counter = left;
				counter->next = merge(left->next, right, criteria, order);
			}
			else if (order == -1) {
				counter = right;
				counter->next = merge(left, right->next, criteria, order);
			}
		}
		else {
			if (order == 1) {
				counter = right;
				counter->next = merge(left, right->next, criteria, order);
			}
			else if (order == -1) {
				counter = left;
				counter->next = merge(left->next, right, criteria, order);
			}
		}
	}

	// Option 4: Time
	// Ascending Order (1): Latest -> Oldest
	// Descending Order (-1): Oldest -> Latest
	else if (criteria == 4) {
		if (compare_time(left->get_time(), right->get_time()) > 0) {
			if (order == 1) {
				counter = left;
				counter->next = merge(left->next, right, criteria, order);
			}
			else if (order == -1) {
				counter = right;
				counter->next = merge(left, right->next, criteria, order);
			}
		}
		else {
			if (order == 1) {
				counter = right;
				counter->next = merge(left, right->next, criteria, order);
			}
			else if (order == -1) {
				counter = left;
				counter->next = merge(left->next, right, criteria, order);
			}
		}
	}

	// Option 5: Type (Priority)
	// Ascending Order (1): Bulky -> Single
	// Descending Order (-1): Single -> Bulky
	else if (criteria == 5) {
		int left_priority = (left->get_type() == "Single") ? 0 : 1;
		int right_priority = (right->get_type() == "Single") ? 0 : 1;

		if (left_priority > right_priority) {
			if (order == 1) {
				counter = left;
				counter->next = merge(left->next, right, criteria, order);
			}
			else if (order == -1) {
				counter = right;
				counter->next = merge(left, right->next, criteria, order);
			}
		}
		else {
			if (order == 1) {
				counter = right;
				counter->next = merge(left, right->next, criteria, order);
			}
			else if (order == -1) {
				counter = left;
				counter->next = merge(left->next, right, criteria, order);
			}
		}
	}

	// Option 6: Status
	// Ascending Order (1): Not Processed -> Processed
	// Descending Order (-1): Processed -> Not Processed
	else if (criteria == 6) {
		int left_status = (left->get_status() == "Not Processed") ? 1 : 0;
		int right_status = (right->get_status() == "Not Processed") ? 1 : 0;

		if (left_status > right_status) {
			if (order == 1) {
				counter = left;
				counter->next = merge(left->next, right, criteria, order);
			}
			else if (order == -1) {
				counter = right;
				counter->next = merge(left, right->next, criteria, order);
			}
		}
		else {
			if (order == 1) {
				counter = right;
				counter->next = merge(left, right->next, criteria, order);
			}
			else if (order == -1) {
				counter = left;
				counter->next = merge(left->next, right, criteria, order);
			}
		}
	}

	return counter;
}

Purchase_Records* Purchase_Records_Linked_List::mid_point(Purchase_Records* node) {
	if (node == NULL || node->next == NULL) {
		return node;
	}

	Purchase_Records* fast = node;
	Purchase_Records* slow = node;

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next;

		if (fast->next == NULL) {
			break;
		}

		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}

Purchase_Records* Purchase_Records_Linked_List::merge_sort(Purchase_Records* node, int criteria, int order) {
	if (node == NULL || node->next == NULL) {
		return node;
	}

	Purchase_Records* mid = mid_point(node);
	Purchase_Records* left = node;
	Purchase_Records* right = mid->next;

	mid->next = NULL;

	left = merge_sort(left, criteria, order);
	right = merge_sort(right, criteria, order);

	Purchase_Records* merged = merge(left, right, criteria, order);
	return merged;
}

// ***********************************************************************************

Purchase_Records* Purchase_Records_Linked_List::sort_records(int option, int order) {
	// Options: 
	// 0: Order ID
	// 1: Client ID
	// 2: Price
	// 3: Date
	// 4: Time
	// 5: Type
	// 6: Status

	// Order: 
	// 1. Ascending
	// -1. Descending

	Purchase_Records* clone_head = clone_list();
	Purchase_Records* sorted_head = merge_sort(clone_head, option, order);
	return sorted_head;
}

// Search Records
Purchase_Records* Purchase_Records_Linked_List::search_records(int criteria, int parameter) {
	Purchase_Records* search_head = NULL;
	Purchase_Records* search_cursor = NULL;
	Purchase_Records* current = head;

	// Search by ID
	if (criteria == 0) {
		while (current != NULL) {
			int order_id = current->get_order_id();
			if (order_id == parameter) {
				search_head = new Purchase_Records;
				search_head->set_order_id(current->get_order_id());
				search_head->set_client_id(current->get_client_id());
				search_head->set_client_name(current->get_client_name());
				search_head->set_item_ids(current->get_item_ids());
				search_head->set_price(current->get_price());
				search_head->set_date(current->get_date());
				search_head->set_time(current->get_time());
				search_head->set_type(current->get_type());
				search_head->set_status(current->get_status());
				search_head->next = NULL;

				search_cursor = search_head;
				return search_head;
			}
			current = current->next;
		}
	}
	// Search by Client ID
	else if (criteria == 1) {
		while (current != NULL) {
			int client_id = current->get_client_id();
			if (client_id == parameter) {
				if (search_head == NULL) {
					// First item discoverd
					search_head = new Purchase_Records;
					search_head->set_order_id(current->get_order_id());
					search_head->set_client_id(current->get_client_id());
					search_head->set_client_name(current->get_client_name());
					search_head->set_item_ids(current->get_item_ids());
					search_head->set_price(current->get_price());
					search_head->set_date(current->get_date());
					search_head->set_time(current->get_time());
					search_head->set_type(current->get_type());
					search_head->set_status(current->get_status());
					search_head->next = NULL;

					search_cursor = search_head;
				}
				else {
					Purchase_Records* search_item = new Purchase_Records;
					search_item->set_order_id(current->get_order_id());
					search_item->set_client_id(current->get_client_id());
					search_item->set_client_name(current->get_client_name());
					search_item->set_item_ids(current->get_item_ids());
					search_item->set_price(current->get_price());
					search_item->set_date(current->get_date());
					search_item->set_time(current->get_time());
					search_item->set_type(current->get_type());
					search_item->set_status(current->get_status());
					search_item->next = NULL;

					search_cursor->next = search_item;
					search_cursor = search_item;
				}
			}

			current = current->next;
		}
	}

	return search_head;
}

// Clone the original linked list before sorting to avoid mutation directly
Purchase_Records* Purchase_Records_Linked_List::clone_list() { 
	Purchase_Records* new_current = NULL;
	Purchase_Records* current = head;
	Purchase_Records* new_head = NULL;
	bool is_first = true;

	while (current != NULL) {
		Purchase_Records* new_node = new Purchase_Records;
		new_node->set_order_id(current->get_order_id());
		new_node->set_client_id(current->get_client_id());
		new_node->set_client_name(current->get_client_name());
		new_node->set_item_ids(current->get_item_ids());
		new_node->set_price(current->get_price());
		new_node->set_date(current->get_date());
		new_node->set_time(current->get_time());
		new_node->set_type(current->get_type());
		new_node->set_status(current->get_status());

		if (is_first) {
			new_current = new_node;
			new_head = new_current;
			is_first = false;
		}
		else {
			new_current->next = new_node;
			new_current = new_current->next;
		}

		current = current->next;
	}

	new_current->next = nullptr;
	return new_head;
}

// Delete every element of the clone list from heap
void Purchase_Records_Linked_List::delete_clone_list(Purchase_Records* clone_head) {
	Purchase_Records* current = clone_head;

	while (current != NULL) {
		Purchase_Records* target = current;
		current = current->next;

		target->next = NULL;
		delete target;
	}
}

#endif
