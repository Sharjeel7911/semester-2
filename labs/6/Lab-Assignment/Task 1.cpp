#include <iostream>
#include <fstream>
using namespace std;

void readFromFile(char sentence[]);
int countSpaces(const char sentence[]);
void displayCount(int spaces);

void task1() {
    char sentence[1000];
    readFromFile(sentence);
    int spaces = countSpaces(sentence);
    displayCount(spaces);
}

void readFromFile(char sentence[]) {
    fstream read("Input.txt", ios::in);
    if (read) {
        read.ignore();
        read.getline(sentence, 1000);
        read.close();
    }
    else {
        cout << "Error opening file." << endl;
    }
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
void displayCount(int spaces) {
    cout << "Spaces in the sentence: " << spaces << endl;
}