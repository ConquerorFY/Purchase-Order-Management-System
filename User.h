/* Header File that Contains the User Class Definition */

#pragma once
#ifndef USER
#define USER
#include <iostream> 
#include <fstream> 
#include <string>
#include "PurchaseRecordsLinkedList.h"
#include "SummaryReportsLinkedList.h"
#include "DetailedReportsLinkedList.h"
using namespace std;

class User {
	private:
		Purchase_Records_Linked_List* ll;
		Summary_Reports_Linked_List* sl;
		Detailed_Reports_Linked_List* dl;
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

		void set_purchase_records_linked_list(Purchase_Records_Linked_List* ll) { this->ll = ll; }
		void set_summary_reports_linked_list(Summary_Reports_Linked_List* sl) { 
			this->sl = sl; 
			this->sl->set_purchase_records_linked_list(ll);
		}
		void set_detailed_reports_linked_list(Detailed_Reports_Linked_List* dl) {
			this->dl = dl;
			this->dl->set_purchase_records_linked_list(ll);
		}
		void set_user_full_name(string name) { full_name = name; }
		void set_username(string usrname) { username = usrname; }
		void set_password(string pass) { password = pass; }
		void set_role(string usrrole) { role = usrrole; }

		void obtain_purchase_records() {
			ll->obtain_records();
		};
		void update_purchase_record() {};		// TBD
		void display_purchase_records() {
			ll->display_order_table();
		};
		void sort_purchase_records(int option, int order) {
			Purchase_Records* sorted_ll = ll->sort_records(option, order);
			ll->display_order_table(sorted_ll);
			ll->delete_clone_list(sorted_ll);
		};
		void search_purchase_records(int criteria, int parameter) {
			Purchase_Records* search_head = ll->search_records(criteria, parameter);
			ll->display_order_table(search_head);
			ll->delete_clone_list(search_head);
		};
		
		void generate_summary_report(int month, int year) {
			sl->update_summary_report_list(month, year);
		};
		void generate_detailed_report(int id) {
			dl->update_detailed_report_list(id);
		};
		void sort_summary_reports(int order) {
			sl->sort_summary_report_list(order);
		};
		void sort_detailed_reports(int order) {
			dl->sort_detailed_reports(order);
		};
		void view_summary_reports() {
			sl->view_summary_report_list();
		};
		void view_detailed_reports() {
			dl->view_detailed_report_list();
		};
};
#endif