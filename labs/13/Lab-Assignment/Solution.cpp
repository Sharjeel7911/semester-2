#include <iostream>
#include <fstream>
using namespace std;

int** allocate_matrix(int rows, int cols);
void read_matrix(ifstream& read, int** mat, int rows, int cols);
void print_matrix(int** mat, int rows, int cols);
void deallocate_matrix(int** mat, int rows);


void add_matrices();
void display_diagonal();
void column_wise();
void sort_rows();
void sum_rows_cols();
void rotate_90();
void dot_cross_product();
void create_jagged_array();
void cinema_jagged_array();


int main() {
    char choice;
    do {
        cout << endl << "--- Matrix & Jagged Array Menu ---" << endl;
        cout << "1. Add two matrices" << endl;
        cout << "2. Display diagonal" << endl;
        cout << "3. Display column-wise" << endl;
        cout << "4. Sort each row" << endl;
        cout << "5. Row-wise and column-wise sum" << endl;
        cout << "6. Rotate 90 degrees" << endl;
        cout << "7. Dot and cross product" << endl;
        cout << "8. Create jagged array (user input)" << endl;
        cout << "9. Cinema hall jagged array" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case '1': add_matrices(); break;
        case '2': display_diagonal(); break;
        case '3': column_wise(); break;
        case '4': sort_rows(); break;
        case '5': sum_rows_cols(); break;
        case '6': rotate_90(); break;
        case '7': dot_cross_product(); break;
        case '8': create_jagged_array(); break;
        case '9': cinema_jagged_array(); break;
        case '10': cout << "Exiting..." << endl; break;
        default: cout << "Invalid choice!" << endl;
        }
    } while (choice != '10');
    return 0;
}


