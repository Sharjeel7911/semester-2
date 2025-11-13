#include <iostream>
#include <fstream>
#include <iomanip>  
using namespace std;

//Task 1

int main1() {

	fstream read("Sample.txt", ios::in);
	fstream write("Result.txt", ios::out);
	if (!read.is_open() || !write.is_open()) {
		cout << "Error while opening the file." << endl;
		return 1;
	}

	char name[50];
	char id[50];
	float ass;
	float quiz;
	float mid;
	float final;
	float percetage;

	while (read.getline(name, 50, ',')) {
		read >> ws;
		read.getline(id, 50, ',');
		read >> ass;
		read.ignore();
		read >> quiz;
		read.ignore();
		read >> mid;
		read.ignore();
		read >> final;
		read.ignore();

		percetage = ((ass + quiz + mid + final) / 115) * 100;

		if (percetage >= 85 && percetage <= 100) {
			write << name << ", " << id << ", " << percetage << "%, " << "A";
		}
		else if (percetage >= 80 && percetage <= 84) {
			write << name << ", " << id << ", " << percetage << "%, " << "A-";
		}
		else if (percetage >= 75 && percetage <= 79) {
			write << name << ", " << id << ", " << percetage << "%, " << "B+";
		}
		else if (percetage >= 70 && percetage <= 74) {
			write << name << ", " << id << ", " << percetage << "%, " << "B";
		}
		else if (percetage >= 65 && percetage <= 69) {
			write << name << ", " << id << ", " << percetage << "%, " << "B-";
		}
		else if (percetage >= 60 && percetage <= 64) {
			write << name << ", " << id << ", " << percetage << "%, " << "C+";
		}
		else if (percetage >= 55 && percetage <= 59) {
			write << name << ", " << id << ", " << percetage << "%, " << "C";
		}
		else if (percetage >= 50 && percetage <= 54) {
			write << name << ", " << id << ", " << percetage << "%, " << "C-";
		}
		else if (percetage < 50) {
			write << name << ", " << id << ", " << percetage << "%, " << "F";
		}
	}
	read.close();
	write.close();
	cout << "Grades have been successfully saved in 'Result.txt'" << endl;

	return 0;
}

//Task 2 

int main2() {
	fstream read;
	fstream write;
	read.open("word_frequency.txt", ios::in);
	write.open("word_length.txt", ios::out);
	if (!read.is_open() || !write.is_open()) {
		cout << "Error while opening the file." << endl;
		return 1;
	}

	char word[50];
	char newword[50] = {};
	char maxword[200] = {};
	int max = 0;

	while (read >> word) {
		int length = 0;
		int count = 0;

		while (word[length] != '\0') {
			if ((word[length] >= 'a' && word[length] <= 'z') || (word[length] >= 'A' && word[length] <= 'Z')) {
				newword[count] = word[length];
				count++;
			}
			length++;
		}
		newword[count] = '\0';

		if (count > max) {
			max = count;
			int i = 0;
			while (newword[i] != '\0') {
				maxword[i] = newword[i];
				i++;
			}
			maxword[i] = '\0';
		}
		else if (count == max) {
			int i = 0, j = 0;
			while (maxword[j] != '\0') {
				j++;
			}
			maxword[j++] = ',';
			maxword[j++] = ' ';

			while (newword[i] != '\0') {
				maxword[j++] = newword[i++];
			}
			maxword[j] = '\0';
		}

		write << newword << ", " << count << endl;
	}
	cout << "Longest word(s): " << maxword << ", " << max << " characters" << endl;

	write.close();
	read.close();
	return 0;
}

