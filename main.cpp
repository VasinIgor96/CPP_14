#include <iostream>
#include <windows.h>

using namespace std;

int* insertElements(int* array, int& size, int index, const int* block, int blockSize) {
    int* newArray = new int[size + blockSize];

    for (int i = 0; i < index; i++) {
        newArray[i] = array[i];
    }

    for (int i = 0; i < blockSize; i++) {
        newArray[index + i] = block[i];
    }

    for (int i = index; i < size; i++) {
        newArray[i + blockSize] = array[i];
    }

    size += blockSize;

    return newArray;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int array[] = { 1, 2, 3, 7, 8, 9 };
    int size = sizeof(array) / sizeof(array[0]);

    int block[] = { 4, 5, 6 };
    int blockSize = sizeof(block) / sizeof(block[0]);

    int index = 3;

    int* newArray = insertElements(array, size, index, block, blockSize);

    cout << "Оригінальний масив: ";
    for (int i = 0; i < size; i++) {
        cout << newArray[i] << " ";
    }
    cout << endl;

    cout << "Блок елементів: ";
    for (int i = 0; i < blockSize; i++) {
        cout << block[i] << " ";
    }
    cout << endl;

    cout << "Новий масив: ";
    for (int i = 0; i < size; i++) {
        cout << newArray[i] << " ";
    }
    cout << endl;

    delete[] newArray;

    return 0;
}
