#include <fstream>
#include <iostream>
#include <iomanip>
#include "KekMatrix.h"
#include <conio.h>
#include <locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int num;
	KekMatrix a;
	char ans = '1';
	while (ans == '1')
	{
	cout << "                                               Программа для работы с матрицами" << endl;
	cout << "1)Нажмите T чтобы транспонировать матрицу" << endl<<endl;
	cout << "2)Нажмите U чтобы умножить матрицу на введеное число" << endl << endl;
	cout << "3)Нажмите D чтобы найти определитель матрицы" << endl << endl;
	cout << "4)Нажмите О чтобы найти обратную матрицу" << endl << endl;

	char ch;
	ch = _getch();
	if (ch == 116 || ch == 84)
	{
		a.setKekMatrix();
		a.transpon();
		a.Zapoln();
	}
	else if (ch == 111 || ch == 79)
	{
		a.setKekMatrix();
		a.Obratnaya();
		a.Zapoln();
	}
	else if (ch == 117 || ch == 85)
	{
		a.setKekMatrix();
		cout << "Введите число на которое нужно умножить матрицу" << endl;
		cin >> num;
		a.UmnojenieNaChislo(num);
		a.Zapoln();
	}
	else if (ch == 100 || ch == 68)
	{
		a.setKekMatrix();
		a.det();
		a.Zapoln();
	}
		cout << "Some work.." << endl;
		cout << "Continue: 1, exit: 0 -> ";
		cin >> ans;
		system("cls");
	}
}
