#include <iostream>
#include <fstream>

using namespace std;

void writeToFile(char* str) {
    ofstream file("FILE.txt");
    if (file.is_open()) {
        file << str;
        file.close();
    }
    else {
        cout << "Ошибка открытия файла" << endl;
    }
}

void readFromFile() {
    ifstream file("FILE.txt");
    if (file.is_open()) {
        char line[100];
        while (file.getline(line, 100)) {
            int i = 0;
            bool odd_number_found = false;
            while (line[i] != '\0') {
                if (isdigit(line[i])) {
                    int number = 0;
                    while (isdigit(line[i])) {
                        number = number * 10 + (line[i] - '0');
                        i++;
                    }
                    if (number % 2 == 1) {
                        cout << number << endl;
                        odd_number_found = true;
                    }
                }
                else {
                    i++;
                }
            }
            if (!odd_number_found) {
                cout << "Нечетные числа не найдены" << endl;
            }
        }
        file.close();
    }
    else {
        cout << "Ошибка открытия файла" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);

    writeToFile(str);

    readFromFile();

    return 0;
}
