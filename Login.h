/* Header File that contain functions for login into system and obtain user's list from file */

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
		User_Linked_List* user;
	public:
		Login(User_Linked_List* head);
		void validateInput(string a, string b);
		bool loginAccount(User* &user);
		bool logoutAccount(User* &user);
};

Login::Login(User_Linked_List* user) {
	this->user = user;
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

bool Login::loginAccount(User* &user) {
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

	user = this->user->validate_login_details(username, pass, loginStatus);
	if (loginStatus) {
		cout << "Login Success!!" << endl; 
		return true;
	}
	else {
		cout << "Invalid Credentials!!" << endl;
		return false;
	}
}

bool Login::logoutAccount(User* &user) {
	loginStatus = false;
	isValidInput = false;
	user = NULL;

	cout << "Logout Successful!!" << endl;
	return true;
}

#endif
