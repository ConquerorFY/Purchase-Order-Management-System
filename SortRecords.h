#pragma once
#ifndef SORTRECORDS
#define SORTRECORDS

#include <iostream>
#include "PurchaseRecords.h"
#include "Utils.h"

using namespace std;


// Sorting Function for LinkedList (Using Merge Sort)
// ***********************************************************************************

Purchase_Records* merge(Purchase_Records* left, Purchase_Records* right, int criteria) {
	if (left == NULL) {
		return right;
	}
	if (right == NULL) {
		return left;
	}

	Purchase_Records* counter = NULL;

	// Option 0: Order ID
	if (criteria == 0) {
		if (left->get_order_id() < right->get_order_id()) {
			counter = left;
			counter->next = merge(left->next, right, criteria);
		}
		else {
			counter = right;
			counter->next = merge(left, right->next, criteria);
		}
	}

	// Option 1: Client ID
	else if (criteria == 1) {
		if (left->get_client_id() < right->get_client_id()) {
			counter = left;
			counter->next = merge(left->next, right, criteria);
		}
		else {
			counter = right;
			counter->next = merge(left, right->next, criteria);
		}
	}

	// Option 2: Price
	else if (criteria == 2) {
		if (left->get_price() < right->get_price()) {
			counter = left;
			counter->next = merge(left->next, right, criteria);
		}
		else {
			counter = right;
			counter->next = merge(left, right->next, criteria);
		}
	}

	// Option 3: Date
	else if (criteria == 3) {
		if (compare_date(left->get_date(), right->get_date()) > 0) {
			counter = left;
			counter->next = merge(left->next, right, criteria);
		}
		else {
			counter = right;
			counter->next = merge(left, right->next, criteria);
		}
	}

	// Option 4: Time
	else if (criteria == 4) {
		if (compare_time(left->get_time(), right->get_time()) > 0) {
			counter = left;
			counter->next = merge(left->next, right, criteria);
		}
		else {
			counter = right;
			counter->next = merge(left, right->next, criteria);
		}
	}

	// Option 5: Type (Priority)
	else if (criteria == 5) {
		int left_priority = (left->get_type() == "Single") ? 0 : 1;
		int right_priority = (right->get_type() == "Single") ? 0 : 1;

		if (left_priority > right_priority) {
			counter = left;
			counter->next = merge(left->next, right, criteria);
		}
		else {
			counter = right;
			counter->next = merge(left, right->next, criteria);
		}
	}

	// Option 6: Status
	else if (criteria == 6) {
		int left_status = (left->get_status() == "Not Processed") ? 1 : 0;
		int right_status = (right->get_status() == "Not Processed") ? 1 : 0;

		if (left_status > right_status) {
			counter = left;
			counter->next = merge(left->next, right, criteria);
		}
		else {
			counter = right;
			counter->next = merge(left, right->next, criteria);
		}
	}

	return counter;
}

Purchase_Records* mid_point(Purchase_Records* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	Purchase_Records* fast = head;
	Purchase_Records* slow = head;

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

Purchase_Records* merge_sort(Purchase_Records* head, int criteria) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	Purchase_Records* mid = mid_point(head);
	Purchase_Records* left = head;
	Purchase_Records* right = mid->next;

	mid->next = NULL;

	left = merge_sort(left, criteria);
	right = merge_sort(right, criteria);

	Purchase_Records* merged = merge(left, right, criteria);
	return merged;
}

// ***********************************************************************************

Purchase_Records* sort_records(Purchase_Records* head, int option) {
	// 0: Order ID
	// 1: Client ID
	// 2: Price
	// 3: Date
	// 4: Time
	// 5: Type
	// 6: Status

	return merge_sort(head, option);
}

void debug_view_sorted_records(Purchase_Records* head) {
	Purchase_Records* current = head;

	while (current != NULL) {
		cout << "Order ID: " << current->get_order_id() << endl;
		cout << "Client ID: " << current->get_client_id() << endl;
		cout << "Client Name: " << current->get_client_name() << endl;
		cout << "Item IDs: " << current->get_item_ids() << endl;
		cout << "Price: " << current->get_price() << endl;
		cout << "Date: " << current->get_date() << endl;
		cout << "Time: " << current->get_time() << endl;
		cout << "Type: " << current->get_type() << endl;
		cout << "Status: " << current->get_status() << endl << endl;

		current = current->next;
	}
}

#endif
