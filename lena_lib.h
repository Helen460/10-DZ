#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

// ��������� ����ֲ�
int* allocateArray(int size);
void fillArrayWithRandomValues(int* ar, int size);
void printArray(int* ar, int size);
int* addElementAtEnd(int* ar, int& size, int value);
int* addElementAtStart(int* ar, int& size, int value);
int* removeElementAtEnd(int* ar, int& size);
int* removeElementAtStart(int* ar, int& size);
int* clearArray(int* ar, int& size);
void fillArraySequentially(int* ar, int size);
void sortArrayAscending(int* ar, int size);
void sortArrayDescending(int* ar, int size);
int sumOfArray(int* ar, int size);
double averageOfArray(int* ar, int size);
int productOfArray(int* ar, int size);
int findMaxInArray(int* ar, int size);

// ������� ��� �������� ���'�� �� �����
int* allocateArray(int size) {
    if (size > 0 && size < 1000000)
        return new int[size];
    else
        throw "Invalid size";
}

// ������� ��� ������ ���������� ������� � �����
void fillArrayWithRandomValues(int* ar, int size) {
    for (int i = 0; i < size; ++i) {
        ar[i] = rand() % 100; // �������� �������� �� 0 �� 99
    }
}

// ������� ��� ������ ������
void printArray(int* ar, int size) {
    for (int i = 0; i < size; ++i) {
        cout << ar[i] << ", ";
    }
    cout << "\n\n";
}

// ������� ��� ��������� ������ �������� � ����� ������
int* addElementAtEnd(int* ar, int& size, int value) {
    int* newArray = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        newArray[i] = ar[i];
    }
    newArray[size] = value;
    delete[] ar;
    ++size;
    return newArray;
}

// ������� ��� ��������� �������� �� ������� ������
int* addElementAtStart(int* ar, int& size, int value) {
    int* newArray = new int[size + 1];
    newArray[0] = value;
    for (int i = 0; i < size; ++i) {
        newArray[i + 1] = ar[i];
    }
    delete[] ar;
    ++size;
    return newArray;
}

// ������� ��� ��������� ���������� �������� ������
int* removeElementAtEnd(int* ar, int& size) {
    if (size <= 0) return ar;
    int* newArray = new int[size - 1];
    for (int i = 0; i < size - 1; ++i) {
        newArray[i] = ar[i];
    }
    delete[] ar;
    --size;
    return newArray;
}

// ��² ����ֲ�:
// ������� ��� ��������� ������� �������� ������
int* removeElementAtStart(int* ar, int& size) {
    if (size <= 0) return ar;
    int* newArray = new int[size - 1];
    for (int i = 1; i < size; ++i) {
        newArray[i - 1] = ar[i];
    }
    delete[] ar;
    --size;
    return newArray;
}

// ������� ��� ��������� ��� �������� ������
int* clearArray(int* ar, int& size) {
    delete[] ar;
    size = 0;
    return nullptr;
}

// ������� ��� ���������� ������ ����������� ������� �� 1 �� N
void fillArraySequentially(int* ar, int size) {
    for (int i = 0; i < size; ++i) {
        ar[i] = i + 1;
    }
}

// ������� ��� ���������� ������ �� ����������
void sortArrayAscending(int* ar, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (ar[j] > ar[j + 1]) {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
}

// ������� ��� ���������� ������ �� ���������
void sortArrayDescending(int* ar, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (ar[j] < ar[j + 1]) {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
}

// ������� ��� ��������� ���� ��� �������� ������
int sumOfArray(int* ar, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += ar[i];
    }
    return sum;
}

// ������� ��� ��������� ���������� �������������
double averageOfArray(int* ar, int size) {
    if (size == 0) return 0.0;
    return static_cast<double>(sumOfArray(ar, size)) / size;
}

// ������� ��� ��������� ������� ��� �������� ������
int productOfArray(int* ar, int size) {
    int product = 1;
    for (int i = 0; i < size; ++i) {
        product *= ar[i];
    }
    return product;
}

// ������� ��� ������ ������������� �������� ������
int findMaxInArray(int* ar, int size) {
    if (size == 0) return -1;
    int max = ar[0];
    for (int i = 1; i < size; ++i) {
        if (ar[i] > max) {
            max = ar[i];
        }
    }
    return max;
}