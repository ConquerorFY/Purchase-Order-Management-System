/* Header File for the User Linked List Class */

#pragma once
#ifndef USERLINKEDLIST
#define USERLINKEDLIST

#include <iostream>
#include "User.h"
using namespace std;

// Linked List Class for User
class User_Linked_List {
	private:
		int size;
		User* head;
	public:
		void obtain_users_list() {};
		User* validate_login_details(string username, string password) {};
};

#endif
