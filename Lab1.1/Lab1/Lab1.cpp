#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void printA(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void DelitingNegEl(vector<int>& arr) {
    vector<int> result;
    for (int num : arr) {
        if (num >= 0) {
            result.push_back(num);
        }
    }
    arr = result;
}

int main() {
    int n;
    cout << "Enter the size of the array A: ";
    cin >> n;
    vector<int> A(n);
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
        ifstream inputFile("D:/C++ Project/Lab1/input.txt");
        if (!inputFile.is_open()) {
            cerr << "Failed to open input.txt file" << endl;
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
            A[i] = -50 + rand() % 101;
        }
    }
    break;
    default:
        cerr << "Incorrect choice of data entry method." << endl;
        return 1;
    }
    cout << "Initial array: ";
    printA(A);
    DelitingNegEl(A);
    cout << "Array after removing negative elements: ";
    printA(A);
    return 0;
}