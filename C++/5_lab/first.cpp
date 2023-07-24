#include <iostream>
#include <fstream>
using namespace std;
struct list
{
    float number;
    list* next;
};

void insert(list*&, float); //функция добавления элемента, передается адрес списка и символ, который добавляется 
float del(list*&, float);   //функция удаления, передается адрес списка и сим-вол, который удаляется 
int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
void printList(list*);      //функция вывода
void menu(void);            //функция, показывающая меню
void sumDiv(list*);         //функция подсчета среднего значения суммы положитеьных элементов
void saveList(list *p);     //Запись в файл
void prList(list* first);

int main()
{
    setlocale(LC_CTYPE, "Russian");
    list* first = NULL;
    int choice;
    float value;
    menu();    // вывести меню 
    cout << " ? ";
    cin >> choice;
    while (choice != 6)
    {
        switch (choice)
        {
        case 1:  	cout << "Введите число "; // добавить число в список
            cin >> value;
            insert(first, value);
            printList(first);
            break;
        case 2:   if (!IsEmpty(first)) // удалить число из списка
        {
            cout << "Введите удаляемое число ";
            cin >> value;
            if (del(first, value))
            {
                cout << "Удалено число " << value << endl;
                printList(first);
            }
            else
                cout << "Число не найдено" << endl;
        }
              else
            cout << "Список пуст" << endl;
            break;
        case 3:   sumDiv(first);	// вычисление суммы	
            break;
        case 4:   saveList(first); // сохраняем список в файл "list.txt"
            break;
        case 5:   prList(first); // сохраняем список в файл "list.txt"
            break;
        default:  cout << "Неправильный выбор" << endl;
            menu();
            break;
        }
        cout << "?  ";
        cin >> choice;
    }
    cout << "Конец" << endl;
    return 0;
}

void menu(void)  //Вывод меню 
{
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод числа" << endl;
    cout << " 2 - Удаление числа" << endl;
    cout << " 3 - Вычисление среднего значение суммы положительных элементов" << endl;
    cout << " 4 - Запись в файл" << endl;
    cout << " 5 - Вывод данных из файла" << endl;
    cout << " 6 - Выход" << endl;
}

void insert(list*& p, float value) //Добавление числа value в список 
{
    list* newP = new list;
    if (newP != NULL)     //есть ли место?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

float del(list*& p, float value)  // Удаление числа 
{
    list* previous, * current, * temp;
    if (value == p->number)
    {
        temp = p;
        p = p->next;      // отсоединить узел 
        delete temp;      //освободить отсоединенный узел 
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; // перейти к следующему 
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

int IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
{
    return p == NULL;
}



void printList(list* p)  //Вывод списка 
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void saveList(list* p) // функция для сохранения списка в файл
{
    std::ofstream file("list.txt"); // создаем объект ofstream для записи в файл "list.txt"

    if (file.is_open()) // проверяем, открылся ли файл
    {
        while (p != NULL) // проходим по списку и записываем каждый элемент в файл
        {
            file << p->number << std::endl;
            p = p->next;
        }

        file.close(); // закрываем файл
    }
    else
    {
        std::cout << "Ошибка открытия файла!" << std::endl;
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

void sumDiv(list* p)  // Подсчет суммы чисел, больших 7  
{
    float sm = 0, i=0, div=0;

    if (p == NULL)
        cout << "Список пуст" << endl;
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
        cout << "Среднее значение положительных элементов = " << div << endl;
    }
}

