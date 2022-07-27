/* Header File for UI */

#pragma once
#ifndef UI
#define UI

#include <iostream>
#include <chrono>
#include <ctime>
#include "Login.h"
#include "PurchaseRecordsLinkedList.h"
#include "SummaryReportsLinkedList.h"
#include "DetailedReportsLinkedList.h"

using namespace std;

Login* l;
User* login_user;

// Function Definitions
void build_UI(Purchase_Records_Linked_List* pr, User_Linked_List* user, Summary_Reports_Linked_List* summary, Detailed_Reports_Linked_List* detailed);

// Clear Console Screen
void clear_screen() {
    system("cls");
}

// Validation whether purchase records data has been obtained
bool validate_purchase_records_list(Purchase_Records_Linked_List* pr) {
    if (pr->get_size() < 1) {
        cout << "\nPlease obtain the purchase records first before proceed!!" << endl;
        return false;
    }
    return true;
}

// Welcome Screen
void welcome_screen() {
	time_t t = time(0);	// get time now
	tm* now = localtime(&t);

	int year = now->tm_year + 1900;
	int month = now->tm_mon + 1;
	int day = now->tm_mday;

	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "               LiveOrder Sdn Bhd Online Store Purchase Order Client System" << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
}

// Login Screen
bool login_screen(User_Linked_List* user) {
    l = new Login(user);
    return l->loginAccount(login_user);
}

