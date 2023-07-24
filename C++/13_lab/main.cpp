#include "Heap.h"
#include <iostream>
#include <Windows.h>
using namespace std;
heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}

int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(3, cmpAAA);
	heap::Heap unionH = heap::create(33, cmpAAA);
	for (;;)
	{
		cout << "1 - вывод кучи на экран" << endl;
		cout << "2 - добавить элемент" << endl;
		cout << "3 - удалить максимальный элемент" << endl;
		cout << "4 - удалить минимальный элемент" << endl;
		cout << "5 - удалить i-ый элемент" << endl;
		cout << "6 - объединить две очереди" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;  cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:  h1.scan(0);
			break;
		case 2: {	AAA* a = new AAA;
			cout << "введите ключ" << endl; 	cin >> k;
			a->x = k;
			h1.insert(a);
		}
			  break;
		case 3:   h1.extractMax();
			break;
		case 4:   h1.extractMin(); break;
		case 5:   h1.extractI(); break;
		case 6:
			for (int i = 0; i < h2.maxSize; i++) {
				AAA* a = new AAA;
				a->x = rand() % 100;
				h2.insert(a);
			}
			unionH = unionHeap(h1, h2);
			h1.scan(0);
			h2.scan(0);
			unionH.scan(0);
			break;
		default:  cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}
