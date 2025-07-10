#include <iostream>
using namespace std;

//Task 1

int main1() {
    int price;
    int* ptr = &price;

    cout << "Enter the price of the car: ";
    cin >> *ptr;

    float x = (*ptr * 0.12) + 15000;

    cout << "First installment to be paid: Rs." << x << endl;
    return 0;
}

//Task 2

int main2() {
    float x, y, result;
    char op;

    float* ptrx = &x;
    float* ptry = &y;
    float* ptrResult = &result;
    char* ptrOp = &op;

    cout << "Enter first value: ";
    cin >> *ptrx;
    cout << "Enter second value: ";
    cin >> *ptry;
    cout << "Enter operator (+, -, *, /): ";
    cin >> *ptrOp;

    if (*ptrOp == '+') {
        *ptrResult = *ptrx + *ptry;
    }
    else if (*ptrOp == '-') {
        *ptrResult = *ptrx - *ptry;
    }
    else if (*ptrOp == '*') {
        *ptrResult = *ptrx * *ptry;
    }
    else if (*ptrOp == '/') {
        if (*ptry != 0) {
            *ptrResult = *ptrx / *ptry;
        }
        else {
            cout << "Division by zero is not possible!" << endl;
            return 1;
        }
    }
    else {
        cout << "Invalid operator!" << endl;
        return 1;
    }
    cout << "Result: " << *ptrResult << endl;
    return 0;
}

//Task 3

int main3() {
    int num, reversed = 0, remainder;
    int* ptrNum = &num;
    int* ptrReversed = &reversed;
    int* ptrRemainder = &remainder;

    cout << "Enter a number: ";
    cin >> *ptrNum;

    int original = *ptrNum;

    while (*ptrNum != 0) {
        *ptrRemainder = *ptrNum % 10;
        *ptrReversed = (*ptrReversed * 10) + *ptrRemainder;
        *ptrNum = *ptrNum / 10;
    }

    if (original == *ptrReversed) {
        cout << original << " is a palindrome." << endl;
    }
    else {
        cout << original << " is not a palindrome." << endl;
    }
    return 0;
}

//Task 4

int main4() {
    int a, b, c;

    int* ptr1 = &a;
    int* ptr2 = &b;
    int* ptr3 = &c;

    cout << "Enter first number: ";
    cin >> *ptr1;
    cout << "Enter second number: ";
    cin >> *ptr2;
    cout << "Enter third number: ";
    cin >> *ptr3;

    int* maxPtr = ptr1;
    if (*ptr2 > *maxPtr)
        maxPtr = ptr2;
    if (*ptr3 > *maxPtr)
        maxPtr = ptr3;

    cout << "The maximum number is: " << *maxPtr << endl;
    return 0;
}

//Task 5

int main5() {
    int a, b;
    int* ptr1 = &a;
    int* ptr2 = &b;

    cout << "Enter first number: ";
    cin >> *ptr1;

    cout << "Enter second number: ";
    cin >> *ptr2;

    cout << endl;

    cout << "Before Swapping:" << endl;
    cout << "a = " << *ptr1 << ", b = " << *ptr2 << endl;

    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

    cout << endl;

    cout << "After Swapping:" << endl;
    cout << "a = " << *ptr1 << ", b = " << *ptr2 << endl;
    return 0;
}

//Task 6

int reverseNumber(int n) {
    int reversed = 0;
    int* ptrN = &n;

    while (*ptrN != 0) {
        reversed = reversed * 10 + (*ptrN % 10);
        *ptrN = *ptrN / 10;
    }
    return reversed;
}
bool isPalindrome(int n) {
    int reversed = reverseNumber(n);
    return (n == reversed);
}
void processNumber(int n) {
    int* ptrNum = &n;

    if (isPalindrome(*ptrNum)) {
        cout << *ptrNum << " is a palindrome." << endl;
        cout << "Square: " << (*ptrNum) * (*ptrNum) << endl;
    }
    else {
        int reversed = reverseNumber(*ptrNum);
        int* ptrRev = &reversed;
        cout << *ptrNum << " is not a palindrome." << endl;
        cout << "Cube of reversed number (" << *ptrRev << "): " << (*ptrRev) * (*ptrRev) * (*ptrRev) << endl;
    }
}

int main6() {
    int num;
    int* ptr = &num;

    cout << "Enter a 3-digit number: ";
    cin >> *ptr;

    if (*ptr >= 100 && *ptr <= 999) {
        processNumber(*ptr);
    }
    else {
        cout << "Invalid input! Please enter a 3-digit number." << endl;
    }
    return 0;
}

//Task 7

void readName(char name[], int& length) {
    cin.ignore();
    cin.getline(name, 100);
    length = 0;
    while (name[length] != '\0') {
        length++;
    }
}
void reverseName(char name[], int length) {
    for (int i = 0; i < length / 2; i++) {
        char temp = name[i];
        name[i] = name[length - 1 - i];
        name[length - 1 - i] = temp;
    }
}
void capitalize(char name[]) {
    if (name[0] >= 'a' && name[0] <= 'z') {
        name[0] = name[0] - ('a' - 'A');
    }
}
void copyName(char destination[], char source[], int length) {
    for (int i = 0; i < length; i++) {
        destination[i] = source[i];
    }
    destination[length] = '\0';
}
void displayName(char name[]) {
    int i = 0;
    while (name[i] != '\0') {
        cout << name[i];
        i++;
    }
}

int main() {
    int n;
    cout << "Enter number of guests: ";
    cin >> n;

    char name[100];
    char vipName[100];
    int nameLength = 0;
    int vipNameLength = 0;
    int maxDays = -1;

    for (int i = 0; i < n; i++) {
        cout << "Enter name of guest " << i + 1 << ": ";
        readName(name, nameLength);
        reverseName(name, nameLength);
        capitalize(name);

        int days;
        cout << "Enter number of days: ";
        cin >> days;

        if (days > maxDays) {
            maxDays = days;
            vipNameLength = nameLength;
            copyName(vipName, name, vipNameLength);
        }
    }

    cout << endl << "VIP Guest: ";
    displayName(vipName);
    cout << endl << "Days of Stay: " << maxDays << endl;
    return 0;
}

//Task 8

void inputNumbers(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter number: ";
        cin >> array[i];
    }
}
void sortNumbers(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
int calculateSum(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}
double calculateAverage(int array[], int size) {
    int sum = calculateSum(array, size);
    return (double)sum / size;
}
int findMin(int array[], int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}
int findMax(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int main8() {
    const int x = 10;
    int array[x];
    int num;

    cout << "Enter the number of values: ";
    cin >> num;

    if (num > x) {
        cout << "Number of values exceeds maximum allowed size (max. 10)." << endl;
        return 1;
    }

    inputNumbers(array, num);
    sortNumbers(array, num);

    cout << "Sorted Numbers: ";
    for (int i = 0; i < num; i++) {
        cout << *(array + i) << " ";
    }
    cout << endl;

    int min = findMin(array, num);
    int max = findMax(array, num);
    int sum = calculateSum(array, num);
    double average = calculateAverage(array, num);

    cout << "Smallest Number: " << min << endl;
    cout << "Largest Number: " << max << endl;
    cout << "Sum of Numbers: " << sum << endl;
    cout << "Average of Numbers: " << average << endl;
    return 0;
}