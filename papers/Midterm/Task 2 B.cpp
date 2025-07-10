#include <iostream>
#include <fstream>
using namespace std;

void words();
void chare(int c);
void write(int count, int c);




void words() {
	ifstream read("X.txt");
	char word[100]; 
		int c = 0;
		if (read) {
			while (read >> word) {
				if (word[0] == 'c' || word[0] == 'C') {
					c++;
				}
			}
		}
	chare(c);
}
void chare(int c) {
	ifstream read("X.txt");
	char ch;
	int count = 0;
	if (read) {
		while (read.get(ch)) {
			if (ch != ' ' && ch != '?' && ch != '.') {
				count++;

			}
		}
	}
	
	write(count, c);
	cout << "Task done";
}

void write(int count,int c) {
	ofstream write("cwords.txt");
	write << "Words starting with 'c' or 'C': " << c << endl;
	write << "Total characters: " << count << endl;

}

int main() {

	words();
}

