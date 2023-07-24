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
	cout << "�� ������ ���������� ���������" << endl;
	cout << "�� - 1" << endl;
	cout << "��� - 0" << endl;
	cin >> a;
	if (a == 1) {
		cout << "����� ���������: " << endl;
		cin >> num;
		cout << "�� ����� ����(� �������): " << endl;
		cin >> ar;
		Contract();
	}
	else if (a == 0) {
		cout << "�������� ��� ���" << endl;
	}
	system("cls");
	menu();
} 
void Room() {
	int floor[5] = { 2,5,3,1,4 };
	int sqare[5] = { 50, 25, 40, 20, 35 };
	string air[5] = { "����","����","����","����","����" };
	int cost[5] = { 200, 100, 160, 80, 140 };
	int choice;
	cout << "=====================ROOMS=====================" << endl;
	cout << "������� ����� ��������� ����� ���������� ����������:" << endl;
	cout << "��������� �1" << endl;
	cout << "��������� �2" << endl;
	cout << "��������� �3" << endl;
	cout << "��������� �4" << endl;
	cout << "��������� �5" << endl;
	cout << "--------------------------------" << endl;
	for (int i = 0; i < 5; i++) {

		cin >> choice;
		cout << "--------------------------------" << endl;
		cout << "����: " << floor[choice - 1] << endl;
		cout << "�������: " << sqare[choice - 1] << " m^2 " << endl;
		cout << "�����������: " << air[choice - 1] << endl;
		cout << "���������: " << cost[choice - 1] << " BYN" << endl;
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
		cout << "������������ �: ";
		cout << current_size + 1 << endl;
		cout << "�.�.�: " << endl;
		cin >> list_of_person[current_size].name;
		cout << "�����: " << endl;
		cin >> list_of_person[current_size].adress;
		cout << "�������: " << endl;
		cin >> list_of_person[current_size].phone;
		cout << "���������: " << endl;
		cin >> list_of_person[current_size].requisites;
		cout << "���������� ����: " << endl;
		cin >> list_of_person[current_size].contact_person;
		current_size++;
	}
	else
		cout << "������� ������������ ���-�� �����" << endl;
	system("cls");
	Room();
}

string namefile;
void Contract() {
	int n;
	cout << "������� �������� �����" << endl;
	cin >> namefile;
		ofstream fout("D:\\labaratorki\\������������ ������ 2 �������\\��\\"+namefile+".txt");
	cout << "����� �������:  " << endl;
	cin >> n;
	fout << "===================CONTRACT===================" << endl;
	fout << "������ �" << n << endl;
	fout << "�.�.�: ";
	fout << list_of_person[n - 1].name << endl;
	fout << "�����: ";
	fout << list_of_person[n - 1].adress << endl;
	fout << "�������: ";
	fout << list_of_person[n - 1].phone << endl;
	fout << "���������: ";
	fout << list_of_person[n - 1].requisites << endl;
	fout << "��������� ����: ";
	fout << list_of_person[n - 1].contact_person << endl;
	fout << "--------------------" << endl;
	fout << "�������� �" << num+1 << endl;
	fout << "--------------------" << endl;
	fout << "���� ������: " << endl;
	fout << "���� ������: " << __TIMESTAMP__ << "; ���� ������: " << ar << " ������(���)" << endl;
	fout << "==============================================" << endl;
	system("cls");
}
ifstream fin;
void Reeding() {
	ifstream fin("D:\\labaratorki\\������������ ������ 2 �������\\��\\"+namefile+".txt"); // �������� ���� ��� ������
	if (fin.is_open())
	{
		int n;
		cout << "����� �������:  " << endl;
		cin >> n;
		cout << "===================CONTRACT===================" << endl;
		cout << "������ �" << n << endl;
		cout << "�.�.�: ";
		cout << list_of_person[n - 1].name << endl;
		cout << "�����: ";
		cout << list_of_person[n - 1].adress << endl;
		cout << "�������: ";
		cout << list_of_person[n - 1].phone << endl;
		cout << "���������: ";
		cout << list_of_person[n - 1].requisites << endl;
		cout << "��������� ����: ";
		cout << list_of_person[n - 1].contact_person << endl;
		cout << "--------------------" << endl;
		cout << "�������� �" << num << endl;
		cout << "--------------------" << endl;
		cout << "���� ������: " << endl;
		cout << "���� ������: " << __TIMESTAMP__ << "; ���� ������: " << ar << " ������(���)" << endl;
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
		cout << "�������� " << endl;
		cout << "0-����� ������" << endl;
		cout << "1-������ � ����:" << endl;
		cout << "2-������ �����:" << endl;
		cout << "3-����� �� �����:" << endl;
		cout << "4-�������� ���������� �����" << endl;
		cout << "5-�������� �����" << endl;
		cout << "6-��������� ���������:" << endl;
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