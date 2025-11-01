#include <iostream>
using namespace std;

void inputGrades(int*& grades, int& size) {
    cout << "Enter number of grades: ";
    cin >> size;
    grades = new int[size];
    cout << "Enter grades: ";
    for (int i = 0; i < size; i++) {
        cin >> grades[i];
    }
}

void longestDecreasingSubsequence(int* grades, int size, int& maxLength) {
    maxLength = 1;
    int current = 1;

    for (int i = 1; i < size; i++) {
        if (grades[i] < grades[i - 1]) {
            current++;
            if (current > maxLength)
                maxLength = current;
        }
        else {
            current = 1;
        }
    }
}

void countUniqueConsonants(char* name, int& count) {
    int flags[26] = { 0 };
    count = 0;

    for (int i = 0; name[i] != '\0'; i++) {
        char ch = name[i];

        if (ch >= 'A' && ch <= 'Z')
            ch = ch + 32;

        if (ch >= 'a' && ch <= 'z') {
            if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
                int index = ch - 'a';
                if (flags[index] == 0) {
                    flags[index] = 1;
                    count++;
                }
            }
        }
    }
}

void checkEvenSum(int* grades, int size, bool& isEven) {
    int sum = grades[0] + grades[size - 1];
    isEven = (sum % 2 == 0);
}

void displaySummary(int maxLength, int consonantCount, bool isEven) {
    cout << "\n--- Student Performance Summary ---\n";
    cout << "Longest Decreasing Subsequence Length: " << maxLength << endl;
    cout << "Unique Consonants in Name: " << consonantCount << endl;
    cout << "Sum of First and Last Grades is " << (isEven ? "Even" : "Odd") << endl;
}

int main() {
    int* grades = nullptr;
    int size;

    inputGrades(grades, size);

    char name[100];
    cout << "Enter name: ";
    cin.ignore();
    cin.getline(name, 100);

    int maxLength = 0;
    int consonantCount = 0;
    bool isEven = false;

    longestDecreasingSubsequence(grades, size, maxLength);
    countUniqueConsonants(name, consonantCount);
    checkEvenSum(grades, size, isEven);
    displaySummary(maxLength, consonantCount, isEven);

    delete[] grades;

    return 0;
}
