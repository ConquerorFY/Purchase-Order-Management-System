/* Header File for the Summary Report Class */

#pragma once
#ifndef SUMMARYREPORT
#define SUMMARYREPORT

#include <iostream>
using namespace std;

class Summary_Report {
private:
	int report_id;
	string month;
	int year;
public:
	Summary_Report* next;

	int get_report_id() {};
	int get_month() {};
	int get_year() {};

	void set_report_id(int id) {};
	void set_month(string month) {};
	void set_year(int year) {};
};

#endif
