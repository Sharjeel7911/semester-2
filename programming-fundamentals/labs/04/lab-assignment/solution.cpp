#include <iostream>
#include <fstream>
using namespace std;

void table()
{
	int n;
	cout << "Enter a number to print its table: ";
	cin >> n;
	for (int i = 1; i <= 10; i++)
	{
		cout << n << " * " << i << " = " << n * i << endl;
	}
}
void divisor()
{
	int n;
	cout << "Enter a number to find its divisors: ";
	cin >> n;
	cout << "Divisors of " << n << " are: ";
	for (int i = 1; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			cout << i << " ";
		}
	}
	cout << endl;
}
void sorting() {
	const int max = 100;
	int array[max] = {};
	int n;

	cout << "How many numbers you want to sort (max " << max << "): ";
	cin >> n;
	do {
		if (n < 1 || n > max) {
			cout << "Invalid input! Please enter a number between 1 and " << max << ": ";
			cin >> n;
		}
	} while (n < 1 || n > max);

	cout << "Enter the numbers: ";
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	// Bubble sorting
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	cout << "Sorted numbers are: ";
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
void power() {
	int a, b;
	cout << "Enter two numbers" << endl;
	cin >> a >> b;
	int power = 1;
	for (int i = 1; i <= b; i++)
	{
		power = power * a;
	}
	cout << "Power of " << a << "^" << b << " is: " << power << endl;
}
void numberseparate() {
	cout << "Enter a number to separate: ";
	int n;
	do {
		cin >> n;
		if (n < 10) {
			cout << "Please write number with atleast two digits positive number." << endl;
		}
	} while (n < 10);

	int array[100] = {};
	int i = 0;
	while (n > 0) {

		array[i] = n % 10;
		n = n / 10;
		i++;
	}
	cout << "Separated numbers are: ";
	for (int j = i - 1; j >= 0; j--) {
		cout << array[j] << " ";
	}
	cout << endl;
}
void convert() {
	char array[100] = {};
	cout << "Enter a string: ";
	cin >> array;
	int length = 0;
	while (array[length] != '\0') {
		length++;
	}	for (int i = 0; i < length; i++) {
		if (array[i] >= 'a' && array[i] <= 'z') {
			array[i] = array[i] - 32;
		}
		else if (array[i] >= 'A' && array[i] <= 'Z') {
			array[i] = array[i] + 32;
		}
	}
	cout << "Converted string is: " << array << endl;
}
void findreverse() {
	cout << "Enter a number: ";
	int n;
	cin >> n;
	int result = 0;
	int i = 0;
	while (n > 0) {

		result = n % 10;
		n = n / 10;
		cout << result;
		i++;
	}
	cout << endl;
}
void palindrome() {
	cout << "Enter a number: ";
	int n;
	cin >> n;
	int temp = n;
	int x = 0;
	int reverse = 0;

	while (n > 0) {
		x = n % 10;
		n = n / 10;
		reverse = reverse * 10 + x;
	}
	if (reverse == temp) {
		cout << "The number is palindrome." << endl;
	}
	else {
		cout << "The number is not palindrome." << endl;
	}
}
void numberlength() {
	fstream read("word_frequency.txt", ios::in);
	fstream write("word_length.txt", ios::out);
	if (!read.is_open() || !write.is_open()) {
		cout << "Error opening file." << endl;
		return;
	}
	char word[100];
	int max = 0;

	char newword[50] = {};
	char maxword[200] = {};
	int counter = 0;

	while (read >> word) {
		int length = 0;
		int count = 0;

		while (word[length] != '\0') {
			if ((word[length] >= 'a' && word[length] <= 'z') || (word[length] >= 'A' && word[length] <= 'Z')) {
				newword[count] = word[length];
				count++;
			}
			length++;
		}
		newword[count] = '\0';

		if (count > max) {
			max = count;
			int i = 0;
			while (newword[i] != '\0') {
				maxword[i] = newword[i];
				i++;
			}
			maxword[i] = '\0';
		}
		else if (count == max) {
			int i = 0, j = 0;
			while (maxword[j] != '\0') {
				j++;
			}
			maxword[j++] = ',';
			maxword[j++] = ' ';

			while (newword[i] != '\0') {
				maxword[j++] = newword[i++];
			}
			maxword[j] = '\0';
		}

		write << newword << ", " << count << endl;
		counter++;
	}
	write << endl << "Longest word(s): " << maxword << ", " << max << " characters" << endl;
	write << "Total words: " << counter << endl;

	read.close();
	write.close();
	cout << "Word lengths saved in word_length.txt" << endl;
}
void factorial() {
	cout << "Enter a number to find its factorial: ";
	int n;
	cin >> n;
	int fact = 1;
	for (int i = 1; i <= n; i++) {
		fact = fact * i;
	}
	cout << "Factorial of " << n << " is: " << fact << endl;
}

int main() {

	do {
		cout << "Welcome to the program" << endl;
		cout << "Press T for printing table" << endl;
		cout << "Press D for finding divisors" << endl;
		cout << "Press S for sorting numbers" << endl;
		cout << "Press P for finding power" << endl;
		cout << "Press N for separating numbers" << endl;
		cout << "Press C to convert string" << endl;
		cout << "Press R to find reverse number" << endl;
		cout << "Press P for palindrome" << endl;
		cout << "Press L for number length in file" << endl;
		cout << "Press F fot factorial" << endl;

		char x;
		cout << "Enter your choice." << endl;
		cin >> x;

		if (x == 't' || x == 'T') {
			table();
		}
		else if (x == 'd' || x == 'D') {
			divisor();
		}
		else if (x == 's' || x == 'S') {
			sorting();
		}
		else if (x == 'a' || x == 'A') {
			power();
		}
		else if (x == 'n' || x == 'N') {
			numberseparate();
		}
		else if (x == 'c' || x == 'C') {
			convert();
		}
		else if (x == 'r' || x == 'R') {
			findreverse();
		}
		else if (x == 'p' || x == 'P') {
			palindrome();
		}
		else if (x == 'l' || x == 'L') {
			numberlength();
		}
		else if (x == 'f' || x == 'F') {
			factorial();
		}
		else {
			cout << "Invalid choice!" << endl;
		}

		cout << "Do you want to continue? (y/n): ";
		char choice;
		cin >> choice;
		if (choice == 'n' || choice == 'N') {
			break;
		}
		else if (choice != 'y' && choice != 'Y') {
			continue;
		}
	} while (true);
	return 0;
}