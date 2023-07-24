#include <iostream>
#include <fstream>
using namespace std;

// размеры массивов для имени и города
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;


// структура для элементов списка
struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};
// функция для вывода меню на экран и получения выбранного пункта
int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод имени" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Запись в файл" << endl;
	cout << "6. Считывание из фала" << endl;
	cout << "7. Удаление первого встречающегося элемента с заданным значением x" << endl;
	cout << "8. Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 8);
	return c;
}
// функция для добавления элемента в конец списка
void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;
	if (*plast == NULL) // если список пуст
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else  // если список не пуст
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
// функция для создания элемента и ввода его значений с клавиатуры
Address* setElement()     
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n'); // ввод имени
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');  // ввод города
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
// функция для вывода списка на экран
void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
// функция для поиска имени в списке
void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;  // если имя найдено, выходим из цикла
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
// функция для удаления имени из списка
void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имени
{
	struct Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))  break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}

//Функция Записи в файл

void writeToFile(Address* phead)       //Запись в файл
{
	Address* t = phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "A.txt", "wb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}

//Функция считывания из файла
void readFromFile(Address** phead, Address** plast) {
	Address* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "A.txt", "rb");
	if (err) {
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Чтение из файла" << endl;
	while (true) {
		t = new Address;
		if (!fread(t, sizeof(Address), 1, fp)) {
			delete t;
			break;
		}
		insert(t, phead, plast);
		cout << "Имя: " << t->name << endl;
		cout << "Город: " << t->city << endl;

	}
	fclose(fp);
}

// Функция удаления первого элемента списка
void deletX(char name[NAME_SIZE], Address** phead, Address** plast) {
	if (*phead == NULL) { // проверка на пустой список
		printf("Список пуст.\n");
		
	}

	Address* t = *phead; // временный указатель на начало списка
	if (strcmp(t->name, name) == 0) { // проверка совпадения имен
		*phead = (*phead)->next; // переназначение начала списка
		free(t); // освобождение памяти
		printf("Элемент удален.\n");
	
	}
	else {
		printf("Элемент не найден.\n");
	}
}


// главная функция программы
int main(void)
{
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: {	  char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {	  char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
		}
			  break;
		case 5:  writeToFile(head);
			break;
		case 6:  readFromFile(&head, &last);
			break;
		case 7: {	  char dname[NAME_SIZE];
			cout << "Введите x: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			deletX(dname, &head, &last);
		}
		case 8:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}