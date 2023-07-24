#include <iostream>
#include <iomanip>

using namespace std;
#define str_len 30
#define size 3
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
int num[size] = { 1, 2, 3 }, ar;
void Room() {
	int floor[3] = { 2,5,3};
	int sqare[3] = { 50, 25, 40};
	string air[3] = { "Есть","Есть","Нету"};
	int cost[3] = { 200, 100, 160};
	int choice;
	cout << "=====================ROOMS=====================" << endl;
	cout << "Введите номер Помещения чтобы посмотреть информацию:" << endl;
	cout << "Помещение №1" << endl;
	cout << "Помещение №2" << endl;
	cout << "Помещение №3" << endl;

	cout << "--------------------------------" << endl;
	 for (int i = 0; i < 3; i++) {

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
	cout << "Пмещение №" << num[n] << endl;
	cout << "--------------------" << endl;
	cout << "Срок аренды: " << endl;
	cout << "Дата начала: "<<__TIMESTAMP__<< "; Срок аренды: "<< ar <<" месяца(цев)" << endl;
	cout << "==============================================" << endl;
	system("pause");
}

void Consent() {
	int a, x;
	cout << "====================CONSENT====================" << endl;
	cout << "Вы готовы арендовать помещение" << endl;
		cout << "Да - 1" << endl;
		cout << "Нет - 0" << endl;
		cin >> a;
		if (a == 1) {
			cout << "Какое помещение: " << endl;
			cin >> x;
			num[x];
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
	int g;
	int i = 0;
		
		for (int i = 0; i < 4; ) {
			cout << "(1)-Для Ввода данных" << endl;
			cout << "(2)-вывод пользователя по номеру телефона" << endl;
			cout << "(3)-Для вывода всех контрактов" << endl;
			cout << "(4)-Для выхода нажмите" << endl;
			cin >> g;
			switch (g)
			{
			case 1:
				cout << "********************WELCOME********************" << endl;
				SignUp();
				Room();
				Consent();
				break;
			case 2:
				int a;
				cin >> a;
				for (int i = 0; i < size; i++) {
					if (a == list_of_person[i].phone) {
						cout << "===================CONTRACT===================" << endl;
						cout << "Клиент №" << i << endl;
						cout << "Ф.И.О: ";
						cout << list_of_person[i].name << endl;
						cout << "Адрес: ";
						cout << list_of_person[i].adress << endl;
						cout << "Телефон: ";
						cout << list_of_person[i].phone << endl;
						cout << "Реквизиты: ";
						cout << list_of_person[i].requisites << endl;
						cout << "Контактне лицо: ";
						cout << list_of_person[i].contact_person << endl;
						cout << "--------------------" << endl;
						cout << "Пмещение №" << num[i] << endl;
						cout << "--------------------" << endl;
						cout << "Срок аренды: " << endl;
						cout << "Дата начала: " << __TIMESTAMP__ << "; Срок аренды: " << ar << " месяца(цев)" << endl;
						cout << "==============================================" << endl;
					}
				}
				break;
			case 3:
				for (int i = 0; i < 3; i++) {
					cout << "===================CONTRACT===================" << endl;
					cout << "Клиент №" << i << endl;
					cout << "Ф.И.О: ";
					cout << list_of_person[i].name << endl;
					cout << "Адрес: ";
					cout << list_of_person[i].adress << endl;
					cout << "Телефон: ";
					cout << list_of_person[i].phone << endl;
					cout << "Реквизиты: ";
					cout << list_of_person[i].requisites << endl;
					cout << "Контактне лицо: ";
					cout << list_of_person[i].contact_person << endl;
					cout << "--------------------" << endl;
					cout << "Пмещение №" << num[i] << endl;
					cout << "--------------------" << endl;
					cout << "Срок аренды: " << endl;
					cout << "Дата начала: " << __TIMESTAMP__ << "; Срок аренды: " << ar << " месяца(цев)" << endl;
					cout << "==============================================" << endl;
				}
				break;
			case 4:
				exit(0);
				break;
			default:
				break;
			}

		}
	}













