/* Header File for the User Linked List Class */

#pragma once
#ifndef USERLINKEDLIST
#define USERLINKEDLIST

#include <iostream>
#include "User.h"
#include "Utils.h"
using namespace std;

// Linked List Class for User
class User_Linked_List {
	private:
		int size;
		User* head = new User;	// stores a memory location addres assigned by new keyword for the User Object, can be used in operations
		// User* head;			// stores NULL, cannot be used in operations which will result in errors
	public:
		void obtain_users_list();
		User* validate_login_details(string username, string password, bool &login_status);
};

void User_Linked_List::obtain_users_list() {
	fstream myfile;
	int line_no = 1;
	bool first = true;

	myfile.open("Account.txt", ios::in);
	if (myfile.is_open()) {
		string line;
		User* current = head;
		while (getline(myfile, line)) {
			if (line_no > 1) {
				string* index = split_string(line, ';');

				User* usr = new User;
				usr->set_user_full_name(index[0]);
				usr->set_username(index[1]);
				usr->set_password(index[2]);
				usr->set_role(index[3]);
				usr->next = NULL;

				current->next = usr;
				current = usr;

				if (first) {
					head = current;
					first = false;
				}

				size++;
			}
			line_no++;
		}
		myfile.close();
	}
}

User* User_Linked_List::validate_login_details(string username, string password, bool& login_status) {
	User* current = head;
	while (current != nullptr) {
		if (username == current->get_username() && password == current->get_password()) {
			login_status = true; // set to true 
			return current;
		}
		else {
			login_status = false; // set to false 
		}
		current = current->next;
	}

	return NULL;
}

#endif
