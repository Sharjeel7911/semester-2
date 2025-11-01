#include <iostream>
#include <fstream>
using namespace std;

void capital();
void ready();
void count(char array[], int& count);
void write(const char word[], int x);
bool already(const char array[]);

void task4() {
	fstream clear("Word Frequency.txt", ios::out);
	clear.close();

	capital();
	ready();
	remove("Temp Sentence.txt");
}

void capital() {
	fstream check("Sentence.txt", ios::in);
	fstream write("Temp Sentence.txt", ios::out);
	if (!check || !write) {
		cout << "Error: 'Sentence.txt' not found." << endl;
		system("pause");
		return;
	}

	char word[100] = {};
	while (check >> word) {
		for (int i = 0; word[i] != '\0'; i++) {
			if (word[i] >= 'a' && word[i] <= 'z') {
				word[i] -= 32;
			}
		}
		write << word << " ";
	}

	check.close();
	write.close();
}
void ready() {
	fstream read("Temp Sentence.txt", ios::in);
	if (read) {
		char wordx[100] = {};
		char word[100] = {};
		while (read >> wordx) {
			int length = 0;
			while (wordx[length] != '\0') {
				length++;
			}

			if ((wordx[length - 1] == ',') || (wordx[length - 1] == '.') || (wordx[length - 1] == '?') || (wordx[length - 1] == '!')) {
				length--;
			}
			int i;
			for (i = 0; i < length; i++) {
				word[i] = wordx[i];
			}
			word[i] = '\0';

			if (!already(word)) {
				int wordCount = 0; 
				count(word, wordCount);
				if (wordCount > 0) {
					write(word, wordCount);
				}
			}
		}
		read.close();
		cout << "The word frequency is written in 'Word Frequency.txt'." << endl;
	}
	else {
		cout << "'Sentence.txt' not found." << endl;
		system("pause");
	}
}
void count(char array[], int& count) {
	fstream read("Temp Sentence.txt", ios::in);
	if (!read) {
		return;
	}
		char wordx[100] = {};
		char word[100] = {};
		count = 0;

		while (read >> wordx) {
			int length = 0;
			while (wordx[length] != '\0') {
				length++;
			}

			if ((wordx[length - 1] == ',') || (wordx[length - 1] == '.') || (wordx[length - 1] == '?') || (wordx[length - 1] == '!')) {
				length--;
			}

			for (int i = 0; i < length; i++) {
				word[i] = wordx[i];
			}
			word[length] = '\0';

			bool match = true;
			int j;
			for (j = 0; array[j] != '\0' && word[j] != '\0'; j++) {
				if (array[j] != word[j]) {
					match = false;
					break;
				}
			}
			if (array[j] != '\0' || word[j] != '\0') {
				match = false;
			}
			if (match) {
				count++;
			}
		}
		read.close();
}
bool already(const char array[]) {
	fstream	read("Word Frequency.txt", ios::in);
	if (!read) {
		return false;
	}
	char wordx[100] = {};
	char word[100] = {};
	while (read >> wordx) {
		int length = 0;
		while (wordx[length] != '\0') {
			length++;
		}

		if ((wordx[length - 1] == ',') || (wordx[length - 1] == '.') || (wordx[length - 1] == '?') || (wordx[length - 1] == '!')) {
			length--;
		}
		for (int i = 0; i < length; i++) {
			word[i] = wordx[i];
		}
		word[length] = '\0';

		bool match = true;
		int j;
		for (j = 0; array[j] != '\0' && word[j] != '\0'; j++) {
			if (array[j] != word[j]) {
				match = false;
				break;
			}
		}
		if (array[j] != '\0' || word[j] != '\0') {
			match = false;
		}
		if (match) {
			read.close();
			return true;
		}
	}
	read.close();
	return false;
}
void write(const char word[], int x) {
	fstream write("Word Frequency.txt", ios::app);
		if (write) {
			write << word << " - " << x << endl;
			write.close();
		}
}