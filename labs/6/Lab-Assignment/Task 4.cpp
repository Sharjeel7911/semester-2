#include <iostream>
using namespace std;

void inputArray(int arr[], int size);
int searchIndex(int arr[], int size, int number);
void displayResult(int index);

void task4() {
    int arr[10];
    inputArray(arr, 10);

    int number;
    cout << "Enter number to search: ";
    cin >> number;

    int index = searchIndex(arr, 10, number);
    displayResult(index);
}

void inputArray(int arr[], int size) {
    cout << "Enter 10 numbers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}
int searchIndex(int arr[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == number) {
            return i;
        }
    }
    return -1;
}
void displayResult(int index) {
    if (index == -1) {
        cout << "Not Found" << endl;
    }
    else {
        cout << "Found at index: " << index << endl;
    }
}