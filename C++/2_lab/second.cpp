#include <iostream>
#include <string>
#include <string.h>

using namespace std;

typedef union { //typedef ��������� ������ ��� union
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
        cout << "������� �������: " << endl;
        cin >> book[i].data.surname;
        cout << "������� ���: " << endl;
        cin >> book[i].data.name;
        cout << "������� ��������: " << endl;
        cin >> book[i].data.dadname;
        cout << "������� ���� ��������: " << endl;
        cin >> book[i].data.birthday;
        cout << "������� �����: " << endl;
        cin >> book[i].data.adress;
        cout << "������� �������: " << endl;
        cin >> book[i].data.phone;
        cout << "������� ����� ������ ��� �����: " << endl;
        cin >> book[i].data.work_place;
        cout << "������� ���������: " << endl;
        cin >> book[i].data.post;

        cout << "������� ����������? (+/-)" << endl;
        char choice;
        cin >> choice;
        if (choice == '-' || choice == '-') {
            break;
        }
    }
    system("cls");
    cout << "������� ������� ��� ������: " << endl;
    char surname[20];
    cin >> surname;
    for (int i = 0; i < 100; i++) {
        if (strcmp(surname, book[i].data.surname) == 0) {
            cout << "������� �������: " << surname << endl;
            cout << "�.�.�: " << book[i].data.surname << " " << book[i].data.name << " " << book[i].data.dadname << endl;
            cout << "���� ��������: " << book[i].data.birthday << endl;
            cout << "�����: " << book[i].data.adress << endl;
            cout << "�������: " << book[i].data.phone << endl;
            cout << "����� ������ ��� ����� : " << book[i].data.work_place << endl;
            cout << "���������: " << book[i].data.post << endl;

        }
    }
    return 0;

}