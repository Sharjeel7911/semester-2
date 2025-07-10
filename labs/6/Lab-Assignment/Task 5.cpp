#include <iostream>
using namespace std;

void inputArrayx(int arr[], int size);
int sumFirstHalf(int arr[]);
int sumSecondHalf(int arr[]);
void displaySums(int firstSum, int secondSum);

void task5() {
    int arr[8];
    inputArrayx(arr, 8);

    int firstHalfSum = sumFirstHalf(arr);
    int secondHalfSum = sumSecondHalf(arr);

    displaySums(firstHalfSum, secondHalfSum);
}

void inputArrayx(int arr[], int size) {
    cout << "Enter 8 numbers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}
int sumFirstHalf(int arr[]) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += arr[i];
    }
    return sum;
}
int sumSecondHalf(int arr[]) {
    int sum = 0;
    for (int i = 4; i < 8; i++) {
        sum += arr[i];
    }
    return sum;
}
void displaySums(int firstSum, int secondSum) {
    cout << "Sum of first half: " << firstSum << endl;
    cout << "Sum of second half: " << secondSum << endl;
    cout << "Total sum: " << firstSum + secondSum << endl;
}