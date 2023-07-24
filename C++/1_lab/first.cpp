#include <iostream>
using namespace std;  

struct State {
	char name[20];
	char capital[20];
	int population;
	int sqare;
	char lastname[20];
};

int choice;

int structur() {
	int  i=0;
	const int size = 3;
	State a[size];
	if (i < size) {
		cout << "input name: " << i + 1 << "st state" << endl;
		cin >> a[i].name;
		cout << "capital: " << endl;
		cin >> a[i].capital;
		cout << "population: " << endl;
		cin >> a[i].population;
		cout << "sqare: " << endl;
		cin >> a[i].sqare;
		cout << "lastname of presdent: " << endl;
		cin >> a[i].lastname;
		i=i+1;
	}
	else {
		cout << "stop" << endl;
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
	return  0;
}
int output() {
	const int size = 3;
	State a[size];
	int c;
	cout << "input number of struct: " << endl;
	cin  >> c;
	cout << a[c].name;
	        a[c].capital;
	        a[c].population;
	        a[c].sqare;
	        a[c].lastname;
			cout << endl;
			return 0;		
}
int main() {
	setlocale(LC_CTYPE, "Russian");

	cout << "Введите:" << endl;
	cout << "1-для ввода новой записи" << endl;
	cout << "2-для вывода записи(ей)" << endl;
	cout << "3-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1: structur();	break;
		case 2: output();  break;
		}
	} while (choice != 5);

}