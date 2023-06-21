#include <iostream>
#include <windows.h>

using namespace std;
const int* findSubset(const int* A, int sizeA, const int* B, int sizeB) {
    for (int i = 0; i <= sizeA - sizeB; i++) {
        bool subsetFound = true;

        for (int j = 0; j < sizeB; j++) {
            if (A[i + j] != B[j]) {
                subsetFound = false;
                break;
            }
        }

        if (subsetFound) {
            return &A[i];
        }
    }

    return nullptr;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);  

    int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int B[] = { 4, 5, 6 };

    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);

    const int* subsetPtr = findSubset(A, sizeA, B, sizeB);

    if (subsetPtr != nullptr) {
        cout << "Масив B є підмножиною масиву A, починаючи з елемента: " << *subsetPtr << endl;
    }
    else {
        cout << "Масив B не є підмножиною масиву A." << endl;
    }

    return 0;
}
