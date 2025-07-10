#include <iostream>
using namespace std;

void getSentence(char sentence[]);
int countVowels(const char sentence[]);
void displayVowelCount(int count);

void task3() {
    char sentence[101]; 
    getSentence(sentence);
    int vowelCount = countVowels(sentence);
    displayVowelCount(vowelCount);
}

void getSentence(char sentence[]) {
    cout << "Enter a sentence: ";
    cin.ignore();
    cin.getline(sentence, 101);
}
int countVowels(const char sentence[]) {
    int count = 0;
    for (int i = 0; sentence[i] != '\0'; i++) {
        char ch = sentence[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++;
        }
    }
    return count;
}
void displayVowelCount(int count) {
    cout << "Number of vowels: " << count << endl;
}