#include <iostream>
#include<fstream>
using namespace std;

void readx(ifstream& read, int array[], int& size) {
	size = 0;
	while (read >> *(array + size)) {
		size++;
	}

}
int main1()
{
	int array[100] = {};
	int size = 0;
	ifstream read("x.txt");
	if (!read) {
		cout << "Error: Unable to open file." << endl;
		return 1;
	}
	
	readx(read, array, size);
	read.close();

	for (int i = 0; i < size; i++) {
		cout << *(array + i) << " ";
	}
	return 0;
}

int main2() {
	cout << "How many elements do you want?" << endl;
	int x;
	cin >> x;

	int* array = new int[x];

	for (int i = 0; i < x ; i++) {
		cin >> array[i]; //*(array+i)
	}

	for (int i = 0; i < x / 2; i++) {
		int temp = *(array + i);
		*(array + i) = *(array + (x - 1 - i));
		*(array + (x - 1 - i)) = temp;
	}
	cout << endl;

	for (int i = 0; i < x; i++) {
		cout << *(array + i) << " ";
	}
	delete[] array;

	return 0;
}

//PRACTICE 
//Task 1
void filesize(int& size);
void readfile(ifstream& read,int array[]);
void writeresult(int result[], int array[], int size);
bool checkpair(int value, int array[], int size);

int main3() {
	int size = 0;
	filesize(size);
	int* array = new int[size];
	ifstream read("Data.txt");
	if (!read) {
		cout << "Error: Unable to open file." << endl;
		return 1;
	}
	readfile(read, array);
	int* result = new int[size];
	writeresult(result, array, size);


	delete[] array;
	delete[] result;

	return 0;

}
void filesize(int& size) {
	ifstream read("Data.txt");
	if (!read) {
		cout << "Error: Unable to open file." << endl;
		return;
	}
	int x;
	while (read >> x) {
		size++;
	}
}
void readfile(ifstream& read, int array[]) {
	int i = 0;
	while (read >> *(array + i)) {
		i++;
	}
}
void writeresult(int result[], int array[], int size) {
	int index = 0;
	for (int i = 0; i < size; i++) {
		bool alreadyAdded = false;
		for (int j = 0; j < index; j++) {
			if (result[j] == array[i]) {
				alreadyAdded = true;
				break;
			}
		}

		if (!checkpair(array[i], array, size) && !alreadyAdded) {
			result[index++] = array[i];
		}
	}

	cout << "Final Result (excluding pairs): ";
	for (int i = 0; i < index; i++) {
		cout << result[i] << " ";
	}
	cout << endl;
}
bool checkpair(int value, int array[], int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (*(array + i) == value) {
			count++;
		}
	}
	return count == 2; 
}


// *** FINAL PRACTICE ***

//1
void take_input(int students, int quiz, int** array);
void average_score(int students, int quiz, int** array, float** average);
void highest_lowest(int students, float** average);
int main4() {
	int students, quiz;

	cout << "How many students? ";
	cin >> students;

	cout << "How many quizzes? ";
	cin >> quiz;

	int** array = new int* [students];

	take_input(students,quiz,array);

	float** average = new float* [students];
	for (int i = 0; i < students; i++) average[i] = new float[2];
	average_score(students, quiz, array, average);

	highest_lowest(students, average);

	for (int i = 0; i < students; i++) {
		delete[] array[i];
		delete[] average[i];
	}
	delete[] array;
	delete[] average;

	return 0;
}
void take_input(int students, int quiz, int** array) {
	for (int i = 0; i < students; i++) array[i] = new int[quiz];
	cout << "Enter marks for each student" << endl;
	for (int i = 0; i < students; i++) {
		cout << "Student: " << i + 1 << endl;
		for (int j = 0; j < quiz; j++) {
			cin >> array[i][j];
		}
	}
}
void average_score(int students, int quiz, int** array, float** average) {
	for (int i = 0; i < students; i++) {
		int sum = 0;
		for (int j = 0; j < quiz; j++) {
			sum += array[i][j];
		}
		float avg = float(sum) / quiz;
		average[i][0] = i;
		average[i][1] = avg;
	}
	cout << "Average score of every student: " << endl;
	for (int i = 0; i < students; i++) {
		cout << "Student " << int(average[i][0]) + 1 << ": " << average[i][1] << endl;
	}
}
void highest_lowest(int students, float** average) {
	float highest = average[0][1];
	float lowest = average[0][1];
	int highest_index = average[0][0]; 
	int lowest_index = average[0][0];

	for (int i = 1; i < students; i++) {
		float avg = average[i][1];

		if (avg > highest) {
			highest = avg;
			highest_index = average[i][0];
		}

		if (avg < lowest) {
			lowest = avg;
			lowest_index = average[i][0];
		}
	}

	cout << "Highest Average: " << highest << " by Student " << highest_index + 1 << endl;
	cout << "Lowest Average: " << lowest << " by Student " << lowest_index + 1 << endl;
}

//2

