//#include <iostream>
//#include <fstream>
//using namespace std;
//
////Task 2
//
//void take_input(int** matrix, int row, int col);
//void primes(int** matrix, int row, int col);
//bool isprime(int x);
//int main() {
//	cout << "Enter number of rows: " << endl;
//	int row;
//	cin >> row;
//	cout << "Enter number of coloumns: " << endl;
//	int col;
//	cin >> col;
//
//	int** matrix = new int* [row];
//	for (int i = 0; i < row; i++) matrix[i] = new int[col];
//
//	take_input(matrix, row, col);
//	for (int j = 0; j < col; j++) {
//		for (int i = 0; i < row; i++) {
//			cout << matrix[i][j] << " ";
//		}
//		cout << endl;
//	}
//	primes(matrix, row, col);
//
//
//	for (int i = 0; i < row; i++) {
//		delete[] matrix[i];
//	}
//	delete[] matrix;
//
//	return 0;
//}
//void take_input(int** matrix, int row, int col) {
//	cout << "Enter matrix elements (each between 10 and 999): " << endl;
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			do {
//				cin >> matrix[i][j];
//				if (matrix[i][j] <= 10 || matrix[i][j] >= 999) {
//					cout << "Plz enter between 10 to 999" << endl;
//				}
//			} while (matrix[i][j] <= 10 || matrix[i][j] >= 999);
//		}
//	}
//}
//void primes(int** matrix, int row, int col) {
//	int counter = 0;
//	int max = 0;
//	int index = 0;
//	for (int j = 0; j < col; j++) {
//		counter = 0;
//		for (int i = 0; i < row; i++) {
//			bool istrue = true;
//			for (int k = 0; i < matrix[i][j] / 2; k++) {
//				istrue = true;
//				if (matrix[i][j] % i == 0) {
//					istrue = false;
//					break;
//				}
//			}
//			if (isprime) {
//				counter++;
//			}
//			else continue;
//		}
//		cout << "Coloumn " << j << " has " << counter << "Primes" << endl;
//
//		if (counter > max) {
//			max = counter;
//			index = j;
//		}
//
//	}
//	cout << "Max primes" << max << " at " << index;
//}
//bool isprime(int x) {
//	bool istrue = true;
//	for (int i = 0; i < x / 2; i++) {
//		istrue = true;
//		if (x % i == 0) {
//			istrue = false;
//			break;
//		}
//	}
//	if (!istrue) return false;
//	else return true;
//}
