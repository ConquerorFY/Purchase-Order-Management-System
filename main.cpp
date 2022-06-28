#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "PurchaseRecords.h"
#include "User.h"
#include "UI.h"

using namespace std;

// Store purchase records as Linked-List
Purchase_Records* pr = new Purchase_Records;

// Store user accounts as Linked-List
User* user = new User;

int main() {
	//pr = obtain_records(pr);

	//// Sort Records
	//pr = sort_records(pr, 4, -1);

	build_UI(pr, user, true);

	return 0;
}