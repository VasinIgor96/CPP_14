#include <iostream>
#include <windows.h>

using namespace std;

int* deleteElements(int* array, int& size, int index, int blockSize) {
    if (index < 0 || index >= size || blockSize <= 0)
        return array; 

    int newSize = size - blockSize;

    if (newSize <= 0)
        return nullptr; 

    int* newArray = new int[newSize];

    for (int i = 0; i < index; i++) {
        newArray[i] = array[i];
    }

    for (int i = index + blockSize; i < size; i++) {
        newArray[i - blockSize] = array[i];
    }

    size = newSize;

    delete[] array;

    return newArray;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int size = sizeof(array) / sizeof(array[0]);

    int index = 2;
    int blockSize = 4;

    int* newArray = deleteElements(array, size, index, blockSize);

    cout << "Оригінальний масив: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Новий масив: ";
    if (newArray != nullptr) {
        for (int i = 0; i < size; i++) {
            cout << newArray[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Масив порожній" << endl;
    }

    delete[] newArray;

    return 0;
}
