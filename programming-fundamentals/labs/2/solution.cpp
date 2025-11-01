#include <iostream>
#include <fstream>
using namespace std; 

int main1() {
	ofstream write;

	write.open("output.txt", ios::out);
	if (write.is_open()) {
		write << "Hello, World!";
		write.close();
	}
	cout << "Text 'Hello,World!' is written in the file 'output.txt' successfully" << endl;
	return 0;
}

int main2() {
	ofstream write;
	write.open("user_data.txt", ios::out);
	if (write.is_open()) {
		cout << "Enter your name." << endl;
		char name[20];
		cin.getline(name,20);
		write << "Name: " << name << endl;
		cout << "Enter your age." << endl;
		int age = 0;
		cin >> age;
		write << "Age: " << age;
		write.close();
	}
	cout << "User data saved to 'user_data.txt' successfully!";
	return 0;
}

int main3() {
	ofstream write;

	write.open("data.txt", ios::out);
	if (write.is_open()) {
		write << "a quick brown fox jumps over the lazy dog." << endl;
		write << "A QUICK BROWN FOX JUMPS OVER THE LAZY DOG." << endl;
		write << "! @ # $ % ^ & * ( )" << endl;
		write.close();
	}
	cout << "Message written to 'data.txt' successfully!";

	return 0;
}

int main4() {
	ofstream write;
	write.open("log.txt", ios::app);
	if (write.is_open()) {
		write << endl;
		write << "This is a new entry.";
		write.close();
	}
	cout << "File 'log.txt' appended successfully." << endl;
	return 0;
}

int main5() {
	ofstream write1;
	ofstream write2;

	write1.open("Name.txt", ios::out);
	write2.open("Age.txt", ios::out);

	if (write1.is_open() && write2.is_open()) {
		cout << "Enter your name." << endl;
		char name[20];
		cin.getline(name, 20);
		write1 << "Name: " << name << endl;

		cout << "Enter your age." << endl;
		int age = 0;
		cin >> age;
		write2 << "Age: " << age;
		write1.close();
		write2.close();
	}
	cout << "Name and Age are saved in two different files successfully." << endl;
	return 0;
}