#include <iostream>
#include <windows.h>

using namespace std;

int* removeNegativeNumbers(const int* array, int size, int& newSize) {
    int positiveCount = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] >= 0)
            positiveCount++;
    }

    int* positiveArray = new int[positiveCount];
    int currentIndex = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] >= 0)
            positiveArray[currentIndex++] = array[i];
    }

    newSize = positiveCount; 

    return positiveArray;    
}

int main() {

    SetConsoleCP(1251);         
    SetConsoleOutputCP(1251);  

    int array[] = { -2, 3, -5, 1, 0, -4, 7, -9 };
    int size = sizeof(array) / sizeof(array[0]);

    int newSize = 0;
    int* positiveArray = removeNegativeNumbers(array, size, newSize);

    cout << "Оригінальний масив: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Масив без від'ємних чисел: ";
    for (int i = 0; i < newSize; i++) {
        cout << positiveArray[i] << " ";
    }
    cout << endl;

    delete[] positiveArray;
    return 0;
}
