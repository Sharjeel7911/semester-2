#include <iostream>
#include <fstream>
using namespace std;

void task1();
void task2();
void task3();
void task4();
void task5();

int main() {
    char choice;
    do {
        system("cls");
        cout << "*** Main Menu ***" << endl;
        cout << "1. Task 1" << endl;
        cout << "2. Task 2" << endl;
        cout << "3. Task 3" << endl;
        cout << "4. Task 4" << endl;
        cout << "5. Task 5" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1': task1(); break;
        case '2': task2(); break;
        case '3': task3(); break;
        case '4': task4(); break;
        case '5': task5(); break;
        case '6': cout << "Thank you for using the program!" << endl; break;
        default: cout << "Invalid choice. Please try again." << endl;
        }

        if (choice != '6') {
            cout << endl << "Press Enter to return to Main Menu...";
            cin.ignore();
            cin.get();
        }

    } while (choice != '6');

    return 0;
}