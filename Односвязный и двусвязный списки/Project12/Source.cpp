#include "List.h"
#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	List Biba;
	List2 Boba;
	int bl;
	cout << "��������, ����� ������� ������:" << endl;
	cout << "1 - �����������" << endl;
	cout << "2 - ����������" << endl;
	cin >> bl;
	if (bl == 1)
	{
		int m;
		system("cls");
		cout << "���������� 10 ��������� ������������ ������" << endl;
		cout << "������� 1 ����� �������� �������" << endl;
		cout << "������� 2 ����� ������� �������" << endl;
		cout << "������� 3 ����� ����������� �������" << endl;
		cout << "������� 4 ����� ����������� ���-�� ��������� ������" << endl;
		int n = 10;
		cout << "-------------------" << endl;
		for (int i = 0; i < n; i++)
		{
			int rnd = rand() % 30;
			Biba.insert(rnd, i);
			cout << Biba[i] << endl;
		}
		cout << "-------------------" << endl;
		cin >> m;
		switch (m)
		{
		case 1:
			system("cls");
			cout << "������ �������� � ������ ������������ ��������" << endl;
			int x,c;
			cout << "������ - ";
			cin >> x;
			cout << endl;
			cout << "�������� - ";
			cin >> c;
			cout << endl;
			Biba.insert(c, x);
			cout << "������� �������� - " << Biba[x] << endl;
			break;
		case 2:
			system("cls");
			cout << "������ ������ ���������� ��������" << endl;
			int v;
			cin >> v;
			Biba.removeAt(v);
			cout << "������� ������"<< endl;
			break;
		case 3:
			system("cls");
			cout << "������ ������ ���������� ��������" << endl;
			int b;
			cin >> b;
			cout << "�������� �������� - " << Biba[b] << endl;
			break;
		case 4:
			system("cls");
			cout << "��������� ���������" << endl;
			cout << Biba.GetSize() << endl;
			break;
		default:
			std::cout << "�������� ������ �����";
			break;
		}
		cout << "-------------------" << endl;
		for (int i = 0; i < Biba.GetSize(); i++)
		{
			cout << Biba[i] << endl;
		}
		cout << "-------------------" << endl;
	}
	else
	{
		int m;
		system("cls");
		cout << "���������� 10 ��������� ����������� ������" << endl;
		cout << "������� 1 ����� �������� �������" << endl;
		cout << "������� 2 ����� ������� �������" << endl;
		cout << "������� 3 ����� ����������� �������" << endl;
		cout << "������� 4 ����� ����������� ���-�� ��������� ������" << endl;
		int n = 10;
		cout << "-------------------" << endl;
		for (int i = 0; i < n; i++)
		{
			int rnd = rand() % 30;
			Boba.insert(rnd, i);
			cout << Boba[i] << endl;
		}
		cout << "-------------------" << endl;
		cin >> m;
		switch (m)
		{
		case 1:
			system("cls");
			cout << "������ �������� � ������ ������������ ��������" << endl;
			int x, c;
			cout << "������ - ";
			cin >> x;
			cout << endl;
			cout << "�������� - ";
			cin >> c;
			cout << endl;
			Boba.insert(c, x);
			cout << "������� �������� - " << Boba[x] << endl;
			break;
		case 2:
			system("cls");
			cout << "������ ������ ���������� ��������" << endl;
			int v;
			cin >> v;
			Boba.removeAt(v);
			cout << "������� ������"<< endl;
			break;
		case 3:
			system("cls");
			cout << "������ ������ ���������� ��������" << endl;
			int b;
			cin >> b;
			cout << "�������� �������� - " << Boba[b] << endl;
			break;
		case 4:
			system("cls");
			cout << "��������� ���������" << endl;
			cout << Boba.GetSize() << endl;
			break;
		default:
			std::cout << "�������� ������ �����";

		}
		cout << "-------------------" << endl;
		for (int i = 0; i < Boba.GetSize(); i++)
		{
			cout << Boba[i] << endl;
		}
		cout << "-------------------" << endl;
	}
}

