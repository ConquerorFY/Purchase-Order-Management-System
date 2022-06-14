/* Header File for Regularly Used Functions (Utilities) */

#pragma once
#ifndef UTILS
#define UTILS

#include <iostream>
#include <string>
#include <sstream>
#include "PurchaseRecords.h"

using namespace std;

// Function to split string into arrays using any delimeters provided
// ***********************************************************************************

string* split_string(string input, char delim) {
	stringstream input_stream(input);
	string* string_tokens = new string[1000000];
	string input_token;
	int i = 0;

	while (getline(input_stream, input_token, delim)) {
		string_tokens[i] = input_token;
		i++;
	}

	return string_tokens;
}

// ***********************************************************************************

#endif
