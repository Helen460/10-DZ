#include "lena_lib.h"

int main() {
    setlocale(0, "UKR");
    srand((time(0)));

    int size = 10;
    int* arr = allocateArray(size);

    fillArrayWithRandomValues(arr, size);
    cout << "Масив пiсля заповнення випадковими значеннями:\n";
    printArray(arr, size);

    arr = addElementAtEnd(arr, size, 999);
    cout << "Масив пiсля додавання елемента в кiнець:\n";
    printArray(arr, size);

    arr = addElementAtStart(arr, size, 777);
    cout << "Масив пiсля додавання елемента в початок:\n";
    printArray(arr, size);

    arr = removeElementAtEnd(arr, size);
    cout << "Масив пiсля видалення елемента з кiнця:\n";
    printArray(arr, size);

    arr = removeElementAtStart(arr, size);
    cout << "Масив пiсля видалення елемента з початку:\n";
    printArray(arr, size);

    fillArraySequentially(arr, size);
    cout << "Масив пiсля заповнення послiдовними числами:\n";
    printArray(arr, size);

    sortArrayDescending(arr, size);
    cout << "Масив пiсля сортування за спаданням:\n";
    printArray(arr, size);

    sortArrayAscending(arr, size);
    cout << "Масив пiсля сортування за зростанням:\n";
    printArray(arr, size);

    cout << "Сума елементiв масиву: " << sumOfArray(arr, size) << "\n";
    cout << "Середнє арифметичне: " << averageOfArray(arr, size) << "\n";
    cout << "Добуток елементiв: " << productOfArray(arr, size) << "\n";
    cout << "Максимальний елемент: " << findMaxInArray(arr, size) << "\n\n";

    arr = clearArray(arr, size);
    cout << "Масив пiсля очищення. Поточний розмiр: " << size << "\n";

    delete[] arr;
}