//Task 3
//Deleted file and Not found
int main() {

	while (true) {
		char choice;

		while (true) {
			cout << endl << "      ***** Welcome to SHARJEEL'S Database *****      " << endl << endl;
			cout << "Press S: Add more 5 records in the file with existing file format." << endl;
			cout << "Press P: Print all records on console.  " << endl;
			cout << "Press E: Find the employee which has max salary on the console. " << endl;
			cout << "Press D: Department wise searching." << endl;
			cout << "Press R: Write all the record into another file except the one who is going to leave the department." << endl;
			cout << "Press X: exit." << endl;
			cin >> choice;
			cin.ignore();

			if (choice == 'S' || choice == 's' || choice == 'P' || choice == 'p' || choice == 'E' || choice == 'e' || choice == 'D' || choice == 'd' || choice == 'R' || choice == 'r' || choice == 'X' || choice == 'x')
			{
				break;
			}
			else {
				cout << "Invalid department number. Please choose again." << endl;
			}
		}

		if (choice == 'S' || choice == 's') {
			fstream read("Employee.txt", ios::in);
			int counter = 0;

			if (read.is_open()) {
				char line[100];
				while (read.getline(line, 100)) {
					counter++;
				}
				read.close();
			}


			fstream write("Employee.txt", ios::app);
			if (!write.is_open()) {
				cout << "Error while opening the file." << endl;
				return 1;
			}

			char name[50];
			float salary;
			char dept[50];


			for (int i = 1; i <= 5; i++) {
				cout << endl;
				int id = counter + i;
				cout << "Enter " << i;

				if (i == 1) cout << "st";
				else if (i == 2) cout << "nd";
				else if (i == 3) cout << "rd";
				else cout << "th";

				cout << " employee's name" << endl;
				cin.ignore();
				cin.getline(name, 50);
				if (name[0] >= 'a' && name[0] <= 'z') {
					name[0] = name[0] - 32;
				}

				cout << "Enter salary" << endl;
				cin >> salary;
				cin.ignore();

				cout << "Enter department" << endl;
				cin.getline(dept, 50);
				int j = 0;
				while (dept[j] != '\0') {
					if (dept[j] >= 'a' && dept[j] <= 'z') {
						dept[j] -= 32;
					}
					j++;
				}
				write << id << ". " << name << ", " << salary << ", " << dept << endl;
			}
			write.close();
			cout << "Five more records are successfully added to database." << endl << endl;
		}

		else if (choice == 'P' || choice == 'p') {
			fstream read("Employee.txt", ios::in);
			if (!read.is_open()) {
				cout << "Error while opening the file." << endl;
				return 1;
			}
			char header[100];
			read.getline(header, 100);
			cout << left << setw(6) << "ID" << setw(24) << "Name" << setw(21) << "Salary" << setw(20) << "Department" << endl;

			int id;
			char name[20];
			char dept[20];
			int salary = 0;

			while (read >> id) {
				read.ignore();
				read.getline(name, 20, ',');
				read >> salary;
				read.ignore();
				read.getline(dept, 20);
				cout << left << setw(5) << id << setw(25) << name << setw(20) << salary << setw(20) << dept << endl;
			}
			read.close();
		}

		else if (choice == 'E' || choice == 'e') {
			fstream read("Employee.txt", ios::in);
			if (!read.is_open()) {
				cout << "Error while opening the file." << endl;
				return 1;
			}

			int max = 0;
			int id;
			int salary;
			char header[100];
			char name[50];
			char nname[200] = {};
			char dept[50];

			read.getline(header, 100);
			while (read >> id) {
				read.ignore();
				read.getline(name, 50, ',');
				read >> salary;
				read.ignore();

				if (salary > max) {
					max = salary;
					int i = 0;
					while (name[i] != '\0') {
						nname[i] = name[i];
						i++;
					}
					nname[i] = '\0';
				}

				else if (salary == max) {
					int i = 0, j = 0;
					while (nname[j] != '\0') {
						j++;
					}
					nname[j++] = ',';
					nname[j++] = ' ';
					while (name[i] != '\0') {
						nname[j++] = name[i++];
					}
					nname[j] = '\0';
				}


				read.getline(dept, 50);
			}
			cout << "The employee with the highest salary in the database is/are: " << nname << endl;
			cout << "Maximum salary: Rs. " << max << endl;
			read.close();
		}

		else if (choice == 'D' || choice == 'd') {
			char dept[50];
			cout << "Which department do you want to inquire about?" << endl;
			cin.getline(dept, 50);

			int k = 0;
			while (dept[k] != '\0') {
				if (dept[k] >= 'a' && dept[k] <= 'z') {
					dept[k] -= 32;
				}
				k++;
			}

			fstream read("Employee.txt", ios::in);
			if (!read.is_open()) {
				cout << "Error while opening the file." << endl;
				return 1;
			}

			char header[100];
			read.getline(header, 100);

			int salary = 0;
			int id;
			char name[50];
			char ddept[50];
			bool found = false;

			while (read >> id) {
				read.ignore();
				read.getline(name, 50, ',');
				read >> salary;
				read.ignore();
				read >> ws;
				read.getline(ddept, 50);
				read >> ws;

				int x = 0;
				while (ddept[x] != '\0') {
					x++;
				}
				x--;
				while (x >= 0 && ddept[x] == ' ') {
					ddept[x] = '\0';
					x--;
				}


				int j = 0;
				bool isMatched = true;
				while (dept[j] != '\0' && ddept[j] != '\0') {
					if (dept[j] != ddept[j]) {
						isMatched = false;
						break;
					}
					j++;
				}

				if (dept[j] != '\0' || ddept[j] != '\0') {
					isMatched = false;
				}


				if (isMatched) {
					if (!found) {
						cout << "Employees in " << dept << " are listed below" << endl << endl;
						cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(15) << "Salary" << endl;
						found = true;
					}
					cout << left << setw(10) << id << setw(25) << name << setw(15) << salary << endl;
				}
			}

			if (!found) {
				cout << "No employees found in department: " << dept << endl;
			}
			read.close();
		}

		else if (choice == 'R' || choice == 'r') {

			cout << "Enter the ID of employee who is set to leave the department." << endl;
			int id;
			cin >> id;
			cin.ignore();

			fstream readx("EmployeeX.txt", ios::in);
			bool employeeXexists = readx.is_open();
			readx.close();

			char header[100];
			char name[20];
			char dept[20];
			int salary = 0;
			int x;

			if (!employeeXexists) {
				fstream read("Employee.txt", ios::in);
				fstream write("EmployeeX.txt", ios::out);
				if (!read.is_open()) {
					cout << "Error while opening file." << endl;
					return 1;
				}

				read.getline(header, 100);
				write << header << endl;

				while (read >> x) {
					read.ignore();
					read >> ws;
					read.getline(name, 50, ',');
					read >> ws;
					read >> salary;
					read.ignore();
					read >> ws;
					read.getline(dept, 50);

					if (x != id) {
						write << x << ". " << name << ", " << salary << ", " << dept << endl;
						continue;
					}
				}
				read.close();
				write.close();
			}

			else {
				fstream read("EmployeeX.txt", ios::in);
				fstream write("XEmployeeX.txt", ios::out);
				if (!read.is_open() || !write.is_open()) {
					cout << "Error while opening file." << endl;
					return 1;
				}
				read.getline(header, 100);
				write << header << endl;

				while (read >> x) {
					read.ignore();
					read >> ws;
					read.getline(name, 50, ',');
					read >> ws;
					read >> salary;
					read.ignore();
					read >> ws;
					read.getline(dept, 50);
					if (x != id) {
						write << x << ". " << name << ", " << salary << ", " << dept << endl;
						continue;
					}

				}
				read.close();
				write.close();

				fstream ready("XEmployeeX.txt", ios::in);
				fstream writey("EmployeeX.txt", ios::out);
				if (!ready.is_open() || !writey.is_open()) {
					cout << "Error while opening file." << endl;
					return 1;
				}

				char copy[100];
				while (ready.getline(copy, 100)) {
					writey << copy << endl;
				}
				ready.close();
				writey.close();
			}
			cout << "Employee with ID " << id << " has been removed successfully and database is updated." << endl;
		}

		if (choice == 'X' || choice == 'x') {
			cout << "Database closed." << endl;
			cout << "See you Soon ^_~" << endl;
			break;
		}

	}
	return 0;
}