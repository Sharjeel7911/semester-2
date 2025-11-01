#include<iostream>
using namespace std;

void task1();
void task2();

int main() {
	int ch;
	cout << "Enter 1 for task 1 or 2 for task 2: ";
	cin >> ch;
	switch (ch) {
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	}
	return 0;
}

