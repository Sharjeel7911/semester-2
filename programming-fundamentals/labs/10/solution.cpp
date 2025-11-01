#include <iostream>
#include <fstream>
using namespace std;

//Task 1: Counting prime numbers
 
int* readdata(const char* filename, int& size);
bool isprime(int num);
int countprime(int* arr, int size);
int main1() {
    int size;
    int* numbers = readdata("Data.txt", size);

    if (numbers == nullptr) return 1;

    int total = countprime(numbers, size);
    cout << "Total Prime Numbers: " << total << endl;
    delete[] numbers; 
    return 0;
}
int* readdata(const char* filename, int& size) {
    ifstream read(filename);
    if (!read) {
        cout << "Error opening file!" << endl;
        size = 0;
        return nullptr;
    }

    int num;
    size = 0;

    while (read >> num) {
        size++;
    }

    int* data = new int[size];

    read.clear();
    read.seekg(0);

    for (int i = 0; i < size; i++) {
        read >> data[i];
    }

    read.close();
    return data;
}
bool isprime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int countprime(int* arr, int size) {
    int primeCount = 0;
    for (int i = 0; i < size; i++) {
        if (isprime(arr[i])) {
            primeCount++;
        }
    }
    return primeCount;
}

//Task 2: Reverse File Data

void printarray(int* arr, int size);
void reversearray(int* arr, int size);
int main2() {
    int size;
    int* data = readdata("Data.txt", size);

    if (data == nullptr) return 1;

    cout << "Original Data: ";
    printarray(data, size);

    reversearray(data, size);

    cout << "Reversed Data: ";
    printarray(data, size);
    delete[] data; 
    return 0;
}
void printarray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void reversearray(int* arr, int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

//Task 3: Find Second Maximum

int findsecondmax(int* arr, int size);
int main3() {
    int size;
    int* data = readdata("data.txt", size);
    if (data == nullptr) return 1;

    int secondMax = findsecondmax(data, size);

    if (secondMax == -1) {
        cout << "No second maximum found." << endl;
    }
    else {
        cout << "Second Maximum: " << secondMax << endl;
    }
    delete[] data;
    return 0;
}
int findsecondmax(int* arr, int size) {
    if (size < 2) return -1; 

    int max1 = arr[0];
    int max2 = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max1) {
            max1 = arr[i];
        }
    }

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] < max1) {
            if ((!found) || (arr[i] > max2)) {
                max2 = arr[i];
                found = true;
            }
        }
    }

    if (found) return max2;
    else return -1; 
}

//Task 4: Remove Duplicates

bool exists(int* arr, int size, int value);
int* unique(int* data, int size, int& newSize);
int main4() {
    int size;
    int* data = readdata("data.txt", size);
    if (data == nullptr) return 1;

    int uniqueSize;
    int* uniqueData = unique(data, size, uniqueSize);

    cout << "Modified Data (Unique): ";
    printarray(uniqueData, uniqueSize);

    delete[] data;
    delete[] uniqueData;
    return 0;

}
bool exists(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value)
            return true;
    }
    return false;
}
int* unique(int* data, int size, int& newSize) {
    int* unique = nullptr;
    newSize = 0;

    for (int i = 0; i < size; i++) {
        if (!exists(unique, newSize, data[i])) {
            int* temp = new int[newSize + 1];
            for (int j = 0; j < newSize; j++) {
                temp[j] = unique[j];
            }
            temp[newSize] = data[i];
            delete[] unique;
            unique = temp;
            newSize++;
        }
    }
    return unique;
}

//Task 5: Character Frequency Count

char* readcharacters(const char* filename, int& size);
void countvowels(char* data, int size);
int main5() {
    int size;
    char* text = readcharacters("Text.txt", size);
    if (!text) return 1;

    countvowels(text, size);

    delete[] text;
    return 0;
}
char* readcharacters(const char* filename, int& size) {
    ifstream read(filename);
    if (!read) {
        cout << "Error opening file!" << endl;
        size = 0;
        return nullptr;
    }

    size = 0;
    char ch;
    while (read.get(ch)) {
        size++;
    }

    read.clear();
    read.seekg(0);

    char* data = new char[size];
    for (int i = 0; i < size; i++) {
        read.get(data[i]);
    }

    read.close();
    return data;
}
void countvowels(char* data, int size) {
    int a = 0, e = 0, i = 0, o = 0, u = 0;

    for (int j = 0; j < size; j++) {
        char ch = data[j];
        if (ch == 'a' || ch == 'A') a++;
        else if (ch == 'e' || ch == 'E') e++;
        else if (ch == 'i' || ch == 'I') i++;
        else if (ch == 'o' || ch == 'O') o++;
        else if (ch == 'u' || ch == 'U') u++;
    }

    cout << "a: " << a << endl;
    cout << "e: " << e << endl;
    cout << "i: " << i << endl;
    cout << "o: " << o << endl;
    cout << "u: " << u << endl;
}

//Task 6: Filter Palindromic Words

int size();
void readddata(char*& arr, int s);
void upperl(char ch[]);
int len(char ch[]);
bool ispalindrome(char ch[]);
void copy(char* arr, int s, char* ch);
char* regrow(char* arr, int& s, char ch[]);
int main6() {
    int s = size();
    char* arr = new char[s];
    readddata(arr, s);

    char word[15];
    ifstream read("Text.txt");
    char* array = new char[1];
    array[0] = '\0';
    int x = 0;

    while (read >> word)
    {
        upperl(word);
        if (ispalindrome(word))
        {
            array = regrow(array, x, word);
        }
    }
    cout << "Palindrome Words: " << endl;
    cout << array << endl;
    delete[] arr;
    delete[] array;
}
int size() {
    int size = 0;
    char ch;
    ifstream read("Text.txt");
    while (read >> ch)
    {
        size++;
    }
    read.close();
    return size;
}
void readddata(char*& arr, int s) {
    ifstream read("Text.txt");
    for (int i = 0; i < s; i++)
    {
        read >> arr[i];
    }
    read.close();
}
void upperl(char ch[]) {
    for (int i = 0; ch[i] != '\0'; i++)
    {
        if (ch[i] >= 'a' && ch[i] <= 'z')
        {
            ch[i] = ch[i] - 32;
        }
    }
}
int len(char ch[]) {
    int i = 0;
    while (ch[i] != '\0')
    {
        i++;
    }
    return i;
}
bool ispalindrome(char ch[]) {
    int length = len(ch);
    for (int i = 0; i < length / 2; i++)
    {
        if (ch[i] != ch[length - i - 1])
        {
            return false;
        }
    }
    return true;
}
void copy(char* arr, int s, char* ch) {
    for (int i = 0; i < s; i++)
    {
        arr[i] = ch[i];
    }
}
char* regrow(char* arr, int& s, char ch[]) {
    int length = len(ch);
    char* narr = new char[s + length + 2];
    copy(narr, s, arr);
    for (int i = 0; i < length; i++)
    {
        narr[s + i] = ch[i];
    }
    narr[s + length] = ' ';
    narr[s + length + 1] = '\0';
    s = s + length + 1;
    delete[] arr;
    return narr;
}