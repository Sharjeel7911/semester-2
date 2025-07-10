#include <iostream>
using namespace std;

void inputMarks(int** arr, int students, int quizzes);
int findMaxStudent(int** arr, int students, int quizzes);
void printBelowAverage(int** arr, int students, int quizzes);
void missedQuizzes(int** arr, int students, int quizzes);
void sortMarks(int* src, int size, int* dest);
void printSorted(int** arr, int students, int quizzes);
void calculateGrades(int** arr, int students, int quizzes);
void normalize(int** arr, float** norm, int students, int quizzes);
void printNormalized(float** norm, int students, int quizzes);

int main() {
    int students, quizzes;

    cout << "Enter number of students: ";
    cin >> students;
    cout << "Enter number of quizzes: ";
    cin >> quizzes;

    int** marks = new int* [students];
    for (int i = 0; i < students; ++i)  marks[i] = new int[quizzes];

    float** normalized = new float* [students];
    for (int i = 0; i < students; ++i) normalized[i] = new float[quizzes];

    inputMarks(marks, students, quizzes);
    int maxStudent = findMaxStudent(marks, students, quizzes);
    cout << "Student with max total marks: Student " << maxStudent + 1 << "\n\n";

    printBelowAverage(marks, students, quizzes);
    cout << endl;
    missedQuizzes(marks, students, quizzes);
    cout << endl;
    printSorted(marks, students, quizzes);
    cout << endl;
    calculateGrades(marks, students, quizzes);

    normalize(marks, normalized, students, quizzes);
    printNormalized(normalized, students, quizzes);

    for (int i = 0; i < students; ++i) {
        delete[] marks[i];
        delete[] normalized[i];
    }
    delete[] marks;
    delete[] normalized;

    return 0;
}

void inputMarks(int** arr, int students, int quizzes) {
    for (int i = 0; i < students; ++i) {
        cout << "Enter marks for Student " << i + 1 << " (-1 if quiz was missed):\n";
        for (int j = 0; j < quizzes; ++j) {
            cout << "Quiz " << j + 1 << ": ";
            cin >> arr[i][j];
        }
    }
}
int findMaxStudent(int** arr, int students, int quizzes) {
    int maxIndex = -1;
    int maxSum = -1;
    for (int i = 0; i < students; ++i) {
        int sum = 0;
        for (int j = 0; j < quizzes; ++j) {
            if (arr[i][j] != -1)
                sum += arr[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxIndex = i;
        }
    }
    return maxIndex;
}
void printBelowAverage(int** arr, int students, int quizzes) {
    for (int j = 0; j < quizzes; ++j) {
        int sum = 0, count = 0;
        for (int i = 0; i < students; ++i) {
            if (arr[i][j] != -1) {
                sum += arr[i][j];
                count++;
            }
        }
        if (count == 0) continue;
        float avg = (float)sum / count;

        cout << "Quiz " << j + 1 << " average: " << avg << " - Below average students: ";
        for (int i = 0; i < students; ++i) {
            if (arr[i][j] != -1 && arr[i][j] < avg)
                cout << i + 1 << " ";
        }
        cout << endl;
    }
}
void missedQuizzes(int** arr, int students, int quizzes) {
    cout << "Students who missed 50% or more quizzes:\n";
    for (int i = 0; i < students; ++i) {
        int missed = 0;
        for (int j = 0; j < quizzes; ++j)
            if (arr[i][j] == -1)
                missed++;
        if (missed >= (quizzes / 2))
            cout << "Student " << i + 1 << " missed " << missed << " quizzes\n";
    }
}
void sortMarks(int* src, int size, int* dest) {
    for (int i = 0; i < size; ++i)
        dest[i] = src[i];

    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (dest[j] > dest[j + 1]) {
                int t = dest[j];
                dest[j] = dest[j + 1];
                dest[j + 1] = t;
            }
}
void printSorted(int** arr, int students, int quizzes) {
    for (int i = 0; i < students; ++i) {
        int temp[10];
        sortMarks(arr[i], quizzes, temp);
        cout << "Student " << i + 1 << " sorted: ";
        for (int j = 0; j < quizzes; ++j)
            if (temp[j] != -1)
                cout << temp[j] << " ";
        cout << endl;
    }
}
void calculateGrades(int** arr, int students, int quizzes) {
    for (int i = 0; i < students; ++i) {
        int valid[10], count = 0, sum = 0;
        for (int j = 0; j < quizzes; ++j)
            if (arr[i][j] != -1) {
                valid[count++] = arr[i][j];
                sum += arr[i][j];
            }

        float avg = (count > 0) ? (float)sum / count : 0;
        float gradeAvg = (avg / 10.0f) * 15.0f;

        for (int a = 0; a < count - 1; ++a)
            for (int b = 0; b < count - a - 1; ++b)
                if (valid[b] < valid[b + 1]) {
                    int t = valid[b];
                    valid[b] = valid[b + 1];
                    valid[b + 1] = t;
                }

        int topSum = 0;
        for (int j = 0; j < 4 && j < count; ++j)
            topSum += valid[j];

        float topAvg = (float)topSum / 4.0f;
        float gradeTop4 = (topAvg / 10.0f) * 15.0f;

        cout << "Student " << i + 1 << ": Avg Method = " << gradeAvg << ", Top 4 Method = " << gradeTop4 << endl;
    }
}
void normalize(int** arr, float** norm, int students, int quizzes) {
    for (int j = 0; j < quizzes; ++j) {
        int max = 0;
        for (int i = 0; i < students; ++i)
            if (arr[i][j] > max)
                max = arr[i][j];

        for (int i = 0; i < students; ++i) {
            if (arr[i][j] == -1)
                norm[i][j] = 0;
            else
                norm[i][j] = (arr[i][j] / (float)max) * 10.0f;
        }
    }
}
void printNormalized(float** norm, int students, int quizzes) {
    cout << "\nNormalized Marks (out of 10):\n";
    for (int i = 0; i < students; ++i) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < quizzes; ++j)
            cout << norm[i][j] << " ";
        cout << endl;
    }
}