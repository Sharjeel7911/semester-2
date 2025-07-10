#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream read("input.txt", ios::in);
	fstream write("vowel_count.txt", ios::out);
	if (!read.is_open() || !write.is_open()) {
		cout << "Error while openning the file." << endl;
		return 1;
	}

	char ch;
	int a = 0, e = 0, i = 0, o = 0, u = 0;
	while (read.get(ch)) {

		if (ch == 'a' || ch == 'A') {
			a++;
		}
		else if (ch == 'e' || ch == 'E') {
			e++;
		}
		else if (ch == 'i' || ch == 'I') {
			i++;
		}
		else if (ch == 'o' || ch == 'O') {
			o++;
		}
		else if (ch == 'u' || ch == 'U') {
			u++;
		}
	}
	int total = a + e + i + o + u;
	if (total == 0) {
		cout << "No vowel" << endl;
		return 1;
	}

	else {
		write << "Vowel Frequency Analysis" << endl;
		write << "-----------------------------  " << endl;
		write << "a: " << a << endl;
		write << "e: " << e << endl;
		write << "i: " << i << endl;
		write << "o: " << o << endl;
		write << "u: " << u << endl;
	}

	int max = a;
	if (e > max) max = e;
	if (i > max) max = i;
	if (o > max) max = o;
	if (u > max) max = u;

	cout << "Vowel count saved in 'vowel_count.txt'" << endl;
	cout << "Most frequent vowel(s): ";

	bool first = true;
	if (a == max) {
		if (!first) cout << ", ";
		cout << "a (" << a << " times)";
		first = false;
	}
	if (e == max) {
		if (!first) cout << ", ";
		cout << "e (" << e << " times)";
		first = false;
	}
	if (i == max) {
		if (!first) cout << ", ";
		cout << "i (" << i << " times)";
		first = false;
	}
	if (o == max) {
		if (!first) cout << ", ";
		cout << "o (" << o << " times)";
		first = false;
	}
	if (u == max) {
		if (!first) cout << ", ";
		cout << "u (" << u << " times)";
		first = false;
	}
	cout << endl;
	write.close();
	read.close();
	return 0;
}