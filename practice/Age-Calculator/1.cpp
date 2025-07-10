#include<iostream>
using namespace std;

int DaysInAMonth(int month, int year);
bool IsLeapYear(int year);
bool IsValidYearInDate(int year);
bool IsValidMonthInDate(int month);
bool IsValidDaysInDate(int day, int month, int year);
bool IsValidDate(int dob,int mob,int yob);
bool IsValidDateOfDeath(int dob,int mob,int yob,int dod,int mod,int yod);
void CalculateAgeAndDisplay(int dob,int mob,int yob,int dod,int mod,int yod);

void task1() {
	int dob, mob, yob, dod, mod, yod;
	cout << "Enter the date of birth (dd mm yyyy): " << endl;
	cin >> dob >> mob >> yob;
	cout << "Enter the date of death (dd mm yyyy): " << endl;
	cin >> dod >> mod >> yod;

	while (!IsValidDate(dob, mob, yob) || !IsValidDateOfDeath(dob, mob, yob, dod, mod, yod)) {
		cout << "Invalid date of birth or date of death." << endl;
		cout << "Enter the date of birth (dd mm yyyy): " << endl;
		cin >> dob >> mob >> yob;
		cout << "Enter the date of death (dd mm yyyy): " << endl;
		cin >> dod >> mod >> yod;
	}
	CalculateAgeAndDisplay(dob, mob, yob, dod, mod, yod);
}

int DaysInAMonth(int month,int year) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 31;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else if (month == 2) {
		if (IsLeapYear(year)) {
			return 29;
		}
		else {
			return 28;
		}
	}
	else {
		return -1;
	}
}
bool IsLeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool IsValidYearInDate(int year) {
	if (year < 1) {
		return false;
	}
	else {
		return true;
	}
}
bool IsValidMonthInDate(int month) {
	if (month > 0 && month <= 12) {
		return true;
	}
	else {
		return false;
	}
}
bool IsValidDaysInDate(int day, int month, int year) {
	if (day > 0 && day <= DaysInAMonth(month, year)) {
		return true;
	}
	else {
		return false;
	}
}
bool IsValidDate(int dob, int mob, int yob){
	return IsValidYearInDate(yob) && IsValidMonthInDate(mob) && IsValidDaysInDate(dob, mob, yob);
}
bool IsValidDateOfDeath(int dob, int mob, int yob, int dod, int mod, int yod){
	if (!IsValidDate(dob, mob, yob) || !IsValidDate(dod, mod, yod)) {
		return false;
	}

	if (yod < yob) {
		return false;
	}
	if (yob == yod) {
		if (mob > mod) {
			return false;
		}
		if (mod == mob && dod < dob) {
			return false;
		}
	}
	return true;
}
void CalculateAgeAndDisplay(int dob, int mob, int yob, int dod, int mod, int yod) {
	if (IsValidDate(dob, mob, yob) && IsValidDateOfDeath(dob, mob, yob, dod, mod, yod)) {
		int Years = yod - yob;
		int Months = mod - mob;
		int Days = dod - dob;
	
		if (Days < 0) {
			mod -= 1;
			if (mod == 0) {
				mod = 12;	
				yod -= 1;
			}
			Days += DaysInAMonth(mod, yod);
			Months--;
		}
		if (Months < 0) {
			Months += 12;
			Years--;
		}

		cout << endl << "----------------------------" << endl;
		cout << "Age at death:\n";
		cout << Years << " years, " << Months << " months, " << Days << " days" << endl;
		cout << "----------------------------" << endl;
	}
	else {
		cout << "Invalid date of birth or date of death." << endl;
	}
}