#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 10;

struct Node
{
    int key;
    char tenants[50];
    Node* next;
};

Node* table[MAX];

int hashFunc(int key)
{
    return key % MAX;
}

void insert(int key, const char tenants[])
{
    int index = hashFunc(key);

    Node* newNode = new Node;
    newNode->key = key;
    strcpy_s(newNode->tenants, tenants);
    newNode->next = NULL;

    if (table[index] == NULL)
    {
        table[index] = newNode;
    }
    else
    {
        Node* current = table[index];

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
    }
}

const char* search(int key)
{
    int index = hashFunc(key);

    if (table[index] == NULL)
    {
        return "�������� �� �������";
    }
    else
    {
        Node* current = table[index];

        while (current != NULL && current->key != key)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            return "�������� �� �������";
        }
        else
        {
            return current->tenants;
        }
    }
}

void remove(int key)
{
    int index = hashFunc(key);

    if (table[index] == NULL)
    {
        return;
    }
    else if (table[index]->key == key)
    {
        Node* temp = table[index];
        table[index] = table[index]->next;
        delete temp;
    }
    else
    {
        Node* current = table[index]->next;
        Node* prev = table[index];

        while (current != NULL && current->key != key)
        {
            prev = current;
            current = current->next;
        }

        if (current == NULL)
        {
            return;
        }
        else
        {
            prev->next = current->next;
            delete current;
        }
    }
}

void displayTable()
{
    for (int i = 0; i < MAX; i++)
    {
        cout << "�������� �� " << i << " �����: ";
        if (table[i] == NULL)
        {
            cout << "�����" << endl;
        }
        else
        {
            Node* current = table[i];
            while (current != NULL)
            {
                cout << current->key << " (" << current->tenants << ") ";
                current = current->next;
            }
            cout << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    for (int i = 0; i < MAX; i++)
    {
        table[i] = NULL;
    }

    insert(10, "������, �������");
    insert(201, "��������, �����");
    insert(305, "��������, ������");
    insert(405, "�������, ��������");
    insert(123, "�������, �������");
    insert(345, "�������, ������");
    insert(786, "��������, �������");
    insert(905, "�������, ������");

    displayTable(); // ������� ��� ���-�������

    cout << search(305) << endl;
    remove(305);
    cout << search(305) << endl;

    displayTable(); // ������� ����������� ���-�������

    return 0;
}