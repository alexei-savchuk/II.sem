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
        deq.push_back(count); // ��������� ����� � ����� �������
        deq.push_front(10 - count); // ��������� ����� � ������ �������
    }

    for (int index = 0; index < deq.size(); ++index) {
        *p = a * deq[index];
        cout << deq[index] << ' ' << endl;
    }

   
    cout << "��������� ������������ ��������� �������:" << endl;
    cout << *p << ' '<<endl;
}
