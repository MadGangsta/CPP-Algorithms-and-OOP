#include "Derevo.h"
#include <windows.h>

Derevo::Derevo()
{
	centr = nullptr;
}

void Derevo::SetArr()
{
	ifstream fin;
	fin.open("Text.txt");
	char sym;
	if (!fin.is_open())
	{
		cout << "Ошибка" << endl;
	}
	else
	{
		for (int n = 0; !fin.eof(); n++)
		{
			double kek;
			fin >> kek;
			Size++;
			fin.get(sym);
			if (sym == '\n')
				break;
		}
		fin.clear();
		a = new double[Size];
		fin.seekg(0, ios::beg);
		for (int i = 0; i < Size; i++)
		{
			fin >> a[i];
		}
		cout << "Числа,считанные из файла" << endl;
		for (int i = 0; i < Size; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
}

void Derevo::SozdanieDereva()
{
	for (int i = 0; i < Size; i++)
	{
		Dobavit(a[i], centr);
	}
}

void Derevo::Otrisovka(Node*& v)
{
	if (v == nullptr)
	{
		return;
	}
	k += 10;
	Otrisovka(v->right);
	for (int i = 0; i < k; i++)
	{
		cout << " ";
	}
	cout << v->data << endl;
	Otrisovka(v->left);
	k -= 10;
	return;
}

void Derevo::Dobavit(double data, Node*& v)
{
	if (v == nullptr)
	{
		v = new Node(data);
		return;
	}
	else
	{
		if (data < v->data)
		{
			Dobavit(data, v->left);
		}
		else
		{
			Dobavit(data, v->right);
		}
	}
}

int Derevo::Visota(Node*& v)
{
	int l, r, m = 0;
	if (v != nullptr)
	{
		l = Visota(v->left);
		r = Visota(v->right);
		if (l > r)
		{
			m = l + 1;
		}
		else
		{
			m = r + 1;
		}
	}
	return m;
}

void Derevo::sortrovka(Node*& v)
{
	if (v != nullptr)
	{
		sortrovka(v->left);
		cout << v->data << " ";
		sortrovka(v->right);
	}
}
