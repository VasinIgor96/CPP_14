#include <iostream>
#include <windows.h>

using namespace std;

void countElements(const int* array, int size, int* negativePtr, int* positivePtr, int* zeroPtr) {
    int negativeCount = 0;
    int positiveCount = 0;
    int zeroCount = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] < 0)
            negativeCount++;
        else if (array[i] > 0)
            positiveCount++;
        else
            zeroCount++;
    }

    *negativePtr = negativeCount;
    *positivePtr = positiveCount;
    *zeroPtr = zeroCount;
}

int main() {

    SetConsoleCP(1251);           
    SetConsoleOutputCP(1251);  

    int numbers[] = { -2, 0, 4, -7, 0, 1, 0 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int negativeCount = 0, positiveCount = 0, zeroCount = 0;
    countElements(numbers, size, &negativeCount, &positiveCount, &zeroCount);

    cout << "Кількість від'ємних елементів: " << negativeCount << endl;
    cout << "Кількість додатніх елементів: " << positiveCount << endl;
    cout << "Кількість нульових елементів: " << zeroCount << endl;

    return 0;
}

