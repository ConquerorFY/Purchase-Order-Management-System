#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "PurchaseRecords.h"
#include "PurchaseRecordsLinkedList.h"
#include "User.h"
#include "UserLinkedList.h"
#include "UI.h"

using namespace std;

// Store purchase records as Linked-List
Purchase_Records_Linked_List* pr = new Purchase_Records_Linked_List;

// Store user accounts as Linked-List
User_Linked_List* user = new User_Linked_List;

int main() {
	//pr = obtain_records(pr);

	//// Sort Records
	//pr = sort_records(pr, 4, -1);

	build_UI(pr, user, true);

	return 0;
}