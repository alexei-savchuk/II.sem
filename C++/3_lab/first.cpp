#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable : 4996)


int main() {
    setlocale(LC_ALL, "rus");
    int k;  // Номер строки, которую нужно скопировать
    FILE* input_file, * output_file;
    int n;  // Количество столбцов в матрице
    double* matrix, * row;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Ошибка открытия файла input.txt\n");
        exit(1);
    }

    // Считываем количество столбцов матрицы
    fscanf(input_file, "%d", &n);

    matrix = (double*)malloc(n * n * sizeof(double));
    if (matrix == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    // Считываем матрицу из файла
    for (int i = 0; i < n * n; i++) {
        fscanf(input_file, "%lf", &matrix[i]);
    }

    fclose(input_file);

    printf("Введите номер строки, которую нужно скопировать (от 1 до %d): ", n);
    scanf("%d", &k);

    if (k < 1 || k > n) {
        printf("Неправильный номер строки\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Ошибка открытия файла output.txt\n");
        exit(1);
    }

    row = matrix + (k - 1) * n;

    // Записываем k-ую строку в новый файл
    for (int j = 0; j < n; j++) {
        fprintf(output_file, "%.2lf ", row[j]);
    }

    fclose(output_file);
    free(matrix);

    printf("Готово!\n");

    return 0;
}
