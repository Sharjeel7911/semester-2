#include<iostream>
using namespace std;	

int DaysInMonth(int month, int years);
int DaysInYear(int year);
int DaysBetweenYears(int startYear, int endYear);
int DaysBetweenMonths(int startMonth, int endMonth, int year);
int DayOfWeek(int day, int month, int year);
bool validdate(int d, int m, int y);	
bool isLeapYear(int years);

void menu();    
void x();   // For 14 August 1947
void y();   // For user-entered date

void task2() {
	menu(); 
}

void menu() {
	int choice;

	cout << "===== Menu =====\n";
	cout << "1. Show the day of the week on 14 August 1947\n";
	cout << "2. Enter any date to find its day of the week\n";
	cout << "Enter your choice (1 or 2): ";
	cin >> choice;

	if (choice == 1) {
		x();
	}
	else if (choice == 2) {
		y();
	}
	else {
		cout << "Invalid choice.\n";
	}
}

void x() {
	int d = 14, m = 8, y = 1947;
	int DayofWeeekIndex = DayOfWeek(d, m, y);

	cout << "14 August 1947 was: ";
	switch (DayofWeeekIndex) {
	case 1: cout << "Sunday"; break;
	case 2: cout << "Monday"; break;
	case 3: cout << "Tuesday"; break;
	case 4: cout << "Wednesday"; break;
	case 5: cout << "Thursday"; break;
	case 6: cout << "Friday"; break;
	case 7: cout << "Saturday"; break;
	}
	cout << endl;
}
void y() {
	int d = 0, m = 0, y = 0;
	cout << "Enter the date (day month year): ";
	cin >> d >> m >> y;
	while (!validdate(d, m, y)) {
		cout << "Invalid Input...\nEnter the date again: ";
		cin >> d >> m >> y;
	}

	int DayofWeeekIndex = DayOfWeek(d, m, y);

	cout << "The day on " << d << "/" << m << "/" << y << " was: ";
	switch (DayofWeeekIndex) {
	case 1: cout << "Sunday"; break;
	case 2: cout << "Monday"; break;
	case 3: cout << "Tuesday"; break;
	case 4: cout << "Wednesday"; break;
	case 5: cout << "Thursday"; break;
	case 6: cout << "Friday"; break;
	case 7: cout << "Saturday"; break;
	}
	cout << endl;
}

bool validdate(int d, int m, int y) {
	if (d < 1 || d > DaysInMonth(m, y) || m < 1 || m > 12) {
		return false;
	}
	else
		return true;
}
int DayOfWeek(int day, int month, int year) {
	int DaysInYears = DaysBetweenYears(1, year);
	int DaysInMonths = DaysBetweenMonths(1, month, year);
	int DayNumber = DaysInYears + DaysInMonths + day;
	int DayOfWeekIndex = (DayNumber % 7) + 1;
	return DayOfWeekIndex;
}
int DaysBetweenMonths(int startMonth, int endMonth, int year) {
	int days = 0;
	for (int month = startMonth; month < endMonth; month++) {
		days += DaysInMonth(month, year);
	}
	return days;
}
int DaysBetweenYears(int startYear, int endYear) {
	int days = 0;
	for (int year = startYear; year < endYear; year++) {
		days += DaysInYear(year);
	}
	return days;
}
int DaysInYear(int year) {
	if (isLeapYear(year)) {
		return 366;
	}
	else {
		return 365;
	}
}
int DaysInMonth(int month, int years) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 31;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	if (month == 2) {
		years = isLeapYear(years);
		if (years != 0) {
			return 29;
		}
		else {
			return 28;
		}
	}
}
bool isLeapYear(int years) {

	if (years % 4 == 0 && years % 100 != 0 || years % 400 == 0) {
		return true;
	}
	else
		return false;
}