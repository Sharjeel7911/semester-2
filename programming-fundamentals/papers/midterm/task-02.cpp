//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int main() {
//	cout << "Enter 7 digit number" << endl;
//
//	char num[10];
//	cin.getline(num, 10);
//
//
//	char x[10] = {};
//
//	int a = num[0], b = num[1], c = num[2], d = num[3], e = num[4], f = num[5], g = num[6];
//
//	x[0] = g;
//	x[1] = f;
//	x[2] = e;
//	x[3] = d; 
//	x[4] = c;
//	x[5] = b;
//	x[6] = a;
//	
//	cout << "Reversed Digits: " << x << " ";
//
//	ofstream write("numbers.txt");
//	if (write) {
//		write << "Original" << ", " << "Reversed" << endl;
//		write << num << ", " << x;
//	}
//	return 0;
//}