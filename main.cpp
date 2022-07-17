#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "PurchaseRecords.h"
#include "PurchaseRecordsLinkedList.h"
#include "User.h"
#include "UserLinkedList.h"
#include "SummaryReportsLinkedList.h"
#include "UI.h"

using namespace std;

// Store purchase records as Linked-List
Purchase_Records_Linked_List* pr = new Purchase_Records_Linked_List;

// Store user accounts as Linked-List
User_Linked_List* user = new User_Linked_List;

// Store summary reports as Linked-List
Summary_Reports_Linked_List* summary = new Summary_Reports_Linked_List;

// Store detailed reports as Linked-List
Detailed_Reports_Linked_List* detailed = new Detailed_Reports_Linked_List;

int main() {
	build_UI(pr, user, summary,detailed);
	return 0;
}