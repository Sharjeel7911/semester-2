#include <iostream>
#include <fstream>
using namespace std;

//Task 1: Find Maximum from File 
void readsize(int& size);
void readfromfile(int array[], int size);
int findmax(int array[], int size);
int main1()
{
	int size = 0;
	readsize(size);
	int* array = new int[size];

	readfromfile(array, size);

	int max = findmax(array, size);
	cout << "The maximum number is: " << max << endl;

	delete[] array;
	return 0;
}
void readsize(int& size) {
	ifstream read("Data.txt");
	if (!read) {
		cout << "Error: Unable to open file." << endl;
		return;
	}
	read >> size;
	read.close();
}
void readfromfile(int array[], int size) {
	ifstream read("Data.txt");
	if (!read) {
		cout << "Error: Unable to open file." << endl;
		return;
	}
	int x;
	read >> x;
	for (int i = 0; i < size; i++) {
		read >> *(array + i);
	}
	read.close();
}
int findmax(int array[], int size) {
	int max = *array;
	for (int i = 1; i < size; i++) {
		if (*(array + i) > max) {
			max = *(array + i);
		}
	}
	return max;
}

//Task 2: Search Number in File Array
void readsizeoffile(int& size);
void numbertofind(int array[], int size);
int main2() {
	int size = 0;
	readsizeoffile(size);
	int* array = new int[size];

	readfromfile(array, size);

	numbertofind(array, size);

	delete[] array;
	return 0;
}
void readsizeoffile(int& size) {
	ifstream read("Data.txt");
	if (!read) {
		cout << "Error: Unable to open file." << endl;
		return;
	}
	int x;
	while (read >> x) {
		size++;
	}
	read.close();
}
void numbertofind(int array[], int size) {
	cout << "Enter the number you want to search." << endl;
	int num;
	cin >> num;

	for (int i = 0; i < size; i++) {
		if (*(array + i) == num) {
			cout << "Number found." << endl;
			return;
		}
	}
	cout << "Number not found in Data.txt" << endl;

}

//Task 3: Square of Numbers (Regrow)
int* readregrow(const char* filename, int& size);
int* squarearray(const int* input, int size);
int main3() {
	int size = 0;
	int* original = readregrow("Data.txt", size);

	if (original == nullptr)
		return 1;

	int* squared = squarearray(original, size);

	cout << "Original Data: ";
	for (int i = 0; i < size; i++)
		cout << original[i] << " ";
	cout << endl;

	cout << "Squared Data:  ";
	for (int i = 0; i < size; i++)
		cout << squared[i] << " ";
	cout << endl;

	delete[] original;
	delete[] squared;

	return 0;
}
int* readregrow(const char* filename, int& size) {
	ifstream read(filename);
	if (!read.is_open()) {
		cerr << "File not found." << endl;
		return nullptr;
	}

	int capacity = 5;
	int* array = new int[capacity];
	int num = 0;
	size = 0;

	while (read >> num) {
		if (size == capacity) {
			capacity *= 2;
			int* new_array = new int[capacity];
			for (int i = 0; i < size; i++)
				new_array[i] = array[i];
			delete[] array;
			array = new_array;
		}
		array[size++] = num;
	}


	read.close();

	int* final_array = new int[size];
	for (int i = 0; i < size; i++)
		final_array[i] = array[i];
	delete[] array;
	array = final_array;
	return array;
}
int* squarearray(const int* input, int size) {
	int capacity = 5;
	int* squares = new int[capacity];
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (count == capacity) {
			capacity *= 2;
			int* new_array = new int[capacity];
			for (int i = 0; i < count; i++)
				new_array[i] = squares[i];
			delete[] squares;
			squares = new_array;
		}
		squares[count++] = input[i] * input[i];
	}

	int* final_array = new int[count];
	for (int i = 0; i < count; i++)
		final_array[i] = squares[i];
	delete[] squares;
	squares = final_array;
	return squares;
}

