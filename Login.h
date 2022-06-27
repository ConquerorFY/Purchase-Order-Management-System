#pragma once
#ifndef LOGIN
#define LOGIN
#include <iostream> 
#include <fstream> 
#include <string>
#include "User.h"
#include "Utils.h"
using namespace std;

class Login{
private:
	bool loginStatus;
	bool isValidInput;
public:
	void validateInput(string a, string b);
	void login();
	void logout();

};

bool isValidInput(string usr, string pass) {

	if (!usr.empty() && !pass.empty()) {

		return true;
	}
	else {
		cout << "cannot enter empty credentials,please try again" << endl;
		return false;

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
		cout << "If statement is running" << endl;
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
		
	}
	return head;
}
 void login(User* head) {
	 User* current = head;
	string username, pass;
	bool loginStatus;
	
	while (true) {

		cout << "Username:" << endl;
		getline(cin, username);
		cout << "Password:" << endl;
		getline(cin, pass);
		if (isValidInput(username, pass)) {
			break;
		}
	}
	while (current != NULL) {
		if (username == current->get_username() && pass == current->get_password()) {

			loginStatus = true; //set to true 
			break;
			

		}
		else {
			
			loginStatus = false; //set to false 
			
		}

		current = current->next;

		

	
	}

			

	if (loginStatus) {
		cout << "Login Success!" << endl;
		//continue the program 
	}
	else {
		cout << "Invalid Credentials!" << endl;;
	}


}

void debug_view_user(User* head) {
	User* current = head;
	while (current != NULL) {
		cout <<"Username:" <<current->get_username() << endl;
			current = current->next;
	}
}





#endif
