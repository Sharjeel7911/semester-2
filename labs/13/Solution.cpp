#include <iostream>
using namespace std;

bool is_symmetric(int* matrix, int size);
void transpose(int* matrix, int* transposeMatrix, int size);

int main() {
    const int row = 3, col = 3;

    int* matrix = new int[row * col];
    int* tmatrix = new int[row * col];

    cout << "Please enter inputs for 3x3 matrix:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> *(matrix + i * col + j);
        }
    }

    transpose(matrix, tmatrix, row);

    cout << "Original matrix:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) cout << *(matrix + i * col + j) << " ";
        cout << endl;
    }
    cout << "Transpose of the matrix:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) cout << *(tmatrix + i * col + j) << " ";
        cout << endl;
    }

    if (is_symmetric(matrix, row)) cout << endl << "The matrix is symmetric." << endl;
    else cout << endl << "The matrix is not symmetric." << endl;

    delete[] matrix;
    delete[] tmatrix;

    return 0;
}

bool is_symmetric(int* matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (*(matrix + i * size + j) != *(matrix + j * size + i)) {
                return false;
            }
        }
    }
    return true;
}
void transpose(int* matrix, int* tmatrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(tmatrix + j * size + i) = *(matrix + i * size + j);
        }
    }
}