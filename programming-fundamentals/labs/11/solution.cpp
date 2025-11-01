#include <iostream>
using namespace std; //2D arrays

//Task 1: Write a program to find the sum of all elements in the array.

int main1() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }

    int sum = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum += matrix[i][j];

    cout << "Sum of all elements = " << sum << endl;

    for (int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;
    return 0;
}

//Task 2: Write a program that takes a 2D array and returns its transpose (swap rows with columns).

int main2() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }

    int** transpose = new int* [cols];
    for (int i = 0; i < cols; i++)
        transpose[i] = new int[rows];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            transpose[j][i] = matrix[i][j];

    cout << endl << "Transposed Matrix:" << endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            cout << transpose[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;

    for (int i = 0; i < cols; i++) delete[] transpose[i];
    delete[] transpose;

    return 0;
}   

//Task 3: Write a program to print the primary diagonal elements of a square matrix.

int main3() {
    int n;

    cout << "Enter the size of square matrix: ";
    cin >> n;

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }

    cout << endl << "Primary Diagonal Elements: ";
    for (int i = 0; i < n; i++) {
        cout << matrix[i][i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) delete[] matrix[i];
    delete[] matrix;
    return 0;
}

//Task 4: Write a function to search for x in the array and return its position (row, col).

int main4() {
    int rows, cols, x;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }

    cout << "Enter the number to search: ";
    cin >> x;

    int found = 0;
    int rpos = -1;
    int cpos = -1;

    for (int i = 0; i < rows && found == 0; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == x) {
                rpos = i;
                cpos = j;
                found = 1;
                break; 
            }
        }
    }

    if (found == 1)
        cout << "Element found at position: (" << rpos << ", " << cpos << ")" << endl;
    else cout << "Element not found. Returning -1 " << endl;

    for (int i = 0; i < rows; i++)  delete[] matrix[i];
    delete[] matrix;
    return 0;
}

//Task 5: Write a function to find the index of the row in a 2D array that has the maximum sum of its elements.

int main5() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }

    int maxSum = -1;
    int maxRowIndex = -1;

    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }

        if (rowSum > maxSum) {
            maxSum = rowSum;
            maxRowIndex = i;
        }
    }
    cout << endl;
    cout << "Row with maximum sum is at index: " << maxRowIndex << endl;

    for (int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;
    return 0;
}