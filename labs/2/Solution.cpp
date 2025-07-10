#include <iostream>
using namespace std;

//Task 1

int main1() {
	char array[100];  
	cout << "Enter a word: ";
	cin >> array;  

	int length = 0;
	while (array[length] != '\0') {
		length++;
	}

	int s = 0, e = length - 1;
	bool isPalindrome = true;
	while (s < e) {
		if (array[s] != array[e]) {
			isPalindrome = false;
			break;
		}
		s++;
		e--;
	}

	if (isPalindrome) {
		cout << "The word is a palindrome." << endl;
	}
	else {
		cout << "The word is NOT a palindrome." << endl;
	}

	return 0;
}

//Task 2

int main2() {
	int array[3] = {};
	cout << "Enter three elements." << endl;
	for (int i = 0; i < 3; i++) {
		cin >> array[i];
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2 - i; j++) {
			if (array[j] > array[j + 1]) {
				char temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	cout << "Sorted array: ";
	for (int i = 0; i < 3; i++) {
		cout << array[i] << " ";
	}
	return 0;
}

//Task 3

int main3() {
	int array[10] = {};
	int x, y;
	cout << "Enter 10 array elements." << endl;
	for (int i = 0; i < 10; i++) {
		cin >> array[i];
		if (i == 2) {
			 x = array[i];
		}
		else if (i == 5) {
			y = array[i];
		}
	}

	for (int i = 0; i < 10; i++) {
		if (i == 2) {
			array[i] = y;
		}
		else if (i == 5) {
			array[i] = x;
		}
	}

	cout << "Array after 2nd and 5th Index swapped: ";
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}

	return 0;
}

//Task 4

int main4() {
	int array[10] = {};
	cout << "Enter 10 array elements." << endl;
	cin >> array[0];
	int max = array[0];
	int secondmax = array[0];
	int min = array[0];

	for (int i = 1; i < 10; i++) {
		cin >> array[i];
		if (array[i] > max) {
			secondmax = max;
			max = array[i];
		}
		else if (array[i] > secondmax && array[i] != max) {
			secondmax = array[i]; 
		}
		if (array[i] < min) {
			min = array[i];
		}
	}
	if (secondmax == max) {
		cout << "No second largest number because all elements are same." << endl;
	}
	else {
		cout << "Maximum: " << max << endl;
		cout << "Second Largest: " << secondmax << endl;
		cout << "Minimum: " << min << endl;
	}
	return 0;
}

//Task 5

int main5() {
	int array[10] = {};
	cout << "Enter array elements." << endl;
	for (int i = 0; i < 10; i++) {
		cin >> array[i];
	}
	cout << "Enter a number" << endl;
	int num;
	cin >> num;

	bool ispresent = false;
	for (int i = 0; i < 10; i++) {

		if (num == array[i]) {
			cout << "Index of number is: " << i << endl;
			ispresent = true;
		}
	}
	if (!ispresent) {
		cout << "Not found." << endl;
	}
	return 0;
}