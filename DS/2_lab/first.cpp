#include <iostream>
#include <iomanip>

using namespace std;
#define str_len 30
#define size 30
struct company
{
	

};
struct person {
	char name[str_len];
	char adress[str_len];
	int  phone;
	char requisites[str_len];
	char contact_person[str_len];
};
struct person list_of_person[size];
int current_size = 0;
int choice;
int num, ar;
void Room() {
	int floor[5] = { 2,5,3,1,4 };
	int sqare[5] = { 50, 25, 40, 20, 35 };
	string air[5] = { "Есть","Есть","Нету","Нету","Есть" };
	int cost[5] = { 200, 100, 160, 80, 140 };
	int choice;
	cout << "=====================ROOMS=====================" << endl;
	cout << "Введите номер Помещения чтобы посмотреть информацию:" << endl;
	cout << "Помещение №1" << endl;
	cout << "Помещение №2" << endl;
	cout << "Помещение №3" << endl;
	cout << "Помещение №4" << endl;
	cout << "Помещение №5" << endl;
	cout << "--------------------------------" << endl;
	 for (int i = 0; i < 5; i++) {

		cin >> choice;
		cout << "--------------------------------" << endl;
		cout << "Этаж: " << floor[choice - 1] << endl;
		cout << "Площадь: " << sqare[choice - 1] << " m^2 " << endl;
		cout << "Кондиционер: " << air[choice - 1] << endl;
		cout << "Стоимость: " << cost[choice - 1] << " BYN" << endl;
		cout << "--------------------------------" << endl;
		choice = 0;
	 }
	 system("pause");
	 system("cls");
}
void SignUp() {
	cout << "=================REGISTRATION=================" << endl;
	if (current_size < size)
	{
		cout << "Пользователь №: ";
		cout << current_size + 1 << endl;
		cout << "Ф.И.О: " << endl;
		cin >> list_of_person[current_size].name;
		cout << "Адрес: " << endl;
		cin >> list_of_person[current_size].adress;
		cout << "Телефон: " << endl;
		cin >> list_of_person[current_size].phone;
		cout << "Реквизиты: " << endl;
		cin >> list_of_person[current_size].requisites;
		cout << "Контактное лицо: " << endl;
		cin >> list_of_person[current_size].contact_person;
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";
	system("cls");
}

void Contract() {
	int n;
	cout << "Номер клиента:  " << endl;
	cin >> n;
	system("cls");
	cout << "===================CONTRACT===================" << endl;
	cout << "Клиент №" << n << endl;
	cout << "Ф.И.О: ";
	cout << list_of_person[n - 1].name << endl;
	cout << "Адрес: ";
	cout << list_of_person[n - 1].adress << endl;
	cout << "Телефон: ";
	cout << list_of_person[n - 1].phone << endl;
	cout << "Реквизиты: ";
	cout << list_of_person[n - 1].requisites << endl;
	cout << "Контактне лицо: ";
	cout << list_of_person[n - 1].contact_person << endl;
	cout << "--------------------" << endl;
	cout << "Пмещение №" << num << endl;
	cout << "--------------------" << endl;
	cout << "Срок аренды: " << endl;
	cout << "Дата начала: "<<__TIMESTAMP__<< "; Срок аренды: "<< ar <<" месяца(цев)" << endl;
	cout << "==============================================" << endl;
	system("pause");
}

void Consent() {
	int a;
	cout << "====================CONSENT====================" << endl;
	cout << "Вы готовы арендовать помещение" << endl;
		cout << "Да - 1" << endl;
		cout << "Нет - 0" << endl;
		cin >> a;
		if (a == 1) {
			cout << "Какое помещение: " << endl;
			cin >> num;
			cout << "На какой срок(в месяцах): " << endl;
			cin >> ar;
			Contract();
		}
		else if (a == 0) {
			cout << "Хорошего вам дня" << endl;
		}
		system("cls");
}


int main() {
	setlocale(LC_ALL, "rus");
	cout << "********************WELCOME********************" << endl;
	SignUp();
	Room();
	Consent();
}

