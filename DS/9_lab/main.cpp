#include <iostream>
#include <cstring>

using namespace std;

struct Person {
    char name[50];
    char address[50];
    int phone;
    char requisites[50];
    char contact_person[50];
};

// Функция для вывода информации о человеке
void display(Person p) {
    cout << "Name: " << p.name << endl;
    cout << "Address: " << p.address << endl;
    cout << "Phone: " << p.phone << endl;
    cout << "Requisites: " << p.requisites << endl;
    cout << "Contact person: " << p.contact_person << endl;
}

// Функция для вывода информации о всех людях
void displayAll(Person persons[], int size) {
    for (int i = 0; i < size; i++) {
        display(persons[i]);
        cout << endl;
    }
}

// Функция для добавления нового человека в массив
void add(Person persons[], int& size) {
    Person p;
    cout << "Enter name: ";
    cin >> p.name;
    cout << "Enter address: ";
    cin >> p.address;
    cout << "Enter phone: ";
    cin >> p.phone;
    cout << "Enter requisites: ";
    cin >> p.requisites;
    cout << "Enter contact person: ";
    cin >> p.contact_person;
    persons[size] = p;
    size++;
}

// Функция для удаления всех людей из массива
void removeAll(Person persons[], int& size) {
    size = 0;
}

// Функция для интерпретирующего поиска по индексу
int searchByIndex(Person persons[], int size, char name[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(persons[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Если не найдено
}

// Функция для бинарного поиска по полю phone
int searchByPhone(Person persons[], int size, int phone) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (persons[mid].phone == phone) {
            return mid;
        }
        else if (persons[mid].phone < phone) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // Если не найдено
}

int main() {
    const int MAX_SIZE = 100;
    Person persons[MAX_SIZE];
    int size = 0;
    int choice;
    char name[50];
    int phone;
    int index;

    do {
        cout << "1. Add a person" << endl;
        cout << "2. Display all persons" << endl;
        cout << "3. Search by name" << endl;
        cout << "4. Search by phone" << endl;
        cout << "5. Remove all" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cout << "*********************************************************" << endl;

        switch (choice) {
        case 1:
            add(persons, size);
            break;
        case 2:
            displayAll(persons, size);
            break;
        case 3:
            cout << "Enter name: ";
            cin >> name;
            index = searchByIndex(persons, size, name);
            if (index != -1) {
                display(persons[index]);
            }
            else {
                cout << "Person not found" << endl;
            }
            break;
        case 4:
            
            cout << "Enter phone: ";
            cin >> phone;
            index = searchByPhone(persons, size, phone);
            if (index != -1) {
                display(persons[index]);
            }
            else {
                cout << "Person not found" << endl;
            }
            break;
        case 5:
            removeAll(persons, size);
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }


    cout << "*********************************************************" << endl;

} while (choice != 6);

return 0;
}