// Sale Executives Screen
void executives_screen(string name, Purchase_Records_Linked_List* pr, User_Linked_List* user, Summary_Reports_Linked_List* summary, Detailed_Reports_Linked_List* detailed) {
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

        cout << "Action Selection: ";
        cin >> selection;

        clear_screen();
        if (selection == 1) {
            // obtain purchase records
            login_user->obtain_purchase_records();
            cout << "[*] Purchase Order Records have been read from file into the program" << endl;
            cout << "[*] Purchase Order Records are stored in a Linked-List within the program for access" << endl << endl;
        }
        else if (selection == 2) {
            // modify purchase records
            if (!validate_purchase_records_list(pr)) {
                continue;
            }

            login_user->update_purchase_record();
        }
        else if (selection == 3) {
            // view purchase records
            if (!validate_purchase_records_list(pr)) {
                continue;
            }

            cout << "All Purchase Order Records: " << endl;
            cout << "*****************************************************************************************************************************************" << endl;
            login_user->display_purchase_records();
            cout << "*****************************************************************************************************************************************" << endl << endl;
        }
        else if (selection == 4) {
            // sort purchase records
            if (!validate_purchase_records_list(pr)) {
                continue;
            }

            int criteria;
            int option;

            while (true) {
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

                if (!cin.fail()) {
                    if (criteria >= 0 && criteria <= 6) {
                        break;
                    }
                    else {
                        cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
                else {
                    cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');

                }
            }

            while (true) {
                cout << "Please Select What Order to Use for Sorting: " << endl;
                cout << "1: Ascending Order (Small -> Big; Latest -> Oldest; Bulky -> Single; Not Processed -> Processed)" << endl;
                cout << "-1: Descending Order (Big -> Small; Oldest -> Latest; Single -> Bulky; Processed -> Not Processed)" << endl;
                cout << "Order Selection: ";
                cin >> option;

                if (!cin.fail()) {
                    if (option == -1 || option == 1) {
                        break;
                    }
                    else {
                        cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
                else {
                    cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }

            login_user->sort_purchase_records(criteria, option);
            cout << "\n[*] Purchase Order Record List has been sorted successfully!!" << endl;
        }
        else if (selection == 5) {
            // search purchase records
            if (!validate_purchase_records_list(pr)) {
                continue;
            }

            int criteria;
            int option;

            while (true) {
                cout << "Please Select What Criteria to Use For Searching: " << endl;
                cout << "********************************************************************************************" << endl;
                cout << "0: Order ID" << endl;
                cout << "1: Client ID" << endl;
                cout << "********************************************************************************************" << endl << endl;

                cout << "Criteria Selection: ";
                cin >> criteria;

                if (!cin.fail()) {
                    if (criteria >= 0 && criteria <= 1) {
                        break;
                    }
                    else {
                        cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
                else {
                    cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');

                }
            }

            while (true) {
                cout << "Please Enter Parameter: ";
                cin >> option;

                if (cin.fail()) {
                    cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');                    
                }
                else {
                    break;
                }
            }

            login_user->search_purchase_records(criteria, option);
            cout << endl << endl;
        }
        else if (selection == 6) {
            // generate detailed report (handled or not handled)
            if (!validate_purchase_records_list(pr)) {
                continue;
            }

            int order_id;
            while (true) {
                cout << "Please Enter Order ID: ";
                cin >> order_id;
                if (cin.fail()) {
                    cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else {
                    break;
                }

            }
            login_user->generate_detailed_report(order_id);
            cout << "\n [*] Detailed Report has been generated successfully!!" << endl;
        }
        else if (selection == 7) {
            // logout
            l->logoutAccount(login_user);
            selection = 8;
            cin.ignore();       // use this to eat up the <Space> character (prevent from affecting getline() in the login_screen() function)
            build_UI(pr, user, summary, detailed);
        }
        else if (selection == 8) {
            // exit
        }
        else {
            // Input Validation
            cout << "[X] Input Error! Please Enter the Correct Inputs!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

// Admin Screen
void admin_screen(string name, Purchase_Records_Linked_List* pr, User_Linked_List* user, Summary_Reports_Linked_List* summary,Detailed_Reports_Linked_List* detailed) {
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
        cout << "7. View Order Reports" << endl;
        cout << "8. Sort Order Reports" << endl;
        cout << "9. View User List" << endl;
        cout << "10. Logout" << endl;
        cout << "11. Exit" << endl;
        cout << "********************************************************************************************" << endl << endl;

        cout << "Action Selection: ";
        cin >> selection;

        clear_screen();
        if (selection == 1) {
            // obtain purchase records
            login_user->obtain_purchase_records();
            cout << "[*] Purchase Order Records have been read from file into the program" << endl;
            cout << "[*] Purchase Order Records are stored in a Linked-List within the program for access" << endl;
        }
        else if (selection == 2) {
            // modify purchase records
            if (!validate_purchase_records_list(pr)) {
                continue;
            }

            login_user->update_purchase_record();
        }
        else if (selection == 3) {
            // view purchase records
            if (!validate_purchase_records_list(pr)) {
                continue;
            }

            cout << "All Purchase Order Records: " << endl;
            cout << "*****************************************************************************************************************************************" << endl;
            login_user->display_purchase_records(); 
            cout << "*****************************************************************************************************************************************" << endl << endl;
        }
        else if (selection == 4) {
            // sort purchase records
            if (!validate_purchase_records_list(pr)) {
                continue;
            }

            int criteria;
            int option;

            while (true) {
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

                if (!cin.fail()) {
                    if (criteria >= 0 && criteria <= 6) {
                        break;
                    }
                    else {
                        cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
                else {
                    cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }

            while (true) {
                cout << "Please Select What Order to Use for Sorting: " << endl;
                cout << "1: Ascending Order (Small -> Big; Latest -> Oldest; Bulky -> Single; Not Processed -> Processed)" << endl;
                cout << "-1: Descending Order (Big -> Small; Oldest -> Latest; Single -> Bulky; Processed -> Not Processed)" << endl;
                cout << "Order Selection: ";
                cin >> option;

                if (!cin.fail()) {
                    if (option == -1 || option == 1) {
                        break;
                    }
                    else {
                        cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
                else {
                    cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }

            login_user->sort_purchase_records(criteria, option);
            cout << "\n [*] Purchase Order Record List has been sorted successfully!!" << endl;
        }
        else if (selection == 5) {
            // search purchase records
            if (!validate_purchase_records_list(pr)) {
                continue;
            }

            int criteria;
            int option;

            while (true) {
                cout << "Please Select What Criteria to Use For Searching: " << endl;
                cout << "********************************************************************************************" << endl;
                cout << "0: Order ID" << endl;
                cout << "1: Client ID" << endl;
                cout << "********************************************************************************************" << endl << endl;

                cout << "Criteria Selection: ";
                cin >> criteria;

                if (!cin.fail()) {
                    if (criteria >= 0 && criteria <= 1) {
                        break;
                    }
                    else {
                        cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
                else {
                    cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');

                }
            }

            while (true) {
                cout << "Please Enter Parameter: ";
                cin >> option;

                if (cin.fail()) {
                    cout << "\n[X] Input Error! Please Enter the Correct Inputs!" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else {
                    break;
                }
            }

            login_user->search_purchase_records(criteria, option);
            cout << endl << endl;
        }
        else if (selection == 6) {
            // generate summary reports
            if (!validate_purchase_records_list(pr)) {
                continue;
            }

            int month, year;

            cout << "Please enter month of summary report (1-12): ";
            cin >> month;
            cout << "Please enter year of summary report (0000-9999): ";
            cin >> year;

            login_user->generate_summary_report(month, year);
            cout << "\n [*] Summary Report has been generated successfully!!" << endl;
        }
        else if (selection == 7) {
            // view order reports
            if (!validate_purchase_records_list(pr)) {
                continue;
            }

            int option;

            cout << "Please select whether to view summary order reports / detailed order reports (summary order reports (1) / detailed order reports (2)): ";
            cin >> option;

            clear_screen();
            if (option == 1) {
                // view summary order reports
                login_user->view_summary_reports();
            }
            else if (option == 2) {
                // view detailed order reports
                login_user->view_detailed_reports();
            }
        }
        else if (selection == 8) {
            // sort order reports
            if (!validate_purchase_records_list(pr)) {
                continue;
            }

            int option;

            cout << "Please select whether to sort summary order reports / detailed order reports (summary order reports (1) / detailed order reports (2)): ";
            cin >> option;

            if (option == 1) {
                // sort summary order reports
                int order;

                cout << "Ascending (Latest - Oldest): 1" << endl;
                cout << "Descending (Oldest - Latest): -1" << endl;
                cout << "Sorting Order: ";
                cin >> order;

                login_user->sort_summary_reports(order);
            }
            else if (option == 2) {
                // sort detailed order reports
                int order;

                cout << "Ascending (Latest - Oldest): 1" << endl;
                cout << "Descending (Oldest - Latest): -1" << endl;
                cout << "Sorting Order: ";
                cin >> order;

                login_user->sort_detailed_reports(order);
            }
        }
        else if (selection == 9) {
            // view user list
            cout << "All Users Details: " << endl;
            cout << "******************************************************************" << endl;
            login_user->display_user_table(user->get_user_list());
            cout << "******************************************************************" << endl;
        }
        else if (selection == 10) {
            // logout
            l->logoutAccount(login_user);
            selection = 10;
            cin.ignore();           // use this to eat up the <Space> character (prevent from affecting getline() in the login_screen() function)
            build_UI(pr, user, summary, detailed);
        }
        else if (selection == 11) {
            // exit
        }
        else {
            // Input Validation
            cout << "[X] Input Error! Please Enter the Correct Inputs!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

// Function to build UI
void build_UI(Purchase_Records_Linked_List* pr, User_Linked_List* user, Summary_Reports_Linked_List* summary, Detailed_Reports_Linked_List* detailed) {
    user->obtain_users_list();

    welcome_screen();
    if (login_screen(user)) {
        clear_screen();
        login_user->set_purchase_records_linked_list(pr);
        login_user->set_summary_reports_linked_list(summary);
        login_user->set_detailed_reports_linked_list(detailed);

        if (login_user->get_role() == "sale") {
            executives_screen(login_user->get_user_full_name(), pr, user, summary, detailed);
        }
        else if (login_user->get_role() == "admin") {
            admin_screen(login_user->get_user_full_name(), pr, user, summary, detailed);
        }
    }
    else {
        build_UI(pr, user, summary, detailed);
    }
}

#endif
