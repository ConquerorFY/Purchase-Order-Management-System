#include <iostream>
#include "ObtainRecords.h"
#include "SortRecords.h"

using namespace std;

// Store purchase records as Linked-List
Purchase_Records* pr = new Purchase_Records;

int main() {
	pr = obtain_records(pr);

	// Sort Records (in this case ascending order with time)
	pr = sort_records(pr, 4, -1);
	return 0;
}