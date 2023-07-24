#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    ifstream file1("FILE1.txt");
    ofstream file2("FILE2.txt");

    char first_word[50];
    file1 >> first_word;

    char line[100];
    int count_letters = 0;

    while (file1.getline(line, 100)) {
        bool found_word = false;
        int i = 0;
        while (line[i] != '\0') {
            if (line[i] == ' ') {
                line[i] = '\0';
                if (strcmp(line, first_word) == 0) {
                    found_word = true;
                    break;
                }
                line[i] = ' ';
            }
            i++;
        }
        if (found_word) {
            file2 << line << endl;
            count_letters += i;
        }
    }

    cout << "Количество букв в файле FILE2: " << count_letters << endl;

    file1.close();
    file2.close();

    return 0;
}



