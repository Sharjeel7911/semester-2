#include <iostream>
#include<fstream>
using namespace std;

//Task 1

int main1() {
	int array[100] = {};
	int size;
	int sum = 0;

	cout << "Enter size." << endl;
	cin >> size;

	cout << "Enter " << size << " integers.";

	for (int i = 0; i < size; i++) {
		cin >> *(array + i);
	}

	for (int i = 0; i < size; i += 2) {
		sum += *(array + i);  
	}

	cout << "Sum of alternate elements: " << sum << endl;
	return 0;
}

//Task 2

int main2() {
	fstream read("Data.txt", ios::in);
	if (!read) {
		cout << "Error: Unable to open file." << endl;
		return 1;
	}

	int array[1000] = {};

	int x = 0;
	while (read >> *(array + x)) {
		x++;
	}
	read.close();

	int max = *array;
	int min = *array;

	for (int i = 0; i < x; i++) {
		if (*(array + i) > max) {
			max = *(array + i);
		}
		if (*(array + i) < min) {
			min = *(array + i);
		}
	}

	int z = max - min;
	cout << "Maximum value: " << max << endl;
	cout << "Minimum value: " << min << endl;
	cout << "Difference between max and min: " << z << endl;
	return 0;
}

//Task 3

int main3() {
	int array[100] = {};
	int arr[100] = {};
	int size;
	int count = 0;

	cout << "Enter size." << endl;
	cin >> size;

	cout << "Enter " << size << " integers.";

	for (int i = 0; i < size; i++) {
		cin >> *(array + i);
	}

	for (int j = 0; j < size; j++) {
		if (*(array + j) % 2 == 0) {
			*(arr + count) = *(array + j);
			count++;
		}	
	}

	cout << "Even numbers are: ";
	for (int k = 0; k < count; k++) {
		cout << *(arr + k) << " ";
	}

	cout << endl;
	cout << "Even count: " << count << endl;
	return 0;
}

//Task 4

int main4() {
	fstream read("Nums.txt", ios::in);
	if (!read) {
		cout << "Error: Unable to open file." << endl;
		return 1;
	}

	int array[100] = {};
	int i = 0;
	while (read >> *(array + i)) {
		i++;
	}
	read.close();

	int count = i;
	for (int i = 0; i < count / 2; i++) {
		int temp = *(array + i);
		*(array + i) = *(array + (count - 1 - i));
		*(array + (count - 1 - i)) = temp;
	}

	fstream write("Reversed.txt", ios::out);
	if (!write) {
		cout << "Error: Unable to create output file." << endl;
		return 1;
	}

	for (int i = 0; i < count; i++) {
		write << *(array + i) << " ";
	}

	write << endl << count; 
	write.close();

	cout << "Reversed array and count written to 'reversed.txt'." << endl;
	return 0;
}

//Task 5

int main5() {
	int array[100] = {};
	int size;

	cout << "Enter size." << endl;
	cin >> size;

	cout << "Enter " << size << " integers." << endl;

	for (int i = 0; i < size; i++) {
		cin >> *(array + i);
	}

	if (*array == 0) {
		cout << "Error: Division by zero is not possible." << endl;
		return 1;
	}

	for (int i = 1; i < size; i++) {
		*(array + i) = (*(array + i) / *array) * 10;
	}
	*array = (*array / *array) * 10;
	cout << "Updated array: ";
	for (int i = 0; i < size; i++) {
		cout << *(array + i) << " ";
	}
	return 0;
}

//Task 6

int main6() {
	int* ptr = new int;

	cout << "Enter a number: ";
	cin >> *ptr;

	cout << "Result: " << (*ptr) * 5 << endl;

	delete ptr;

	return 0;
}

//Task 7

int findMaxPointerr(int* arr, int size) {
	int max = *arr;
	for (int i = 1; i < size; i++) {
		if (*(arr + i) > max) {
			max = *(arr + i);
		}
	}
	return max;
}

int main7() {
	int array[100] = {};
	int size;

	cout << "Enter size." << endl;
	cin >> size;

	cout << "Enter " << size << " integers.";

	for (int i = 0; i < size; i++) {
		cin >> *(array + i);
	}

	int max = findMaxPointerr(array, size);

	cout << "Maximum value is: " << max << endl;

	return 0;
}