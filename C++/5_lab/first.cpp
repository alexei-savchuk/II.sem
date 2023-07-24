#include <iostream>
#include <fstream>
using namespace std;
struct list
{
    float number;
    list* next;
};

void insert(list*&, float); //������� ���������� ��������, ���������� ����� ������ � ������, ������� ����������� 
float del(list*&, float);   //������� ��������, ���������� ����� ������ � ���-���, ������� ��������� 
int IsEmpty(list*);         //�������, ������� ���������, ���� �� ������
void printList(list*);      //������� ������
void menu(void);            //�������, ������������ ����
void sumDiv(list*);         //������� �������� �������� �������� ����� ������������ ���������
void saveList(list *p);     //������ � ����
void prList(list* first);

int main()
{
    setlocale(LC_CTYPE, "Russian");
    list* first = NULL;
    int choice;
    float value;
    menu();    // ������� ���� 
    cout << " ? ";
    cin >> choice;
    while (choice != 6)
    {
        switch (choice)
        {
        case 1:  	cout << "������� ����� "; // �������� ����� � ������
            cin >> value;
            insert(first, value);
            printList(first);
            break;
        case 2:   if (!IsEmpty(first)) // ������� ����� �� ������
        {
            cout << "������� ��������� ����� ";
            cin >> value;
            if (del(first, value))
            {
                cout << "������� ����� " << value << endl;
                printList(first);
            }
            else
                cout << "����� �� �������" << endl;
        }
              else
            cout << "������ ����" << endl;
            break;
        case 3:   sumDiv(first);	// ���������� �����	
            break;
        case 4:   saveList(first); // ��������� ������ � ���� "list.txt"
            break;
        case 5:   prList(first); // ��������� ������ � ���� "list.txt"
            break;
        default:  cout << "������������ �����" << endl;
            menu();
            break;
        }
        cout << "?  ";
        cin >> choice;
    }
    cout << "�����" << endl;
    return 0;
}

void menu(void)  //����� ���� 
{
    cout << "�������� �����:" << endl;
    cout << " 1 - ���� �����" << endl;
    cout << " 2 - �������� �����" << endl;
    cout << " 3 - ���������� �������� �������� ����� ������������� ���������" << endl;
    cout << " 4 - ������ � ����" << endl;
    cout << " 5 - ����� ������ �� �����" << endl;
    cout << " 6 - �����" << endl;
}

void insert(list*& p, float value) //���������� ����� value � ������ 
{
    list* newP = new list;
    if (newP != NULL)     //���� �� �����?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "�������� ���������� �� ���������" << endl;
}

float del(list*& p, float value)  // �������� ����� 
{
    list* previous, * current, * temp;
    if (value == p->number)
    {
        temp = p;
        p = p->next;      // ����������� ���� 
        delete temp;      //���������� ������������� ���� 
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; // ������� � ���������� 
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            delete(temp);
            return value;
        }
    }
    return 0;
}

int IsEmpty(list* p) //������  ������? (1-��, 0-���) 
{
    return p == NULL;
}



void printList(list* p)  //����� ������ 
{
    if (p == NULL)
        cout << "������ ����" << endl;
    else
    {
        cout << "������:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void saveList(list* p) // ������� ��� ���������� ������ � ����
{
    std::ofstream file("list.txt"); // ������� ������ ofstream ��� ������ � ���� "list.txt"

    if (file.is_open()) // ���������, �������� �� ����
    {
        while (p != NULL) // �������� �� ������ � ���������� ������ ������� � ����
        {
            file << p->number << std::endl;
            p = p->next;
        }

        file.close(); // ��������� ����
    }
    else
    {
        std::cout << "������ �������� �����!" << std::endl;
    }
}


void prList(list* first)
{
    list* current = first;

    while (current != NULL)
    {
        cout << current->number << " ";
        current = current->next;
    }

    cout << endl;
}

void sumDiv(list* p)  // ������� ����� �����, ������� 7  
{
    float sm = 0, i=0, div=0;

    if (p == NULL)
        cout << "������ ����" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number > 0) {
                ++i;
                sm += p->number;
            }
            div = sm / i;
            p = p->next;
        }
        cout << i << endl;
        cout << "������� �������� ������������� ��������� = " << div << endl;
    }
}

