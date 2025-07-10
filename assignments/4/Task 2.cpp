#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int max_employees = 10;
const int name_len = 20;

char* allocate_char_array(int size);
float* allocate_float_row(int cols);
void read_data(ifstream& read, char names[][name_len], float** data, int& count);
void calculate_pay(float** data, int count);
float calculate_average(float** data, int count);
void print_high_earners(char names[][name_len], float** data, int count, float avg);
void print_all(char names[][name_len], float** data, int count);

void task2() {
    char names[max_employees][name_len];
    float** data = new float* [max_employees]; 

    for (int i = 0; i < max_employees; i++) {
        *(data + i) = allocate_float_row(3);
    }

    int count = 0;

    ifstream read("Employee.txt");
    if (!read) {
        cout << "Cannot open file: Employee.txt" << endl;
        return;
    }

    read_data(read, names, data, count);
    read.close();

    calculate_pay(data, count);
    float avg = calculate_average(data, count);

    cout << endl << "All employee data:" << endl << endl;
    print_all(names, data, count);

    cout << endl << "Average weekly pay: Rs. " << fixed << setprecision(2) << avg << endl;

    cout << endl << "Employees earning more than average" << endl;
    print_high_earners(names, data, count, avg);

    for (int i = 0; i < max_employees; i++) delete[] * (data + i);
    delete[] data;
}

char* allocate_char_array(int size) {
    char* arr = new char[size]; return arr;
}
float* allocate_float_row(int cols) {
    float* row = new float[cols]; return row;
}
void read_data(ifstream& read, char names[][name_len], float** data, int& count) {
    while (count < max_employees && read >> *(names + count)) {
        read >> *(*(data + count) + 0);
        read >> *(*(data + count) + 1);
        count++;
    }
}
void calculate_pay(float** data, int count) {
    for (int i = 0; i < count; i++) {
        float hours = *(*(data + i) + 0);
        float rate = *(*(data + i) + 1);
        float pay = 0;
        if (hours <= 40) pay = hours * rate;
        else pay = 40 * rate + (hours - 40) * 1.5 * rate;
        *(*(data + i) + 2) = pay;
    }
}
float calculate_average(float** data, int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) sum += *(*(data + i) + 2);
    return sum / count;
}
void print_all(char names[][name_len], float** data, int count) {
    cout << left << setw(12) << "Name" << setw(12) << "Hours" << setw(12) << "Rate" << setw(12) << "Pay" << endl;
    for (int i = 0; i < count; i++) {
        cout << left << setw(12) << *(names + i) << setw(12) << *(*(data + i) + 0) << setw(12) << *(*(data + i) + 1) << setw(12) << *(*(data + i) + 2) << endl;
    }
}
void print_high_earners(char names[][name_len], float** data, int count, float avg) {
    for (int i = 0; i < count; i++) {
        float pay = *(*(data + i) + 2);
        if (pay >= avg) cout << setw(12) << *(names + i) << ": " << pay << endl;
    }
}