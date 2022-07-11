/* Header File for the Detailed Report Class */

#pragma once
#ifndef DETAILEDREPORT
#define DETAILEDREPORT

#include <iostream>
using namespace std;

class Detailed_Report {
private:
	int report_id;
	int order_id;
public:
	Detailed_Report* next;

	int get_report_id() {};
	int get_order_id() {};

	void set_report_id(int id) {};
	void set_order_id(int id) {};
};

#endif
