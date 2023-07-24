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
	string air[3] = { "����","����","����"};
	int cost[3] = { 200, 100, 160};
	int choice;
	cout << "=====================ROOMS=====================" << endl;
	cout << "������� ����� ��������� ����� ���������� ����������:" << endl;
	cout << "��������� �1" << endl;
	cout << "��������� �2" << endl;
	cout << "��������� �3" << endl;

	cout << "--------------------------------" << endl;
	 for (int i = 0; i < 3; i++) {

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
		cout << "������� ������������ ���-�� �����";
	system("cls");
}

void Contract() {
	int n;
	cout << "����� �������:  " << endl;
	cin >> n;
	system("cls");
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
	cout << "�������� �" << num[n] << endl;
	cout << "--------------------" << endl;
	cout << "���� ������: " << endl;
	cout << "���� ������: "<<__TIMESTAMP__<< "; ���� ������: "<< ar <<" ������(���)" << endl;
	cout << "==============================================" << endl;
	system("pause");
}

void Consent() {
	int a, x;
	cout << "====================CONSENT====================" << endl;
	cout << "�� ������ ���������� ���������" << endl;
		cout << "�� - 1" << endl;
		cout << "��� - 0" << endl;
		cin >> a;
		if (a == 1) {
			cout << "����� ���������: " << endl;
			cin >> x;
			num[x];
			cout << "�� ����� ����(� �������): " << endl;
			cin >> ar;
			Contract();
		}
		else if (a == 0) {
			cout << "�������� ��� ���" << endl;
		}
		system("cls");
}




int main() {
	setlocale(LC_ALL, "rus");
	int g;
	int i = 0;
		
		for (int i = 0; i < 4; ) {
			cout << "(1)-��� ����� ������" << endl;
			cout << "(2)-����� ������������ �� ������ ��������" << endl;
			cout << "(3)-��� ������ ���� ����������" << endl;
			cout << "(4)-��� ������ �������" << endl;
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
						cout << "������ �" << i << endl;
						cout << "�.�.�: ";
						cout << list_of_person[i].name << endl;
						cout << "�����: ";
						cout << list_of_person[i].adress << endl;
						cout << "�������: ";
						cout << list_of_person[i].phone << endl;
						cout << "���������: ";
						cout << list_of_person[i].requisites << endl;
						cout << "��������� ����: ";
						cout << list_of_person[i].contact_person << endl;
						cout << "--------------------" << endl;
						cout << "�������� �" << num[i] << endl;
						cout << "--------------------" << endl;
						cout << "���� ������: " << endl;
						cout << "���� ������: " << __TIMESTAMP__ << "; ���� ������: " << ar << " ������(���)" << endl;
						cout << "==============================================" << endl;
					}
				}
				break;
			case 3:
				for (int i = 0; i < 3; i++) {
					cout << "===================CONTRACT===================" << endl;
					cout << "������ �" << i << endl;
					cout << "�.�.�: ";
					cout << list_of_person[i].name << endl;
					cout << "�����: ";
					cout << list_of_person[i].adress << endl;
					cout << "�������: ";
					cout << list_of_person[i].phone << endl;
					cout << "���������: ";
					cout << list_of_person[i].requisites << endl;
					cout << "��������� ����: ";
					cout << list_of_person[i].contact_person << endl;
					cout << "--------------------" << endl;
					cout << "�������� �" << num[i] << endl;
					cout << "--------------------" << endl;
					cout << "���� ������: " << endl;
					cout << "���� ������: " << __TIMESTAMP__ << "; ���� ������: " << ar << " ������(���)" << endl;
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