//Task 4: Replace Values by Subtracting from Max 
void subtractfrommax(int array[], int size, int max);
int main4() {
	int size = 0;
	readsize(size);
	int* array = new int[size];

	readfromfile(array, size);

	int max = findmax(array, size);

	subtractfrommax(array, size, max);

	cout << "Array: ";
	for (int i = 0; i < size; i++) {
		cout << *(array + i) << " ";
	}

	delete[] array;
	return 0;
}
void subtractfrommax(int array[], int size, int max) {
	for (int i = 0; i < size; i++) {
		*(array + i) = max - *(array + i);
	}
}

//Task 5: Remove Number
void removenum(int array[], int size);
int main5() {
	int size = 0;
	readsize(size);
	int* array = new int[size];

	readfromfile(array, size);

	removenum(array, size);

	cout << "Array: ";
	for (int i = 0; i < size; i++) {
		cout << *(array + i) << " ";
	}

	delete[] array;
	return 0;
}
void removenum(int array[], int size) {
	cout << "Enter the number to remove." << endl;
	int num;
	cin >> num;

	for (int i = 0; i < size; i++) {
		if (*(array + i) == num) {
			*(array + i) = *(array + size - 1);
			*(array + size - 1) = 0;
		}
	}
}

//Task 6: Separate One-digit and Two-digit 
void separateint(int* singled, int* doubled, int* original, int size);
void display(int* singled, int count, int* doubled, int counter);
int main6() {
	int size = 0;
	int* original = readregrow("Data.txt", size);

	if (original == nullptr) return 1;

	int count = 0;
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (*(original + i) / 10 == 0) {
			count++;
		}
		else counter++;
	}
	int* singled = new int[count];
	int* doubled = new int[counter];

	separateint(singled, doubled, original, size);

	display(singled, count, doubled, counter);

	delete[] original;
	delete[] singled;
	delete[] doubled;
	return 0;
}
void separateint(int* singled, int* doubled, int* original, int size) {
	int s = 0, d = 0;
	for (int i = 0; i < size; i++) {
		if (*(original + i) / 10 == 0) {
			*(singled + s++) = *(original + i);
		}
		else {
			*(doubled + d++) = *(original + i);
		}
	}
}
void display(int* singled, int count, int* doubled, int counter) {
	cout << "One-digit Numbers: ";
	for (int i = 0; i < count; i++)
		cout << singled[i] << " ";
	cout << endl;

	cout << "Two-digit Numbers: ";
	for (int i = 0; i < counter; i++)
		cout << doubled[i] << " ";
	cout << endl;
}

//Task 7: Word Lengths from File
int* readwordlengths(const char* filename, int& size);
bool isalphanumeric(char ch);
int main7() {
	int size = 0;
	int* word_lengths = readwordlengths("Text.txt", size);

	if (word_lengths == nullptr)
		return 1;

	cout << "Word Lengths: ";
	for (int i = 0; i < size; i++)
		cout << word_lengths[i] << " ";
	cout << endl;

	delete[] word_lengths;
	return 0;
}
int* readwordlengths(const char* filename, int& size) {
	ifstream read(filename);
	if (!read.is_open()) {
		cerr << "File not found." << endl;
		return nullptr;
	}

	int capacity = 5;
	int* lengths = new int[capacity];
	size = 0;

	char ch;
	int wordLength = 0;

	while (read.get(ch)) {
		if (isalphanumeric(ch)) {
			wordLength++;
		}
		else if (wordLength > 0) {
			if (size == capacity) {
				capacity *= 2;
				int* new_array = new int[capacity];
				for (int i = 0; i < size; i++)
					new_array[i] = lengths[i];
				delete[] lengths;
				lengths = new_array;
			}
			lengths[size++] = wordLength;
			wordLength = 0;
		}
	}

	if (wordLength > 0) {
		if (size == capacity) {
			capacity *= 2;
			int* new_array = new int[capacity];
			for (int i = 0; i < size; i++)
				new_array[i] = lengths[i];
			delete[] lengths;
			lengths = new_array;
		}
		lengths[size++] = wordLength;
	}
	read.close();

	int* final_array = new int[size];
	for (int i = 0; i < size; i++)
		final_array[i] = lengths[i];
	delete[] lengths;
	lengths = final_array;
	return lengths;
}
bool isalphanumeric(char ch) {
	return (ch >= 'A' && ch <= 'Z') ||
		(ch >= 'a' && ch <= 'z') ||
		(ch >= '0' && ch <= '9');
}

