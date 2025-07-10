#include <iostream>
using namespace std;

void menu();
void sorting();
void compare();
void max();
void count();
bool search();
void strcpy();

void task1() {
	menu();
}

void menu() {
	char choice;
	do {
		system("cls");
		cout << "Welcome to Sharjeel's program." << endl;
		cout << "Enter your choice." << endl;
		cout << "S: Sorting" << endl;
		cout << "C: Compare" << endl;
		cout << "M: Maximum" << endl;
		cout << "X: Count" << endl;
		cout << "Y: Search" << endl;
		cout << "Z: Strcpy" << endl;
		char ch;
		cin >> ch;

		if (ch == 's' || ch == 'S') {
			sorting();
		}
		else if (ch == 'c' || ch == 'C') {
			compare();
		}
		else if (ch == 'm' || ch == 'M') {
			max();
		}
		else if (ch == 'x' || ch == 'X') {
			count();
		}
		else if (ch == 'y' || ch == 'Y') {
			if (search()) {
				cout << "The character is found." << endl;
			}
			else {
				cout << "The character is not found." << endl;
			}
		}
		else if (ch == 'z' || ch == 'Z') {
			strcpy();
		}
		else {
			cout << "Invalid choice." << endl;
		}

		cout << "Do you want to continue? (Y/N)" << endl;
		cin >> choice;
		if (choice == 'n' || choice == 'N') {
			cout << "Thank you for using Sharjeel's program." << endl;
		}
		else if (choice != 'y' && choice != 'Y') {
			cout << "Invalid choice." << endl;
		}
		system("pause");
	} while (choice == 'y' || choice == 'Y');
}

void sorting() {
	cout << "Write any random characters." << endl;
	char array[100];
	cin.ignore();
	cin.getline(array, 100);

	char x[100] = {};
	int k = 0;
	for (int i = 0; array[i] != '\0'; i++) {
		if (array[i] != ' ') {
			x[k++] = array[i];
		}
	}
	x[k] = '\0';

	for (int i = 0; i < k - 1; i++) {
		for (int j = 0; j < k - 1 - i; j++) {
			if (x[j] > x[j + 1]) {
				char temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
			}
		}
	}

	cout << "Sorted alphabeticaly:";
	for (int i = 0; i < k; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}
void compare() {
	char a[100];
	char b[100];
	cout << "Enter the first word." << endl;
	cin >> a;
	cout << "Enter the second word." << endl;
	cin >> b;

	int j = 0;
	while (a[j] != '\0' && b[j] != '\0') {
		if (a[j] >= 'A' && a[j] <= 'Z') {
			a[j] += 32;
		}
		if (b[j] >= 'A' && b[j] <= 'Z') {
			b[j] += 32;
		}
		j++;
	}

	int i = 0;
	bool issame = true;

	while (a[i] != '\0' || b[i] != '\0') {
		if (a[i] != b[i]) {
			issame = false;
			break;
		}
		i++;
	}
	if (issame) {
		cout << "Both words are the same." << endl;
	}
	else {
		cout << "Both words are not same." << endl;
	}
}
void max() {
	int x;
	do {
		cout << "How many values you want to take?" << endl;
		cin >> x;
		if (x <= 0) {
			cout << "Invalid number of values." << endl;
		}
	} while (x <= 0);

	int array[100] = {};
	cout << "Enter the values." << endl;
	for (int i = 0; i < x; i++) {
		cin >> array[i];
	}

	int max = array[0];
	for (int i = 1; i < x; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	cout << "The maximum value is: " << max << endl;
}
void count() {
	//Not considring space as character
	char array[100];
	cout << "Enter a string." << endl;
	cin.ignore();
	cin.getline(array, 100);
	int count = 0;
	for (int i = 0; array[i] != '\0'; i++) {
		if (array[i] != ' ') {
			count++;
		}
	}
	cout << "The number of characters in the string is: " << count << endl;
}
bool search() {
	char array[100];
	cout << "Enter an array." << endl;
	cin.ignore();
	cin.getline(array, 100);
	char search;
	cout << "Enter the character you want to search." << endl;
	cin >> search;
	int i = 0;
	bool found = false;
	while (array[i] != '\0') {
		if (array[i] == search) {
			found = true;
			break;
		}
		i++;
	}
	if (found) {
		return true;
	}
	else {
		return false;
	}
}
void strcpy() {
	char a[100] = {};
	char b[100] = {};
	cout << "Enter the string." << endl;
	cin.ignore();
	cin.getline(a, 100);
	cout << "The original string is: " << a << endl;
	int i = 0;
	while (a[i] != '\0') {
		b[i] = a[i];
		i++;
	}
	b[i] = '\0';
	cout << "The copied string from original string is: " << b << endl;
}