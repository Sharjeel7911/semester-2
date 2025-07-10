#include <iostream>
#include <fstream>
using namespace std;

void readFile(int arr[], int size);
float calculateAverage(const int arr[], int size);
void displayAverage(float average);

void task2() {
    const int size = 5;
    int numbers[size];

    readFile(numbers, size);
    float avg = calculateAverage(numbers, size);
    displayAverage(avg);
}

void readFile(int arr[], int size) {
    fstream read("Inputx.txt", ios::in);
    if (read) {
        for (int i = 0; i < size; i++) {
            read >> arr[i];
        }
        read.close();
    }
    else {
        cout << "Error opening file." << endl;
    }
}
float calculateAverage(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return static_cast<float>(sum) / size;
}
void displayAverage(float average) {
    cout << "Average is: " << average << endl;
}