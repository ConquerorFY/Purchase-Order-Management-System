/* Header File for Detailed Reports Linked List */

#pragma once
#ifndef DETAILEDREPORTSLINKEDLIST
#define DETAILEDREPORTSLINKEDLIST

#include <iostream>
#include "DetailedReport.h"
using namespace std;

class Detailed_Reports_Linked_List {
	private:
		int size;
		Detailed_Report* head;

		Detailed_Report* merge(Detailed_Report* left, Detailed_Report* right, int order) {};
		Detailed_Report* mid_point() {};
		Detailed_Report* merge_sort(int order) {};
	public:
		void generate_detailed_report(int order_id) {};
		void sort_detailed_reports(int order) {};
		void view_detailed_reports() {};
};

#endif
