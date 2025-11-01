#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>  
using namespace std;

// First practice. Just opening and closing file and understanding

int main1()
{
	ofstream write;

	write.open("X.txt");

	if (write.is_open()) {
		write << "Absolute cinema" << endl;
		write.close();
	}
	write.open("X.txt", ios::app);

	if (write.is_open()) {
		write << "Peace be upon the broken part in my heart, the one that does not make any noise.";
		write.close();
	}

	ifstream read;
	read.open("X.txt");
	if (read.is_open()) {
		string line;
		while (getline(read, line)) {
			cout << line << endl;
		}
		read.close();
	}
	return 0;
}

//Playing with ASCII

int main2() {
	ofstream write;
	write.open("XX.txt");
	if (write.is_open()) {
		write << "a quick brown fox jumps over the lazy dog" << endl;
		write << "A QUICK BROWN FOX JUMPS OVER THE LAZY DOG" << endl;
		write << "!@#$%^&*()" << endl;
		write.close();
	}

	ifstream read;
	read.open("XX.txt");
	if (read.is_open()) {
		string line;
		while (getline(read, line)) {
			cout << line << endl;
		}
		cout << endl;
		read.clear(); // IMPORTANT
		read.seekg(0);  // IMPORTANT    // IMPORTANT    // IMPORTANT    // IMPORTANT   // IMPORTANT

		char ch;
		while (read.get(ch)) {

			if (ch >= 'A' && ch <= 'Z') {
				cout << char(ch + 32);
			}
			else if (ch >= 'a' && ch <= 'z') {
				cout << char(ch - 32);
			}
			else if (ch == ' ') {
				cout << " ";
			}
			else if (ch == '\n') {
				cout << endl;
			}
			else {
				cout << char(ch + 10) << " ";
			}
		}
		read.close();
	}
	return 0;
}

//Write a C++ program to count the number of lines in a text file

int main3() {
	ofstream write;

	write.open("XXX.txt");

	if (write.is_open()) {
		write << "Absolute cinema" << endl;
		write << "Absolute cinema" << endl;
		write << "Absolute cinema" << endl;
		write << "Absolute cinema" << endl;
		write << "Absolute cinema" << endl;
		write.close();
	}

	ifstream read;
	read.open("XXX.txt");
	if (read.is_open()) {
		string line;
		int count = 0;
		while (getline(read, line)) {
			count++;
		}
		cout << "The number of lines is " << count;
		read.close();
	}


	return 0;
}

//Write a C++ program to count the number of words in a text file

int main4() {
	ofstream write;

	write.open("XXXX.txt");

	if (write.is_open()) {
		write << "Peace be upon the broken part in my heart, the one that does not make any noise.";
		write.close();
	}

	ifstream read;
	read.open("XXXX.txt");
	if (read.is_open()) {
		string word;
		int count = 0;
		while (read >> word) {
			count++;
		}
		cout << "The number of words is " << count;
		read.close();
	}
	return 0;
}

//Write a C++ program to copy the contents of one text file to another

int main5() {
	ofstream write;
	write.open("XXXXX.txt");

	if (write.is_open()) {
		write << "Peace be upon the broken part in my heart, the one that does not make any noise." << endl;
		write << "Peace be upon the broken part in my heart, the one that does not make any noise." << endl;
		write.close();
	}
	ofstream writeX;
	writeX.open("XXXXXX.txt");
	if (writeX.is_open()) {
		ifstream read;
		read.open("XXXXX.txt");
		if (read.is_open()) {
			string line;
			while (getline(read, line)) {
				writeX << line << endl;
			}
			read.close();
		}
		writeX.close();
	}
	return 0;
}

//Write a C++ program to find and replace a specific word in a text file