void size_of_file(int &size);
void read_data_from_file(ifstream& read, char** students, int* roll, float* gpa, int size);
void descending(char** students, int* roll, float* gpa, int size);
void find_student(char** students, int* roll, float* gpa, int size);
int main5() {
	int size = 0;
	size_of_file(size);
	char** students = new char* [size];
	for (int i = 0; i < size; i++) students[i] = new char[50];
	int* roll = new int[size];
	float* gpa = new float[size];

	ifstream read("Students.csv");
	if (!read) {
		cout << "Error: Unable to open file." << endl;
		return 1;
	}
	read_data_from_file(read,students,roll,gpa,size);

	descending(students, roll, gpa, size);

	find_student(students, roll, gpa, size);

	for (int i = 0; i < size; i++) delete[] students[i];
	delete[] students;
	delete[] gpa;
	delete[] roll;
	return 0;
}
void size_of_file(int& size) {
	ifstream read("Students.csv");
	if (!read) {
		cout << "Error: Unable to open file." << endl;
		return;
	}
	char array[100];
	while (read.getline(array, 100)) {
		size++;
	}
}
void read_data_from_file(ifstream& read, char** students, int* roll, float* gpa, int size) {
	for (int i = 0; i < size; i++) {
		char ch;
		int j = 0;

		while (read.get(ch) && ch != ',' && j < 50) {
			students[i][j++] = ch;
		}
		students[i][j] = '\0';

		read >> roll[i];
		read.ignore(); 
		read >> gpa[i];
		read.ignore();  
	}
}
void descending(char** students, int* roll, float* gpa, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (gpa[j] < gpa[j + 1]) {
				float temp_gpa = gpa[j];
				gpa[j] = gpa[j + 1];
				gpa[j + 1] = temp_gpa;

				int temp_roll = roll[j];
				roll[j] = roll[j + 1];
				roll[j + 1] = temp_roll;

				char* temp_name = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp_name;

			}
		}
	}
	for (int i = 0; i < size; i++) {
		cout << "Name: " << students[i] << ", Roll: " << roll[i] << ", GPA: " << gpa[i] << endl;
	}
}
void find_student(char** students, int* roll, float* gpa, int size) {
	cout << "Enter Roll number" << endl;
	int x;
	cin >> x;

	bool isfound = false;
	for (int i = 0; i < size; i++) {
		if (roll[i] == x) {
			cout << "Name: " << students[i] << ", Roll: " << roll[i] << ", GPA: " << gpa[i] << endl;
			isfound = true;
			break;
		}
	}
	if (!isfound) {
		cout << "Student not found." << endl;
	}

}

//3
//Sparse matrix

int main6() {
	int n;
	cout << "Enter matrix size: ";
	cin >> n;

	int** matrix = new int* [n];
	int count = 0;

	cout << "Enter matrix elements (" << n << "x" << n << "):\n";
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] != 0) count++;
		}
	}

	int** compressed = new int* [count];
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != 0) {
				compressed[k] = new int[3];
				compressed[k][0] = i;
				compressed[k][1] = j;
				compressed[k][2] = matrix[i][j];
				k++;
			}
		}
	}

	cout << "Compressed Matrix (row, col, value):" << endl;
	for (int i = 0; i < count; i++) {
		cout << "(" << compressed[i][0] << "," << compressed[i][1] << ")" << "," << compressed[i][2] << endl;
	}

	int** original = new int* [n];
	for (int i = 0; i < n; i++) {
		original[i] = new int[n];
		for (int j = 0; j < n; j++) {
			original[i][j] = 0;
		}
	}

	for (int i = 0; i < count; i++) {
		int r = compressed[i][0];
		int c = compressed[i][1];
		int v = compressed[i][2];
		original[r][c] = v;
	}

	cout << "Reconstructed Full Matrix:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << original[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
		delete[] original[i];
	}
	delete[] matrix;
	delete[] original;

	for (int i = 0; i < count; i++) {
		delete[] compressed[i];
	}
	delete[] compressed;

	return 0;
}

//4

void read_matrix(int** matrix, int size);
int main7() {
	const int size = 5;
	int** matrix = new int* [size];

	for (int i = 0; i < size; i++) matrix[i] = new int[size - i];

	read_matrix(matrix, size);

	//Display
	for (int i = 0; i < size; i++) {
		int k = 0;
		for (int j = 0; j < size; j++) {
			if (j < i) cout << "0 ";
			else cout << matrix[i][k++] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < size; i++) delete[] matrix[i];
	delete[] matrix;
	return 0;
}
void read_matrix(int** matrix, int size) {
	ifstream read("Matrix.txt");
	if (!read) {
		cout << "Error";
		return;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			read >> matrix[i][j];
		}
	}
	read.close();
}

//5
//Regrow & Shrink

void read_regrow(int*& array, int& size);
int* regrow(int* array, int size, int capacity);
int* shrink(int* array, int size);
int main8() {
	int* array = nullptr;
	int size = 0;
	read_regrow(array, size);

	cout << "Data read from file (Total " << size << " elements):" << endl;
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}

	return 0;
}
void read_regrow(int*& array, int& size) {
	ifstream read("Data.txt");
	if (!read) {
		cout << "Error";
		return;
	}
	size = 0;
	int capacity = 2;
	int num;
	array = new int[capacity];

	while (read >> num) {
		if (size == capacity) {
			array = regrow(array, size, capacity * 2);
			capacity *= 2;
		}
		array[size++] = num;
	}
	array = shrink(array, size);
}
int* regrow(int* array, int size, int capacity) {
	int* new_array = new int[capacity * 2];
	for (int i = 0; i < size; i++) {
		new_array[i] = array[i];
	}
	delete[] array;
	return new_array;
}
int* shrink(int* array, int size) {
	int* new_array = new int[size];
	for (int i = 0; i < size; i++) {
		new_array[i] = array[i];
	}
	delete[] array;
	return new_array;
}

