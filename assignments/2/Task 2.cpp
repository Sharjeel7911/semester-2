#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;

void menux();
bool writex();
void display();
void lowest();
void descending();
void search();

void task2() {
	if (writex()) { 
		menux();    
	}
}

void menux() {
	char choice;
	do {
		system("cls");
		cout << "*** Menu ***" << endl;
		cout << "D: Display all records" << endl;
		cout << "L: Find the roll number who has the lowest marks" << endl;
		cout << "M: Display the result according to marks (descending order)" << endl;
		cout << "R: Search according to Roll number" << endl;
		cout << "5: Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();

		if (choice == 'd' || choice == 'D') {
			system("cls");
			display();
			system("pause");
		}
		else if (choice == 'l' || choice == 'L') {
			system("cls");
			lowest();
			system("pause");
		}
		else if (choice == 'm' || choice == 'M') {
			system("cls");
			descending();
			system("pause");
		}
		else if (choice == 'r' || choice == 'R') {
			system("cls");
			search();
			system("pause");
		}
		else if (choice == '5') {
			cout << "Thank you for using the program!" << endl;
			system("pause");
		}
		else {
			system("cls");
			cout << "Invalid choice. Please try again." << endl;
			system("pause");	
		}
	} while (choice != '5');
}

bool writex() {
	fstream read("Test.txt", ios::in);
	fstream write("Result.txt", ios::out);
	if (read) {
		char roll[100];
		char ch;
		float marks = 0;
		float result = 0;
		write << left << setw(14) << "Roll No" << setw(22) << "Test card" << setw(12) << "Percentage" << setw(7) << "Grade" << endl;

		while (read.getline(roll, 100, ',')) {
			write << roll << ",";
			marks = 0; 
			while (read.get(ch) && ch != '\n') {
				if (ch == ' ') {
					marks += 0;
				}
				else if (ch == 'F') {
					marks -= 1;
				}
				else if (ch == 'T') {
					marks += 2;
				}
				write << ch;
			}
			result = (marks / 40.0) * 100.0;

			write << ", " << left << setw(12) << result;

			if (result >= 90 && result <= 100) {
				write << left << setw(5) << "A" << endl;
			}
			else if (result >= 80 && result <= 89.99) {
				write << left << setw(5) << "B" << endl;
			}
			else if (result >= 70 && result <= 79.99) {
				write << left << setw(5) << "C" << endl;
			}
			else if (result >= 60 && result <= 69.99) {
				write << left << setw(5) << "D" << endl;
			}
			else if (result <= 59.99) {
				write << left << setw(5) << "F" << endl;
			}
		}
		read.close();
		write.close();
		return true; 
	}
	else {
		cout << "'Test.txt' not found." << endl;
		system("pause"); 
		return false;
	}
}
void display() {

	fstream read("Result.txt", ios::in);
	if (read) {
		char header[100];
		read.getline(header, 100);
		cout << header << endl;
		char roll[20];
		char card[30];
		char ch[10];
		float marks = 0;
		while (read.getline(roll, 20, ',')) {
			read >> ws;
			read.getline(card, 30, ',');
			read >> ws;
			read >> marks;
			read >> ws;
			read.getline(ch, 10);
			cout << left << setw(14) << roll << setw(22) << card << setw(12) << marks << setw(7) << ch << endl;
		}
		read.close();
	}
	else {
		cout << "'Result.txt' not found." << endl;
	}
}
void lowest() {
	fstream read("Result.txt", ios::in);
	if (read) {
		char header[100];
		read.getline(header, 100);

		char roll[20];
		char lowest[20] = {};
		char card[30];
		char ch[10];
		float min = 101;
		float marks = 0;

		while (read.getline(roll, 20, ',')) {
			read >> ws;
			read.getline(card, 30, ',');
			read >> ws;
			read >> marks;
			read.ignore(100, '\n');

			if (marks < min) {
				min = marks;

				int i = 0;
				while (roll[i] != '\0') {
					lowest[i] = roll[i];
					i++;
				}
				lowest[i] = '\0';
				read.ignore();
			}
		}
		cout << "The roll number with the lowest marks is: " << lowest << " with " << min << " %" << endl;
		read.close();
	}
	else {
		cout << "'Result.txt' not found." << endl;
	}
}
void descending() {
	fstream read("Result.txt", ios::in);
	if (read) {
		char header[100];
		read.getline(header, 100); 

		char roll[20];
		char card[30];
		char grade[10];
		float marks[200]; 
		int order[200];   

		float percentage;

		int i = 0;
		while (read.getline(roll, 20, ',') && i < 160) {
			read >> ws;
			read.getline(card, 30, ',');
			read >> ws;
			read >> percentage;
			read >> ws;
			read.getline(grade, 10);

			marks[i] = percentage;
			order[i] = i;          
			i++;
		}
		read.close();

		for (int j = 0; j < i - 1; j++) {
			for (int k = 0; k < i - j - 1; k++) {
				if (marks[order[k]] < marks[order[k + 1]]) {
					int temp = order[k];
					order[k] = order[k + 1];
					order[k + 1] = temp;
				}
			}
		}

		cout << "The result in descending order is: " << endl << endl;
		cout << left << setw(14) << "Roll No" << setw(22) << "Test card" << setw(12) << "Percentage" << setw(7) << "Grade" << endl;

		for (int j = 0; j < i; j++) {
			fstream read("Result.txt", ios::in);
			read.getline(header, 100); 

			int index = order[j]; 

			for (int k = 0; k <= index; k++) {
				read.getline(roll, 20, ',');
				read >> ws;
				read.getline(card, 30, ',');
				read >> ws;
				read >> percentage;
				read >> ws;
				read.getline(grade, 10);
			}

			cout << left << setw(14) << roll << setw(22) << card << setw(12) << percentage << setw(7) << grade << endl;
			read.close();
		}
	}
	else {
		cout << "'Result.txt' not found." << endl;
	}
}
void search() {
	fstream read("Result.txt", ios::in);
	if (read) {
		char header[100];
		read.getline(header, 100);

		char roll[20];
		char search[20];
		char card[30];
		char ch[10];
		float marks = 0;
		bool found = false;

		cout << "Enter the roll number you want to search: ";
		cin >> search;
		for (int i = 0; search[i] != '\0'; i++) {
			if (search[i] >= 'a' && search[i] <= 'z') {
				search[i] -= 32;
			}
		}
		while (read.getline(roll, 20, ',')) {
			read >> ws;
			read.getline(card, 30, ',');
			read >> ws;
			read >> marks;
			read >> ws;
			read.getline(ch, 10);

			bool match = true;

			int j = 0;
			while (roll[j] != '\0' && search[j] != '\0') {
				if (roll[j] != search[j]) {
					match = false;
					break;
				}
				j++;
			}
			if (roll[j] != search[j]) {
				match = false;
			}
			if (match) {
				found = true;
				cout << endl;
				cout << left << setw(14) << "Roll No" << setw(22) << "Test card" << setw(12) << "Percentage" << setw(7) << "Grade" << endl;
				cout << left << setw(14) << roll << setw(22) << card << setw(12) << marks << setw(7) << ch << endl;
				break;
			}
			if (!match) {
				continue;
			}
		}
		read.close();
		if (!found) {
			cout << "Record not found." << endl;
		}
	}
		else {
			cout << "'Result.txt' not found." << endl;
		}
}