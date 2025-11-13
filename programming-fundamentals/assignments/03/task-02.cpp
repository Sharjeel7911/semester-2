#include <iostream>
#include <conio.h>
using namespace std;

void getPassword(char* password, int size);
bool validatePassword(char* password, int size);
bool isDigit(char ch);
bool isLetter(char ch);

void task2() {
    system("cls");
	cout << "Welcome to American Equities' web page." << endl;

    int size = 8;
    char* password = new char[size];

    do {
        cout << "Enter 8 character password." << endl;
        getPassword(password, size);


        if (validatePassword(password, size)) {
            cout << endl << "Password is valid" << endl;
            break;
        }

        else {
            cout << endl << "Password is invalid" << endl;
            

            cout << "Do you want to try again? (Y/N): ";
            char choice;
            cin >> choice;
            if (choice == 'N' || choice == 'n') {
                cout << "Exiting program." << endl;
                break;
            }   
            system("cls");
        }
    } while (true);

    delete[] password;
}

void getPassword(char* password, int size) {
    char ch;
    int i = 0;

    while (true) {
        ch = _getch();
        if (ch == 13) {
            break;
        }

        else if (ch == 8 && i > 0) {
            cout << "\b \b";
            i--;
        }
        else if (ch >= 32 && ch <= 126 && i < 8) {
            *(password + i) = ch;
            cout << '*';
            i++;
        }
    }
}
bool validatePassword(char* password, int size) {
    int letterCount = 0;
    int digitCount = 0;

    for (int i = 0; i < size; i++) {
        char ch = *(password + i);
        if (isDigit(ch))
            digitCount++;
        else if (isLetter(ch))
            letterCount++;
        else
            return false; 
    }

    return (letterCount >= 5 && digitCount >= 3);
}
bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}
bool isLetter(char ch) {
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}