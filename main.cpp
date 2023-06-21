#include <iostream>
#include <windows.h>

using namespace std;

int* addElementsToEnd(const int* array, int size, const int* block, int blockSize, int& newSize) {
   
    int* newArray = new int[size + blockSize];

    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }

    for (int i = 0; i < blockSize; i++) {
        newArray[size + i] = block[i];
    }

    newSize = size + blockSize;  

    return newArray;           
}

int main() {

    SetConsoleCP(1251);           
    SetConsoleOutputCP(1251);     

    int array[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(array) / sizeof(array[0]);

    int block[] = { 6, 7, 8 };
    int blockSize = sizeof(block) / sizeof(block[0]);

    int newSize = 0;
    int* newArray = addElementsToEnd(array, size, block, blockSize, newSize);

    cout << "Оригінальний масив: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Блок елементів: ";
    for (int i = 0; i < blockSize; i++) {
        cout << block[i] << " ";
    }
    cout << endl;

    cout << "Новий масив: ";
    for (int i = 0; i < newSize; i++) {
        cout << newArray[i] << " ";
    }
    cout << endl;

    delete[] newArray;  

    return 0;
}
