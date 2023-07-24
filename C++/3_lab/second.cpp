#include <stdio.h>
#pragma warning(disable : 4996)
#define FILE_A "NameA.txt"
#define FILE_B "NameB.txt"
#define FILE_C "NameC.txt"
#define FILE_D "NameD.txt"

int main() {
    FILE* file_a, * file_b, * file_c, * file_d;
    int a, b, c;

    file_a = fopen(FILE_A, "r");
    file_b = fopen(FILE_B, "r");
    file_c = fopen(FILE_C, "r");
    file_d = fopen(FILE_D, "w");

    if (file_a == NULL || file_b == NULL || file_c == NULL || file_d == NULL) {
        printf("Failed to open file(s)\n");
        return 1;
    }

    while (fscanf(file_a, "%d", &a) == 1 &&
        fscanf(file_b, "%d", &b) == 1 &&
        fscanf(file_c, "%d", &c) == 1) {
        fprintf(file_d, "%d\n", (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c));
    }

    fclose(file_a);
    fclose(file_b);
    fclose(file_c);
    fclose(file_d);

    return 0;
}
