/* Header File for Summary Reports Linked List */

#pragma once
#include "SummaryReport.h"
#ifndef SUMMARYREPORTSLINKEDLIST
#define SUMMARYREPORTSLINKEDLIST

class Summary_Reports_Linked_List {
	private:
		int size;
		Summary_Report* head;

		Summary_Report* merge(Summary_Report* left, Summary_Report* right, int order) {};
		Summary_Report* mid_point() {};
		Summary_Report* merge_sort(int order) {};
	public:
		void generate_detailed_report(string month, int year) {};
		void sort_detailed_reports(int order) {};
		void view_detailed_reports() {};
};

#endif