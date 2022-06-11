/* Header File for the Purchase_Records Class */

#pragma once
#ifndef PURCHASERECORDS
#define PURCHASERECORDS

#include <iostream>
using namespace std;

// Linked List Node Class
// Type (Bulky = Max Priority, Single = Min Priority)
class Purchase_Records {
private:
	int order_id;
	int client_id;
	string client_name;
	string item_ids;
	double price;
	string date;
	string time;
	string type;
	string status;

public:
	Purchase_Records* next;

	// Getters
	int get_order_id(void) {
		return order_id;
	}
	int get_client_id(void) {
		return client_id;
	}
	string get_client_name(void) {
		return client_name;
	}
	string get_item_ids(void) {
		return item_ids;
	}
	double get_price(void) {
		return price;
	}
	string get_date(void) {
		return date;
	}
	string get_time(void) {
		return time;
	}
	string get_type(void) {
		return type;
	}
	string get_status(void) {
		return status;
	}

	// Setters
	void set_order_id(int id) {
		order_id = id;
	}
	void set_client_id(int id) {
		client_id = id;
	}
	void set_client_name(string name) {
		client_name = name;
	}
	void set_item_ids(string ids) {
		item_ids = ids;
	}
	void set_price(double price) {
		this->price = price;
	}
	void set_date(string date) {
		this->date = date;
	}
	void set_time(string time) {
		this->time = time;
	}
	void set_type(string type) {
		this->type = type;
	}
	void set_status(string status) {
		this->status = status;
	}
};

#endif
