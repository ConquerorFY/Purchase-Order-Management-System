/* Header File that Contains the User Class Definition */

#pragma once
#ifndef USER
#define USER
#include <iostream> 
#include <fstream> 
#include <string>
#include "PurchaseRecordsLinkedList.h"
using namespace std;

class User {
	private:
		string full_name;
		string username;
		string password;
		string role;
	public:
		User* next;

		string get_user_full_name(void) { return full_name; }
		string get_username(void) { return username; }
		string get_password(void) { return password; }
		string get_role(void) { return role; }

		void set_user_full_name(string name) { full_name = name; }
		void set_username(string usrname) { username = usrname; }
		void set_password(string pass) { password = pass; }
		void set_role(string usrrole) { role = usrrole; }

		void obtain_purchase_records(Purchase_Records_Linked_List* ll) {};
		void update_purchase_record(Purchase_Records_Linked_List* ll) {};
		void display_purchase_records(Purchase_Records_Linked_List* ll) {};
		void sort_purchase_records(Purchase_Records_Linked_List* ll, int option, int order) {};
		void search_purchase_records(Purchase_Records_Linked_List* ll, int id) {};
		
		void generate_summary_report(string month, int year) {};
		void generate_detailed_report(int id) {};
		void sort_summary_reports(int order) {};
		void sort_detailed_reports(int order) {};
		void view_summary_reports() {};
		void view_detailed_reports() {};
};



#endif