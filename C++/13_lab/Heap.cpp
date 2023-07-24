#include "Heap.h"
#include <iostream>
#include <iomanip>
void AAA::print()
{
	std::cout << x;
}
namespace heap
{
	Heap unionHeap(Heap heap1, Heap heap2)
	{
		int MaxSize = heap1.maxSize + heap2.maxSize;
		Heap res = create(MaxSize, heap1.compare);
		for (int i = 0; i < heap1.size; i++) {
			res.insert(heap1.storage[i]);
		}
		for (int i = 0; i < heap2.size; i++) {
			res.insert(heap2.storage[i]);
		}
		return res;
	}
	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix)
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix)
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) 	irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}
	void Heap::insert(void* x)
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[0];
			storage[0] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}
	void* Heap::extractMin()
	{
		void* rc = nullptr;
		void* min = nullptr;
		if (!isEmpty())
		{
			min = storage[0];
			for (int i = size - 1; i >= 0; i--) {
				if (((AAA*)min)->x > ((AAA*)storage[i])->x) {
					min = storage[i];
					storage[i] = storage[size - 1];
					storage[size - 1] = min;
				}
			}
			rc = min;
			std::cout << ((AAA*)min)->x << '\n';
			size--;
			heapify(0);
		} return rc;
	}
	void* Heap::extractI()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			int i = 0;
			std::cout << "Введите индекс удаляемого элемента: ";
			std::cin >> i;
			if (i < size && i>0) {
				rc = storage[i];
				storage[0] = storage[size - 1];
				size--;
				heapify(0);
			}
			else {
				std::cout << "Элемента с таким индексом не существует.";
			}
		} return rc;
	}

	void Heap::scan(int i) const     //Вывод значений элементов на экран
	{
		int probel = 20;
		std::cout << '\n';
		if (size == 0)
			std::cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{
			std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		std::cout << '\n';
	}
}
