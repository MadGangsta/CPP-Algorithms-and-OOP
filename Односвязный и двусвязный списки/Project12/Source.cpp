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
	cout << "Выберите, какой создать список:" << endl;
	cout << "1 - односвязный" << endl;
	cout << "2 - двусвязный" << endl;
	cin >> bl;
	if (bl == 1)
	{
		int m;
		system("cls");
		cout << "Составлено 10 элементов односвязного списка" << endl;
		cout << "Нажмите 1 чтобы добавить элемент" << endl;
		cout << "Нажмите 2 чтобы удалить элемент" << endl;
		cout << "Нажмите 3 чтобы просмотреть элемент" << endl;
		cout << "Нажмите 4 чтобы просмотреть кол-во элементов списка" << endl;
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
			cout << "Ведите значение и индекс добавляемого элемента" << endl;
			int x,c;
			cout << "Индекс - ";
			cin >> x;
			cout << endl;
			cout << "Значение - ";
			cin >> c;
			cout << endl;
			Biba.insert(c, x);
			cout << "Элемент добавлен - " << Biba[x] << endl;
			break;
		case 2:
			system("cls");
			cout << "Ведите индекс удаляемого элемента" << endl;
			int v;
			cin >> v;
			Biba.removeAt(v);
			cout << "Элемент удален"<< endl;
			break;
		case 3:
			system("cls");
			cout << "Ведите индекс требуемого элемента" << endl;
			int b;
			cin >> b;
			cout << "Значение элемента - " << Biba[b] << endl;
			break;
		case 4:
			system("cls");
			cout << "Колическо элементов" << endl;
			cout << Biba.GetSize() << endl;
			break;
		default:
			std::cout << "Выберите другое число";
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
		cout << "Составлено 10 элементов двусвязного списка" << endl;
		cout << "Нажмите 1 чтобы добавить элемент" << endl;
		cout << "Нажмите 2 чтобы удалить элемент" << endl;
		cout << "Нажмите 3 чтобы просмотреть элемент" << endl;
		cout << "Нажмите 4 чтобы просмотреть кол-во элементов списка" << endl;
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
			cout << "Ведите значение и индекс добавляемого элемента" << endl;
			int x, c;
			cout << "Индекс - ";
			cin >> x;
			cout << endl;
			cout << "Значение - ";
			cin >> c;
			cout << endl;
			Boba.insert(c, x);
			cout << "Элемент добавлен - " << Boba[x] << endl;
			break;
		case 2:
			system("cls");
			cout << "Ведите индекс удаляемого элемента" << endl;
			int v;
			cin >> v;
			Boba.removeAt(v);
			cout << "Элемент удален"<< endl;
			break;
		case 3:
			system("cls");
			cout << "Ведите индекс требуемого элемента" << endl;
			int b;
			cin >> b;
			cout << "Значение элемента - " << Boba[b] << endl;
			break;
		case 4:
			system("cls");
			cout << "Колическо элементов" << endl;
			cout << Boba.GetSize() << endl;
			break;
		default:
			std::cout << "Выберите другое число";

		}
		cout << "-------------------" << endl;
		for (int i = 0; i < Boba.GetSize(); i++)
		{
			cout << Boba[i] << endl;
		}
		cout << "-------------------" << endl;
	}
}

