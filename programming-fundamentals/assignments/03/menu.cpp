#include <iostream>
using namespace std;

void task1();
void task2();

int main() {
    char choice;

    do {
        system("cls");
        cout << "*** Main Menu ***" << endl;
        cout << "1. Task 1" << endl;
        cout << "2. Task 2" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            task1();
            break;
        case '2':
            task2();
            break;
        case '3':
            cout << "Thank you for using the program!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        if (choice != '3') {
            cout << "Press Enter to return to Main Menu...";
            cin.ignore();
            cin.get();
        }
    } while (choice != '3');
    return 0;
}