//Task 8: Separate Even and Odd Numbers
void separateevenodd(int* singled, int* doubled, int* original, int size);
void displayx(int* even, int count, int* odd, int counter);
int main8() {
	int size = 0;
	int* original = readregrow("Data.txt", size);

	if (original == nullptr) return 1;

	int count = 0;
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (*(original + i) % 2 == 0) {
			count++;
		}
		else counter++;
	}
	int* even = new int[count];
	int* odd = new int[counter];

	separateevenodd(even, odd, original, size);

	displayx(even, count, odd, counter);

	delete[] original;
	delete[] even;
	delete[] odd;
	return 0;
}
void separateevenodd(int* even, int* odd, int* original, int size) {
	int e = 0, o = 0;
	for (int i = 0; i < size; i++) {
		if (*(original + i) % 2 == 0) {
			*(even + e++) = *(original + i);
		}
		else {
			*(odd + o++) = *(original + i);
		}
	}
}
void displayx(int* even, int count, int* odd, int counter) {
	cout << "Even Numbers: ";
	for (int i = 0; i < count; i++)
		cout << even[i] << " ";
	cout << endl;

	cout << "Odd Numbers: ";
	for (int i = 0; i < counter; i++)
		cout << odd[i] << " ";
	cout << endl;
}

//Task 9: Sort Even Ascending & Odd Descending order
void ascending(int* array, int size);
void descending(int* array, int size);
void recombine(int* original, int* even, int count, int* odd, int counter);
void displayy(int* original, int size);
int main9() {
	int size = 0;
	int* original = readregrow("Data.txt", size);
	if (original == nullptr) return 1;

	int count = 0;
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (*(original + i) % 2 == 0) {
			count++;
		}
		else counter++;
	}
	int* even = new int[count];
	int* odd = new int[counter];

	separateevenodd(even, odd, original, size);

	ascending(even, count);
	descending(odd, counter);

	recombine(original, even, count, odd, counter);

	displayy(original, size);

	delete[] original;
	delete[] even;
	delete[] odd;
	return 0;
}
void ascending(int* array, int size) {
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (array[i] > array[j]) {
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
}
void descending(int* array, int size) {
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (array[i] < array[j]) {
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
}
void recombine(int* original, int* even, int count, int* odd, int counter) {
	for (int i = 0; i < count; i++)
		original[i] = even[i];
	for (int i = 0; i < counter; i++)
		original[count + i] = odd[i];
}
void displayy(int* original, int size) {
	cout << "Sorted Combined Array: ";
	for (int i = 0; i < size; i++)
		cout << original[i] << " ";
	cout << endl;
}

//Task 10: Shift Even Left, Odd Right
int main10() {
	int size = 0;
	int* original = readregrow("Data.txt", size);
	if (original == nullptr) return 1;

	int count = 0, counter = 0;
	for (int i = 0; i < size; i++) {
		if (original[i] % 2 == 0)
			count++;
		else
			counter++;
	}

	int* even = new int[count];
	int* odd = new int[counter];

	separateevenodd(even, odd, original, size);

	recombine(original, even, count, odd, counter);

	displayy(original, size);

	delete[] original;
	delete[] even;
	delete[] odd;
	return 0;
}

//Task 11: Shift and Remove Vowel 
bool isvowel(char ch);
void shiftandshrink(char*& arr, int& size);
char* readcharacters(const char* filename, int& size);
void displayz(char* arr, int size);
int main11() {
	int size = 0;
	char* text = readcharacters("Text.txt", size);
	if (text == nullptr) return 1;

	int n = size; 

	for (int i = 0; i < n && size > 0; i++) {
		shiftandshrink(text, size);
	}

	displayz(text, size);
	delete[] text;
	return 0;
}
bool isvowel(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
		ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}
void shiftandshrink(char*& arr, int& size) {
	char last = arr[size - 1]; 
	for (int i = 1; i < size; i++)
		arr[i - 1] = arr[i];

	if (isvowel(last)) {
		size--;  
		char* newarray = new char[size];
		for (int i = 0; i < size; i++)
			newarray[i] = arr[i];
		delete[] arr;
		arr = newarray;
	}
}
char* readcharacters(const char* filename, int& size) {
	ifstream read(filename);
	if (!read) {
		cerr << "File not found." << endl;
		return nullptr;
	}

	int capacity = 10;
	char* arr = new char[capacity];
	size = 0;
	char ch;

	while (read.get(ch)) {
		if (ch == '\n' || ch == '\r') continue; 
		if (size == capacity) {
			capacity *= 2;
			char* temp = new char[capacity];
			for (int i = 0; i < size; i++)
				temp[i] = arr[i];
			delete[] arr;
			arr = temp;
		}
		arr[size++] = ch;
	}

	read.close();
	return arr;
}
void displayz(char* arr, int size) {
	cout << "Modified Text: ";
	for (int i = 0; i < size; i++)
		cout << arr[i];
	cout << endl;
}


//Task 12: Rearrange Words 
int myStrLen(const char* s) {
	int len = 0;
	while (s[len] != '\0') len++;
	return len;
}
void myStrCpy(char* dest, const char* src) {
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
bool isDigitWord(const char* word) {
	int len = myStrLen(word);
	if (len == 0) return false;
	for (int i = 0; i < len; i++) {
		if (word[i] < '0' || word[i] > '9')
			return false;
	}
	return true;
}
bool isAlphaWord(const char* word) {
	int len = myStrLen(word);
	if (len == 0) return false;
	for (int i = 0; i < len; i++) {
		if (!((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z')))
			return false;
	}
	return true;
}
char** readRegrow(const char* filename, int& size) {
	ifstream fin(filename);
	if (!fin) return nullptr;

	char** arr = nullptr;
	int capacity = 0;
	size = 0;
	char buffer[100];

	while (fin >> buffer) {
		if (size == capacity) {
			int newCap = capacity == 0 ? 2 : capacity * 2;
			char** temp = new char* [newCap];
			for (int i = 0; i < size; i++)
				temp[i] = arr[i];
			delete[] arr;
			arr = temp;
			capacity = newCap;
		}
		int len = myStrLen(buffer);
		arr[size] = new char[len + 1];
		myStrCpy(arr[size], buffer);
		size++;
	}
	fin.close();
	return arr;
}
void separateWords(char** digitWords, char** alphaWords, char** original, int size) {
	int d = 0, a = 0;
	for (int i = 0; i < size; i++) {
		if (isDigitWord(original[i])) {
			digitWords[d++] = original[i];
		}
		else if (isAlphaWord(original[i])) {
			alphaWords[a++] = original[i];
		}
		
	}
}
void displayWords(char** digitWords, int digitCount, char** alphaWords, int alphaCount) {
	for (int i = 0; i < digitCount; i++) {
		cout << digitWords[i];
		if (i != digitCount - 1 || alphaCount > 0)
			cout << " ";
	}
	for (int i = 0; i < alphaCount; i++) {
		cout << alphaWords[i];
		if (i != alphaCount - 1)
			cout << " ";
	}
	cout << endl;
}
int main() {
	int size = 0;
	char** original = readRegrow("x.txt", size);
	if (original == nullptr) {
		cout << "Error reading file." << endl;
		return 1;
	}

	int digitCount = 0, alphaCount = 0;
	for (int i = 0; i < size; i++) {
		if (isDigitWord(original[i]))
			digitCount++;
		else if (isAlphaWord(original[i]))
			alphaCount++;
	}

	char** digitWords = new char* [digitCount];
	char** alphaWords = new char* [alphaCount];

	separateWords(digitWords, alphaWords, original, size);

	cout << "Modified Text: ";
	displayWords(digitWords, digitCount, alphaWords, alphaCount);

	for (int i = 0; i < size; i++) {
		delete[] original[i];
	}
	delete[] original;
	delete[] digitWords;
	delete[] alphaWords;
	return 0;
}