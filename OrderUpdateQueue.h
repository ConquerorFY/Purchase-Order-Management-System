/* Header File for the Order Update Queue Class (Use Arrays) */

#pragma once
#ifndef ORDERUPDATEQUEUE
#define ORDERUPDATEQUEUE

#include <iostream>
#include "PurchaseRecords.h"
using namespace std;

class Order_Update_Queue {
	private:
		int size;
		Purchase_Records* linked_list;
		Purchase_Records* queue;

	public:
		Order_Update_Queue(int size, Purchase_Records* head);
		void modify_order_queue();
};

Order_Update_Queue::Order_Update_Queue(int size, Purchase_Records* head) {
	this->size = size;
	this->linked_list = head;
	this->queue = new Purchase_Records[size];		// create array with fixed size
}

#endif
