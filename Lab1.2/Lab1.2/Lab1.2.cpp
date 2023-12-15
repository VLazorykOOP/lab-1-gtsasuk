#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int findingMaxNeg(int* arr, int n, int T) {
    int pos_T = -1; 
    int pos_max = -1; 
    for (int i = 0; i < n; i++) {
        if (arr[i] == T && pos_T == -1) {
            pos_T = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (arr[i] > arr[pos_max] && i < pos_T) {
                pos_max = i;
            }
        }
        if (i == pos_T) {
            break; 
        }
    }
    cout << pos_T;
    return pos_max;
}

void printA(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array A: ";
    cin >> n;
    int T;
    cout << "Enter the value T: ";
    cin >> T;
    int* A = new int[n];
    char method;
    cout << "Choose a data entry method (a/b/c): ";
    cin >> method;
    switch (method) {
    case 'a':
        cout << "Enter array elements separated by space: ";
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        break;
    case 'b':
    {
        ifstream inputFile("D:/C++ Project/Lab1.2/L1.2.array.txt");
        if (!inputFile.is_open()) {
            cerr << "Failed to open L1.2.array.txt file" << endl;
            delete[] A;
            return 1;
        }
        for (int i = 0; i < n; i++) {
            inputFile >> A[i];
        }
        inputFile.close();
    }
    break;
    case 'c':
    {
        srand(static_cast<unsigned>(time(nullptr)));
        for (int i = 0; i < n; i++) {
            A[i] = -10 + rand() % 21;
        }
    }
    break;
    default:
        cerr << "Incorrect choice of data entry method." << endl;
        delete[] A;
        return 1;
    }
    cout << "Array A: ";
    printA(A, n);
    int pos_max = findingMaxNeg(A, n, T);
    cout << "pos_max: " << pos_max << endl;
    if (pos_max != -1) {
        cout << "The first maximum negative element before the first T element is at position " << pos_max << endl;
    }
    else {
        cout << "No negative elements found before the first T element." << endl;
    }
    delete[] A;
    return 0;
}