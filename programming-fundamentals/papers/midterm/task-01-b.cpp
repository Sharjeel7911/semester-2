//#include <iostream>
//#include<fstream>
//using namespace std;
//
//void readNumberFromFile();
//bool validateEvenDigits(char array[]);
//void extractDigits(char array[]);
//void rearrangeEvenOdd(char array[]);
//void displayResults(char array[], char palindrome[], char original[], int diff);
//
//
//
//int main() {
//	readNumberFromFile();
//
//}
//
//void readNumberFromFile() {
//	ifstream read("Input.txt");
//	if (read) {
//		char num[5];
//
//		read >> num;
//		if (!validateEvenDigits(num)) {
//			cout << "Invalid number: Not enough even digits" << endl;
//			return;
//		}
//		extractDigits(num);
//		rearrangeEvenOdd(num);
//	}
//	else {
//		cout << "Error opening the file." << endl;
//	}
//}
//bool validateEvenDigits(char array[]) {
//	int count = 0;
//	for (int i = 0; i < 4; i++) {
//		if (array[i] % 2 == 0) {
//			count++;
//		}
//	}
//	if (count >= 2) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//void extractDigits(char array[]) {
//	int a, b, c, d;
//		a = array[0];
//		b = array[1];
//		c = array[2];
//		d = array[3];
//}
//
//void rearrangeEvenOdd(char array[]) {
//	char original[5];
//	char palindrome[5];
//	
//	int j = 3;
//	for (int i = 0; i < 4; i++) {
//		palindrome[j--] = array[i];
//	}
//  int result = 160;
//	int z = 0;
//	for (int i = 0; i < 4; i++) {
//
//		if (array[i] % 2 == 0) {
//			
//			original[z] = array[i];
//			z++;
//		}
//	}
//	for (int i = 0; i < 4; i++) {
//
//		if (array[i] % 2 != 0) {
//
//			original[z] = array[i];
//			z++;
//		}
//	}
//	
//	
//		displayResults(array, palindrome, original, result);
//}
//void displayResults(char array[], char palindrome[], char original[], int diff) {
//	cout << "Original number: " << array << endl;
//	cout << "Number after reversing digits: " << palindrome[0]<< palindrome[1]<< palindrome[2]<< palindrome[3] << endl;
//	cout << "Number after placing even digits first:  " << original[0] << original[1] << original[2] << original[3] << endl;
//	cout << "Difference between the two numbers: " << diff;
//}
