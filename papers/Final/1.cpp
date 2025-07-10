#include <iostream>
#include <fstream>
using namespace std;

void input(int* array, int size, int& count);
int* regrow(int* array, int& size);
int* shrink(int* array, int& size, int capacity);
int main() {
	int size = 2;
	int count = 0;
	int* array = new int[size];
	cout << "Enter choice(1/2/3)";
	int x;
	cin >> x;
	while (x != 4) {
		if (x == 1) {
			input(array, size, count);
			if (count == size) {
				array = regrow(array, size);
				cout << "New capacity " << size << endl;
			}
		}
		else if (x == 2) {
			int num = 0;
			cout << "Enter priority to resolve" << endl;
			cin >> num;
			array = shrink(array, size, num);
			size = size - 1;
			array--;
			cout << "Priority resolved. New capacity: " << size << endl;
		}
		else if (x == 2) {
			cout << "Queue";
			for (int i = 0; i < count; i++) {
				cout << array[i] << ", ";
			}
		}
		else cout << "Invalid choice";
	}
	delete[]array;
	return 0;
}


void input(int* array, int size, int& count) {
	for (int i = 0; i < size; i++) {
		cout << "Add a caller" << endl;
		cin >> array[i];
		count++;
	}

}
int* regrow(int* array, int& size) {
	int* newarr = new int[size + 2];
	for (int i = 0; i < size; i++) {
		newarr[i] = array[i];
	}
	size = size + 2;
	return newarr;
}
int* shrink(int* array, int& size, int num) {
	int index = 0;
	int* newarr = new int[size - 1];
	for (int i = 0; i < size; i++) {
		if (array[i] == num) {
			index = i;
			break;
		}
	}
	for (int i = 0; i < size; i++) {
		if (i >= index) {
			newarr[i] = array[i + 1];
		}
		else {
			newarr[i] = array[i];
		}
	}
	size = size - 1;
	return newarr;
}