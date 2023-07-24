#include <iostream>
#include <cstring>

using namespace std;

struct Person {
    char name[50];
    char adress[50];
    int phone;
    char requisites[50];
    char contact_person[50];
};

// Функция для вывода информации о человеке

void display(Person p) {
    cout << "Name: " << p.name << endl;
    cout << "Adress: " << p.adress << endl;
    cout << "phone: " << p.phone << endl;
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
    cout << "Enter aderss: ";
    cin >> p.adress;
    cout << "Enter phone: ";
    cin >> p.phone;
    cout << "Enter requisites: ";
    cin >> p.requisites;
    cout << "Enter 	char contact_person: ";
    cin >> p.contact_person;
    persons[size] = p;
    size++;
}

// Функция для удаления человека по индексу

void removeByIndex(Person persons[], int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index" << endl;
        return;
    }

    for (int i = index; i < size - 1; i++) {
        persons[i] = persons[i + 1];
    }

    size--;
}

// Функция для удаления человека по имени

void removeByName(Person persons[], int& size, const char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(persons[i].name, name) == 0) {
            removeByIndex(persons, size, i);
            return;
        }
    }

    cout << "Person not found" << endl;
}

// Функция для изменения информации о человеке

void modify(Person persons[], int size, const char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(persons[i].name, name) == 0) {
            cout << "Current details:" << endl;
            display(persons[i]);
            cout << "Enter new name: ";
            cin >> persons[i].name;
            cout << "Enter new adress: ";
            cin >> persons[i].adress;
            cout << "Enter phone: ";
            cin >> persons[i].phone;
            cout << "Enter requisites: ";
            cin >> persons[i].requisites;
            cout << "Enter 	char contact_person: ";
            cin >> persons[i].contact_person;

            return;
        }
    }

    cout << "Person not found" << endl;
}

void removeAll(Person persons[], int& size) {
    size = 0;
}

int main() {
    const int MAX_SIZE = 100;
    Person persons[MAX_SIZE];
    int size = 0;
    int choice;
    char name[50];

    do {
        cout << "1. Add a person" << endl;
        cout << "2. Display all persons" << endl;
        cout << "3. Remove by index" << endl;
        cout << "4. Remove by name" << endl;
        cout << "5. Modify" << endl;
        cout << "6. Remove all" << endl;
        cout << "7. Exit" << endl;

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
            int index;
            cout << "Enter index: ";
            cin >> index;
            removeByIndex(persons, size, index);
            break;
        case 4:
            cout << "Enter name: ";
            cin >> name;
            removeByName(persons, size, name);
            break;
        case 5:
            cout << "Enter name: ";
            cin >> name;
            modify(persons, size, name);
            break;
        case 6:
            removeAll(persons, size);
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }

        cout << endl;
       
    } while (choice != 7);

    return 0;
}