int main6() {
	ofstream write;
	write.open("XXXXXXX.txt");

	if (write.is_open()) {
		write << "Peace be upon the broken part in my heart, the one that does not make any noise." << endl;
		write.close();
	}

	cout << "Enter the word which is to be replaced." << endl;
	string wordtofind;
	cin >> wordtofind;
	cout << "What wordtofind to replace?" << endl;
	string wordtoreplaceX;
	cin >> wordtoreplaceX;

	ifstream read;
	read.open("XXXXXXX.txt");
	string sentence = "", word;
	if (read.is_open()) {
		while (read >> word) {
			string cleanWord = word; // IMPORTANT   // IMPORTANT   // IMPORTANT   // IMPORTANT  // IMPORTANT
			if (ispunct(cleanWord.back())) {
				cleanWord.pop_back();
			}
			if (cleanWord == wordtofind) {
				sentence += wordtoreplaceX + " ";
			}
			else {
				sentence += word + " ";
			}
		}
		read.close();
	}

	ofstream writeX;
	writeX.open("XXXXXXX.txt");
	if (writeX.is_open()) {
		writeX << sentence;
		writeX.close();
	}
	cout << "Word replacement done! Check the file." << endl;

	return 0;
}

//Write a C++ program to append new data to an existing text file

//Write a program which will write the data into a file “sampleoutput.txt” and print it on the screen. The file contains student’s name, student Fee and department name.

int main71() {
	fstream write;
	write.open("sampleoutput.txt", ios::out);
	int numStudents;
	cout << "Enter the number of students: ";
	cin >> numStudents;
	write << left << setw(25) << "Student Name" << setw(20) << "Student id" << setw(20) << "Department" << endl;
	//IMPORTANT  USE SETW FOR GIVING EQUAL SPACE
	if (write.is_open()) {
		cin.ignore();
		for (int i = 0; i < numStudents; i++) {
			char name[50];
			char dept[50];
			int id;
			cout << "Enter data for " << i + 1 << " student" << endl;
			cout << "Enter student name" << endl;
			cin.getline(name, 50);
			cout << "Enter student id" << endl;
			cin >> id;
			cin.ignore();
			cout << "Enter student department" << endl;
			cin.getline(dept, 50);

			write << left << setw(25) << name << setw(20) << id << setw(20) << dept << endl;
		}
		cout << "Your data is saved successfully" << endl;
		write.close();
	}

	return 0;
}

//Write a program which reads the file sampleIn.txt as given below and display it on the screen.                                            
int main72() {
	fstream read;
	read.open("sampleoutput.txt", ios::in);
	if (!read.is_open()) {
		cout << "Error opening file!" << endl;
		return 1;
	}
	char header[100];
	read.getline(header, 100);
	cout << header << endl;
	char name[50];
	char dept[50];
	int id = 0;
	while (read.getline(name, 50, ',')) {
		read >> id;
		read.ignore();
		read.getline(dept, 50);

		cout << left << setw(25) << name << setw(2) << id << setw(20) << dept << endl;
	}
	read.close();
	return 0;
}

//Write a program which will read from a file “sampleIn.txt” and print it on the screen. The file contains student’s name, student Fee and department name.

int main8() {
	fstream read;
	read.open("sampleIn.txt", ios::in);

	if (!read.is_open()) {
		cout << "Error opening the file" << endl;
		return 1;
	}

	char header[100];
	read.getline(header, 100);
	cout << left << setw(25) << "Name" << setw(10) << "Fee" << setw(20) << "Depatment" << endl;

	char name[20];
	char dept[20];
	int fee = 0;

	while (read.getline(name, 20, ',')) {
		read >> fee;
		read.ignore();
		read.getline(dept, 20);
		cout << left << setw(25) << name << setw(10) << fee << setw(20) << dept << endl;
	}
	read.close();
	return 0;
}

//Write a C++ program in which, asks a c-string name, age and c-string contact number from user. Now insert this information into a file “record.txt” at start.

