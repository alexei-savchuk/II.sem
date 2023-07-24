#include <iostream>
#include <string>
#include <string.h>

using namespace std;

typedef union { //typedef позволяет задать имя union
    struct {
        char surname[20];
        char name[20];
        char dadname[20];
        char birthday[10];
        char adress[20];
        char phone[20];
        char work_place[20];
        char post[20];
    } data;
} call;

int main() {
    setlocale(LC_ALL, "rus");
        call book[100];
    for (int i = 0; i < 100; i++) {
        cout << "Введите фамилию: " << endl;
        cin >> book[i].data.surname;
        cout << "Введите имя: " << endl;
        cin >> book[i].data.name;
        cout << "Введите отчество: " << endl;
        cin >> book[i].data.dadname;
        cout << "Введите дату рождения: " << endl;
        cin >> book[i].data.birthday;
        cout << "Введите адрес: " << endl;
        cin >> book[i].data.adress;
        cout << "Введите телефон: " << endl;
        cin >> book[i].data.phone;
        cout << "Введите место работы или учебы: " << endl;
        cin >> book[i].data.work_place;
        cout << "Введите должность: " << endl;
        cin >> book[i].data.post;

        cout << "Желаете продолжить? (+/-)" << endl;
        char choice;
        cin >> choice;
        if (choice == '-' || choice == '-') {
            break;
        }
    }
    system("cls");
    cout << "Введите фамилию для поиска: " << endl;
    char surname[20];
    cin >> surname;
    for (int i = 0; i < 100; i++) {
        if (strcmp(surname, book[i].data.surname) == 0) {
            cout << "Фамилия найдена: " << surname << endl;
            cout << "Ф.И.О: " << book[i].data.surname << " " << book[i].data.name << " " << book[i].data.dadname << endl;
            cout << "Дата рождения: " << book[i].data.birthday << endl;
            cout << "Адрес: " << book[i].data.adress << endl;
            cout << "Телефон: " << book[i].data.phone << endl;
            cout << "место работы или учебы : " << book[i].data.work_place << endl;
            cout << "Должность: " << book[i].data.post << endl;

        }
    }
    return 0;

}