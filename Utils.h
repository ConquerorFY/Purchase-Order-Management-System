/* Header File for Regularly Used Functions (Utilities) */

#pragma once
#ifndef UTILS
#define UTILS

#include <iostream>
#include <string>
#include <sstream>
#include "PurchaseRecords.h"

using namespace std;

string* split_string(string input, char delim) {
	stringstream input_stream(input);
	string* string_tokens = new string[100000];
	string input_token;
	int i = 0;

	while (getline(input_stream, input_token, delim)) {
		string_tokens[i] = input_token;
		i++;
	}

	return string_tokens;
}

bool compare_equal_month(string date, int month) {
	string* date_list = split_string(date, '-');

	// Month Comparison
	if (stoi(date_list[1]) == month) {
		return true;
	}

	return false;
}

bool compare_equal_year(string date, int year) {
	string* date_list = split_string(date, '-');

	// Year Comparison
	if (stoi(date_list[0]) == year) {
		return true;
	}

	return false;
}

int compare_month_year(int month1, int year1, int month2, int year2) {
	// Returns 1 if MM1-YY1 > MM2-YY2
	//		  -1 if MM1-YY1 < MM2-YY2
	//		   0 if MM1-YY1 == MM2-YY2

	if (year1 > year2) {
		return 1;
	}
	else if (year1 < year2) {
		return -1;
	}
	else {
		if (month1 > month2) {
			return 1;
		}
		else if (month1 < month2) {
			return -1;
		}
		else {
			return 0;
		}
	}
}

int compare_date(string date1, string date2) {
	// Date is in YYYY-MM-DD Format
	// Returns 1 if date1 > date2; 
	//		  -1 if date1 < date2; 
	//         0 if date1 == date2

	string* date1_list = split_string(date1, '-');
	string* date2_list = split_string(date2, '-');

	// Date element to index conversion
	int day = 2;
	int month = 1;
	int year = 0;

	// Year Comparison
	if (stoi(date1_list[0]) == stoi(date2_list[0])) {
		// Month Comparison
		if (stoi(date1_list[1]) == stoi(date2_list[1])) {
			// Day Comparison
			if (stoi(date1_list[2]) == stoi(date2_list[2])) {
				return 0;
			}
			else if (stoi(date1_list[2]) > stoi(date2_list[2])) {
				return 1;
			}
			else if (stoi(date1_list[2]) < stoi(date2_list[2])) {
				return -1;
			}
		}
		else if (stoi(date1_list[1]) > stoi(date2_list[1])) {
			return 1;
		}
		else if (stoi(date1_list[1]) < stoi(date2_list[1])) {
			return -1;
		}
	}
	else if (stoi(date1_list[0]) > stoi(date2_list[0])) {
		return 1;
	}
	else if (stoi(date1_list[0]) < stoi(date2_list[0])) {
		return -1;
	}
}

string* split_time_string(string time) {
	string* time_list = new string[10000];
	string* first_half = split_string(time, ' ');	// "HH:MM", ["AM" / "PM"]
	string* second_half = split_string(first_half[0], ':');		// "HH", "MM"

	time_list[0] = second_half[0];
	time_list[1] = second_half[1];
	time_list[2] = first_half[1];

	return time_list;	// ["HH", "MM", ["AM" / "PM"]]
}

int compare_time(string time1, string time2) {
	// Time is in HH:MM AM/PM Format
	// Returns 1 if time1 > time2; 
	//		  -1 if time1 < time2; 
	//         0 if time1 == time2

	string* time1_list = split_time_string(time1);
	string* time2_list = split_time_string(time2);

	// AM / PM Comparison
	if (time1_list[2] == time2_list[2]) {
		// HH Comparison
		if (stoi(time1_list[0]) == stoi(time2_list[0])) {
			// MM Comparison
			if (stoi(time1_list[1]) == stoi(time2_list[1])) {
				return 0;
			}
			else if (stoi(time1_list[1]) > stoi(time2_list[1])) {
				return 1;
			}
			else if (stoi(time1_list[1]) < stoi(time2_list[1])) {
				return -1;
			}
		}
		else if (stoi(time1_list[0]) > stoi(time2_list[0])) {
			if (stoi(time1_list[0]) == 12) {
				return -1;
			}
			return 1;
		}
		else if (stoi(time1_list[0]) < stoi(time2_list[0])) {
			if (stoi(time2_list[0]) == 12) {
				return 1;
			}
			return -1;
		}
	}
	else if (time1_list[2] == "pm" && time2_list[2] == "am") {
		return 1;
	}
	else if (time1_list[2] == "am" && time2_list[2] == "pm") {
		return -1;
	}
}

// Check whether string is number
// Reference: https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

bool validate_item_ids(string ids) {
	ids = ids + ",*";
	string* ids_arr = split_string(ids, ',');

	int i = 0;
	while (true) {
		if (ids_arr[i] != "*") {
			if (!is_number(ids_arr[i])) {
				return false;
			}
		}
		else {
			break;
		}
		i++;
	}
	return true;
}

bool validate_date(string date) {
	string* date_arr = split_string(date, '-');
	string year = date_arr[0];
	string month = date_arr[1];
	string day = date_arr[2];

	if (is_number(year) && is_number(month) && is_number(day)) {
		if (stoi(month) < 1 || stoi(month) > 12) {
			return false;
		}

		if (stoi(day) < 1 || stoi(day) > 31) {
			return false;
		}
	}
	else {
		return false;
	}

	return true;
}

bool validate_time(string time) {
	string* time_arr = split_time_string(time);
	string hh = time_arr[0];
	string mm = time_arr[1];
	string apm = time_arr[2];

	if (apm == "am" || apm == "pm") {
		if (is_number(hh) && is_number(mm)) {
			if (stoi(hh) < 0 || stoi(hh) > 11) {
				return false;
			}

			if (stoi(mm) < 0 || stoi(mm) > 59) {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}

	return true;
}

#endif
