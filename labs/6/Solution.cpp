#include<iostream>
#include<fstream>
using namespace std;

void readFromFile(char sentence[]);
int countVowels(const char sentence[]);
int countConsonants(const char sentence[]);
int countDigits(const char sentence[]);
int countSpaces(const char sentence[]);
void displayStats(int vowels, int consonants, int digits, int spaces);


int main() {
    char sentence[100];

    readFromFile(sentence);
    int vowels = countVowels(sentence);
    int consonants = countConsonants(sentence);
    int digits = countDigits(sentence);
    int spaces = countSpaces(sentence);

    displayStats(vowels, consonants, digits, spaces);

    return 0;
}

void readFromFile(char sentence[]) {
	fstream read("Input.txt",ios::in);
	if (read) {
		read.ignore(); 
		read.getline(sentence, 100);
		read.close();
	}
	else {
		cout << "Error opening file." << endl;
	}
}
int countVowels(const char sentence[]) {
	int count = 0;
	for (int i = 0; sentence[i] != '\0'; i++) {
		if (sentence[i] == 'a' || sentence[i] == 'A' || sentence[i] == 'e' || sentence[i] == 'E' || sentence[i] == 'i' || sentence[i] == 'I' || sentence[i] == 'o' || sentence[i] == 'O' || sentence[i] == 'u' || sentence[i] == 'U') {
			count++;
		}
	}
	return count;
}
int countConsonants(const char sentence[]) {
	int count = 0;
	for (int i = 0; sentence[i] != '\0'; i++) {
		if ((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z')) {
			if (!(sentence[i] == 'a' || sentence[i] == 'A' || sentence[i] == 'e' || sentence[i] == 'E' || sentence[i] == 'i' || sentence[i] == 'I' || sentence[i] == 'o' || sentence[i] == 'O' || sentence[i] == 'u' || sentence[i] == 'U')) {
				count++;
			}
		}
	}
	return count;
}
int countDigits(const char sentence[]) {
	int count = 0;
	for (int i = 0; sentence[i] != '\0'; i++) {
		if (sentence[i] >= '0' && sentence[i] <= '9') {
			count++;
		}
	}
	return count;
}
int countSpaces(const char sentence[]) {
	int count = 0;
	for (int i = 0; sentence[i] != '\0'; i++) {
		if (sentence[i] == ' ') {
			count++;
		}
	}
	return count;
}
void displayStats(int vowels, int consonants, int digits, int spaces) {
	cout << "Vowels: " << vowels << endl;
	cout << "Consonants: " << consonants << endl;
	cout << "Digits: " << digits << endl;
	cout << "Spaces: " << spaces << endl;
	cout << "Total characters: " << (vowels + consonants + digits + spaces) << endl;
}