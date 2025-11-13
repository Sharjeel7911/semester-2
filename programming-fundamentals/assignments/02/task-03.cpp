#include <iostream>
#include <fstream>
using namespace std;

void readx();
void spellcheck(char array[]);
void dictionaryspell();

void task3() {
	dictionaryspell();
	readx();
}

void dictionaryspell() {
	fstream check("Dictionary.txt", ios::in);
	fstream write("Update.txt", ios::out);
	if (!check || !write) {
		cout << "Error: 'Dictionary.txt' not found." << endl;
		return;
	}

	char word[100] = {};
	while (check >> word) {
		for (int i = 0; word[i] != '\0'; i++) {
			if (word[i] >= 'a' && word[i] <= 'z') {
				word[i] -= 32;
			}
		}
		write << word << endl;
	}

	check.close();
	write.close();
	remove("Dictionary.txt");
	(void)rename("Update.txt", "Dictionary.txt");
}
void readx() {
	fstream read("Input.txt", ios::in);
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
			for (int i = 0; word[i] != '\0'; i++) {
				if (word[i] >= 'a' && word[i] <= 'z') {
					word[i] -= 32;
				}
			}
			spellcheck(word);
		}
		read.close();
	}
	else {
		cout << "'Input.txt' not found." << endl;
	}
}
void spellcheck(char array[]) {
	fstream check("Dictionary.txt", ios::in);
	if (check) {
		char word[100] = {};
		bool found = false;
		while (check >> word) {
			int i = 0;
			bool match = true;
			while (array[i] != '\0' && word[i] != '\0') {
				if (array[i] != word[i]) {
					match = false;
					break;
				}
				i++;
			}
			if (array[i] == '\0' && word[i] == '\0' && match) {
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Misspelled Word: " << array << endl;
		}

		check.close();
	}
	else {
		cout << "'Dictionary.txt' not found." << endl;
	}
}