int** allocate_matrix(int rows, int cols) {
    int** mat = new int* [rows];
    for (int i = 0; i < rows; ++i)
        mat[i] = new int[cols];
    return mat;
}
void read_matrix(ifstream& read, int** mat, int rows, int cols) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            read >> mat[i][j];
}
void print_matrix(int** mat, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
void deallocate_matrix(int** mat, int rows) {
    for (int i = 0; i < rows; ++i)
        delete[] mat[i];
    delete[] mat;
}


void add_matrices() {
    ifstream read("Data.txt");
    int r1, c1, r2, c2;
    read >> r1 >> c1;
    int** a = allocate_matrix(r1, c1);
    read_matrix(read, a, r1, c1);
    read >> r2 >> c2;
    int** b = allocate_matrix(r2, c2);
    read_matrix(read, b, r2, c2);

    if (r1 != r2 || c1 != c2) {
        cout << "Matrix dimensions do not match for addition." << endl;
        return;
    }

    int** sum = allocate_matrix(r1, c1);
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c1; ++j)
            sum[i][j] = a[i][j] + b[i][j];

    cout << "Sum of matrices:" << endl;
    print_matrix(sum, r1, c1);
    deallocate_matrix(a, r1);
    deallocate_matrix(b, r2);
    deallocate_matrix(sum, r1);
    read.close();
}
void display_diagonal() {
    ifstream read("Data.txt");
    int r, c;
    read >> r >> c;
    int** mat = allocate_matrix(r, c);
    read_matrix(read, mat, r, c);

    cout << "Diagonal elements:" << endl;
    for (int i = 0; i < r && i < c; ++i)
        cout << mat[i][i] << " ";
    cout << endl;

    deallocate_matrix(mat, r);
    read.close();
}
void column_wise() {
    ifstream read("Data.txt");
    int r, c;
    read >> r >> c;
    int** mat = allocate_matrix(r, c);
    read_matrix(read, mat, r, c);

    cout << "Column-wise display:" << endl;
    for (int j = 0; j < c; ++j) {
        for (int i = 0; i < r; ++i)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    deallocate_matrix(mat, r);
    read.close();
}
void sort_rows() {
    ifstream read("Data.txt");
    int r, c;
    read >> r >> c;
    int** mat = allocate_matrix(r, c);
    read_matrix(read, mat, r, c);

    cout << "Original matrix:" << endl;
    print_matrix(mat, r, c);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c - 1; ++j) {
            for (int k = 0; k < c - j - 1; ++k) {
                if (mat[i][j] > mat[i][j + 1]) {
                    int temp = mat[i][j];
                    mat[i][j] = mat[i][j + 1];
                    mat[i][j + 1] = temp;
                }
            }
        }
    }
    cout << "Sorted matrix (row-wise):" << endl;
    print_matrix(mat, r, c);
    deallocate_matrix(mat, r);
    read.close();
}
void sum_rows_cols() {
    ifstream read("Data.txt");
    int r, c;
    read >> r >> c;
    int** mat = allocate_matrix(r, c);
    read_matrix(read, mat, r, c);

    cout << "Row-wise sum: ";
    for (int i = 0; i < r; ++i) {
        int sum = 0;
        for (int j = 0; j < c; ++j)
            sum += mat[i][j];
        cout << sum << " ";
    }
    cout << endl;

    cout << "Column-wise sum: ";
    for (int j = 0; j < c; ++j) {
        int sum = 0;
        for (int i = 0; i < r; ++i)
            sum += mat[i][j];
        cout << sum << " ";
    }
    cout << endl;

    deallocate_matrix(mat, r);
    read.close();
}
void rotate_90() {
    ifstream read("data.txt");
    int n;
    read >> n;
    int** mat = allocate_matrix(n, n);
    read_matrix(read, mat, n, n);

    cout << "Original matrix:" << endl;
    print_matrix(mat, n, n);

    // Transpose
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }

    // Reverse rows
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n / 2; ++j) {
            int temp = mat[i][j];
            mat[i][j] = mat[i][n - 1 - j];
            mat[i][n - 1 - j] = temp;
        }

    cout << "Matrix after 90 degree rotation:" << endl;
    print_matrix(mat, n, n);
    deallocate_matrix(mat, n);
    read.close();
}
void dot_cross_product() {
    ifstream read("data.txt");
    int r1, c1;
    read >> r1 >> c1;
    int** a = allocate_matrix(r1, c1);
    read_matrix(read, a, r1, c1);

    int r2, c2;
    read >> r2 >> c2;
    int** b = allocate_matrix(r2, c2);
    read_matrix(read, b, r2, c2);

    if (r1 == 1 && r2 == 1 && c1 == c2 && c1 == 3) {
        int dot = 0;
        for (int i = 0; i < 3; ++i)
            dot += a[0][i] * b[0][i];
        cout << "Dot product: " << dot << endl;

        int cross[3];
        cross[0] = a[0][1] * b[0][2] - a[0][2] * b[0][1];
        cross[1] = a[0][2] * b[0][0] - a[0][0] * b[0][2];
        cross[2] = a[0][0] * b[0][1] - a[0][1] * b[0][0];

        cout << "Cross product: ";
        for (int i = 0; i < 3; ++i)
            cout << cross[i] << " ";
        cout << endl;
    }
    else {
        cout << "Cross product only supports 1x3 vectors." << endl;
    }

    deallocate_matrix(a, r1);
    deallocate_matrix(b, r2);
    read.close();
}
void create_jagged_array() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    int* sizes = new int[rows];
    int** jagged = new int* [rows];

    for (int i = 0; i < rows; ++i) {
        cout << "Enter number of elements in row " << i + 1 << ": ";
        cin >> sizes[i];
        jagged[i] = new int[sizes[i]];
        for (int j = 0; j < sizes[i]; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> jagged[i][j];
        }
    }

    cout << endl << "Jagged Array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < sizes[i]; ++j)
            cout << jagged[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < rows; ++i)
        delete[] jagged[i];
    delete[] jagged;
    delete[] sizes;
}
void cinema_jagged_array() {
    const int rows = 10;
    int seat_sizes[rows] = { 5, 5, 5, 7, 7, 7, 7, 12, 12, 12 };
    int** seats = new int* [rows];

    for (int i = 0; i < rows; ++i) {
        seats[i] = new int[seat_sizes[i]];
        for (int j = 0; j < seat_sizes[i]; ++j)
            seats[i][j] = 0; // 0 means empty
    }

    cout << "Initial Cinema Seating (0 = empty):" << endl;
    for (int i = 0; i < rows; ++i) {
        char row_label = 'A' + i;
        cout << row_label << ": ";
        for (int j = 0; j < seat_sizes[i]; ++j)
            cout << seats[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < rows; ++i)
        delete[] seats[i];
    delete[] seats;
}