int main9() {
	fstream write;
	write.open("record.txt", ios::app);
	if (!write.is_open()) {
		cout << "Error" << endl;
		return 1;
	}

	char name[20];
	int age;
	char cont[15];

	cout << "Enter your name" << endl;
	cin.getline(name, 20);
	cout << "Enter your age" << endl;
	cin >> age;
	cin.ignore();
	cout << "Enter your contact number" << endl;
	cin.getline(cont, 15);
	write << endl;
	write << name << ", " << age << ", " << cont;
	cout << "Record saved successfully!" << endl;

	write.close();
	return 0;
}

//Write a program which reads an input file of student’s “samplein2.txt”, add the fee of each student by 4000 and write the result in new file “sampleout2.txt.”

int main10() {
	fstream read;
	fstream write;
	read.open("samplein2.txt", ios::in);
	write.open("sampleout2.txt", ios::out);
	if (!read.is_open()||!write.is_open()) {
		cout << "Error" << endl;
		return 1;
	}
	char header[100];
	char name[50];
	int fee = 0;
	read.getline(header, 100);
	write << header << endl;
	while (read.getline(name, 50, ',')) {
		read >> fee;
		int x = fee + 4000;
		write << name << ",";
		write << x;
	}
	read.close();
	write.close();
	cout << "Processing complete. Check 'sampleout2.txt'" << endl;
	return 0;
}

//Write a program which reads the file sampleIn.txt as given below. use getline() function and display it on the screen and count the number of records present into the sampleln.txt.

int main11() {
	fstream read;
	read.open("samplein3.txt", ios::in);
	if (!read.is_open()) {
		cout << "Error";
		return 1;
	}
	char header[100];
	read.getline(header, 100);
	cout << left << setw(25) << "Name" << setw(13) << "Salary" << setw(20) << "Department" << endl;

	char name[20];
	int salary = 0;
	char dept[20];
	int count = 0;
	while (read.getline(name, 20, ',')) {
		read >> salary;
		read.ignore();


		read.getline(dept, 20);
		cout << left << setw(25) << name << setw(10) << salary << setw(20) << dept << endl;
		count++;
	}
	cout << endl << "The number of records: " << count << endl;
	read.close();

	return 0;
}

//Write a C++ program in which, read a c-string sentence from file sentence.txt at once. Your task is to separate each word into another c-string one by one and store them into a file word.txt.

int main12() {
	fstream read;
	fstream write;
	read.open("sentence.txt", ios::in);
	write.open("word.txt", ios::out);
	if (!read.is_open() || !write.is_open()) {
		cout << "Error";
		return 1;
	}
	char word[50];
	while (read >> word) {
		write << word << endl;
	}
	write.close();
	read.close();
	cout << "Saved successfully" << endl;
	return 0;
}

//Write a C++ program to search the data from the file named "gpa.txt". Print the name who has greater than 3.2 CGPA. 

int main13() {
	fstream read;
	read.open("gpa.txt", ios::in);
	if (!read.is_open()) {
		cout << "Error";
		return 1;
	}
	char header[100];
	read.getline(header, 100);
	char name[50];
	float gpa;
	cout << "Students to get gpa greater than 3.2" << endl;
	while (read.getline(name, 50, ',')) {
		read >> gpa;
		if (gpa > 3.2001) {
			cout << name;
		}
	}
	read.close();
	return 0;
}

//Write a C++ program that reads character by character form data.txt , and replace the character ‘y’ with character ‘a’ in a new file (replace.txt). Note: we don’t know how much data a file has. 

int main14() {
	fstream write;
	fstream read;
	 read.open("data.txt", ios::in);
	 write.open("replace.txt", ios::out);

	if (!read.is_open() || !write.is_open()) {
		cout << "Error opening file!" << endl;
		return 1;
	}
	char ch;
	while (read.get(ch)) { 
		if (ch == 'y' ) {
			ch = 'a';
		}
		else if (ch == 'Y') {
			ch = 'A';
		}
		write << ch;
	}
	read.close();
	write.close();
	cout << "Replacement done! Check 'replace.txt'." << endl;

	return 0;
}