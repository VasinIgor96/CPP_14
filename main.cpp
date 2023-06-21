#include <iostream>
#include <windows.h>
using namespace std;

void calculateSumAndProduct(const int* array, int size, int* sumPtr, int* productPtr) {
    int sum = 0;
    int product = 1;

    for (int i = 0; i < size; i++) {
        sum += array[i];
        product *= array[i];
    }

    *sumPtr = sum;
    *productPtr = product;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int numbers[] = { 2, 4, 6, 8, 10 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int sum, product;
    calculateSumAndProduct(numbers, size, &sum, &product);

    cout << "Сума: " << sum << endl;
    cout << "Добуток: " << product << endl;

    return 0;
}
