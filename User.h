/* Header File that Contains the User Class Definition */
#pragma once
#ifndef USER
#define USER
#include <iostream> 
#include <fstream> 
#include <string>
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
	
};



#endif