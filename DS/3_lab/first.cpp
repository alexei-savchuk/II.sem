#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdio.h>

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

void Contract();
void menu();
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
	menu();
} 
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
	Consent();
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
		cout << "Введено максимальное кол-во строк" << endl;
	system("cls");
	Room();
}

string namefile;
void Contract() {
	int n;
	cout << "Введите название файла" << endl;
	cin >> namefile;
		ofstream fout("D:\\labaratorki\\лабараторные работы 2 семестр\\СД\\"+namefile+".txt");
	cout << "Номер клиента:  " << endl;
	cin >> n;
	fout << "===================CONTRACT===================" << endl;
	fout << "Клиент №" << n << endl;
	fout << "Ф.И.О: ";
	fout << list_of_person[n - 1].name << endl;
	fout << "Адрес: ";
	fout << list_of_person[n - 1].adress << endl;
	fout << "Телефон: ";
	fout << list_of_person[n - 1].phone << endl;
	fout << "Реквизиты: ";
	fout << list_of_person[n - 1].requisites << endl;
	fout << "Контактне лицо: ";
	fout << list_of_person[n - 1].contact_person << endl;
	fout << "--------------------" << endl;
	fout << "Пмещение №" << num+1 << endl;
	fout << "--------------------" << endl;
	fout << "Срок аренды: " << endl;
	fout << "Дата начала: " << __TIMESTAMP__ << "; Срок аренды: " << ar << " месяца(цев)" << endl;
	fout << "==============================================" << endl;
	system("cls");
}
ifstream fin;
void Reeding() {
	ifstream fin("D:\\labaratorki\\лабараторные работы 2 семестр\\СД\\"+namefile+".txt"); // окрываем файл для чтения
	if (fin.is_open())
	{
		int n;
		cout << "Номер клиента:  " << endl;
		cin >> n;
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
		cout << "Дата начала: " << __TIMESTAMP__ << "; Срок аренды: " << ar << " месяца(цев)" << endl;
		cout << "==============================================" << endl;
	}

}



void deletef() {
	ofstream fout(namefile+".txt", ios_base::trunc);
}
int rem() {
	char filename[] = "File.txt";
	// remove the file "program.cpp"
	int result = remove(filename);
	cout << result;
	return 0;
	system("cls");
}

void menu() {
	int number;
	
	for (int i = 0; i < 99; i++) {
		cout << "Выбирете " << endl;
		cout << "0-Новая запись" << endl;
		cout << "1-Запись в файл:" << endl;
		cout << "2-Чтение файла:" << endl;
		cout << "3-Выход из файла:" << endl;
		cout << "4-Удаление содержмого файла" << endl;
		cout << "5-Удаление файла" << endl;
		cout << "6-Завершить программу:" << endl;
		cin >> number;
		switch (number)
		{
		case 0: SignUp(); break;
		case 1: Contract(); break;
		case 2: Reeding(); break;
		case 3: fin.close(); break;
		case 4: deletef(); break;
		case 5: rem(); break;
		case 6: i = 99; break;

		}
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	cout << "********************WELCOME********************" << endl;

	menu();


}