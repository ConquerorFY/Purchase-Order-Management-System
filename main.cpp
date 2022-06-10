#include <iostream>
#include "ObtainRecords.h"

using namespace std;

// Store purchase records as Linked-List
Purchase_Records* pr = new Purchase_Records;

int main() {
	pr = obtain_records(pr);
	debug_view_records(pr);

	return 0;
}