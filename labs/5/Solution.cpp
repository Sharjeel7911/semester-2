#include <iostream>
#include <fstream>
using namespace std;

//Task 1
bool prime(int num) {

	if (num < 2) {
		return false;
	}
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
		else {
			return true;
		}
	}
}
//Task 2
int vowel(char array[]) {
	int count = 0;
	for (int i = 0; array[i] != '\0'; i++) {
		char ch = array[i];
		if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U') {
			count++;
		}
	}
	return count;
}
//Task 3
int sum(int n) {
	int sum = 0;
	if (n > 0) {
		for (int i = 1; i <= n; i++) {
			sum += i;
		}
		return sum;
	}
	else {
		for (int i = -1; i >= n; i--) {
			sum += i;
		}
		return sum;
	}
}
//Task 4
void result(double x) {
	cout << "The power is: " << x << endl;
}
void power(double x, double y) {
	double powerx = 1.0;
	if (y == 0) {
		powerx = 1;
	}
	else if (y > 0) {
		for (double i = 1.0; i <= y; i++) {
			powerx *= x;
		}
	}
	else {
		for (double i = 1.0; i <= -y; i++) {
			powerx *= x;
		}
		powerx = 1.0 / powerx;
	}
	result(powerx);
}
void read() {
	double num;
	int numx;
	cout << "Enter a number." << endl;
	cin >> num;
	cout << "Enter the power (can be negative but not decimal)" << endl;
	cin >> numx;
	power(num, numx);
}
//Task 5
void resultx(int sum) {
	cout << "The sum of array elements is: " << sum << endl;
}
void sumx(int array[]) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += array[i];
	}
	resultx(sum);
}
void readx() {
	int array[5] = {};
	cout << "Enter 5 integers." << endl;
	for (int i = 0; i < 5; i++) {
		cin >> array[i];
	}
	sumx(array);
}
//Task 6
int number;
int cubex = 1;

void ready() {
	cout << "Enter a number." << endl;
	cin >> number;
}
void cube() {
	cubex = number * number * number;
}
void write() {
	cout << "The cube of " << number << " is: " << cubex << endl;

	fstream writex("output.txt", ios::out);
	if (writex.is_open()) {
		writex << "The cube of " << number << " is: " << cubex << endl;
		writex.close();
		cout << "Result written to output.txt" << endl;
	}
	else {
		cout << "Unable to open file!" << endl;
	}
}
void controller() {
	ready();
	cube();
	write();
}
//Task 7
void readAndDisplay() {
	char name[100];
	int age;
	
	cin.ignore();
	cout << "Enter your name: ";
	cin.getline(name, 100);  
	
	cout << "Enter your age: ";
	cin >> age;

	cout << "Your name is: " << name << endl;
	cout << "Your age is: " << age << endl;
}
void processInfo() {
	readAndDisplay();
}


int main()
{
	//Task 1
	int num;
	cout << "Enter a number." << endl;
	cin >> num;
	if (prime(num)) {
		cout << num << " is a prime number." << endl;
	}
	else {
		cout << num << " is not a prime number." << endl;
	}
	cin.ignore();

	//Task 2
	cout << "Enter a sentence." << endl;
	char array[100];
	cin.getline(array, 100);
	int x = vowel(array);
	cout << "Number of vowels: " << x << endl;

	//Task 3
	cout << "Enter a number." << endl;
	int n;
	cin >> n;
	int sumx = sum(n);
	cout << "The sum of numbers from 1 to " << n << " is: " << sumx << endl;

	//Task 4
	read();

	//Task 5
	readx();

	//Task 6
	controller();

	//Task 7
	processInfo();

	return 0;
}