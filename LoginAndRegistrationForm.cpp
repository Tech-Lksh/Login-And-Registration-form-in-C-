#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void login();
void registration();
void forgot();

int main() {
    int choice;
    while (true) {
        cout << "\t\t\t_______________________________________________________\n\n\n";
        cout << "\t\t\t               Welcome to the login page               \n\n\n";
        cout << "\t\t\t_______________          MENU           _______________\n\n\n";
        cout << "\t| Press 1 to LOGIN                          |\n";
        cout << "\t| Press 2 to REGISTRATION                   |\n";
        cout << "\t| Press 3 if you forgot your PASSWORD       |\n";
        cout << "\t| Press 4 to EXIT                           |\n";
        cout << "\n\t\t\t Please enter your choice : ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                registration();
                break;
            case 3:
                forgot();
                break;
            case 4:
                cout << "\t\t\t Thank you!\n\n\n";
                return 0;
            default:
                system("cls");
                cout << "\t\t\t Please select from the options given above\n" << endl;
        }
    }
    return 0;
}

void login() {
    int count = 0;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter username & password : " << endl;
    cout << "\t\t\t USERNAME: ";
    cin >> userId;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    ifstream input("record.txt");
    while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;
            break;
        }
    }
    input.close();

    if (count == 1) {
        cout << userId << "\nYour LOGIN is successful\nThanks for logging in!\n";
    } else {
        cout << "\nLOGIN ERROR\nPlease check your username and password\n";
    }
}

void registration() {
    string reguserId, regpassword;
    system("cls");
    cout << "\t\t\t Enter the username: ";
    cin >> reguserId;
    cout << "\t\t\t Enter the password: ";
    cin >> regpassword;

    ofstream f1("record.txt", ios::app);
    f1 << reguserId << ' ' << regpassword << endl;
    f1.close();
    system("cls");
    cout << "\n\t\t\t Registration is successful!\n";
}

void forgot() {
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password? No worries\n";
    cout << "Press 1 to search your id by username\n";
    cout << "Press 2 to go back to the main menu\n";
    cout << "\t\t\t Enter your choice: ";
    cin >> option;

    switch (option) {
        case 1: {
            int count = 0;
            string suserId, sId, spass;
            cout << "\n\t\t\t Enter the username which you remembered: ";
            cin >> suserId;

            ifstream f2("record.txt");
            while (f2 >> sId >> spass) {
                if (sId == suserId) {
                    count = 1;
                    cout << "\n\nYour account is found!\n";
                    cout << "\nYour password is: " << spass << endl;
                    break;
                }
            }
            f2.close();
            if (count == 0) {
                cout << "\nSorry! Your account is not found!\n";
            }
            break;
        }
        case 2:
            // Return to main menu
            break;
        default:
            cout << "\t\t\t Wrong choice! Please try again\n";
    }
}