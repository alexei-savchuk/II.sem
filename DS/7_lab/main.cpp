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

void display(Person p) {
    cout << "Name: " << p.name << endl;
    cout << "Address: " << p.address << endl;
    cout << "Phone: " << p.phone << endl;
    cout << "Requisites: " << p.requisites << endl;
    cout << "Contact person: " << p.contact_person << endl;
}

void displayAll(Person persons[], int size) {
    for (int i = 0; i < size; i++) {
        display(persons[i]);
        cout << endl;
    }
}

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

void removeByName(Person persons[], int& size, const char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(persons[i].name, name) == 0) {
            removeByIndex(persons, size, i);
            return;
        }
    }

    cout << "Person not found" << endl;
}

void modify(Person persons[], int size, const char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(persons[i].name, name) == 0) {
            cout << "Current details:" << endl;
            display(persons[i]);
            cout << "Enter new name: ";
            cin >> persons[i].name;
            cout << "Enter new address: ";
            cin >> persons[i].address;
            cout << "Enter phone: ";
            cin >> persons[i].phone;
            cout << "Enter requisites: ";
            cin >> persons[i].requisites;
            cout << "Enter contact person: ";
            cin >> persons[i].contact_person;

            return;
        }
    }

    cout << "Person not found" << endl;
}

void removeAll(Person persons[], int& size) {
    size = 0;
}

// Quicksort implementation for sorting by name and phone number
int partition(Person persons[], int low, int high) {
    Person pivot = persons[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(persons[j].name, pivot.name) < 0 ||
            (strcmp(persons[j].name, pivot.name) == 0 && persons[j].phone < pivot.phone)) {
            i++;
            swap(persons[i], persons[j]);
        }
    }

    swap(persons[i + 1], persons[high]);
    return i + 1;
}

void quicksort(Person persons[], int low, int high) {
    if (low < high) {
        int p = partition(persons, low, high);
        quicksort(persons, low, p - 1);
        quicksort(persons, p + 1, high);
    }
}

int main() {
    Person persons[100];
    int size = 0;
    int choice;
    do {
        cout << "1. Add person" << endl;
        cout << "2. Remove person by name" << endl;
        cout << "3. Modify person details" << endl;
        cout << "4. Display all persons" << endl;
        cout << "5. Remove all persons" << endl;
        cout << "6. Sort persons by name and phone number" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            add(persons, size);
            break;
        case 2: {
            char name[50];
            cout << "Enter name: ";
            cin >> name;
            removeByName(persons, size, name);
            break;
        }
        case 3: {
            char name[50];
            cout << "Enter name: ";
            cin >> name;
            modify(persons, size, name);
            break;
        }
        case 4:
            displayAll(persons, size);
            break;
        case 5:
            removeAll(persons, size);
            break;
        case 6:
            quicksort(persons, 0, size - 1);
            cout << "Sorted by name and phone number:" << endl;
            displayAll(persons, size);
            break;
        case 0:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}