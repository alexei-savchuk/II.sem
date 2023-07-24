#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable : 4996)


int main() {
    setlocale(LC_ALL, "rus");
    int k;  // ����� ������, ������� ����� �����������
    FILE* input_file, * output_file;
    int n;  // ���������� �������� � �������
    double* matrix, * row;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("������ �������� ����� input.txt\n");
        exit(1);
    }

    // ��������� ���������� �������� �������
    fscanf(input_file, "%d", &n);

    matrix = (double*)malloc(n * n * sizeof(double));
    if (matrix == NULL) {
        printf("������ ��������� ������\n");
        exit(1);
    }

    // ��������� ������� �� �����
    for (int i = 0; i < n * n; i++) {
        fscanf(input_file, "%lf", &matrix[i]);
    }

    fclose(input_file);

    printf("������� ����� ������, ������� ����� ����������� (�� 1 �� %d): ", n);
    scanf("%d", &k);

    if (k < 1 || k > n) {
        printf("������������ ����� ������\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("������ �������� ����� output.txt\n");
        exit(1);
    }

    row = matrix + (k - 1) * n;

    // ���������� k-�� ������ � ����� ����
    for (int j = 0; j < n; j++) {
        fprintf(output_file, "%.2lf ", row[j]);
    }

    fclose(output_file);
    free(matrix);

    printf("������!\n");

    return 0;
}
