#include <iostream>
#include <fstream>
#include <cstdlib> 
using namespace std;

const int rows = 13;
const int cols = 6;

char* allocate_row(int cols);
void read_seat_map(ifstream& read, char** seat_map, int* col_sizes);
bool is_valid_class(int row, int class_type);
int get_column_index(char seat_char);
bool assign_seat(char** seat_map, int* col_sizes, int row, int col);
void menu(char** seat_map, int* col_sizes);
void write_seat_map(ofstream& write, char** seat_map, int* col_sizes);
void deallocate(char** seat_map);
void show_class_info(int class_type);
void show_available_seats(char** seat_map, int* col_sizes, int class_type);

void task1() {
    char** seat_map = new char* [rows];
    int* col_sizes = new int[rows];

    ifstream read("Map.txt");
    if (!read) {
        cout << "Cannot open file: Map.txt" << endl;
        return;
    }

    read_seat_map(read, seat_map, col_sizes);
    read.close();

    menu(seat_map, col_sizes);

    ofstream fout("Map.txt");
    if (!fout) {
        cout << "Cannot write to file: Map.txt" << endl;
        return;
    }

    write_seat_map(fout, seat_map, col_sizes);
    fout.close();

    deallocate(seat_map);
    delete[] col_sizes;
}

char* allocate_row(int cols) {
    char* row = new char[cols]; return row;
}
void read_seat_map(ifstream& read, char** seat_map, int* col_sizes) {
    for (int i = 0; i < rows; i++) {
        *(seat_map + i) = allocate_row(cols);
        for (int j = 0; j < cols; j++) {
            read >> *(*(seat_map + i) + j);
        }
        *(col_sizes + i) = cols;
    }
}
bool is_valid_class(int row, int class_type) {
    if (class_type == 1 && row >= 0 && row <= 1) return true;
    if (class_type == 2 && row >= 2 && row <= 6) return true;
    if (class_type == 3 && row >= 7 && row <= 12) return true;
    return false;
}
int get_column_index(char seat_char) {
    if (seat_char >= 'A' && seat_char <= 'F') return seat_char - 'A';
    if (seat_char >= 'a' && seat_char <= 'f') return seat_char - 'a';
    return -1;
}
bool assign_seat(char** seat_map, int* col_sizes, int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= *(col_sizes + row))
        return false;
    if (*(*(seat_map + row) + col) == '*') {
        *(*(seat_map + row) + col) = 'X';
        return true;
    }
    return false;
}
void show_class_info(int class_type) {
    if (class_type == 1) {
        cout << "You selected First Class (Rows 1-2)" << endl;
    }
    else if (class_type == 2) {
        cout << "You selected Business Class (Rows 3-7)" << endl;
    }
    else if (class_type == 3) {
        cout << "You selected Economy Class (Rows 8-13)" << endl;
    }
}
void show_available_seats(char** seat_map, int* col_sizes, int class_type) {
    int start = 0, end = 0;
    if (class_type == 1) { start = 0; end = 1; }
    else if (class_type == 2) { start = 2; end = 6; }
    else if (class_type == 3) { start = 7; end = 12; }

    cout << endl << "Available seats in this class: " << endl;
    bool any = false;

    for (int i = start; i <= end; i++) {
        for (int j = 0; j < *(col_sizes + i); j++) {
            if (*(*(seat_map + i) + j) == '*') {
                cout << "Row " << (i + 1) << " Seat " << char('A' + j) << endl;
                any = true;
            }
        }
    }

    if (!any) {
        cout << "No available seats in this class." << endl;
    }
}
void menu(char** seat_map, int* col_sizes) {
    int class_type, row_num;
    char seat_char;

    while (true) {
        system("cls");
        cout << "========== Seat Booking Menu ==========" << endl;
        cout << "1. First Class (Rows 1-2)" << endl;
        cout << "2. Business Class (Rows 3-7)" << endl;
        cout << "3. Economy Class (Rows 8-13)" << endl;
        cout << "4. Exit" << endl;
        cout << "=======================================" << endl;
        cout << "Enter your option: ";
        cin >> class_type;

        if (class_type == 4) break;

        show_class_info(class_type);
        show_available_seats(seat_map, col_sizes, class_type);

        char retry;
        do {
            cout << endl << "Enter desired Row: ";
            cin >> row_num;

            cout << "Enter Seat Letter (A-F): ";
            cin >> seat_char;

            int row = row_num - 1;
            int col = get_column_index(seat_char);

            if (!is_valid_class(row, class_type)) {
                cout << "Invalid row for the selected class." << endl;
                retry = 'y';
            }
            else if (assign_seat(seat_map, col_sizes, row, col)) {
                cout << "Seat successfully assigned." << endl;
                break;
            }
            else {
                cout << "Seat is either occupied or invalid." << endl;
                cout << "Do you want to try again? (y/n): ";
                cin >> retry;
            }
        } while (retry == 'y' || retry == 'Y');

        cout << endl;
        system("pause");
    }
}
void write_seat_map(ofstream& write, char** seat_map, int* col_sizes) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < *(col_sizes + i); j++) {
            write << *(*(seat_map + i) + j) << " ";
        }
        write << endl;
    }
}
void deallocate(char** seat_map) {
    for (int i = 0; i < rows; i++) delete[] * (seat_map + i);
    delete[] seat_map;
}
