/* Header File for the Purchase_Records Linked List Class */

#pragma once
#ifndef PURCHASERECORDSLINKEDLIST
#define PURCHASERECORDSLINKEDLIST

#include <iostream>
#include "PurchaseRecords.h"
using namespace std;

// Linked List Class for Purchase Records
class Purchase_Records_Linked_List {
	private:
		int size;
		Purchase_Records* head;

		Purchase_Records* merge(Purchase_Records* left, Purchase_Records* right, int criteria, int order) {};
		Purchase_Records* mid_point() {};
		Purchase_Records* merge_sort(int criteria, int order) {};

	public:
		void obtain_records() {};
		void update_records() {};
		void display_order_table() {};
		void sort_records(int option, int order) {};
		void search_records(int id) {};
};

#endif
