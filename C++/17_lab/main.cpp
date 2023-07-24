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

// Алгоритм сортировки Хоара (быстрая сортировка)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low + 1;
        int j = high;
        while (i <= j) {
            while (i <= j && arr[i] <= pivot) {
                i++;
            }
            while (i <= j && arr[j] > pivot) {
                j--;
            }
            if (i < j) {
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[low], arr[j]);

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}



void heapify(int arr[], int size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != root) {
        std::swap(arr[root], arr[largest]);
        heapify(arr, size, largest);
    }
}

// Алгоритм пирамидальной сортировки
void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    for (int i = size - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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

    int sizes[] = { 1000, 2000, 3000, 4000, 5000 };
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        int* arr = new int[size];

        fillArray(arr, size);

        std::cout << "Original array (" << size << " elements): ";
        printArray(arr, size);
        std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;

        // Сортировка массива с помощью алгоритма Хоара (быстрая сортировка)
        clock_t startTime = clock();
        quickSort(arr, 0, size - 1);
        clock_t endTime = clock();
        double quickSortTime = double(endTime - startTime) / CLOCKS_PER_SEC;
        std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;

        std::cout << "Array sorted with Quick Sort: ";
        printArray(arr, size);
        std::cout << "Time taken by Quick Sort: " << quickSortTime << " seconds" << std::endl;

        fillArray(arr, size);  // Перезаполняем массив случайными числами
    std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
        // Сортировка массива с помощью пирамидальной сортировки
        startTime = clock();
        heapSort(arr, size);
        endTime = clock();
        double heapSortTime = double(endTime - startTime) / CLOCKS_PER_SEC;

        std::cout << "Array sorted with Heap Sort: ";
        printArray(arr, size);
        std::cout << "Time taken by Heap Sort: " << heapSortTime << " seconds" << std::endl;

        fillArray(arr, size);  // Перезаполняем массив случайными числами
        std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;

        // Сортировка массива с помощью сортировки выбором
        startTime = clock();
        selectionSort(arr, size);
        endTime = clock();
        double selectionSortTime = double(endTime - startTime) / CLOCKS_PER_SEC;

        std::cout << "Array sorted with Selection Sort: ";
        printArray(arr, size);
        std::cout << "Time taken by Selection Sort: " << selectionSortTime << " seconds" << std::endl;

        delete[] arr;
    }

    return 0;
}
