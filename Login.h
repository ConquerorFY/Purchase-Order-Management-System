/* Header File that contain functions for logging into system */

#pragma once
#ifndef LOGIN
#define LOGIN
#include <iostream> 
#include <fstream> 
#include <string>
#include "User.h"
#include "Utils.h"
using namespace std;

class Login {
	private:
		bool loginStatus;
		bool isValidInput;
		User* head;
	public:
		Login(User* head);
		void validateInput(string a, string b);
		bool loginAccount(string &name, string &role);
		bool logoutAccount(string &name, string &role);
		void debug_view_user();
};

Login::Login(User* head) {
	this->head = head;
	loginStatus = false;
	isValidInput = false;
}

void Login::validateInput(string usr, string pass) {
	if (!usr.empty() && !pass.empty()) {
		isValidInput = true;
	}
	else {
		cout << "Cannot enter empty credentials, Please try again!!" << endl;
		isValidInput = false;
	}
}

bool Login::loginAccount(string &name, string &role) {
	User* current = head;
	string username, pass;

	while (true) {
		cout << "Username: ";
		getline(cin, username);
		cout << "Password: ";
		getline(cin, pass);

		validateInput(username, pass);
		if (isValidInput) {
			break;
		}
	}

	while (current != nullptr) {
		if (username == current->get_username() && pass == current->get_password()) {
			loginStatus = true; // set to true 
			role = current->get_role();
			name = current->get_user_full_name();
			break;
		}
		else {
			loginStatus = false; // set to false 
		}
		current = current->next;
	}

	if (loginStatus) {
		cout << "Login Success!!" << endl; 
		return true;
	}
	else {
		cout << "Invalid Credentials!!" << endl;
		return false;
	}
}

bool Login::logoutAccount(string& name, string& role) {
	loginStatus = false;
	isValidInput = false;
	name = "";
	role = "";

	cout << "Logout Successful!!" << endl;
	return true;
}

void Login::debug_view_user() {
	User* current = head;

	while (current != nullptr) {
		cout << "Username:" << current->get_username() << endl;
		current = current->next;
	}
}

User* obtain_users_list(User* head) {
	fstream myfile;
	int line_no = 1;
	bool first = true;

	myfile.open("Account.txt", ios::in);
	if (myfile.is_open()) {
		string line;
		User* current = head;
		while (getline(myfile,line)) {
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
			}
			line_no++;
		}
		myfile.close();
	}
	return head;
}

#endif
