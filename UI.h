#pragma once
#ifndef UI
#define UI

#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <conio.h>
#include <windows.h>
#include "ObtainRecords.h"
#include "SortRecords.h"

using namespace std;

bool key_clicked = false;

void clear_screen() {
    system("cls");
}

void keyevent_listener()
{
    HANDLE hIn;
    int KeyEvents = 0;
    INPUT_RECORD InRec;
    DWORD NumRead;

    hIn = GetStdHandle(STD_INPUT_HANDLE);

    while (true)
    {
        ReadConsoleInput(hIn, &InRec, 1, &NumRead);

        if (InRec.EventType == KEY_EVENT) {
            key_clicked = true;
            break;
        }
    }
}

void welcome_screen() {
	time_t t = time(0);	// get time now
	tm* now = localtime(&t);

	int year = now->tm_year + 1900;
	int month = now->tm_mon + 1;
	int day = now->tm_mday;

	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "LiveOrder Sdn Bhd Online Store Purchase Order Client System" << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;

	cout << "Date: " << year << "/" << month << "/" << day << endl;
	while (true) {
		time_t t = time(0);	// get time now
		tm* now = localtime(&t);
		int hour = now->tm_hour;
		int min = now->tm_min;
		int sec = now->tm_sec;

		cout << "Time: " << hour << ":" << min << ":" << sec;

		std::chrono::seconds dura(1);
		std::this_thread::sleep_for(dura);

		printf("\33[2K\r");

        if (key_clicked) {
            time_t t = time(0);	// get time now
            tm* now = localtime(&t);
            int hour = now->tm_hour;
            int min = now->tm_min;
            int sec = now->tm_sec;

            cout << "Time: " << hour << ":" << min << ":" << sec << endl;
            break;
        }
	}
}

void login_screen() {
    // login screen
}

void executives_screen(string name, Purchase_Records* &pr) {
    int selection = 0;

    while (selection != 8) {
        cout << "Welcome, " << name << "!" << endl << endl;
        cout << "********************************************************************************************" << endl;
        cout << "What do you want to do? " << endl;
        cout << "---------------------------" << endl;
        cout << "1. Obtain Purchase Order Records Placed Online from File" << endl;
        cout << "2. Modify / Update Purchase Order Records" << endl;
        cout << "3. View All Purchase Order Records on Original List" << endl;
        cout << "4. Sort Purchase Order Records According to Criteria Specified" << endl;
        cout << "5. Search Purchase Order Record Based on Order ID or other parameters" << endl;
        cout << "6. Generate Detailed Order Reports" << endl;
        cout << "7. Logout" << endl;
        cout << "8. Exit" << endl;
        cout << "********************************************************************************************" << endl << endl;

        cout << "Action Selection: " << endl;
        cin >> selection;

        clear_screen();
        if (selection == 1) {
            pr = obtain_records(pr);
            cout << "[*] Purchase Order Records have been read from file into the program" << endl;
            cout << "[*] Purchase Order Records are stored in a Linked-List within the program for access" << endl;
        }
        else if (selection == 2) {
            // modify
        }
        else if (selection == 3) {
            cout << "All Purchase Order Records: " << endl;
            cout << "********************************************************************************************" << endl;
            debug_view_records(pr);
            cout << "********************************************************************************************" << endl;
        }
        else if (selection == 4) {
            int criteria;
            int option;

            cout << "Please Select What Criteria to Use For Sorting: " << endl;
            cout << "********************************************************************************************" << endl;
            cout << "0: Order ID" << endl;
            cout << "1: Client ID" << endl;
            cout << "2: Price" << endl;
            cout << "3: Date" << endl;
            cout << "4: Time" << endl;
            cout << "5: Type" << endl;
            cout << "6: Status" << endl;
            cout << "********************************************************************************************" << endl << endl;

            cout << "Criteria Selection: ";
            cin >> criteria;

            cout << "Please Select What Order to Use for Sorting: " << endl;
            cout << "1: Ascending Order" << endl;
            cout << "-1: Descending Order" << endl;
            cout << "Order Selection: ";
            cin >> option;

            pr = sort_records(pr, criteria, option);
            cout << "\n[*] Purchase Order Record List has been sorted successfully!!" << endl;
        }
        else if (selection == 5) {
            // search
        }
        else if (selection == 6) {
            // generate detailed report (handled or not handled)
        }
        else if (selection == 7) {
            // logout
        }
    }
}

void admin_screen(string name, Purchase_Records*& pr) {
    int selection = 0;

    while (selection != 11) {
        cout << "Welcome, " << name << "!" << endl << endl;
        cout << "********************************************************************************************" << endl;
        cout << "What do you want to do? " << endl;
        cout << "---------------------------" << endl;
        cout << "1. Obtain Purchase Order Records Placed Online from File" << endl;
        cout << "2. Modify / Update Purchase Order Records" << endl;
        cout << "3. View All Purchase Order Records on Original List" << endl;
        cout << "4. Sort Purchase Order Records According to Criteria Specified" << endl;
        cout << "5. Search Purchase Order Record Based on Order ID or other parameters" << endl;
        cout << "6. Generate Summary Order Reports" << endl;
        cout << "7. View Order Reports List" << endl;
        cout << "8. View Order Report Details" << endl;
        cout << "9. Sort Order Reports List" << endl;
        cout << "10. Logout" << endl;
        cout << "11. Exit" << endl;
        cout << "********************************************************************************************" << endl << endl;

        cout << "Action Selection: " << endl;
        cin >> selection;

        clear_screen();
        if (selection == 1) {
            pr = obtain_records(pr);
            cout << "[*] Purchase Order Records have been read from file into the program" << endl;
            cout << "[*] Purchase Order Records are stored in a Linked-List within the program for access" << endl;
        }
        else if (selection == 2) {
            // modify
        }
        else if (selection == 3) {
            cout << "All Purchase Order Records: " << endl;
            cout << "********************************************************************************************" << endl;
            debug_view_records(pr);
            cout << "********************************************************************************************" << endl;
        }
        else if (selection == 4) {
            int criteria;
            int option;

            cout << "Please Select What Criteria to Use For Sorting: " << endl;
            cout << "********************************************************************************************" << endl;
            cout << "0: Order ID" << endl;
            cout << "1: Client ID" << endl;
            cout << "2: Price" << endl;
            cout << "3: Date" << endl;
            cout << "4: Time" << endl;
            cout << "5: Type" << endl;
            cout << "6: Status" << endl;
            cout << "********************************************************************************************" << endl << endl;

            cout << "Criteria Selection: ";
            cin >> criteria;

            cout << "Please Select What Order to Use for Sorting: " << endl;
            cout << "1: Ascending Order" << endl;
            cout << "-1: Descending Order" << endl;
            cout << "Order Selection: ";
            cin >> option;

            pr = sort_records(pr, criteria, option);
            cout << "\n[*] Purchase Order Record List has been sorted successfully!!" << endl;
        }
        else if (selection == 5) {
            // search
        }
        else if (selection == 6) {
            // generate summary report
        }
        else if (selection == 7) {
            // view order report lists
        }
        else if (selection == 8) {
            // view order report details
        }
        else if (selection == 9) {
            // sort order report list
        }
        else if (selection == 10) {
            // logout
        }
    }
}

void build_UI(Purchase_Records* pr) {
    std::thread thread_obj(keyevent_listener);
    welcome_screen();
    thread_obj.join();

    clear_screen();

    // executives_screen("Ryan", pr);
    admin_screen("Ryan", pr);
}

#endif
