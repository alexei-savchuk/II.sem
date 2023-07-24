#include <iostream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

struct Date {
    int day : 6;    
    int month : 5;  
    int year : 12;  
};

struct Contact {
    string name;
    string surname;
    string patronymic;
    Date data;
    string address;
    string phone_number;
};


void print_contact(const Contact& c) {
    cout << "Name: " << c.name << endl;
    cout << "Surname: " << c.surname << endl;
    cout << "Patronymic: " << c.patronymic << endl;
    cout << "Data: " << c.data.day << "." << c.data.month << "." << c.data.year << endl;
    cout << "Address: " << c.address << endl;
    cout << "Phone number: " << c.phone_number << endl;
}


Contact input_contact() {
    Contact c;
    int day, month, year;
    cout << "Enter name: ";
    cin >> c.name;
    cout << "Enter surname: ";
    cin >> c.surname;
    cout << "Enter patronymic: ";
    cin >> c.patronymic;
    cout << "Enter date: ";
    cin >> day >> month >> year;
    c.data.day = day;
    c.data.month = month;
    c.data.year = year;
    cout << "Enter address: ";
    cin >> c.address;
    cout << "Enter phone number: ";
    cin >> c.phone_number;
    return c;
}


void delete_contact(Contact contacts[], int& count, int index) {
    for (int i = index; i < count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    count--;
}


void find_contact(const Contact contacts[], int count, const string& surname) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (contacts[i].surname == surname) {
            print_contact(contacts[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No contacts with surname " << surname << " found." << endl;
    }
}

int main() {
    const int MAX_CONTACTS = 100;
    Contact contacts[MAX_CONTACTS];
    int count = 0;

    while (true) {
        cout << endl;
        cout << "1. Add contact" << endl;
        cout << "2. Print all contacts" << endl;
        cout << "3. Delete contact" << endl;
        cout << "4. Find contact by surname" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            if (count < MAX_CONTACTS) {
                contacts[count] = input_contact();
                count++;
            }
            else {
                cout << "Maximum number of contacts reached." << endl;
            }
        }
        else if (choice == 2) {
            for (int i = 0; i < count; i++) {
                print_contact(contacts[i]);
            }
        }
        else if (choice == 3) {
            cout << "Enter index of contact to delete: ";
            int index;
            cin >> index;
            if (index >= 0 && index < count) {
                delete_contact(contacts, count, index);
            }
            else {
                cout << "Invalid index." << endl;
            }
        }
        else if (choice == 4) {
            cout << "Enter surname to search for: ";
            string surname;
            cin >> surname;
            find_contact(contacts, count, surname);
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}