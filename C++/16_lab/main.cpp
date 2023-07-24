#include <iostream>
#include <ctime>
#include <algorithm>

// Функция для заполнения массива случайными числами
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  // Заполняем случайными числами от 0 до 99
    }
}

// Функция для вывода массива на экран
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Функция для копирования элементов с четными индексами из массива A в массив B
void copyEvenElements(const int arrA[], int sizeA, int arrB[], int& sizeB) {
    sizeB = 0;
    for (int i = 0; i < sizeA; i += 2) {
        arrB[sizeB] = arrA[i];
        sizeB++;
    }
}

// Алгоритм сортировки пузырьком
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Алгоритм сортировки выбором
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {
    srand(time(0));  // Инициализируем генератор случайных чисел

    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int* arrA = new int[size];
    int* arrB = new int[size / 2];
    int sizeB;

    fillArray(arrA, size);
    std::cout << "Array A (original): ";
    printArray(arrA, size);

    copyEvenElements(arrA, size, arrB, sizeB);
    std::cout << "Array B (copied even elements from A): ";
    printArray(arrB, sizeB);

    // Сортировка массива B с помощью алгоритма "пузырек"
    clock_t startBubbleSort = clock();
    bubbleSort(arrB, sizeB);
    clock_t endBubbleSort = clock();

    std::cout << "Array B (sorted with bubble sort): ";
    printArray(arrB, sizeB);
    std::cout << "Time taken for bubble sort: " << double(endBubbleSort - startBubbleSort) / CLOCKS_PER_SEC << " seconds" << std::endl;

    // Сортировка массива B с помощью алгоритма сортировки выбором
    clock_t startSelectionSort = clock();
    selectionSort(arrB, sizeB);
    clock_t endSelectionSort = clock();

    std::cout << "Array B (sorted with selection sort): ";
    printArray(arrB, sizeB);
    std::cout << "Time taken for selection sort: " << double(endSelectionSort - startSelectionSort) / CLOCKS_PER_SEC << " seconds" << std::endl;

    delete[] arrA;
    delete[] arrB;

    return 0;
}
