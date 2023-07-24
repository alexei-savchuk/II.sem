#include <iostream>
#include <deque>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int a = 1, *p = &a;
    deque<int> deq;
    for (int count = 1; count < 4; ++count)
    {
        deq.push_back(count); // вставляем числа в конец массива
        deq.push_front(10 - count); // вставляем числа в начало массива
    }

    for (int index = 0; index < deq.size(); ++index) {
        *p = a * deq[index];
        cout << deq[index] << ' ' << endl;
    }

   
    cout << "результат произведения элементов массива:" << endl;
    cout << *p << ' '<<endl;
}
