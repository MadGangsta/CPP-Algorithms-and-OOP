#include "Derevo.h"
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	Derevo t;
	t.SetArr();
	t.SozdanieDereva();
	cout << "Сортировка массива" << endl;
	t.sortrovka(t.centr);

	cout << endl;
	cout << "Высота дерева = " << t.Visota(t.centr) << endl;
	t.Otrisovka(t.centr);
}
