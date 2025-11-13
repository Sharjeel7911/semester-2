#include <iostream>
#include <fstream>
using namespace std;

//Task 1

int main1() {
	fstream read;
	read.open("data.txt", ios::in);
	if (!read.is_open()) {
		cout << "Error opening the file" << endl;
		return 1;
	}
	char header[100];
	read.getline(header, 100, '\n');
	cout << "Header: " << header;
	read.close();
	return 0;
}

//Task 2

int main2() {
	fstream read;
	read.open("input.txt", ios::in);
	if (!read.is_open()) {
		cout << "Error opening the file" << endl;
		return 1;
	}
	char array[200];
	read.get(array, 200);
	cout << "Array read character by character: " << array << endl;
	read.close();
	return 0;
}

//Task 3

int main3() {
	fstream read;
	read.open("text.txt", ios::in);
	if (!read.is_open()) {
		cout << "Error opening the file" << endl;
		return 1;
	}
	char array[200];
	int count = 0;
	while (read.getline(array, 200)) {
		count++;
	}
	cout << "Number of lines in the file: " << count << endl;
	read.close();
	return 0;

}

//Task 4

int main4() {
	fstream write;
	
	write.open("source.txt",ios::out);
	if (write.is_open()) {
		write << "https://wira.adem.my.id/?source=youtube&title=UrIFS3ffJU&type=mp4&download=aHR0cHM6Ly9ocmVmLmxpLz9odHRwczovL3ZkNDA3Lm9rY2RuLnJ1Lz9leHBpcmVzPTE3NDI4MDMxMzk0Mzcmc3JjSXA9MTkzLjE2MC43OS4xMiZwcj0xMCZzcmNBZz1DSFJPTUUmbXM9NDUuMTM2LjIwLjQwJnR5cGU9MyZzdWJJZD02NjQyMTY3MzE5MDg3JnNpZz0waE56VHUzYy1ZbyZjdD0wJnVybHM9NDUuMTM2LjIyLjQ5JmNsaWVudFR5cGU9MCZpZD02NjQyMTY3MzE5MDg3" << endl;
		write.close();
	}

	fstream read;
	fstream destination;
	destination.open("destination.txt", ios::out);
	read.open("source.txt", ios::in);
	if (!read.is_open() || !destination.is_open()) {
		cout << "Error opening the file" << endl;
		return 1;
	}
	char array[200];
	read.getline(array, 200);
	destination << array;
	read.close();
	destination.close();

	cout << "The content of 'source.txt' is successfully copied to 'destination.txt'" << endl;

	return 0;
}

//Task 5

int main5() {
	fstream read;
	read.open("data1.txt", ios::in);
	if (!read.is_open()) {
		cout << "Error opening the file" << endl;
		return 1;
	}
	char ch;
	read.get(ch);
	if (fread) { 
		cout << "First character in file: " << ch << endl;
	}
	else {
		cout << "File is empty or an error occurred!" << endl;
	}
	read.close();
	return 0;
}